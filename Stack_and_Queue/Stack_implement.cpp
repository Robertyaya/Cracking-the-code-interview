#include <bits/stdc++.h>
struct Stack_Node
{
  Stack_Node(int data) : data(data), next(nullptr) {}
  int data;
  Stack_Node *next;
};
class Stack
{
public:
  Stack() { root = nullptr; };
  ~Stack() { delete root; };

  void Push(int data);
  int Pop();
  int Peek();
  bool isEmpty();

  Stack_Node *GetRoot() { return root; };

private:
  Stack_Node *root;
};

bool Stack::isEmpty()
{
  if (root == nullptr)
    return true;
  else
    return false;
}
int Stack::Peek()
{
  if (root == nullptr)
    return -1;
  else
    return root->data;
}

int Stack::Pop()
{
  if (root == nullptr)
    return -1;
  else
  {
    int data = root->data;
    Stack_Node *temp = root;
    root = root->next;
    delete temp;
    return data;
  }
}

void Stack::Push(int data)
{
  if (root == nullptr)
    root = new Stack_Node(data);
  else
  {
    Stack_Node *temp = new Stack_Node(data);
    temp->next = root;
    root = temp;
  }
}

int main()
{
  Stack stack;
  stack.Push(1);
  stack.Push(2);
  stack.Pop();
  stack.Pop();
  std::cout << stack.Peek() << std::endl;
}
