#include "node.h"

class BST {
 public:
  Node* root;

  BST(Node*);
  BST(string, int);
  int insert(string, int);
  int insert(string, int, Node*);
  int depthOf(int);
  int depthOf(int, Node*);
};
