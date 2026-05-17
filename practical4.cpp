#include <iostream> // Input output sathi
using namespace std;

// Chess board create kela
// 0 = Queen nahi
// 1 = Queen ahe

int board[4][4]={0};

// Viva: N-Queen problem kay ahe?
// Ans: N queens asa place karaycha ki ek queen dusryala attack karu naye

// Safe position check function
bool safe(int row,int col){

    // Same column madhye queen ahe ka check

    for(int i=0;i<row;i++){

        if(board[i][col])

            return false;
    }

    // Viva: Queen kuthlya direction la attack karte?
    // Ans: Row, Column, Diagonal

    // Left diagonal check

    for(int i=row,j=col;i>=0 && j>=0;i--,j--){

        if(board[i][j])

            return false;
    }

    // Right diagonal check

    for(int i=row,j=col;i>=0 && j<4;i--,j++){

        if(board[i][j])

            return false;
    }

    // Position safe ahe

    return true;
}

// Recursive function
bool solve(int row){

    // Viva: Base condition kay ahe?
    // Ans: Sarva queens place zale

    if(row==4)

        return true;

    // Current row madhle sarva columns try kara

    for(int col=0;col<4;col++){

        // Safe asel tar queen place kara

        if(safe(row,col)){

            board[row][col]=1;

            // Viva: Recursion ka use kela?
            // Ans: Next row solve karayla

            if(solve(row+1))

                return true;

            // Backtracking step
            // Wrong path asel tar queen remove kara

            board[row][col]=0;

            // Viva: Backtracking mhanje kay?
            // Ans: Wrong path sodun dusra path try karne
        }
    }

    return false;
}

int main(){

    // First row pasun solve start

    solve(0);

    cout<<"Solution:\n";

    // Final board print

    for(int i=0;i<4;i++){

        for(int j=0;j<4;j++){

            cout<<board[i][j]<<" ";
        }

        cout<<endl;
    }

    return 0;
}

/*
Important Viva:

1) N Queen problem kay ahe?
Ans: Queens asa place karne ki attack hou naye

2) Backtracking kay ahe?
Ans: Wrong path varun mage yeun dusra path try karne

3) Time Complexity?
Ans: O(N!)

4) Queen kontya direction la attack karte?
Ans: Row, Column, Diagonal

5) Recursion ka use kela?
Ans: Row by row solve karayla
*/