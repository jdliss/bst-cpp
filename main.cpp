#include "bst.h"

int main() {
  BST ll = BST("root node", 50);

  cout << "root node data: " <<  ll.root->data << ", value: " <<  ll.root->value << endl;

  ll.insert("rchild 1", 55);
  ll.insert("lchild 1", 45);

  Node *rchild = ll.root->rchild;
  cout << "root rchild data: " << rchild->data << ", value: " << rchild->value << endl;


  Node *lchild = ll.root->lchild;
  cout << "root rchild data: " << lchild->data << ", value: " << lchild->value << endl;

  return 0;
}
