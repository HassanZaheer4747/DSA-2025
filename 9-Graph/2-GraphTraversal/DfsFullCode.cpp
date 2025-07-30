#include <iostream>
#include <vector>
using namespace std;

// DFS function
void DFS(int node, vector<int> AdjList[], vector<bool> &visited)
{
    visited[node] = 1;
    cout << node << " ";

    for (int i=0;i<AdjList[node].size();i++)
    {
        int neighbor = AdjList[node][i];
        if(!visited[AdjList[node][i]])
        {
            DFS(neighbor, AdjList, visited);
        }
    }
}

int main()
{
    int vertex, edges;
    cin >> vertex >> edges;

    vector<int> AdjList[vertex];

    int u, v;
    for (int i = 0; i < edges; i++)
    {
        cin >> u >> v;
        AdjList[u].push_back(v);
        AdjList[v].push_back(u); // undirected
    }

    vector<bool> visited(vertex, 0);

        // print the list
    for(int i=0;i<vertex;i++)
    {
        cout<<i<<" ->";
        for(int j=0;j<AdjList[i].size();j++)
        {
            cout<<AdjList[i][j]<<" ";
        }
        cout<<endl;
    }

    cout << "DFS Traversal: ";
    DFS(0, AdjList, visited);
}
