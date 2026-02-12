/**     @file main.cpp
 *
 *     EEEE2076 - Software Engineering & VR Project
 *
 *     Entry point for Worksheet 6
 */

#include "ModelPartList.h"
#include <QApplication>
#include <QTreeView>


int main(int argc, char *argv[]) {
  QApplication app(argc, argv);

  // Create a simple window to display the tree
  QTreeView treeView;
  treeView.setWindowTitle("Worksheet 6 - Tree Model");
  treeView.resize(400, 600);

  // Create the data model
  // The explicit string conversion is just to satisfy the constructor signature
  // in the starter code if it expects QString
  ModelPartList *model = new ModelPartList("Root");

  // Set the model for the view
  treeView.setModel(model);

  // Show the window
  treeView.show();

  return app.exec();
}
