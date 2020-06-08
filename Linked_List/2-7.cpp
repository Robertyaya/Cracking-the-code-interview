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
  void DeleteNode(Node *c);  // The input only the node need to be removed, we can't use the root of linked list O(1)
  Node *Partition(int pivot);
  Node *kthToLastRecursive(int k); // O(n), Space: O(n)
  Node *kthToLastIterative(int k); // O(n), Space: O(1)
  Node *GetRoot() { return root; };
  bool Palindrome();  // Reverse the linkedlist to compare
  bool Palindrome2(); // Iterative the linkedlist
  bool Palindrome3(); // Recursive the linkedlist

private:
  Node *root; // Record the linked list root
  Node *last; // Record the linked list last element
  int size;   // Record the linked list size

private:
  Node *kthToLast(Node *head, int &i, int k);
};

Node *Interaction(Node *a, Node *b)
{
  // Use the hash map
  std::unordered_map<Node *, int> hash_table;
  Node *a_runner = a;
  Node *b_runner = b;

  //Use linked list "a" to build the hash table
  // O(n)
  while (a_runner != nullptr)
  {
    hash_table[a_runner] = a_runner->data;
    a_runner = a_runner->next;
  }
  // O(n)
  while (b_runner != nullptr)
  {
    if (hash_table.find(b_runner) != hash_table.end())
      return b_runner;
    b_runner = b_runner->next;
  }
  return nullptr;
}

bool Palindrome_recursive(Node *&left, Node *right)
{
  // Base case stop with right node
  if (right == nullptr)
    return true;

  bool flag = Palindrome_recursive(left, right->next);
  if (!flag)
    return false;

  if (left->data != right->data)
    return false;

  left = left->next;
  return true;
}

bool LinkedList::Palindrome3()
{
  return Palindrome_recursive(root, root);
}

bool LinkedList::Palindrome2()
{
  Node *slow = root;
  Node *fast = root;
  std::stack<int> temp_stack;
  while (fast != nullptr && fast->next != nullptr)
  {
    temp_stack.push(slow->data);

    // Update the slow node
    slow = slow->next;
    if (fast->next->next == nullptr) // The linked list is even, arrive the last node
    {
      fast = fast->next;
      break;
    }

    // Update the fast node
    fast = fast->next->next;
    if (fast->next == nullptr) // The linked list is odd, when the fast arrive the last node
      temp_stack.pop();
  }

  // slow start from middle node
  while (slow != nullptr)
  {
    slow = slow->next;
    if (slow->data != temp_stack.top())
      return false;
    else
    {
      temp_stack.pop();
    }
  }
  return true;
}

bool Compare(Node *a, Node *b, int size)
{
  if (size % 2 == 0)
  {
    for (int i = 0; i < size / 2; i++)
    {
      if (a->data != b->data)
        return false;
      a = a->next;
      b = b->next;
    }
  }
  else
  {
    for (int i = 0; i < size / 2 + 1; i++)
    {
      if (a->data != b->data)
        return false;
      a = a->next;
      b = b->next;
    }
  }
  return true;
}

bool LinkedList::Palindrome()
{
  // Reverse the linked list and compare
  Node *reverse_linkedlist;
  Node *previous;      // point to the reverse linkedlist previous node
  Node *current;       // point ot the reverse linkedlist current node
  Node *runner = root; // Transverse the original linkedlist
  previous = new Node(runner->data);
  current = previous;

  // O(n)
  while (runner != nullptr)
  {
    runner = runner->next;
    if (runner == nullptr)
      break;
    current = new Node(runner->data);
    current->next = previous;
    previous = current;
  }
  reverse_linkedlist = previous;

  // O(n/2)
  return Compare(root, reverse_linkedlist, size);
}

void SumOfListRecursive(Node *&sum, Node *&sum_last, int &carry, Node *a, Node *b)
{
  if (a == nullptr || b == nullptr)
    return;
  // Arrive the last node
  SumOfListRecursive(sum, sum_last, carry, a->next, b->next);

  // Add two linked list's node and carry
  int sum_num = a->data + b->data + carry;
  if (sum_num > 9)
  {
    // Update next position's carry
    carry = 1;
    sum_num -= 10;
  }
  else
  {
    // Update next position's carry
    carry = 0;
  }

  // Initialize
  if (sum == nullptr)
  {
    sum = new Node(sum_num);
    sum_last = sum;
  }
  else // Update the sum linked list
  {
    Node *temp = new Node(sum_num);
    sum_last->next = temp;
    sum_last = temp;
  }
}
int length(Node *a)
{
  int count = 0;
  while (a != nullptr)
  {
    a = a->next;
    count++;
  }
  return count;
}

void padList(Node *&node, int length)
{
  for (int i = 0; i < length; i++)
  {
    Node *temp = new Node(0);
    temp->next = node;
    node = temp;
  }
}

Node *SumOfList_FollowUp(Node *a, Node *b)
{
  // Arrive the last node
  int len1 = length(a);
  int len2 = length(b);
  Node *sum_linked_list = nullptr;
  Node *sum_last = nullptr;

  // pad the smaller list, fill the zero to shorter linked list
  if (len1 > len2)
  {
    padList(b, len1 - len2);
  }
  else
  {
    padList(a, len2 - len1);
  }
  int carry = 0;
  // O(n)
  SumOfListRecursive(sum_linked_list, sum_last, carry, a, b);

  // Reverse the sum_linked_list
  // O(n)
  Node *previous = nullptr;
  Node *current = sum_linked_list;
  Node *preceding = sum_linked_list->next;
  while (current != nullptr)
  {
    // Reverse the linked list
    current->next = previous;

    // Update three temp node
    previous = current;
    current = preceding;
    if (current == nullptr)
      break;
    preceding = preceding->next;
  }
  sum_linked_list = previous;

  return sum_linked_list;
}

Node *SumOfList(Node *a, Node *b)
{
  Node *sum = nullptr;
  Node *sum_runner = nullptr;
  Node *a_runner = a;
  Node *b_runner = b;

  int place = 0;
  while (a_runner != nullptr || b_runner != nullptr)
  {
    if (a_runner == nullptr)
    {
      if (sum_runner == nullptr)
      {
        sum = new Node(b_runner->data);
        sum_runner = sum;
      }
      else
      {
        Node *temp = new Node(b_runner->data + place);
        sum_runner->next = temp;
        sum_runner = sum_runner->next;
        if (place != 0)
          place = 0;
      }
    }
    else if (b_runner == nullptr)
    {
      if (sum_runner == nullptr)
      {
        sum = new Node(a_runner->data);
        sum_runner = sum;
      }
      else
      {
        Node *temp = new Node(a_runner->data + place);
        sum_runner->next = temp;
        sum_runner = sum_runner->next;
        if (place != 0)
          place = 0;
      }
    }
    else // a_runner != nullptr && b_runner != nullptr
    {
      int total = a_runner->data + b_runner->data + place;
      if (place != 0)
        place = 0;
      if (total >= 10)
      {
        place++;
        total -= 10;
      }

      if (sum_runner == nullptr)
      {
        sum = new Node(total);
        sum_runner = sum;
      }
      else
      {
        Node *temp = new Node(total);
        sum_runner->next = temp;
        sum_runner = sum_runner->next;
      }
    }

    if (a_runner == nullptr)
      b_runner = b_runner->next;
    else if (b_runner == nullptr)
      a_runner = a_runner->next;
    else
    {
      a_runner = a_runner->next;
      b_runner = b_runner->next;
    }
  }

  return sum;
}

Node *LinkedList::Partition(int pivot)
{
  Node *runner = root;
  Node *pivot_node = root;
  int count = pivot;
  // O(1)
  while (count != 1)
  {
    pivot_node = pivot_node->next;
    count--;
  }

  // O(n)
  Node *left_start = nullptr; // point to the start of the left
  Node *left_end = nullptr;
  Node *right_start = new Node(pivot_node->data); // point to the pivot
  Node *right_end = right_start;
  while (runner != nullptr)
  {
    if (runner == pivot_node)
    {
      runner = runner->next;
      continue;
    }

    if (runner->data < pivot)
    {
      Node *temp = new Node(runner->data);
      // Initial left side node
      if (left_start == nullptr || left_end == nullptr)
      {
        left_start = temp;
        left_end = temp;
      }
      left_end->next = temp;
      left_end = left_end->next;
    }
    else
    {
      Node *temp = new Node(runner->data);
      right_end->next = temp;
      right_end = right_end->next;
    }
    runner = runner->next;
  }
  left_end->next = right_start;
  right_end->next = nullptr;
  return left_start;
}

void LinkedList::DeleteNode(Node *c)
{
  // Represent the c node is the last node, no answer
  if (c->next == nullptr)
    return;

  Node *next_node = c->next;
  c->next = next_node->next;
  c->data = next_node->data;
  delete next_node;
}

Node *LinkedList::kthToLastIterative(int k)
{
  if (k == 0)
    return nullptr;

  Node *first = root;
  Node *second = root;
  for (int i = 0; i < k; i++)
  {
    first = first->next;
    if (first == nullptr)
      return nullptr;
  }
  while (first != nullptr)
  {
    second = second->next;
    first = first->next;
  }
  return second;
}

Node *LinkedList::kthToLast(Node *head, int &i, int k)
{
  if (head == nullptr)
    return nullptr;

  // Until node arrive the last one
  Node *node = kthToLast(head->next, i, k);
  i = i + 1;
  if (i == k)
    return head;

  return node;
}
// O(k)
Node *LinkedList::kthToLastRecursive(int k)
{
  if (k == 0)
    return nullptr;

  int i = 0;
  Node *head = root;
  return kthToLast(head, i, k);
}

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
  for (int i = 0; i < 5; i++)
  {
    list->Push_Back(Random_Range(1, 10));
  }
  list->PrintList();
  Node *b = list->GetRoot();
  b = b->next->next;
  Node *temp = Interaction(list->GetRoot(), b);
  if (temp == nullptr)
    std::cout << "No interaction" << std::endl;
  else
    std::cout << temp->data << std::endl;

  return 0;
}
