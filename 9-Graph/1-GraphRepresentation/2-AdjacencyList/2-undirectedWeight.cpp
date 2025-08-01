#include<iostream>
#include<vector>
using namespace std;

// Undirected Graph(no weight)

int main()
{
    int vertex,edges;
    cin>>vertex>>edges;

    vector<pair<int,int>> AdjList[vertex];

    int u,v,weight;
    for(int i=0;i<edges;i++)
    {
        cin>>u>>v,weight;
        AdjList[u].push_back({v,weight});
           AdjList[v].push_back({u,weight});
    }

    // print the list
    for(int i=0;i<vertex;i++)
    {
        cout<<i<<" ->";
       for (int j = 0; j < AdjList[i].size(); j++) {
    cout << "(" << AdjList[i][j].first << ", w=" << AdjList[i][j].second << ") ";
}

        cout<<endl;
    }
}