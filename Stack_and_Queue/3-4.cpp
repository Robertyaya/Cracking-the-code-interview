#include <bits/stdc++.h>

class MyQueue
{
public:
  MyQueue(){};
  ~MyQueue(){};

  // Add data to queue O(1)
  void push(int data);

  // pop the data from queue O(n)
  void pop();

  // Get the data from queue
  int front();

private:
  std::stack<int> stack1;
  std::stack<int> stack2;
};

void MyQueue::push(int data)
{
  stack1.push(data);
}

// O(N)
void MyQueue::pop()
{
  if (stack1.empty())
    return;

  // O(n)
  while (!stack1.empty())
  {
    int temp_data = stack1.top();
    stack2.push(temp_data);
    stack1.pop();
  }

  // Pop up the data
  stack2.pop();

  // Put the data to stack1
  // O(n)
  while (!stack2.empty())
  {
    int temp_data = stack2.top();
    stack1.push(temp_data);
    stack2.pop();
  }
}

int MyQueue::front()
{
  if (stack1.empty())
    return -1;

  // O(n)
  while (!stack1.empty())
  {
    int temp_data = stack1.top();
    stack2.push(temp_data);
    stack1.pop();
  }

  int front_data = stack2.top();

  while (!stack2.empty())
  {
    int temp_data = stack2.top();
    stack1.push(temp_data);
    stack2.pop();
  }

  return front_data;
}

int main()
{
  MyQueue queue;
  for (int i = 0; i < 5; i++)
    queue.push(i);

  queue.pop();
  queue.pop();
  std::cout << queue.front() << std::endl;
}
