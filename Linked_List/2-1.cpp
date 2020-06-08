#include <bits/stdc++.h>
#include <unordered_map>

struct Node
{
  Node() : data(0), next(nullptr) {}
  Node(int data) : data(data), next(nullptr) {}
  int data;
  Node *next;
};

class LinkedList
{
public:
  LinkedList() { root = nullptr, last = nullptr, size = 0; };
  ~LinkedList(){};

public:
  void PrintList();          // O(n)
  void Push_Front(int data); // O(1)
  void Push_Back(int data);  // O(1), due to we record the last node
  void Delete(int data);     // O(n), need to transverse all node to find the target
  void Clear();              // O(n), need to transverse all node to delete every node
  void Reverse();            // O(n)
  void RemoveDul();          // O(n^2)
  void RemoveDul2();         // O(n), use hash table

private:
  Node *root; // Record the linked list root
  Node *last; // Record the linked list last element
  int size;   // Record the linked list size
};

// Use hash table
// Time: O(n), Space: O(n)
void LinkedList::RemoveDul2()
{
  if (root == nullptr || root->next == nullptr)
    return;

  std::unordered_map<int, int> node_map;
  Node *current = root->next;
  Node *previous = root;
  node_map[previous->data] = 1;
  while (current != nullptr)
  {
    // The node the duplicate
    if (node_map.find(current->data) != node_map.end())
    {
      Node *temp = current;
      previous->next = current->next;
      current = current->next;
      delete temp;
      size--;
    }
    else
    {
      current = current->next;
      previous = previous->next;
    }
  }
}

// O(n^2)
void LinkedList::RemoveDul()
{
  if (root == nullptr || root->next == nullptr)
    return;

  Node *current, *runner;
  current = root;
  while (current != nullptr)
  {
    runner = current;
    while (runner->next != nullptr)
    {
      if (current->data == runner->next->data)
      {
        Node *temp = runner->next;
        runner->next = runner->next->next;
        delete temp;
        size--;
      }
      else
      {
        runner = runner->next;
      }
    }
    current = current->next;
  }
}

void LinkedList::Reverse()
{
  if (size == 0 || root->next == nullptr)
    return;

  Node *previous = nullptr;
  Node *current = root;
  Node *preceding = root->next;
  last = root;
  while (current != nullptr)
  {
    // Reverse the linked list
    current->next = previous;

    // Update the temp node
    previous = current;
    current = preceding;
    // Handle the last node
    if (current == nullptr)
      break;
    preceding = preceding->next;
  }
  root = previous;
}

void LinkedList::Clear()
{
  // We can't directly delete the root, will cause the memory leak problem
  // We need to transverse all node to delete the node
  Node *current;
  while (root != nullptr)
  {
    current = root;
    root = root->next;
    delete current;
  }
}

void LinkedList::Delete(int data)
{
  Node *current = root;
  Node *previous = nullptr;

  // The delete the node is the first one
  if (current->data == data)
  {
    root = root->next;
    delete current;
    current = nullptr;
    size--;
    return;
  }

  while (current->next != nullptr)
  {
    previous = current;
    current = current->next;
    if (current->data == data)
    {
      previous->next = current->next;
      delete current;
      current = nullptr;
      size--;
      return;
    }
  }
}

void LinkedList::Push_Front(int data)
{
  Node *temp = new Node(data);
  if (root == nullptr)
  {
    root = temp;
    last = temp;
  }
  else
  {
    temp->next = root;
    root = temp;
  }
  size++;
}

void LinkedList::Push_Back(int data)
{
  // Head point to the first node in the linked list
  // Last point to the last node in the linked list
  Node *temp = new Node(data);

  // Represent this node is the first element
  if (root == nullptr)
  {
    root = temp;
    last = temp;
  }
  else
  {
    last->next = temp;
    last = temp;
  }
  size++;
}

void LinkedList::PrintList()
{
  Node *temp;
  // No node in linked list
  if (root == nullptr)
    return;
  else
  {
    temp = root;
    while (temp != nullptr)
    {
      std::cout << temp->data << "->";
      temp = temp->next;
    }
    std::cout << "NULL" << std::endl;
  }
}

int Random_Range(int a, int b)
{
  return a + rand() % b;
}

int main()
{
  LinkedList *list = new LinkedList();
  for (int i = 0; i < 10; i++)
  {
    list->Push_Back(Random_Range(1, 10));
  }
  list->PrintList();
  list->RemoveDul();
  list->PrintList();

  return 0;
}
