#include <bits/stdc++.h>
class FixedMultiStack
{
public:
  // Create 3 stacks, each stack is of size stackCapacity
  // The size of stack is static
  FixedMultiStack(int stackCapacity);
  ~FixedMultiStack();

  // Push an element onto stack stackNum, where stackNum is from 0~2
  void Push(int stackNum, int value);

  // Pop the top element from stack stackNum, where stackNum is from 0~2
  void Pop(int stackNum);

  // Return the top element on stack stackNum, where stackNum is from 0~2
  int top(int stackNum);

  // Return the minimize value in the stack, where stackNum is from 0~2
  int GetMinimum(int stackNum);

private:
  int IndexOfTop(int stackNum); // Return the top index in the stack
  bool isEmpty(int stackNum);
  bool isFull(int stackNum);

private:
  int numOfStack = 3;
  int stackCapacity;
  int *stackArray;
  int *stackCapacityUsed;          // Record the size of stack
  std::stack<int> *MinValue_array; // Record the minimize value in every stack
};

FixedMultiStack::FixedMultiStack(int stackCapacity)
{
  this->stackCapacity = stackCapacity;
  stackArray = new int[stackCapacity * numOfStack];
  stackCapacityUsed = new int[numOfStack];
  MinValue_array = new std::stack<int>[numOfStack];
}

FixedMultiStack::~FixedMultiStack()
{
  delete[] stackArray;
  delete[] stackCapacityUsed;
  delete[] MinValue_array;
}

int FixedMultiStack::GetMinimum(int stackNum)
{
  return MinValue_array[stackNum].top();
}

void FixedMultiStack::Push(int stackNum, int value)
{
  if (isFull(stackNum))
    std::cout << "This stack is full" << std::endl;
  else
  {
    stackCapacityUsed[stackNum]++;
    stackArray[IndexOfTop(stackNum)] = value;

    if (MinValue_array[stackNum].empty())
      MinValue_array[stackNum].push(value);
    else
    {
      if (value <= MinValue_array[stackNum].top())
        MinValue_array[stackNum].push(value);
    }
  }
}

void FixedMultiStack::Pop(int stackNum)
{
  if (isEmpty(stackNum))
    std::cout << "This stack is empty" << std::endl;
  else
  {
    int top_value = stackArray[IndexOfTop(stackNum)];
    stackArray[IndexOfTop(stackNum)] = 0;
    stackCapacityUsed[stackNum]--;

    if (top_value == MinValue_array[stackNum].top())
      MinValue_array[stackNum].pop();
  }
}

int FixedMultiStack::top(int stackNum)
{
  if (isEmpty(stackNum))
    std::cout << "This stack is empty" << std::endl;
  else
    return stackArray[IndexOfTop(stackNum)];
}

int FixedMultiStack::IndexOfTop(int stackNum)
{
  int startIndex = stackNum * stackCapacity;
  int stack_cap = stackCapacityUsed[stackNum];
  return stackNum * stackCapacity + stack_cap - 1;
}

bool FixedMultiStack::isEmpty(int stackNum)
{
  return stackCapacityUsed[stackNum] == 0;
}

bool FixedMultiStack::isFull(int stackNum)
{
  return stackCapacityUsed[stackNum] == stackCapacity;
}

int main()
{
  FixedMultiStack stac(5);
  stac.Push(0, 6);
  stac.Push(0, 5);
  stac.Push(0, 4);
  stac.Push(0, 2);
  stac.Push(0, 2);
  std::cout << stac.GetMinimum(0) << std::endl;
  stac.Pop(0);
  stac.Pop(0);
  std::cout << stac.GetMinimum(0) << std::endl;

  return 0;
}
