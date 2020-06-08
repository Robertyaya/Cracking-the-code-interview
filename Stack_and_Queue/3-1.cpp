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

private:
  int IndexOfTop(int stackNum); // Return the top index in the stack
  bool isEmpty(int stackNum);
  bool isFull(int stackNum);

private:
  int numOfStack = 3;
  int stackCapacity;
  int *stackArray;
  int *stackCapacityUsed; // Record the size of stack
};

FixedMultiStack::FixedMultiStack(int stackCapacity)
{
  stackArray = new int[stackCapacity * numOfStack];
  stackCapacityUsed = new int[numOfStack];
}

FixedMultiStack::~FixedMultiStack()
{
  delete[] stackArray;
  delete[] stackCapacityUsed;
}

void FixedMultiStack::Push(int stackNum, int value)
{
  if (isFull(stackNum))
    std::cout << "This stack is full" << std::endl;
  else
  {
    stackCapacityUsed[stackNum]++;
    stackArray[IndexOfTop(stackNum)] = value;
  }
}

void FixedMultiStack::Pop(int stackNum)
{
  if (isEmpty(stackNum))
    std::cout << "This stack is empty" << std::endl;
  else
  {
    stackArray[IndexOfTop(stackNum)] = 0;
    stackCapacityUsed[stackNum]--;
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
  return 0;
}
