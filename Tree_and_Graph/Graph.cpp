#include <bits/stdc++.h>

class Graph
{
public:
  Graph() : num_vertex(0){};
  Graph(int num) : num_vertex(num)
  {
    AdjList.resize(num);
  };

  void AddEdgeList(int from, int to);

  // Breadth-First Search (Can find the shorest path)
  void BFS(int start);

  // Depth-First Search
  void DFS(int start);

private:
  int num_vertex;

  // Adjacency List
  std::vector<std::list<int>> AdjList;

  // Three kind of color
  // 1. White: not be found
  // 2. Gray: Be found, put in the queue
  // 3. Black: Be found, remove from queue
  int *color;
  // record the the vertex is fonund by which vertex, in order to back track the path
  int *predecessor;

  // (BFS) record the "shortest distance" between the start and the any vertex
  int *distance;

  // (DFS) record the vertex which time be found and finish
  int *discover;
  int *finish;

private:
  void DFSVisit(int start_vertex, int &time);
};

void Graph::AddEdgeList(int from, int to)
{
  AdjList[from].push_back(to);
}

void Graph::DFS(int start)
{
  color = new int[num_vertex];
  discover = new int[num_vertex];
  finish = new int[num_vertex];
  predecessor = new int[num_vertex];

  // Initialize
  for (int i = 0; i < num_vertex; i++)
  {
    color[i] = 0;
    discover[i] = 0;
    finish[i] = 0;
    predecessor[i] = -1;
  }

  int i = start;
  int time = 0; // Build the time stamp
  // Tranverse every vertex ensure every vertex will be visited
  for (int j = 0; j < num_vertex; j++)
  {
    // If we find the vertex not been visited yet, enter into DFSVisit
    if (color[i] == 0)
    {
      DFSVisit(i, time);
    }
    i = j;
  }
}
void Graph::DFSVisit(int vertex, int &time)
{
  color[vertex] = 1;
  discover[vertex] = ++time; // Record the vertex's be discovered time

  // Tranverse the input vertex's adjacent list
  for (std::list<int>::iterator iter = AdjList[vertex].begin(); iter != AdjList[vertex].end(); iter++)
  {
    if (color[*iter] == 0)
    {
      predecessor[*iter] = vertex;
      DFSVisit(*iter, time);
    }
  }
  color[vertex] = 2;
  finish[vertex] = ++time; // Record the vertex's finish time
}

void Graph::BFS(int start)
{
  // Initialize
  color = new int[num_vertex];
  predecessor = new int[num_vertex];
  distance = new int[num_vertex];
  for (int i = 0; i < num_vertex; i++)
  {
    color[i] = 0;                 // 0: white
    predecessor[i] = -1;          // -1: represent no predecessor
    distance[i] = num_vertex + 1; // Set the big num, the longest path in graph is "num_vertex-1"
  }

  // Use queue to do BFS
  std::queue<int> q;
  int i = start;
  // Tranverse every vertex
  for (int j = 0; j < num_vertex; j++)
  {
    if (color[i] == 0)
    {
      color[i] = 1; // 1: gray
      distance[i] = 0;
      predecessor[i] = -1; // Every connected component's start point don't have predecessor

      q.push(i);
      while (!q.empty())
      {
        int u = q.front();
        // Tranverse the u's adjancent list
        for (std::list<int>::iterator iter = AdjList[u].begin(); iter != AdjList[u].end(); iter++)
        {
          // Have not been visited
          if (color[*iter] == 0)
          {
            color[*iter] = 1; // Set to gray, have beed visited
            distance[*iter] = distance[u] + 1;
            predecessor[*iter] = u;
            q.push(*iter); // push the vertex into queue
          }
        }
        q.pop();      // pop up "u" from queue
        color[u] = 2; // color the u as "black", have been visited and pop up from queue
      }
    }
    i = j; // If we not visited all vertex yet, represent there are several connected component in the graph
  }
}

int main()
{
  // 定義一個具有八個vertex的Graph
  Graph g2(8);
  // 建立如圖三之Graph
  g2.AddEdgeList(0, 1);
  g2.AddEdgeList(0, 2);
  g2.AddEdgeList(1, 3);
  g2.AddEdgeList(2, 1);
  g2.AddEdgeList(2, 5);
  g2.AddEdgeList(3, 4);
  g2.AddEdgeList(3, 5);
  // AdjList[4] is empty
  g2.AddEdgeList(5, 1);
  g2.AddEdgeList(6, 4);
  g2.AddEdgeList(6, 7);
  g2.AddEdgeList(7, 6);

  g2.DFS(0); // 以vertex(0), 也就是vertex(A作為DFS()的起點

  return 0;
}
