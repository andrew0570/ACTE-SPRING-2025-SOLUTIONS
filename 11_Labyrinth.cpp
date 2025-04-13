#include <iostream>
#include <cmath>
#include <algorithm>
#include <cctype>
#include <list>
#include <vector>
#include <stack>
#include <queue>
using namespace std;

int aroundX[4] = {0, 0, 1, -1}; //x coordinates for surrounding cells
int aroundY[4] = {1, -1, 0, 0}; //y coordinates for surrounding cells

int n, m, numrooms = 0; //input variables and answer
bool visited[1000][1000]; //visited status
char grid[1000][1000]; //input grid

//checks if coordinates in the grid
bool inGrid (int y, int x)
{
  if (y < 0) 
    return false;
  if (x < 0) 
    return false;
  if (y >= n) 
    return false;
  if (x >= m) 
    return false;
  return true;
}

//checking for valid floors
bool inBounds (int y, int x) {
  if(!(inGrid(y,x))) //checking if its in the grid
    return false;
  if (grid[y][x] == 'A') //checks if it is wall
    return false;
  return true;
}

//depth first search traversal method to search for all surrounding floors
void dfs (int y, int x) {
  visited[y][x] = true; //changes visited status
  for (int i = 0 ; i < 4 ; i++) { //goes through surrounding cells list
    int X = x + aroundX[i]; //sets surrounding cells x & y coordinates
    int Y = y + aroundY[i];
    if (inBounds(Y, X)) //make sure coordinates in grid and its not a wall
    { 
      if (!(visited[Y][X])) //make sure not to count cell twice
        dfs(Y,X); //recursion
    }
  }
}

int main() {
    cin>>n>>m;
    //creating grid from input
    for (int i = 0 ; i < n ; i++) {
      for (int j = 0 ; j < m ; j++) {
        cin >> grid[i][j]; 
        visited[i][j] = false; //sets all cells status to false initially
      }
    }

    //traverses maze
    for (int i = 0 ; i < n ; i++) {
      for (int j = 0 ; j < m ; j++) {
        if (grid[i][j] == 'V' && !(visited[i][j])) {
          //checks for floors and make sure its not visited
          dfs(i, j); //calls dfs to search for all surrounding cells that are floors
          numrooms++; //increases count of rooms
        }
      }
    }
    cout<<numrooms<<endl; //prints answer
    return 0; 
}
