#include<iostream>
#include<vector>
#include<queue>
using namespace std;

vector<int> BFSTraversal(int v,vector<int> Adj[])
{
   queue<int> q;
   vector<bool> visited(v,0);

   q.push(0);
   visited[0]=1;

   vector<int> ans;

   while(!q.empty())
   {
   int node=q.front();
   q.pop();
   ans.push_back(node);

   for(int j=0;j<Adj[node].size();j++)
   {
      if(!visited[Adj[node][j]])
      {
        visited[Adj[node][j]]=1;
        q.push(Adj[node][j]);
      }
   }
   }
return ans;
}


int main() {
    int v = 5; // total 5 nodes: 0,1,2,3,4
    vector<int> Adj[5];

    // Create the graph (undirected)
    Adj[0].push_back(1);
    Adj[0].push_back(2);
    Adj[1].push_back(0);
    Adj[1].push_back(3);
    Adj[2].push_back(0);
    Adj[3].push_back(1);
    Adj[3].push_back(4);
    Adj[4].push_back(3);

    // Call BFS
    vector<int> bfsResult = BFSTraversal(v, Adj);

    // Print the result
    cout << "BFS Traversal: ";
    for(int i : bfsResult){
        cout << i << " ";
    }

    return 0;
}

// WHY USE BFS TRAVERSAL FOR PRINTING WHEN WE CAN JUST PRINT BY USING CODE AS WE DID IN GRAPH REPRESENTATION?

// | Your Code (In graph representation)      | BFS Traversal                                                    |
// | ---------------------------------------- | ---------------------------------------------------------------- |
// | Prints **structure** of the graph        | Prints **order of node visits**                                  |
// | Shows which nodes are connected to which | Shows the order nodes are **visited** starting from a **source** |
// | Just prints adjacency lists              | Helps explore paths, shortest routes, reachability, etc.         |
