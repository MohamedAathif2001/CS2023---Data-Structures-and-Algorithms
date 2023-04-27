#include <iostream>
using namespace std;

struct node 
{
  int key;
  struct node *left, *right;
};

struct node *findMin(struct node *node) // new utility function to find  miminum in right sub tree
{
    if (node == NULL)
    {
        
        return NULL;
    }
    else if (node->left == NULL)
    {
        return node;
    }
    else
    {
        return findMin(node->left);
    }
}

// Inorder traversal
void traverseInOrder(struct node *root) 
{
    if (root == NULL)
    {
        return; // returning if tree is null
    }
    traverseInOrder(root->left); //concept of inorder
    cout<<root->key<<" ";
    traverseInOrder(root->right);
}

// Insert a node
struct node *insertNode(struct node *node, int key) 
{
    if (node==NULL) //checking for null tress
    {
        struct node *newTree = new struct node; // creating a new BST with root as key
        newTree->key = key;
        newTree->left = NULL;
        newTree->right = NULL;
        return newTree;
    }
    else if (key > node->key) // if the value is greater than node value insert in right sub tree
    {
        node->right = insertNode(node->right,key);
    }
    else // else insert in left sub tree
    {
        node->left = insertNode(node->left,key);
    }
    return node;
}

// Deleting a node
struct node *deleteNode(struct node *root, int key) 
{
    if(root == NULL) 
    {
        return root; //if root is empty return
    }
    
    else if(key < root->key) 
    {
        root->left = deleteNode(root->left, key);
    }
    
    else if(key > root->key) 
    {
        root->right = deleteNode(root->right, key);  
    }
    
    else 
    {
        // Case 1: No child
        
        if(root->left == NULL && root->right == NULL) 
        {
            delete root;
            root = NULL;
        }
        
        //Case 2: One child
        
        else if(root->left == NULL)
        {
            struct node *temp = root;
            root = root->right;
            delete temp;
        }
        else if(root->right == NULL)
        {
            struct node *temp = root;
            root = root->left;
            delete temp;
        }
        
        //case 3:two childs
        
        else
        {
            struct node *temp = findMin(root->right);
            root->key = temp->key; 
            root->right = deleteNode(root->right, temp->key); 
        }
    }    
    return root;
}

// Driver code
int main() 
{
  struct node *root = NULL;

  int operation;
  int operand;
  cin >> operation;

  while (operation != -1) 
  {
    switch(operation) 
    {
      case 1: // insert
        cin >> operand;
        root = insertNode(root, operand);
        cin >> operation;
        break;
      case 2: // delete
        cin >> operand;
        root = deleteNode(root, operand);
        cin >> operation;
        break;
      default:
        cout << "Invalid Operator!\n";
        return 0;
    }
  }
  
  traverseInOrder(root);
}