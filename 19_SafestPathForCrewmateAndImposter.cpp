// Solution to Problem 19 - Safest Path For Crewmate And Imposter
//  
//   - If we are given the "Crewmate" role we want to maximize the bitwise OR of all paths from start to end, and if we are given the "Imposter" role we want to minimize the bitwise AND of all paths from start to end
//   - We know that taking the AND of two numbers will only decrease our result or stay the same, and we know that taking the OR of two numbers will only increase our result or stay the same. We also know we can take the same path multiple times, so we need to find ALL of the paths that connect to our start node and subsequent connected nodes and take the bitwise OR or AND of ALL the paths' weights.
//   - We can do this by 

#include <bits/stdc++.h>

using namespace std;

void rec(vector<int> &weights, map<int,bool> &used, map<int,vector<pair<int,int>>> &graph, int i){
    used[i]=true;
    for(auto j:graph[i]){
        weights.push_back(j.second);
        if(used[j.first]) continue;
        rec(weights,used,graph,j.first);
    }
}

int main(){

    // INPUT
    char role;
    cin>>role;

    int n, m;
    cin>>n;
    cin>>m;

    map<int,vector<pair<int,int>>> graph;
    int a,b,p;
    for(int i=0;i<m;i++){
        cin>>a>>b>>p;
        graph[a].push_back({b,p});
        graph[b].push_back({a,p});
    }

    int s, e;
    cin>>s>>e;

    // FINDING ALL CONNECTED PATHS
    vector<int> weights;
    map<int,bool> used;
    rec(weights,used,graph,s);

    // CALCULATE
    int out;
    if(used[e]){
        if(role=='c'){ // Crewmate, find maximum OR
            out=0;
            for(int i:weights) out|=i;
        }
        else{ // Imposter, find minimum AND
            out=INT_MAX;
            for(int i:weights) out&=i;
        }
    }
    else out=-1; // if no path to "end" room

    // OUTPUT
    cout<<out<<endl;

    return 0;
}
