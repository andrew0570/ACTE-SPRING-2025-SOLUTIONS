#include <bits/stdc++.h>
using namespace std;


void solve()
{
    string s,p;
    getline(cin,s);
    getline(cin,p);
    int ans=abs(int(s.size()-p.size()));
    for(int i=0; i<min(s.size(),p.size()); i++)
    {
        if(s[i]!=p[i])
        {
            ans+=1;
        }
    }
    cout<<ans<<endl;

}



int main()
{
    freopen("input1.in","r",stdin);
    freopen("output1.out","w",stdout);
    int t;
    cin>>t;
    cin.ignore();
    while(t--)
    {
        solve();
    }
    return 0;
}