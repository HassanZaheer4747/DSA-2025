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
    height = 1;
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

Node *rightRotation(Node *root)
{
  Node *child = root->left;
  Node *childRight = child->right;
  child->right = root;
  root->left = childRight;

  root->height = 1 + max(getHeight(root->left), getHeight(root->right));
  child->height = 1 + max(getHeight(child->left), getHeight(child->right));

  return child;
}

Node *leftRotation(Node *root)
{
  Node *child = root->right;
  Node *childleft = child->left;
  child->left = root;
  root->right = childleft;

  root->height = 1 + max(getHeight(root->left), getHeight(root->right));
  child->height = 1 + max(getHeight(child->left), getHeight(child->right));

  return child;
}

Node *insert(Node *root, int key)
{
  if (!root)
    return new Node(key);

  if (key < root->data)
    root->left = insert(root->left, key);
  else if (key > root->data)
    root->right = insert(root->right, key);
  else
    return root;

  root->height = 1 + max(getHeight(root->left), getHeight(root->right));
  int balance = getbalance(root);

  if (balance > 1 && key < root->left->data)
    return rightRotation(root);

  if (balance < -1 && key > root->right->data)
    return leftRotation(root);

  if (balance > 1 && key > root->left->data)
  {
    root->left = leftRotation(root->left);
    return rightRotation(root);
  }

  if (balance < -1 && key < root->right->data)
  {
    root->right = rightRotation(root->right);
    return leftRotation(root);
  }

  return root;
}

Node *minValueNode(Node *node)
{
  Node *curr = node;
  while (curr->left)
    curr = curr->left;
  return curr;
}

Node *deleteNode(Node *root, int key)
{
  if (!root)
    return root;

  if (key < root->data)
    root->left = deleteNode(root->left, key);
  else if (key > root->data)
    root->right = deleteNode(root->right, key);
  else
  {
    if (!root->left || !root->right)
    {
      Node *temp = root->left ? root->left : root->right;
      if (!temp)
      {
        temp = root;
        root = NULL;
      }
      else
        *root = *temp;
      delete temp;
    }
    else
    {
      Node *temp = minValueNode(root->right);
      root->data = temp->data;
      root->right = deleteNode(root->right, temp->data);
    }
  }

  if (!root)
    return root;

  root->height = 1 + max(getHeight(root->left), getHeight(root->right));
  int balance = getbalance(root);

  if (balance > 1 && getbalance(root->left) >= 0)
    return rightRotation(root);

  if (balance > 1 && getbalance(root->left) < 0)
  {
    root->left = leftRotation(root->left);
    return rightRotation(root);
  }

  if (balance < -1 && getbalance(root->right) <= 0)
    return leftRotation(root);

  if (balance < -1 && getbalance(root->right) > 0)
  {
    root->right = rightRotation(root->right);
    return leftRotation(root);
  }

  return root;
}

void inorder(Node *root)
{
  if (!root)
    return;
  inorder(root->left);
  cout << root->data << " ";
  inorder(root->right);
}

int main()
{
  Node *root = NULL;

  root = insert(root, 10);
  root = insert(root, 20);
  root = insert(root, 30);
  root = insert(root, 50);
  root = insert(root, 70);
  root = insert(root, 5);
  root = insert(root, 100);
  root = insert(root, 95);

  cout << "Inorder traversal: ";
  inorder(root);
  cout << endl;

  root = deleteNode(root, 50);
  root = deleteNode(root, 10);

  cout << "After deletion: ";
  inorder(root);
  cout << endl;

  return 0;
}
