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
  std::stack<int> sorted_stacks;
};

int main()
{
}
