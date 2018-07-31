#ifndef BSTREE_H
#define BSTREE_H
#include <vector>

class BSTree{
  private:
    class Node{
      public:
        Node(int);
        Node *left;
        Node *right;
        Node *parent;
        int data;
      };


  Node *root;
  public:
    BSTree();
    ~BSTree();
    BSTree(const BSTree &old_tree);

    bool empty();
    bool insert(int val);
    bool find(int val);
    bool remove(int val);
    BSTree::Node* findValue(int val);

    void sortedArray(std::vector<int> &list);


    //Traversal
    void postOrder(Node *);
    void BSTreeCopy(Node *);
    void inOrderVector(Node *, std::vector<int> &list);



  };

#endif
