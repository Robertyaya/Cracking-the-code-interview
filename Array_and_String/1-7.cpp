#include <bits/stdc++.h>

void Rotate(int **matrix, int N)
{
  for (int layer = 0; layer < N / 2; layer++)
  {
    int first = layer;
    int last = N - layer - 1;
    for (int i = first; i < last; i++)
    {
      // Save the top value
      int top = matrix[layer][i];

      // left to top
      matrix[first][i] = matrix[last - (i - first)][layer];

      // bottom to left
      matrix[last - (i - first)][layer] = matrix[last][last - (i - first)];

      // right to bottom
      matrix[last][last - (i - first)] = matrix[i][last];

      // temp to right
      matrix[i][last] = top;
    }
  }
}

void PrintMatrix(int **matrix, int N)
{
  for (int i = 0; i < N; i++)
  {
    for (int j = 0; j < N; j++)
      std::cout << matrix[i][j] << " ";
    std::cout << std::endl;
  }
}
int main()
{
  int N;
  std::cout << "Enter N for NxN matrix" << std::endl;
  std::cin >> N;

  // Allocate the space
  int **matrix = new int *[N];
  for (int i = 0; i < N; i++)
  {
    matrix[i] = new int[N];
  }

  // Assign the element
  for (int i = 0; i < N; i++)
  {
    for (int j = 0; j < N; j++)
    {
      std::cin >> matrix[i][j];
    }
  }

  std::cout << "Rotate matrix by 90 (clockwise)" << std::endl;
  std::cout << "Original: ";
  PrintMatrix(matrix, N);

  std::cout << "After rotate: ";
  Rotate(matrix, N);
  std::cout << std::endl;
  PrintMatrix(matrix, N);
}
