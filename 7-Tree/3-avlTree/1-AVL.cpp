#include <iostream>
using namespace std;

class Node
{
public:
  int data, height;
  Node *left, *right;

  Node(int val)
  {
    data = val;
    height = 1; // one node :height will be 1
    left = right = NULL;
  }
};

int getHeight(Node *root)
{
  if (!root)
    return 0;

  return root->height;
}

int getbalance(Node *root)
{
  return getHeight(root->left) - getHeight(root->right);
}

//  Right Rotation
Node *rightRotation(Node *root)
{
  Node *child = root->left;
  Node *childRight = child->right;
  child->right = root;
  root->left = childRight;

  //  Update the height
  root->height = 1 + max(getHeight(root->left), getHeight(root->right));
  child->height = 1 + max(getHeight(root->left), getHeight(root->right));

  return child;

  // Update the lower node (old root) height first.
  // Then update the new root height (child) because it depends on the updated heights of its children.
}

//  Left Rotation
Node *leftRotation(Node *root)
{
  Node *child = root->right;
  Node *childleft = child->left;
  child->left = root;
  root->right = childleft;

  //  Update the height
  root->height = 1 + max(getHeight(root->left), getHeight(root->right));
  child->height = 1 + max(getHeight(root->left), getHeight(root->right));

  return child;
}

Node *insert(Node *root, int key)
{
  // Dosent exist
  if (!root)
    return new Node(key);

  // exist
 if (key < root->data) {
    root->left = insert(root->left, key);   // ✅ Store the updated subtree
}
else if (key > root->data) {
    root->right = insert(root->right, key); // ✅ Store the updated subtree
}

  else
    return root; // Duplicate elements are not allowed

  // update height
  root->height = 1 + max(getHeight(root->left), getHeight(root->right)); // make fun to check if left and right height exist or not a=can do diretly herer but will get complex

  // Balace chedck
  int balance = getbalance(root);

  // LL case
  if (balance > 1 && key < root->left->data)
    return rightRotation(root);

  // RR case
  if (balance < -1 && key >root->right->data)
    return leftRotation(root);

  // LR case
if (balance > 1 && key > root->left->data) {
    root->left = leftRotation(root->left); // fix inner imbalance first
    return rightRotation(root);            // then fix outer imbalance
}


  // RL case
 if (balance < -1 && key < root->right->data) {
    root->right = rightRotation(root->right);  // fix inner imbalance
    return leftRotation(root);                 // fix outer imbalance
}


  // No Unbalance
  return root;
};

void inOrderPrint(Node* root) {
    if (!root) return;
    inOrderPrint(root->left);
    cout << root->data << " ";
    inOrderPrint(root->right);
}

int main()
{

  // Duplicate elemnts not allowed

  Node *root = NULL;

  root = insert(root, 10);
  root = insert(root, 20);
  root = insert(root, 30);
  root = insert(root, 50);
  root = insert(root, 70);
  root = insert(root, 5);
  root = insert(root, 100);
  root = insert(root, 95);

  inOrderPrint(root);
}

/* //-----------------------------> IMP
AVL Tree Rotation Guide:

If Balance > 1 → Imbalance on Left Side
    → Perform Left Rotation

    - Case LL (Left-Left):
        key < root->left->data

    - Case LR (Left-Right):
        key > root->left->data

If Balance < -1 → Imbalance on Right Side
    → Perform Right Rotation

    - Case RL (Right-Left):
        key < root->right->data

    - Case RR (Right-Right):
        key > root->right->data
*/


// ----------------------WHY HEIGHT IS SO IMPORTANT--------------------------
// Height is the core info for balance
// AVL trees stay balanced by tracking the height of each node’s subtree.

// The balance factor = height(left subtree) - height(right subtree).

// If this factor goes beyond +1 or -1, the tree is unbalanced and needs rotation.
