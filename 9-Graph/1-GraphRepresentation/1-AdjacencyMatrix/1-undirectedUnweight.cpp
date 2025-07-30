#include<iostream>
#include<vector>
using namespace std;

// Adjacency matrixu
// undirected unweighted graph

int main()
{
    int vertex,edges;
    cin>>vertex>>edges;             //if vertex=4 and edge =3 then we get u and v for each edge as done by using for loop 
    
    vector<vector<bool> >AdjMat(vertex, vector<bool>(vertex,0));

    int u,v;   // if there's an edge between node 2 and node 3, then:u = 2; v = 3;
    for(int i=0;i<edges;i++)
    {
        cin>>u >> v;
        // // We'll use u and v here to build the graph
        AdjMat[u][v]=1;
        AdjMat[v][u]=1;
    }

    for(int i=0;i<vertex;i++)   // loop over rows
    {
        for(int j=0;j<vertex;j++)   // loop over columns
        {
          cout << AdjMat[i][j] << " ";
        }
        cout<<endl;
    }
    // in 1st row print all column and then move to 2nd row and print all column and go on like that
    
    // First loop:
// i = 0 → We're printing row 0.

// Inside that:

// j = 0 → print AdjMat[0][0]
// j = 1 → print AdjMat[0][1]
// j = 2 → print AdjMat[0][2]
// j = 3 → print AdjMat[0][3]

// After that row is printed, cout << endl moves to a new line.

    return 0;
}





// What does vector<bool>(vertex, 0) mean?
// It means:    Make a 1D vector (a row) with vertex number of items, and fill them all with 0s."
// So for vertex = 4, this makes:    [0, 0, 0, 0]  // one row
// Now do this vertex times?
// vector<vector<bool>> AdjMat(vertex, vector<bool>(vertex, 0));
// “Make a vector that has vertex rows, and each row is a vector of vertex 0s.”
// Boom — you now have a 2D matrix of size vertex x vertex, filled with 0s (i.e., false).

// When the user inputs:
// 4 3
// 0 1
// 1 2
// 2 3
// In your loop:
// cin >> u >> v;
// AdjMat[u][v] = 1;
// AdjMat[v][u] = 1; // for undirected graph

// You're updating the table to say:
// 0 and 1 are connected
// 1 and 2 are connected
// 2 and 3 are connected

// So after the loop, your matrix looks like:
// |   | 0 | 1 | 2 | 3 |
// | - | - | - | - | - |
// | 0 | 0 | 1 | 0 | 0 |
// | 1 | 1 | 0 | 1 | 0 |
// | 2 | 0 | 1 | 0 | 1 |
// | 3 | 0 | 0 | 1 | 0 |



// ----->Time Complexity
// have to fill every box in 2d array(matrix) so o(v2)
// ----->Space Complexity
// v number of vertex then space will be v*v o(v2)