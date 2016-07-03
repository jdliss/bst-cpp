#include "node.h"

class BST {
 public:
  Node* root;

  BST(Node*);
  BST(string, int);
  void insert(string, int);
  void insert(string, int, Node*);
};
