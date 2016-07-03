#include <string>
#include <iostream>

using namespace std;

class Node {
 public:
  string data;
  int value;
  Node* lchild;
  Node* rchild;

  Node(string);
};
