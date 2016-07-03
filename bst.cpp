#include "bst.h"
#include <stdexcept>

BST::BST(Node *node) {
  this->root = node;
}

BST::BST(string data, int value) {
  Node *node = new Node(data, value);
  this->root = node;
}

void BST::insert(string data, int value) {
  if (this->root->value == value) {
    throw std::invalid_argument("Duplicates are not allowed to be inserted.");
  } else if (this->root->value < value) {
    if (this->root->rchild == NULL) {
      Node *node = new Node(data, value);
      this->root->rchild = node;
    } else {
      insert(data, value, this->root->rchild);
    }
  } else {
    if (this->root->lchild == NULL) {
      Node *node = new Node(data, value);
      this->root->lchild = node;
    } else {
      insert(data, value, this->root->lchild);
    }
  }
}

void BST::insert(string data, int value, Node* currentNode) {
  if (currentNode->value == value) {
    throw invalid_argument("Duplicates are not allowed to be inserted.");
  } else if (currentNode->value < value) {
    if (currentNode->rchild == NULL) {
      Node *node = new Node(data, value);
      currentNode->rchild = node;
    } else {
      insert(data, value, currentNode->rchild);
    }
  } else {
    if (currentNode->lchild == NULL) {
      Node *node = new Node(data, value);
      currentNode->lchild = node;
    } else {
      insert(data, value, currentNode->lchild);
    }
  }
}
