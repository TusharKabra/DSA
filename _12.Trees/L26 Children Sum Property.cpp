
Node=Left node Value +right Node value
Also we can only increase the value and not decrease it for any node.

Procedure:
If both children sum is less than parent, make children's value to parent's value.

If both children values sum is greater than or equal to parent, make parent's value to children's sum.

Recursively go left and right. Traversal type: DFS.

When coming back up the tree, take children sum and replace it in parent.

At any point we reach null, just return (base case)

Intuition: while going down, increase the children values so we make sure to never fall short, 
then all we have to do is sum both children and replace it in parent.

#include <bits/stdc++.h>

using namespace std;

struct node {
  int data;
  struct node * left, * right;
};

void reorder(node * root) {
  if (root == NULL) 
    return;
  int child = 0;
//Calculating sum of child node value  
  if (root -> left) 
  {
    child += root -> left -> data;
  }
  if (root -> right) 
  {
    child += root -> right -> data;
  }
 
  if (child < root -> data) 
  {
    if (root -> left) 
	root -> left -> data = root -> data;
	
    else if (root -> right) 
	root -> right -> data = root -> data;
  }

  reorder(root -> left);
  reorder(root -> right);


//When we are coming up the tree
  int tot = 0;
  if (root -> left) tot += root -> left -> data;
  if (root -> right) tot += root -> right -> data;
  if (root -> left || root -> right) root -> data = tot;
}
void changeTree(node * root) {
  reorder(root);
}

struct node * newNode(int data) {
  struct node * node = (struct node * ) malloc(sizeof(struct node));
  node -> data = data;
  node -> left = NULL;
  node -> right = NULL;

  return (node);
}

int main() {

  struct node * root = newNode(2);
  root -> left = newNode(35);
  root -> left -> left = newNode(2);
  root -> left -> right = newNode(3);
  root -> right = newNode(10);
  root -> right -> left = newNode(5);
  root -> right -> right = newNode(2);

  changeTree(root);

  return 0;
}