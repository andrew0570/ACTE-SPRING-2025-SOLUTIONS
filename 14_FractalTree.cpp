#include <bits/stdc++.h>
using namespace std;
using ll=long long;
#define dbg(x) cout << #x << " = " << (x) << endl;

//notice that 2+(2^i) will always be even, thus we can tell number of healthy branches through casework
//even - odd = odd > and even - even is even, so we only need to find the parity of infected branches 

int bruteForceGrowth(int n); //scroll down to see a brute force implementation
//every infected branch infects floor(i^log10(i)+ abs(3cos(i))) for every already infected branch plus an extra i branches (where i is the time)

int growth(int i)
{
    return int(floor(pow(i, log10(i))+fabs((3*cos(i)))))%2;
    //the growth function for branches mod 2
}

void solve()
{
    int n; 
    cin>>n;
    int x=1,y=0,z=0; //x is initial, y is the  fractal growth and z is the extra i branches grown at time i
    //1 represents odd and 0 represents even -> this keeps the memory of the variables small 

    for(int i=0; i<=n; i++)
    {
        y=growth(i);
        z=i%2;
        //notice that: new branches = (old_branches +(old_branches*growth(i)))+i -> when will this be odd or even? x+(xy)+z = x(1+y)+z
        if(x^(x&y)^z==1){x=1;} //use bitwise operations to determine when the expression is even or odd, another approach is simple casework
        else{x=0;}   
    }

    cout<<((x==0)? "EVEN":"ODD")<<endl;
}


int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        solve();
    }
}



int bruteForceGrowth(int n)
{ //this is the brute force calculation of the number of branches at t = n
    ll branches=1;
    for(int i=1; i<=n; i++)
    {
        branches=branches+(branches*(growth(i)))+i;
        //remove the mod 2 in the growth function to get the actual number of branches
    }
    return branches;
}
