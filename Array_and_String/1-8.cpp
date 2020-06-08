#include <bits/stdc++.h>
void PrintMatrix(int **matrix, int M, int N)
{
  for (int i = 0; i < M; i++)
  {
    for (int j = 0; j < N; j++)
      std::cout << matrix[i][j] << " ";
    std::cout << std::endl;
  }
}

void Zero_Matrix(int **matrix, int M, int N)
{
  // Need to record which row and coloum is zero
  // Transverse all matrix
  std::vector<std::pair<int, int>> vec;

  // O(N*M)
  for (int i = 0; i < M; i++)
  {
    for (int j = 0; j < N; j++)
    {
      if (matrix[i][j] == 0)
      {
        vec.push_back(std::make_pair(i, j));
        // We can directly break to next row
        break;
      }
    }
  }

  for (int i = 0; i < vec.size(); i++)
  {
    int row = vec[i].first;
    int col = vec[i].second;
    // Fill the zero in row
    for (int y = 0; y < N; y++)
      matrix[row][y] = 0;
    // Fill the zero in col
    for (int z = 0; z < M; z++)
      matrix[z][col] = 0;
  }
}

int main()
{
  int M, N;
  std::cin >> M >> N;

  // Allocate the M*N array
  int **matrix = new int *[M];
  for (int i = 0; i < M; i++)
    matrix[i] = new int[N];

  for (int i = 0; i < M; i++)
  {
    for (int j = 0; j < N; j++)
      std::cin >> matrix[i][j];
  }
  PrintMatrix(matrix, M, N);
  Zero_Matrix(matrix, M, N);
  std::cout << std::endl;
  PrintMatrix(matrix, M, N);

  return 0;
}
