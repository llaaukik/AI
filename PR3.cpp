#include <iostream> // Input Output sathi
#include <vector>   // Dynamic array use karayla
#include <algorithm> // sort() function sathi

using namespace std;

// Viva: MST mhanje kay?
// Ans: Minimum cost madhe sarva vertices connect karanara tree

// Edge structure graph chi information store karto
struct Edge
{
    int src,dest,weight; // Source, Destination ani Weight
};

// Weight nusar sorting function

// Viva: Greedy approach kay karto?
// Ans: Pratyek step la minimum value select karto

bool compareEdges(Edge a,Edge b)
{
    return a.weight<b.weight;
}

// DSU = Disjoint Set Union
// Cycle detect karayla use karto

class DSU
{
    vector<int> parent;

public:

    // Constructor
    DSU(int n)
    {
        parent.resize(n);

        // Initially swatacha parent swatach
        for(int i=0;i<n;i++)
        {
            parent[i]=i;
        }
    }

    // Root parent find function

    // Viva: Find function kay karto?
    // Ans: Root parent shodhto

    int find(int i)
    {
        if(parent[i]==i)
        {
            return i;
        }

        // Path compression fast searching sathi

        return parent[i]=find(parent[i]);
    }

    // Don sets merge karne

    void unite(int i,int j)
    {
        int root_i=find(i);

        int root_j=find(j);

        // Jar roots vegle astil tar connect kara

        if(root_i!=root_j)
        {
            parent[root_i]=root_j;
        }
    }
};

// Kruskal algorithm function

void kruskalMST(int V,vector<Edge>& edges)
{
    // Step 1 : Weight nusar sorting

    sort(edges.begin(),edges.end(),compareEdges);

    DSU dsu(V);

    vector<Edge> mst;

    int totalWeight=0;

    cout<<"Edges in Minimum Spanning Tree:"<<endl;

    // Pratyek edge check kara

    for(Edge &e:edges)
    {
        // Viva: Cycle check ka karto?
        // Ans: MST madhe cycle nasavi

        if(dsu.find(e.src)!=dsu.find(e.dest))
        {
            dsu.unite(e.src,e.dest);

            // Edge MST madhye add kara

            mst.push_back(e);

            // Total weight calculate kara

            totalWeight+=e.weight;

            cout<<e.src
                <<" -- "
                <<e.dest
                <<" == "
                <<e.weight
                <<endl;
        }
    }

    cout<<"Total Minimum Weight: "
        <<totalWeight
        <<endl;
}

int main()
{
    int V=4; // Total vertices

    // Graph define kela

    vector<Edge> edges=
    {
        {0,1,10},
        {0,2,6},
        {0,3,5},
        {1,3,15},
        {2,3,4}
    };

    // Function call

    kruskalMST(V,edges);

    return 0;
}

/*

Important Viva:

1) Greedy algorithm kay ahe?
Ans: Locally best choice select karto

2) MST full form?
Ans: Minimum Spanning Tree

3) Kruskal algorithm kay karto?
Ans: Minimum cost tree create karto

4) DSU ka use karto?
Ans: Cycle detect karayla

5) Time Complexity?
Ans: O(E log E)

6) Sorting ka keli?
Ans: Minimum weight edge pahila select karayla

*/