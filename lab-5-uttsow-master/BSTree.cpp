#include "BSTree.h"
#include <cstdlib>
#include <iostream>
#include <vector>

using namespace std;

BSTree::Node::Node(int aData){
  data = aData;
	parent = NULL;
	left = NULL;
	right = NULL;
}

BSTree::BSTree(){
	root = NULL;
}


//Recursive Destructor; Works with ~BSTree
void BSTree::postOrder(Node *n){
  if(n){
    postOrder(n->left);
    postOrder(n->right);
    delete n;
  }   //postOder operations go at the end
}

BSTree::~BSTree(){
  postOrder(root);
}

//DEEP COPY
BSTree::BSTree(const BSTree &old_tree){
  if(old_tree.root == NULL){
    root = NULL;
  }else{
    root = new BSTree::Node(old_tree.root->data);
    BSTreeCopy(old_tree.root);
  }
}

//uses inOrder transveral to copy the tree
void BSTree::BSTreeCopy(Node *n){
  if(n == NULL){
    return;
  }else{
    //preOrder
    insert(n->data);
    if(n->left) BSTreeCopy(n->left);
    if(n->right) BSTreeCopy(n->right);
  }
}


bool BSTree::empty(){
	if(root == NULL){
		return true;
	}else{
		return false;
	}
}

//uses loops
bool BSTree::insert(int val){
	Node * temp = root;

	if(root == NULL) {
		root = new BSTree::Node(val);
		return true;
	}

	while(true){
		if(val > temp->data){
			if(temp->right == NULL){
				temp->right = new BSTree::Node(val);
				temp->right->parent = temp;
				return true;
			}else{
				temp = temp->right;
			}
		}
		if(val < temp->data){
			if(temp->left == NULL){
				temp->left = new BSTree::Node(val);
				temp->left->parent = temp;
				return true;
			}else{
				temp = temp->left;
			}
		}

		if(val == temp->data){
			return false;
		}
	}
}

bool BSTree::find(int val){
	Node *temp = root;

	if(root == NULL){
		return false;
	}

	while(true){
		if(val > temp->data){
			if(temp->right == NULL){
				return false;
			}else{
				temp = temp->right;
			}
		}
		if(val < temp->data){
			if(temp->left == NULL){
				return false;
			}else{
				temp = temp->left;
			}
		}

		if(val == temp->data){
			return true;
		}
	}
}

//Used with remove to find the node to remove
BSTree::Node * BSTree::findValue(int val){
  Node *temp = root;
  Node *retVal = NULL;

  if(temp == NULL){
    return retVal;
  }

  while(true){
    if(val > temp->data){
      if(temp->right == NULL){
        return retVal;
      }else{
        temp = temp->right;
      }
    }
    if(val < temp->data){
      if(temp->left ==NULL){
        return retVal;
      }else{
        temp = temp ->left;
      }

    }
    if(val == temp->data){
      retVal=temp;
      return retVal;
    }
  }
}

bool BSTree::remove(int val){
  //Check if the root is NULL
  if(empty()){
    return false;
  }

  Node * temp = findValue(val);

  if(temp == NULL) return false;

  if(temp->parent && !temp->left && !temp->right){
    if(temp->parent->left != NULL && temp->parent->left == temp){
      temp->parent->left = NULL;
      delete temp;
      return true;
    }else{
      temp->parent->right = NULL;
      delete temp;
      return true;
    }
  }

  //Tree has a root but no children
  if(root == temp && !root->left && !root->right){
    root = NULL;
    delete temp;
    return true;
  }

  //If right child is null but left exist
  if(temp->right == NULL && temp->left){
    if(temp->parent){
      if(temp->parent->right == temp){
        temp->parent->right = temp->left;
        temp->left->parent = temp->parent;
        delete temp;
        return true;
      }else{
        temp->parent->left = temp->left;
        temp->left->parent = temp->parent;
        delete temp;
        return true;
      }
    }else{
      temp->left->parent = NULL;
      root = temp->left;
      delete temp;
      return true;
    }
  }

  //If right is not NULL but left is NULL
  if(temp->right && temp->left == NULL){
    if(temp->parent){
      if(temp->parent->left == temp){
        temp->parent->left = temp->right;
        temp->right->parent = temp->parent;
        delete temp;
        return true;
      }else{
        temp->parent->right = temp->right;
        temp->right->parent = temp->parent;
        delete temp;
        return true;
      }
    }else{
      temp->right->parent = NULL;
      root = temp->right;
      delete temp;
      return true;
    }
  }

  //Node has both a left and right: 2 Children
  if(temp->left && temp->right){
    Node *replace = temp->right;
    while(replace->left != NULL){
      replace = replace->left;
    }

    temp->data = replace->data;
    if(replace->parent->left == replace){
      replace->parent->left = replace->right;
      if(replace->right)replace->right->parent = replace->parent;
    }else{
      replace->parent->right = replace->right;
      if(replace->right)replace->right->parent = replace->parent;
    }
    delete replace;
    return true;
  }

  return false;
  }


//Uses inOrder Traversal
  void BSTree::inOrderVector(Node * thisRoot, vector<int> &list){
  	Node * temp =  thisRoot;

  	if(temp){
  		if(temp->left) inOrderVector(temp->left,list);
  		list.push_back(temp->data);   //Opeartion is done in the middle
  		if(temp->right) inOrderVector(temp->right,list);
  	}
  }

//Sorting array;
  void BSTree::sortedArray(vector<int> &list){
  	if(root == NULL){
  		return;
  	}else{
  		inOrderVector(root,list);
  	}
  }
