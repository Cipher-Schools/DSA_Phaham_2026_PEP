#include <bits/stdc++.h>
using namespace std;

// Building Undirected graph
vector<vector<int>> adj_matrix_undirected(vector<vector<int>> &edges, int n)
{
  vector<vector<int>> graph(n, vector<int>(n, 0));

  // build the graph
  for (auto edge : edges)
  {
    int u = edge[0];
    int v = edge[1];

    graph[u][v] = 1;
    graph[v][u] = 1;
  }

  return graph;
}

// Building directed graph

vector<vector<int>> adj_matrix_directed(vector<vector<int>> &edges, int n)
{
  vector<vector<int>> graph(n, vector<int>(n, 0));

  // build the graph
  for (auto edge : edges)
  {
    int u = edge[0];
    int v = edge[1];

    graph[u][v] = 1;
    // graph[v][u] = 1;
  }
  return graph;
}

// bfs traversal
void bfs(int src, int n, vector<vector<int>> graph)
{
  vector<bool> visited(n, false);
  queue<int> q;
  q.push(src);
  visited[src] = true;
  vector<int>result;
  while (!q.empty())
  {
    int front = q.front();
    q.pop();
    // result.push_back();

    for (int i = 0; i < n; i++)
    {
      if (!visited[i] && graph[front][i] == 1)
      {
        visited[i] = true;
        q.push(i);
      }
    }
  }
}

// dfs traversal
void dfs_helper(int src, int n, vector<vector<int>> &graph, vector<bool> &visited){
  visited[src] = true;

  for(int i=0;i<n;i++){
    if(graph[src][i] == 1 && !visited[i]) dfs_helper(i, n, graph, visited);
  }

}
void dfs(int src, int n, vector<vector<int>> graph){
  vector<bool> visited(n, false);
  dfs_helper(0, n, graph, visited);
}


int main()
{
  int n = 3;
  vector<vector<int>> edges = {{1, 0}, {2, 0}, {1, 2}};
  vector<vector<int>> undirected_graph = adj_matrix_undirected(edges, n);
  vector<vector<int>> directed_graph = adj_matrix_directed(edges, n);

  // print un-directed adjacency matrix
  for (int i = 0; i < n; i++)
  {
    for (int j = 0; j < n; j++)
    {
      cout << undirected_graph[i][j] << " ";
    }
    cout << endl;
  }
  cout << "Printing Directed Graph" << endl;
  // print directed adjacency matrix
  for (int i = 0; i < n; i++)
  {
    for (int j = 0; j < n; j++)
    {
      cout << directed_graph[i][j] << " ";
    }
    cout << endl;
  }
}