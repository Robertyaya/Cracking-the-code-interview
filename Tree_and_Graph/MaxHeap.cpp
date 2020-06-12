#include <bits/stdc++.h>

class MaxHeap
{
public:
  MaxHeap(){};
  ~MaxHeap(){};

public:
  // Insert data to heap
  void Insert(int data);

  // Extract max value from MaxHeap
  int ExtractMax();

  // Delete max value from MaxHeap
  void DeleteMax();

  // Print Heap
  void Print();

private:
  // Return parent's index
  int parent(int child);
  // Return left child's index
  int left(int parent);
  // Return right child's index
  int right(int parent);

  // Keep the max heap properties from bottom to top
  void heapify_up(int index);
  // Keep the max heap properties from top to bottom
  void heapify_down(int index);

private:
  std::vector<int> heap;
};

void MaxHeap::heapify_down(int index)
{
  // if the right child valid->left child must valid
  int child = left(index);
  int child1 = right(index);

  // Choose the bigger one, the left child and right child is valid
  if (child >= 0 && child1 >= 0 && heap[child1] > heap[child])
    child = child1;
  if (child >= 0 && heap[child] > heap[index])
  {
    int temp = heap[child];
    heap[child] = heap[index];
    heap[index] = temp;
    heapify_down(child);
  }
}

void MaxHeap::DeleteMax()
{
  if (heap.size() == 0)
    std::cout << "Heap is empty" << std::endl;

  // Move the last value to the root and remove the max value
  heap.at(0) = heap.at(heap.size() - 1);
  heap.pop_back();

  heapify_down(0);
}

int MaxHeap::ExtractMax()
{
  if (heap.size() == 0)
    return -1;
  return heap.front();
}

void MaxHeap::heapify_up(int index)
{
  if (index >= 0 && parent(index) >= 0 && heap[parent(index)] < heap[index])
  {
    // Switch two value due to we need to keep the max heap every insert
    int temp = heap[parent(index)];
    heap[parent(index)] = heap[index];
    heap[index] = temp;
    heapify_up(parent(index));
  }
}

void MaxHeap::Print()
{
  for (int i = 0; i < heap.size(); i++)
    std::cout << heap[i] << " ";
  std::cout << std::endl;
}

void MaxHeap::Insert(int data)
{
  heap.push_back(data);
  // We need to keep the max heap every insert
  heapify_up(heap.size() - 1);
}

int MaxHeap::parent(int index)
{
  if (index == 0)
    return -1;
  return (index - 1) / 2;
}

int MaxHeap::left(int index)
{
  int left_index = index * 2 + 1;
  if (left_index > heap.size() - 1)
    return -1;
  return left_index;
}

int MaxHeap::right(int index)
{
  int right_index = index * 2 + 2;
  if (right_index > heap.size() - 1)
    return -1;
  return right_index;
}

int main()
{
  MaxHeap hea;
  for (int i = 0; i < 10; i++)
    hea.Insert(i);
  hea.Print();
  hea.DeleteMax();
  hea.Print();
}
