// Adjacency List 

#include<bits/stdc++.h>
using namespace std;


void print_graph(vector<int>adj_list[], int V){
  for(int i=0;i<V;i++){
    cout<<"adj list of"<<" "<<i<<" "<<endl;
    for(int nbr: adj_list[i]){
      cout<<nbr<<" ";
    }
    cout<<endl;
  }
}

// DFS Traversal Of Adj List
void dfs_helper(int src, vector<int>adj_list[], int V, vector<bool> &visited){
  visited[src] = true;
  for(int nbr: adj_list[src]){
    if(!visited[nbr]) dfs_helper(nbr, adj_list, V, visited);
  }
}
vector<int> dfs_adj_list(int src, vector<int>adj_list[], int V){
  vector<bool> visited(V, false);
  dfs_helper(src, adj_list, V, visited);
}


// BFS Traversal Of Adj List
vector<int> bfs_adj_list(int src, vector<int>adj_list[], int V){
  vector<bool> visited(V, false);
  queue<int> q;
  q.push(src);
  visited[src] = true;
  vector<int>result;
  while (!q.empty())
  {
    int front = q.front();
    q.pop();
    result.push_back(front);

    for (int nbr: adj_list[front])
    {
      if (!visited[nbr])
      {
        visited[nbr] = true;
        q.push(nbr);
      }
    }
  }
  return result;
}

// undirected
void add_edge_undirected(vector<int>adj_list[], int u, int v){
  adj_list[u].push_back(v);
  adj_list[v].push_back(u);
}

// directed
void add_edge_directed(vector<int>adj_list[], int u, int v){
  adj_list[u].push_back(v);
}

int main(){
  int V = 5;

  vector<int>adj_list[V];


  add_edge_undirected(adj_list, 0, 1);
  add_edge_undirected(adj_list, 0, 4);
  add_edge_undirected(adj_list, 1, 2);
  add_edge_undirected(adj_list, 1, 3);
  add_edge_undirected(adj_list, 1, 4);
  add_edge_undirected(adj_list, 2, 3);
  add_edge_undirected(adj_list, 3, 4);


  print_graph(adj_list, V);


  
  bfs_adj_list(0, adj_list, V);
  
  dfs_adj_list(0, adj_list, V);

  // disconnected graphs
  // vector<bool> visited(V, false);
  // for(int i=0;i<V;i++){
  //   if(!visited[i]) bfs_adj_list(i, adj_list, V);
  // }

  return 0;
}