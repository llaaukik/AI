#include <iostream> // Input Output sathi
#include <vector>   // Grid store karayla
#include <queue>    // Priority Queue sathi
#include <cmath>    // abs() function sathi
#include <algorithm>

using namespace std;

// Node structure

// Viva: Node kay store karto?
// Ans: Position ani cost values

struct Node {

    int x,y; // Coordinates

    double g,h,f;

    // g = Actual cost
    // h = Heuristic cost
    // f = Total cost

    Node* parent;

    // Constructor

    Node(int x,int y,
         double g=0,
         double h=0,
         Node* p=nullptr)

    :x(x),y(y),g(g),
     h(h),f(g+h),
     parent(p){}
};


// Comparator for priority queue

// Viva: Priority Queue ka use karto?
// Ans: Minimum f value pahila milavi mhanun

struct CompareF{

bool operator()(Node* a,Node* b)
{
    return a->f>b->f;
}
};


// Heuristic function

// Viva: Heuristic kay ahe?
// Ans: Goal paryant estimated distance

double heuristic(int x1,int y1,
                 int x2,int y2)
{
    // Manhattan distance formula

    return abs(x1-x2)+abs(y1-y2);
}


// A* function

void aStar(vector<vector<int>>& grid,
           pair<int,int> start,
           pair<int,int> goal)
{

    int rows=grid.size();

    int cols=grid[0].size();

    // Open List

    priority_queue<
    Node*,
    vector<Node*>,
    CompareF> openList;

    // Closed List

    vector<vector<bool>>
    closedList(rows,
    vector<bool>(cols,false));

    // Start node insert

    openList.push(
    new Node(
    start.first,
    start.second,
    0,
    heuristic(
    start.first,
    start.second,
    goal.first,
    goal.second)));

    while(!openList.empty())
    {
        // Minimum f value node ghya

        Node* current=openList.top();

        openList.pop();

        // Goal check

        // Viva: Goal condition kay?
        // Ans: Current node = Goal node

        if(current->x==goal.first
        && current->y==goal.second)
        {
            cout<<"Path found: ";

            while(current)
            {
                cout<<"("
                <<current->x
                <<","
                <<current->y
                <<") ";

                current=current->parent;
            }

            return;
        }

        // Node visited mark

        closedList[current->x]
                   [current->y]
                   =true;


        // Directions

        int dx[]={-1,1,0,0};

        int dy[]={0,0,-1,1};

        // Up Down Left Right

        for(int i=0;i<4;i++)
        {
            int nx=
            current->x+dx[i];

            int ny=
            current->y+dy[i];

            // Valid position check

            if(nx>=0
            && nx<rows
            && ny>=0
            && ny<cols
            && grid[nx][ny]==0
            && !closedList[nx][ny])
            {
                // New cost

                double gNew=
                current->g+1;

                double hNew=
                heuristic(nx,
                          ny,
                          goal.first,
                          goal.second);

                openList.push(
                new Node(
                nx,
                ny,
                gNew,
                hNew,
                current));
            }
        }
    }

    cout<<"No path found";
}

int main()
{
    // Grid create kela

    vector<vector<int>>
    grid=
    {
        {0,0,0,0,0},
        {0,1,1,1,0},
        {0,0,0,1,0},
        {0,1,0,0,0}
    };

    // Function call

    aStar(grid,{0,0},{3,2});

    return 0;
}


/*

Important Viva:

1) A* full form?
Ans: A Star Algorithm

2) Formula kay ahe?
Ans: f(n)=g(n)+h(n)

3) g(n) kay?
Ans: Actual cost

4) h(n) kay?
Ans: Estimated cost

5) Heuristic function kay?
Ans: Goal distance estimate karto

6) Priority queue ka use keli?
Ans: Minimum cost node select karayla

7) A* advantage?
Ans: Fast shortest path search

8) Time Complexity?
Ans: O(E)

*/