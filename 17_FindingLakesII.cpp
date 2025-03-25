// Solution to Problem 17 - Finding Lakes II
//  
//   - uses a min heap to store all current edges of our working portion of the grid
//   - gradually moves boundaries in, lowest edge at a time, either adding to our total water volume count or updating the border value each time
//   - keep track of used cells to prevent double counting

#include <bits/stdc++.h>

using namespace std;

int main(){
    // INPUT
    int m,n;
    cin>>m>>n;

    vector<vector<int>> hm(m,vector<int>(n)); // height map grid
    for(int i=0;i<m;i++) for(int j=0;j<n;j++) cin>>hm[i][j];

    // CREATING MIN HEAP
    priority_queue<pair<int,pair<int,int>>, vector<pair<int,pair<int,int>>>, greater<pair<int,pair<int,int>>>> bounds;
    vector<vector<bool>> used(m,vector<bool>(n));
    for(int i=0;i<m;i++){
        used[i][0]=true, used[i][n-1]=true;
        bounds.push({hm[i][0],{i,0}});
        bounds.push({hm[i][n-1],{i,n-1}});
    }
    for(int j=1;j<n-1;j++){
        used[0][j]=true, used[m-1][j]=true;
        bounds.push({hm[0][j],{0,j}});
        bounds.push({hm[m-1][j],{m-1,j}});
    }

    // CLOSING BOUNDS UNTIL ALL CELLS COUNTED
    int cnt=0;
    int y[4] = {0,0,-1,1};
    int x[4] = {1,-1,0,0};
    int height, i,j;
    while(!bounds.empty()){
        height=bounds.top().first, i=bounds.top().second.first, j=bounds.top().second.second;
        bounds.pop();

        for(int k=0;k<4;k++){
            if(i+y[k]<m && i+y[k]>=0 && j+x[k]<n && j+x[k]>=0 && !used[i+y[k]][j+x[k]]){
                cnt+=max(0, height-hm[i+y[k]][j+x[k]]);
                bounds.push({max(height,hm[i+y[k]][j+x[k]]),{i+y[k],j+x[k]}});
                used[i+y[k]][j+x[k]]=true;
            }
        }
    }

    // OUTPUT
    cout<<cnt<<endl;

    return 0;
}
