#include <bits/stdc++.h>
using namespace std;
using ll=long long;
#define dbg(x) cout << #x << " = " << (x) << endl;
//notice that the growth over time for new mold cells is quadratic after modeling it on paper. 
// at n=0, f(n)=4 (starting point) -> so we know the value of c is 4 in the quadratic an^2 + bn + c
//after this, we can do some experimentation to figure out the values for a and b.
//the formula for the number of bacteria at t=n is: f(n) = 2n^2 + 7x + 4 >>>interestingly, this can be rewritten as: n + (n+2)^2 + (n+1)^2 - 1 

int f(int n)
{
    // return n+((n+2)*(n+2))+((n+1)*(n+1))-1;
    return (2*n*n) + (7*n) + 4; //this statement and the above commented out expression is equivalent
}

void solve()
{
    int l,r;
    cin>>l>>r;
    cout<<f(r)-f(l)<<endl;
}

int main()
{
    int t;
    cin>>t;
    while(t--)
    {solve();}
    return 0;
}
