#include "bst.h"

int main() {
  BST bst = BST("root node", 50);

  cout << "root node data: " <<  bst.root->data << ", value: " <<  bst.root->value << endl;

  bst.insert("rchild 1", 55);
  bst.insert("lchild 1", 45);

  cout << "root->rchild data: " << bst.root->rchild->data
       << ", value: " << bst.root->rchild->value << endl;

  cout << "root->lchild data: " << bst.root->lchild->data
       << ", value: " << bst.root->lchild->value << endl;

  bst.insert("rchild 2", 52);
  bst.insert("lchild 2", 48);

  Node *rchildTwo = bst.root->rchild->lchild;
  cout << "root->rchild->lchild data: " << rchildTwo->data
       << ", value: " << rchildTwo->value << endl;

  Node *lchildTwo = bst.root->lchild->rchild;
  cout << "root->lchild->rchild data: " << lchildTwo->data
       << ", value: " << lchildTwo->value << endl;

  cout << "depth of root node is: " << bst.depthOf(50) << endl;
  cout << "depth of root->rchild is: " << bst.depthOf(55) << endl;
  cout << "depth of root->lchild is: " << bst.depthOf(45) << endl;

  cout << "depth of root->rchild->lchild is: " << bst.depthOf(52) << endl;
  cout << "depth of root->lchild->rchild is: " << bst.depthOf(48) << endl;

  bst.insert("rchild 3", 53);
  bst.insert("rchild 4", 54);

  cout << "depth of root->rchild->lchild->rchild is: " << bst.depthOf(53) << endl;
  cout << "depth of root->rchild->lchild->rchild->rchild is: " << bst.depthOf(54) << endl;

  if (bst.includes(50)) {
    cout << "bst includes a node with a value of 50" << endl;
  } else {
    cout << "something went wrong" << endl;
  }

  bst.insert("max node", 100);
  bst.insert("min node", 0);

  cout << "Max value in tree: " << bst.max() << endl;
  cout << "Min value in tree: " << bst.min() << endl;

  BST newBST = BST("root node", 50);
  newBST.load("data.txt");

  cout << "\nCreate new tree, load from file, print sorted tree" << endl << endl;

  vector<map<string, int>> sortedTree = newBST.sort();
  for (int i = 0; i < sortedTree.size(); i++) {
    for ( const auto &myPair : sortedTree[i] ) {
      cout << "{ " << myPair.first << ", " << myPair.second << " }" << endl;
    }
  }

  return 0;
}
