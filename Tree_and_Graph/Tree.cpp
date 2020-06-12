#include <bits/stdc++.h>

struct TreeNode
{
  TreeNode(int data) : data(data), leftchild(nullptr), rightchild(nullptr) {}

  int data;
  TreeNode *leftchild;
  TreeNode *rightchild;
};

class BST
{
public:
  BST() { root = nullptr; };
  BST(TreeNode *root) { this->root = root; };
  ~BST();

public:
  TreeNode *GetRoot() { return root; };

  // Insert to Binary search tree
  void Insert(int data);

  // To check whether input data is in the BST
  bool Contains(int data);

  // Remove value from BST
  void Remove(int data);

  // Pre-order
  void Preorder(TreeNode *current);

  // In-order
  void Inorder(TreeNode *current);

  // Post-order
  void Postorder(TreeNode *current);

  // Level-order
  void Levelorder();

private:
  TreeNode *root;

  // To handle the recursive
  void Insert(TreeNode *&node, int data);   // Helper function to Insert
  bool Contains(TreeNode *&node, int data); // Helper function to Contains
  void Remove(TreeNode *&node, int data);   // Helper function to Remove
  TreeNode *&FindMinNode(TreeNode *&node);  // Helper function to Remove
};

void BST::Remove(int data)
{
  Remove(root, data);
}
void BST::Remove(TreeNode *&node, int data)
{
  if (node == nullptr)
    std::cout << "This data not contain in this BST" << std::endl;
  else if (data == node->data) // Find the remove data
  {
    // Point to the node which we want to remove
    TreeNode *trash = nullptr;

    // Four case
    // 1. on the leaf, directly remove it
    if (node->rightchild == nullptr && node->leftchild == nullptr)
    {
      trash = node;
      node = nullptr;
    }
    else if (node->rightchild == nullptr && node->leftchild != nullptr) // 2. only have left child
    {
      trash = node;           // Use trash to point to this node
      node = node->leftchild; // Update original node to its leftchild
    }
    else if (node->rightchild != nullptr && node->leftchild == nullptr) // 3. only have right child
    {
      std::cout << "FUCK2" << std::endl;
      trash = node;            // Use trash to point to this node
      node = node->rightchild; // Update original node to its rightchild
    }
    else // 4. have both left child and right child, we have the min node in right tree, and use this node to replace be removed node
    {
      TreeNode *&minNode = FindMinNode(node->rightchild);

      node->data = minNode->data;     // update minode data to be removed node
      Remove(minNode, minNode->data); // Remove this minnode
    }

    // Release memory
    if (trash != nullptr)
      delete trash;
  }
  else if (data >= node->data)
  {
    Remove(node->rightchild, data);
  }
  else // data < node->data
  {
    Remove(node->leftchild, data);
  }
}

// Find min node in sub tree
TreeNode *&BST::FindMinNode(TreeNode *&node)
{
  if (node->leftchild == nullptr) // Represent this node is the min node in this sub tree
    return node;
  return FindMinNode(node->leftchild);
}

bool BST::Contains(int data)
{
  return Contains(root, data);
}

bool BST::Contains(TreeNode *&node, int data)
{
  if (node == nullptr)
    return false;

  if (data == node->data)
    return true;
  else if (data > node->data)
    return Contains(node->rightchild, data);
  else
    return Contains(node->leftchild, data);
}

void BST::Insert(int data)
{
  Insert(root, data);
}
void BST::Insert(TreeNode *&node, int data)
{
  if (node == nullptr)
  {
    node = new TreeNode(data);
  }
  else if (data >= node->data)
  {
    Insert(node->rightchild, data);
  }
  else // data < node->data
  {
    Insert(node->leftchild, data);
  }
}

BST::~BST()
{
  if (root != nullptr)
    delete root;
}

void BST::Preorder(TreeNode *current)
{
  if (current != nullptr)
  {
    std::cout << current->data << " ";
    Preorder(current->leftchild);
    Preorder(current->rightchild);
  }
}

void BST::Inorder(TreeNode *current)
{
  if (current != nullptr)
  {
    Inorder(current->leftchild);
    std::cout << current->data << " ";
    Inorder(current->rightchild);
  }
}

void BST::Postorder(TreeNode *current)
{
  if (current != nullptr)
  {
    Postorder(current->leftchild);
    Postorder(current->rightchild);
    std::cout << current->data << " ";
  }
}

void BST::Levelorder()
{
  std::queue<TreeNode *> temp_queue;
  temp_queue.push(root);
  while (!temp_queue.empty())
  {
    TreeNode *tempNode = temp_queue.front();
    std::cout << tempNode->data << " ";
    temp_queue.pop();

    if (tempNode->leftchild != nullptr)
      temp_queue.push(tempNode->leftchild);
    if (tempNode->rightchild != nullptr)
      temp_queue.push(tempNode->rightchild);
  }
}

int main()
{
  BST tree;
  for (int i = 0; i < 10; i++)
  {
    tree.Insert(rand() % 10);
  }
  std::cout << "Pre-order: ";
  tree.Preorder(tree.GetRoot());
  std::cout << std::endl;

  std::cout << "In-order: ";
  tree.Inorder(tree.GetRoot());
  std::cout << std::endl;

  std::cout << "Post-order: ";
  tree.Postorder(tree.GetRoot());
  std::cout << std::endl;

  if (tree.Contains(3))
    std::cout << "Contain 3" << std::endl;
  else
    std::cout << "No contain 3" << std::endl;

  if (tree.Contains(11))
    std::cout << "Contain 11" << std::endl;
  else
    std::cout << "No contain 11" << std::endl;

  tree.Remove(7);
  tree.Inorder(tree.GetRoot());
}
