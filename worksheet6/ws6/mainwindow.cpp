#include "mainwindow.h"
#include "OptionDialog.h"
#include "ui_mainwindow.h"
#include <QDir>
#include <QFileDialog>
#include <QFileInfo>
#include <QMessageBox>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent), ui(new Ui::MainWindow) {
  ui->setupUi(this);

  // Connect the released() signals to the slots
  connect(ui->pushButton, &QPushButton::released, this,
          &MainWindow::handleButton);
  connect(ui->pushButton_2, &QPushButton::released, this,
          &MainWindow::handleButton2);

  // Connect the statusUpdateMessage() signal to the showMessage() slot of the
  // status bar
  connect(this, &MainWindow::statusUpdateMessage, ui->statusbar,
          &QStatusBar::showMessage);

  // Connect the clicked() signal of the tree view to the handleTreeClicked slot
  connect(ui->treeView, &QTreeView::clicked, this,
          &MainWindow::handleTreeClicked);

  /* Create/allocate the ModelList */
  this->partList = new ModelPartList("PartsList");

  /* Link it to the treeview in the GUI */
  ui->treeView->setModel(this->partList);

  /* Manually create a model tree - there are much better and more flexible ways
     of doing this, e.g. with nested functions. This is just a quick example as
     a starting point. */
  ModelPart *rootItem = this->partList->getRootItem();

  /* Add 3 top level items */
  for (int i = 0; i < 3; i++) {
    /* Create strings for both data columns */
    QString name = QString("TopLevel %1").arg(i);
    QString visible("Yes");

    /* Create child item */
    ModelPart *childItem = new ModelPart({name, visible});

    /* Append to tree top-level */
    rootItem->appendChild(childItem);

    /* Add 5 sub-items */
    for (int j = 0; j < 5; j++) {
      QString name = QString("Item %1,%2").arg(i).arg(j);
      QString visible("Yes");

      ModelPart *childChildItem = new ModelPart({name, visible});

      /* Append to parent */
      childItem->appendChild(childChildItem);
    }
  }
  ui->treeView->setContextMenuPolicy(Qt::ActionsContextMenu);
  ui->treeView->addAction(ui->actionItem_Options);
}

MainWindow::~MainWindow() {
  delete ui;
  delete partList;
}

void MainWindow::handleButton() {
  emit statusUpdateMessage(QString("Button 1 was clicked"), 0);
}

void MainWindow::handleButton2() {
  /* Get the index of the selected item */
  QModelIndex index = ui->treeView->currentIndex();

  /* If the index isn't valid, nothing is selected */
  if (!index.isValid()) {
    QMessageBox::warning(this, "No Selection",
                         "Please select an item in the tree view first.");
    return;
  }

  /* Get a pointer to the item from the index */
  ModelPart *selectedPart = static_cast<ModelPart *>(index.internalPointer());

  /* Create the dialog and set the initial values */
  OptionDialog dialog(this);
  dialog.setName(selectedPart->data(0).toString());
  dialog.setItemVisible(selectedPart->data(1).toString() == "Yes");
  dialog.setStlPath(selectedPart->getStlPath());
  dialog.setR(selectedPart->getColourR());
  dialog.setG(selectedPart->getColourG());
  dialog.setB(selectedPart->getColourB());

  /* Show the dialog */
  if (dialog.exec() == QDialog::Accepted) {
    /* Update the item data through the model to ensure view updates */
    partList->setData(index, dialog.getName(), Qt::EditRole);
    partList->setData(index.siblingAtColumn(1),
                      dialog.getVisible() ? "Yes" : "No", Qt::EditRole);

    selectedPart->setStlPath(dialog.getStlPath());
    selectedPart->setColour(dialog.getR(), dialog.getG(), dialog.getB());

    emit statusUpdateMessage(QString("Updated item: ") + dialog.getName(), 0);
  }
}

void MainWindow::handleTreeClicked() {
  /* Get the index of the selected item */
  QModelIndex index = ui->treeView->currentIndex();

  /* Get a pointer to the item from the index */
  ModelPart *selectedPart = static_cast<ModelPart *>(index.internalPointer());

  /* In this case, we will retrieve the name string from the internal QVariant
   * data array */
  QString text = selectedPart->data(0).toString();

  emit statusUpdateMessage(QString("The selected item is: ") + text, 0);
}

void MainWindow::on_actionOpen_File_triggered() {
  /* Get the index of the selected item */
  QModelIndex index = ui->treeView->currentIndex();

  /* If the index isn't valid, nothing is selected */
  if (!index.isValid()) {
    QMessageBox::warning(this, "No Selection",
                         "Please select an item in the tree view first.");
    return;
  }

  /* Get a pointer to the item from the index */
  ModelPart *selectedPart = static_cast<ModelPart *>(index.internalPointer());

  QString fileName =
      QFileDialog::getOpenFileName(this, tr("Open File"), QDir::currentPath(),
                                   tr("STL Files (*.stl);;Text Files (*.txt)"));

  if (!fileName.isEmpty()) {
    /* Load the STL file - this updates internal path */
    selectedPart->loadSTL(fileName);

    /* Update the item name property in the model to reflect the filename
     * selected This will trigger the view to update via the dataChanged signal
     * inside setData */
    QFileInfo fileInfo(fileName);
    partList->setData(index.siblingAtColumn(0), fileInfo.fileName(),
                      Qt::EditRole);

    emit statusUpdateMessage(QString("Opened file: ") + fileInfo.fileName() +
                                 " and updated item name",
                             0);
  } else {
    emit statusUpdateMessage(QString("Open file cancelled"), 0);
  }
}

void MainWindow::on_actionItem_Options_triggered() { handleButton2(); }
