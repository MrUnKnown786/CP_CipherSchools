// Check if the tree is a (full binary tree or balanced binary tree or perfect binary tree) or not

#include<bits/stdc++.h> 
  
struct Node 
{ 
    int key; 
    struct Node *left, *right; 
}; 
   
int findADepth(Node *node) 
{ 
   int d = 0; 
   while (node != NULL) 
   { 
      d++; 
      node = node->left; 
   } 
   return d; 
} 
  
bool isPerfectRec(struct Node* root, int d, int level = 0) 
{ 
    if (root == NULL) 
        return true; 
  
    if (root->left == NULL && root->right == NULL) 
        return (d == level+1); 
   
    if (root->left == NULL || root->right == NULL) 
        return false; 
   
    return isPerfectRec(root->left, d, level+1) && 
           isPerfectRec(root->right, d, level+1); 
} 
  
bool isPerfect(Node *root) 
{ 
   int d = findADepth(root); 
   return isPerfectRec(root, d); 
} 
  
struct Node *newNode(int k) 
{ 
    struct Node *node = new Node; 
    node->key = k; 
    node->right = node->left = NULL; 
    return node; 
}

bool isFullBinaryTree(struct Node *root) {
  
  if (root == NULL)
    return true;

  if (root->left == NULL && root->right == NULL)
    return true;

  if ((root->left) && (root->right))
    return (isFullBinaryTree(root->left) && isFullBinaryTree(root->right));

  return false;
}

bool checkHeightBalance(node *root, int *height) {
  
  int leftHeight = 0, rightHeight = 0;

  int l = 0, r = 0;

  if (root == NULL) {
    *height = 0;
    return 1;
  }

  l = checkHeightBalance(root->left, &leftHeight);
  r = checkHeightBalance(root->right, &rightHeight);

  *height = (leftHeight > rightHeight ? leftHeight : rightHeight) + 1;

  if ((leftHeight - rightHeight >= 2) || (rightHeight - leftHeight >= 2))
    return 0;

  else
    return l && r;
}
  
int main() 
{ 
	int height=0;
    struct Node* root = NULL; 
    root = newNode(10); 
    root->left = newNode(20); 
    root->right = newNode(30); 
  
    root->left->left = newNode(40); 
    root->left->right = newNode(50); 
    root->right->left = newNode(60); 
    root->right->right = newNode(70); 
  
    if (isPerfect(root)) 
        printf("It is Perfect Binary tree"); 
    else if (isFullBinaryTree(root))
        printf("It is Full Binary Tree"); 
    
    else if (checkHeightBalance(root, &height))
    	printf("It is Balanced Binary Tree");
  
    return(0); 
} 
