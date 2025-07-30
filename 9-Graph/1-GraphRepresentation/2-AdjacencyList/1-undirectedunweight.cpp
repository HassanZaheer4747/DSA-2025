#include<iostream>
#include<vector>
using namespace std;

// Undirected Graph(no weight)

int main()
{
    int vertex,edges;
    cin>>vertex>>edges;

    vector<int>AdjList[vertex];

    int u,v;
    for(int i=0;i<edges;i++)
    {
        cin>>u>>v;
        AdjList[u].push_back(v);
           AdjList[v].push_back(u);
    }

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
}

// for(int j = 0; j < AdjList[i].size(); j++)
// This loop does NOT go from 0 to total number of vertices. Instead:

// It only loops through the number of neighbors for vertex i.

// So if vertex 0 is connected to 1 and 2, then AdjList[0].size() is 2, and:

// AdjList[0][0] = 1
// AdjList[0][1] = 2