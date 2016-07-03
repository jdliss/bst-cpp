#include "node.h"
#include <vector>
#include <map>

class BST {
 public:
  Node* root;

  BST(Node*);
  BST(string, int);

  int insert(string, int);
  int insert(string, int, Node*);
  int depthOf(int);
  int depthOf(int, Node*);
  bool includes(int);
  bool includes(int, Node*);
  int max();
  int min();
  vector<map<string, int>> sort();
  void sort(Node*);

 private:
  vector<map<string, int>> sorted;
};
