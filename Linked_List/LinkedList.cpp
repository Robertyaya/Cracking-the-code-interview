#include <bits/stdc++.h>
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

private:
  Node *root; // Record the linked list root
  Node *last; // Record the linked list last element
  int size;   // Record the linked list size
};

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

int main()
{
  LinkedList *list = new LinkedList();

  // Add the element to the end
  for (int i = 0; i < 5; i++)
    list->Push_Back(i);

  // Print the linked list
  list->PrintList();

  // Add the element to the begin
  list->Push_Front(10);

  list->PrintList();

  list->Reverse();
  std::cout << "Reverse: ";
  list->PrintList();

  // Delete the targe node
  list->Delete(2);
  list->PrintList();
  list->Delete(3);
  list->PrintList();
  list->Delete(10);
  list->PrintList();

  // Clear the linked list
  list->Clear();

  return 0;
}
