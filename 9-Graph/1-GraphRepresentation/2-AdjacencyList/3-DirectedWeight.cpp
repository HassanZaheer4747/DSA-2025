#include<iostream>
#include<vector>
#include<queue>
using namespace std;

int main()
{
    int vertex,edge;
    cin>>vertex>>edge;

    vector<pair<int,int>> AdjLst[vertex];

    int u,v,weight;
    for(int i=0;i<edge;i++)
    {
        cin>>u>>v>>weight;
        AdjLst[u].push_back({v,weight});
    }

    // printing
    for(int i=0;i<vertex;i++)
    {
        cout<<i<<"->";
        for(int j=0;j<AdjLst[i].size();j++)
        {
            cout<<"("<<AdjLst[i][j].first<<", w="<<AdjLst[i][j].second<<")";
        }
        cout<<endl;
    }

    // ---------- BFS Traversal ----------
    cout << "\nBFS Traversal from source node 0:\n";

    vector<bool> visited(vertex, false);
    queue<int> q;

    int source = 0;
    visited[source] = true;
    q.push(source);

    while(!q.empty())
    {
        int current = q.front();
        q.pop();
        cout << current << " ";

        for(auto &neighbor : AdjLst[current])
        {
            int next = neighbor.first;
            if(!visited[next])
            {
                visited[next] = true;
                q.push(next);
            }
        }
    }

    cout << endl;

    return 0;
}