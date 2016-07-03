#include "bst.h"
#include <stdexcept>

BST::BST(Node* node) {
  this->root = node;
}

BST::BST(string data) {
  Node *node = new Node(data);
  this->root = node;
}

void BST::insert(string data, int value) {
  if (self->root.value == value) {
    throw std::invalid_argument("Duplicates are not allowed to be inserted.");
  }
}

