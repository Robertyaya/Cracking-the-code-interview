#include <bits/stdc++.h>

class SortedStacks
{
public:
  SortedStacks(){};
  ~SortedStacks(){};

  void Push(int data);
  void Pop();
  int Peek();
  bool isEmpty();

private:
  void sort(int data);
  std::stack<int> sorted_stacks;
};

void SortedStacks::sort(int data)
{
  std::stack<int> temp_stack;
  while (!sorted_stacks.empty() && sorted_stacks.top() < data)
  {
    temp_stack.push(sorted_stacks.top());
    sorted_stacks.pop();
  }
  sorted_stacks.push(data);

  while (!temp_stack.empty())
  {
    sorted_stacks.push(temp_stack.top());
    temp_stack.pop();
  }
}

void SortedStacks::Pop()
{
  sorted_stacks.pop();
}

int SortedStacks::Peek()
{
  return sorted_stacks.top();
}

bool SortedStacks::isEmpty()
{
  return sorted_stacks.empty();
}

void SortedStacks::Push(int data)
{
  sort(data);
}

int main()
{
  SortedStacks stack;
  for (auto v : {5, 10, 4, 9, 3, 3, 8, 1, 2, 2, 7, 6})
  {
    stack.Push(v);
  }
  while (!stack.isEmpty())
  {
    std::cout << stack.Peek() << std::endl;
    stack.Pop();
  }
}
