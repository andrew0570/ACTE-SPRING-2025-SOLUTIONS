#include <bits/stdc++.h>
using namespace std;


void solve()
{
    string s;
    getline(cin,s);
    int c=0;
    for(auto &k:s)
    {
        if(k=='X')
        {
            c+=1;
        }
    }
    cout<<pow(3,c)<<endl;
}



int main()
{
    int t;
    cin>>t;
    cin.ignore();
    while(t--)
    {
        solve();
    }
    return 0;
}
