#include <bits/stdc++.h>
#define CHAR_SIZE 128

struct TrieNode
{
  TrieNode();
  TrieNode *children[CHAR_SIZE];
  bool isEndOfNode;
};

class Trie
{
public:
  Trie() { root = nullptr; };

public:
  // Insert string to trie
  void Insert(std::string str);

  // Delete string from trie
  void Delete(std::string str);

  // Search string whether in the trie
  bool Search(std::string str);

private:
  // Recursive helper
  bool Delete(TrieNode *&current_node, std::string str, int depth);
  // To check the input node whether have the children
  bool HaveChildren(TrieNode *&current_node);

private:
  TrieNode *root;
};

TrieNode::TrieNode()
{
  isEndOfNode = false;
  for (int i = 0; i < CHAR_SIZE; i++)
    children[i] = nullptr;
}

void Trie::Insert(std::string key)
{
  if (root == nullptr)
    root = new TrieNode();

  // Point the the current node
  TrieNode *current_node = root;
  for (int i = 0; i < key.size(); i++)
  {
    int index = int(key[i]);
    if (current_node->children[index] == nullptr)
      current_node->children[index] = new TrieNode();

    // Move to next postion
    current_node = current_node->children[index];
  }
  // Mark current node as leaf
  current_node->isEndOfNode = true;
}

bool Trie::Search(std::string key)
{
  // This trie is empty
  if (root == nullptr)
    return false;

  TrieNode *current_node = root;
  for (int i = 0; i < key.size(); i++)
  {
    int index = int(key[i]);

    // Represent no this character
    if (current_node->children[index] == nullptr)
      return false;

    // Update current_node
    current_node = current_node->children[index];
  }
  // We can't directly return true If we save "apple" in the trie, directly return true will not handle when we search "apples", we need to ensure it reach the end of node and match our key
  return current_node->isEndOfNode;
}

bool Trie::HaveChildren(TrieNode *&current_node)
{
  for (int i = 0; i < CHAR_SIZE; i++)
  {
    if (current_node->children[i] != nullptr)
      return true;
  }
  return false;
}

// Recursive fuc  tion to delete a key in the trie
void Trie::Delete(std::string key)
{
  Delete(root, key, 0);
}
bool Trie::Delete(TrieNode *&current_node, std::string key, int depth)
{
  // Not find the char in trie (current_node->children[index] == nullptr)
  if (current_node == nullptr)
    return false;

  // Arrive the end of key string
  if (depth == key.size())
  {
    // Check whether arrive the end of node
    if (current_node->isEndOfNode)
    {
      delete current_node;
      current_node = nullptr;
      return true;
    }
    else
      return false;
  }

  // Until arrive the leaf
  int index = int(key[depth]);
  // Success delete the child
  if (Delete(current_node->children[index], key, depth + 1))
  {
    // Check whether current_node is the prefix of another node
    if (!HaveChildren(current_node) && !current_node->isEndOfNode)
    {
      delete current_node;
      current_node = nullptr;
    }
    return true;
  }
  else
    return false;
}

int main()
{
  Trie tri;
  std::string str[] = {"the", "a", "there",
                       "answer", "any", "by",
                       "bye", "their", "hero", "heroplane"};
  for (int i = 0; i < 10; i++)
  {
    tri.Insert(str[i]);
  }

  tri.Search("the") ? std::cout << "Yes\n" : std::cout << "No\n";
  tri.Search("these") ? std::cout << "Yes\n" : std::cout << "No\n";
  tri.Delete("heroplane");
  tri.Search("hero") ? std::cout << "Yes\n" : std::cout << "No\n";
  return 0;
}
