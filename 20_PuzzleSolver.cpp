// Solution to Problem 20 - Puzzle Solver
//  
//   - Use a backtracking algorithm to test each piece in all possible spots in order; guarantees solution even though it is slow

#include <bits/stdc++.h>

using namespace std;

// Helper function, checks if piece can be placed at i,j in grid
bool isvalid(vector<vector<char>> &grid, vector<vector<char>> &piece, int i, int j){
    for(int y=0;y<3;y++){
        for(int x=0;x<3;x++){
            if(piece[y][x]=='X'){
                if(i+y<0||i+y>=10||j+x<0||j+x>=10) return false;
                if(grid[i+y][j+x]!='_') return false;
            }
        }
    }
    return true;
}

// Recursive backtracking function, tries pieces in order one by one, moving to next piece if it has a spot and going back if it doesn't
bool rec(vector<vector<char>> &grid, vector<vector<vector<char>>> &pieces, int n, int curr){
    if(curr==n) return true; // catch return without undoing grid once solved

    for(int i=-2;i<12;i++){
        for(int j=-2;j<12;j++){
            if(isvalid(grid,pieces[curr],i,j)){
                for(int y=0;y<3;y++) for(int x=0;x<3;x++) if(pieces[curr][y][x]=='X') grid[i+y][j+x]=char(curr)+'0';
                if(rec(grid,pieces,n,curr+1)) return true;
                for(int y=0;y<3;y++) for(int x=0;x<3;x++) if(pieces[curr][y][x]=='X') grid[i+y][j+x]='_';
            }
        }
    }

    return false;
}

int main(){
    
    // INPUT
    vector<vector<char>> grid(10,vector<char>(10));
    int n;

    for(int i=0;i<10;i++) for(int j=0;j<10;j++) cin>>grid[i][j];
    cin>>n;
    vector<vector<vector<char>>> pieces(n,vector<vector<char>>(3,vector<char>(3)));
    for(int i=0;i<n;i++){
        for(int j=0;j<3;j++){
            cin>>pieces[i][j][0]>>pieces[i][j][1]>>pieces[i][j][2];
        }
    }

    // CALCULATE
    rec(grid,pieces,n,0);

    // OUTPUT
    for(auto i:grid){
        for(char j:i) cout<<j<<' '; cout<<endl;
    }

    return 0;
}
