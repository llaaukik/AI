#include <iostream>   // Input/Output sathi
#include <vector>     // Graph store karayla
#include <queue>      // BFS sathi queue

using namespace std;

// Viva: DFS mhanje kay?
// Ans: Depth First Search - depth madhye traverse karto

void dfs(int node, vector<int> adj[], vector<bool> &visited)
{
    visited[node]=true;   // Current node visited mark

    cout<<node<<" ";      // Node print

    // Viva: visited array ka use karto?
    // Ans: Same node punha visit hou naye

    for(int next:adj[node])   // Neighbor traverse
    {
        if(!visited[next])    // Visit nasel tar
        {
            dfs(next,adj,visited); // Recursive DFS call
        }
    }
}

int main()
{
    int n=7; // Total nodes

    // Viva: Graph representation konta?
    // Ans: Adjacency List

    vector<int> adj[n];

    // Graph create karat ahe
    adj[0].push_back(1);
    adj[1].push_back(0);

    adj[0].push_back(2);
    adj[2].push_back(0);

    adj[1].push_back(3);
    adj[3].push_back(1);

    adj[1].push_back(4);
    adj[4].push_back(1);

    adj[2].push_back(5);
    adj[5].push_back(2);

    adj[2].push_back(6);
    adj[6].push_back(2);

    // BFS part

    vector<bool> visitedBFS(n,false);

    // Viva: BFS madhe queue ka use karto?
    // Ans: Level by level traversal sathi

    queue<int> q;

    visitedBFS[0]=true; // Starting node visited

    q.push(0); // Queue madhye insert

    cout<<"BFS Traversal: ";

    while(!q.empty())
    {
        int node=q.front(); // Front node ghya

        q.pop(); // Remove from queue

        cout<<node<<" ";

        for(int next:adj[node])
        {
            if(!visitedBFS[next])
            {
                visitedBFS[next]=true;

                q.push(next);
            }
        }
    }

    cout<<endl;

    // DFS part

    vector<bool> visitedDFS(n,false);

    cout<<"DFS Traversal: ";

    // Viva: DFS madhe recursion ka use karto?
    // Ans: Depth madhye janyasathi

    dfs(0,adj,visitedDFS);

    return 0;
}

/*
Important Viva:

1) BFS full form?
Ans: Breadth First Search

2) DFS full form?
Ans: Depth First Search

3) BFS data structure?
Ans: Queue

4) DFS data structure?
Ans: Stack/Recursion

5) Time Complexity?
Ans: O(V+E)

6) Graph kay ahe?
Ans: Nodes ani edges cha collection
*/