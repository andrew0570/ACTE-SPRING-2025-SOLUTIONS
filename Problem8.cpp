#include <bits/stdc++.h>
using namespace std;

void solve()
{
    int n;
    cin>>n;
    int ans=0;
    for(int i=1; i<=n; i++)
    {
        ans+=i;
    }
    cout<<ans<<endl;
}


int main()
{
    freopen("input1.in","r",stdin);
    freopen("output1.out","w",stdout);
    int t;
    cin>>t;
    while(t--)
    {
        solve();
    }
    return 0;
}