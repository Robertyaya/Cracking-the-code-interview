#include <bits/stdc++.h>

class SetofStacks
{
public:
  SetofStacks(int stack_size) { this->stack_size = stack_size; };
  ~SetofStacks(){};

  void Push(int data);
  void Pop();
  void Popat(int index);
  void Print_Stack();

private:
  void shiftLeftTo(int index);
  int stack_size;
  std::vector<std::stack<int>> stack_vec;
};

void SetofStacks::shiftLeftTo(int index)
{
  int stack_index = stack_vec.size();
  std::stack<int> temp_stack;

  // Put all data behind the target index stack into queue first, then move to left
  // However, we need to keep the priority, we put the data to the stack from the "last" stack to "index+1" stack
  for (int i = stack_index - 1; i >= index + 1; i--)
  {
    int stack_size = stack_vec[i].size();
    for (int j = 0; j < stack_size; j++)
    {
      int temp_data = stack_vec[i].top();
      temp_stack.push(temp_data);
      stack_vec[i].pop();
    }
    stack_vec.pop_back();
  }

  int temp_stack_size = temp_stack.size();
  for (int i = 0; i < temp_stack_size; i++)
  {
    int temp_data = temp_stack.top();
    this->Push(temp_data);
    temp_stack.pop();
  }
}

void SetofStacks::Popat(int index)
{
  int stack_index = stack_vec.size();
  if (index > stack_index - 1)
  {
    std::cout << "This stack is empty" << std::endl;
    return;
  }

  stack_vec[index].pop();

  // Represent target index is not the last stack, we need to move the data behind the index to fill the hole
  if (index != stack_index - 1)
    shiftLeftTo(index);
}

void SetofStacks::Print_Stack()
{
  std::vector<std::stack<int>> temp_vec;
  temp_vec.assign(stack_vec.begin(), stack_vec.end());
  for (int i = 0; i < temp_vec.size(); i++)
  {
    std::stack<int> temp;
    int stack_size = temp_vec[i].size();
    for (int j = 0; j < stack_size; j++)
    {
      temp.push(temp_vec[i].top());
      temp_vec[i].pop();
    }
    int temp_size = temp.size();
    for (int k = 0; k < temp_size; k++)
    {
      std::cout << temp.top() << " ";
      temp.pop();
    }
    std::cout << std::endl;
  }
}

void SetofStacks::Push(int data)
{
  int stack_index = stack_vec.size();

  // Initialize
  if (stack_index == 0)
  {
    std::stack<int> temp_stack;
    temp_stack.push(data);
    stack_vec.push_back(temp_stack);
    return;
  }

  // This stack is full, need to create new one
  if (stack_vec.at(stack_index - 1).size() == stack_size)
  {
    std::stack<int> temp_stack;
    temp_stack.push(data);
    stack_vec.push_back(temp_stack);
  }
  else
    stack_vec.at(stack_index - 1).push(data);
}

void SetofStacks::Pop()
{
  int stack_index = stack_vec.size();

  // Boundary case
  if (stack_index == 0)
  {
    std::cout << "The set of stacks is empty" << std::endl;
    return;
  }
  stack_vec.at(stack_index - 1).pop();
  if (stack_vec.at(stack_index - 1).size() == 0)
    stack_vec.pop_back();
}

int main()
{
  // The maximum size of stack is 3
  SetofStacks set(3);
  for (int i = 0; i < 10; i++)
    set.Push(i);
  set.Print_Stack();
  std::cout << std::endl;
  set.Popat(2);
  set.Print_Stack();
  set.Popat(0);
  set.Popat(0);
  set.Popat(2);
  set.Popat(1);
  std::cout << std::endl;
  set.Print_Stack();
}
