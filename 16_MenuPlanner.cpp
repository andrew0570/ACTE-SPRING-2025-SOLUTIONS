#include <bits/stdc++.h>
#define dbg(x) cout<<#x<<" = "<<x<<endl;
#define pb push_back
#define all(x) (x).begin(), (x).end()
using ll=long long;
using namespace std;

int main() 
{
    int n;
    cin>>n;

    vector<string> recipes(n);
    unordered_map<string, vector<string>> ingredients;
    unordered_map<string, int> inDeg; //we will be using indegree method for our topological sort, but there are other ways
    
    unordered_map<string, vector<string>> rgraph;

    //get input
    for (int i=0; i<n; i++) 
    { cin>>recipes[i]; inDeg[recipes[i]]=0; }

    for (int i=0; i<n; i++)  //read in your ingredients and create a graph with an adjacency list
    {
        int m;
        cin>>m;
        vector<string> temp(m);
        for (int j=0; j<m; ++j) //initialize indegrees and create a reverse graph - (rgraph)
        {
            cin>>temp[j];
            rgraph[temp[j]].pb(recipes[i]);
            inDeg[recipes[i]]++;//count the number of needed ingredients
        }
        ingredients[recipes[i]]=temp;
    }

    int k;
    cin>>k;

    unordered_set<string>free;
    queue<string>q;

    for (int i=0; i<k; i++) //get the ingredients that you have
    {
        string temp; 
        cin>>temp;
        free.insert(temp); 
        q.push(temp); 
    }
    
    vector<string>result;
    while (!q.empty()) //apply bfs to do the topological sort
    {
        string current=q.front();
        q.pop();
        for (const string& recipe:rgraph[current]) 
        {
            inDeg[recipe]-=1;
            if (inDeg[recipe]==0)
            {   //these are the free ingredients that you can use
                free.insert(recipe);
                q.push(recipe);
                result.pb(recipe);
            }
        }
    }

    sort(all(result)); //remember to return in alphabetical order
    for (const string& r:result){cout<<r<<endl;}
    return 0;
}
