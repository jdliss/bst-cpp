#include "bst.h"
#include <stdexcept>
#include <fstream>
#include <sstream>


BST::BST(Node *node) {
  this->root = node;
}

BST::BST(string data, int value) {
  Node *node = new Node(data, value);
  this->root = node;
}

int BST::insert(string data, int value) {
  return insert(data, value, this->root);
}

int BST::insert(string data, int value, Node* currentNode) {
  if (currentNode->value < value) {
    if (currentNode->rchild == NULL) {
      Node *node = new Node(data, value);
      currentNode->rchild = node;
      return depthOf(value);
    } else {
      return insert(data, value, currentNode->rchild);
    }
  } else {
    if (currentNode->lchild == NULL) {
      Node *node = new Node(data, value);
      currentNode->lchild = node;
      return depthOf(value);
    } else {
      return insert(data, value, currentNode->lchild);
    }
  }
}

int BST::depthOf(int value) {
  return depthOf(value, this->root);
}

int BST::depthOf(int value, Node* currentNode) {
  if (currentNode->value == value) {
    return 1;
  } else {
    if (currentNode->value < value) {
      return 1 + depthOf(value, currentNode->rchild);
    } else {
      return 1 + depthOf(value, currentNode->lchild);
    }
  }
}

bool BST::includes(int value) {
  return includes(value, this->root);
}

bool BST::includes(int value, Node* currentNode) {
  if (currentNode->value == value) {
    return true;
  } else {
    if (currentNode->value < value) {
      return includes(value, currentNode->rchild);
    } else {
      return includes(value, currentNode->lchild);
    }
  }
}

Node* BST::maxNode() {
  Node* currentNode = this->root;
  while (currentNode->rchild != NULL) {
    currentNode = currentNode->rchild;
  }
  return currentNode;
}

int BST::max() {
  return maxNode()->value;
}

Node* BST::minNode() {
  Node* currentNode = this->root;
  while (currentNode->lchild != NULL) {
    currentNode = currentNode->lchild;
  }
  return currentNode;
}

int BST::min() {
  return minNode()->value;
}

vector<map<string, int>> BST::sort() {
  sort(this->root);
  return this->sorted;
}

void BST::sort(Node* currentNode) {
  if (currentNode->lchild != NULL) {
    sort(currentNode->lchild);
  }

  map<string, int> hash;
  hash[currentNode->data] = currentNode->value;
  this->sorted.push_back(hash);

  if (currentNode->rchild != NULL) {
    sort(currentNode->rchild);
  }
}

void BST::load(string filename) {
  vector<string> data;
  string line;
  ifstream file;
  file.open(filename);
  while (getline(file, line)) {
    data.push_back(line);
  }

  vector<map<string, int>> parsedLines;
  for (const string s : data) {

    string::size_type loc = s.find( ",", 0 );
    string value = s.substr(0, loc);
    int val = atoi(value.c_str());

    string data = s.substr(loc+1);
    map<string, int> hash;
    hash[data] = val;
    parsedLines.push_back(hash);
  }

  for (int i = 0; i < parsedLines.size(); i++) {
    for ( const auto &pair : parsedLines[i]){
      int value = pair.second;
      string data = pair.first;
      insert(data.erase(0,1), value);
    }
  }
}
