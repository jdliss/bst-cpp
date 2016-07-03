#include "node.h"

Node::Node(string data, int value) {
  this->data = data;
  this->value = value;
  this->rchild = NULL;
  this->lchild = NULL;
}
