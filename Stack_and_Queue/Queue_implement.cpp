#include <bits/stdc++.h>
struct Queue_Node
{
  Queue_Node(int data) : data(data), next(nullptr) {}
  int data;
  Queue_Node *next;
};

class Queue
{
public:
  Queue() { root = nullptr, last = nullptr; };
  ~Queue() { delete root; };
  void add(int data);
  void remove();
  int peek();
  bool isEmpty();

private:
  Queue_Node *root;
  Queue_Node *last;
};

void Queue::add(int data)
{
  if (root == nullptr)
  {
    root = new Queue_Node(data);
    last = root;
  }
  else
  {
    Queue_Node *temp = new Queue_Node(data);
    last->next = temp;
    last = temp;
  }
}

void Queue::remove()
{
  if (root != nullptr)
  {
    Queue_Node *temp = root;
    root = root->next;
    delete temp;
  }
}

int Queue::peek()
{
  if (root == nullptr)
    return -1;
  else
    return root->data;
}

bool Queue::isEmpty()
{
  if (root == nullptr)
    return true;
  else
    return false;
}
int main()
{
  Queue q;
  q.add(1);
  q.add(2);
  q.add(3);
  std::cout << q.peek() << std::endl;
  q.remove();
  std::cout << q.peek() << std::endl;
}
