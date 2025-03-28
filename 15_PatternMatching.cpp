#include <iostream>
#include <vector>
using namespace std;

int dpsolve(const string& S, const string& P) {
    int slen=S.size(), plen=P.size(); //initializing variables and dp table
    vector<vector<bool>> dp(plen+1,vector<bool>(slen+1,false));
    dp[0][0]=true;
    for (int i=1;i<=plen;i++) {
        if (P[i-1]=='*') dp[i][0]=dp[i-1][0];
        else break;
    } //creating dp table
    for (int i=1;i<=plen;i++) {
        for (int j=1;j<=slen;j++) {
            if (P[i-1]==S[j-1]||P[i-1]=='?'){
                dp[i][j]=dp[i-1][j-1];
            } else if (P[i-1]=='*'){
                dp[i][j]=dp[i-1][j]||dp[i][j-1];
            }
        }
    }
    if (dp[plen][slen]) return -1; // -1 means strings match
    // find first mismatch index
    int i=0,j=0;
    while (i<slen&&j<plen) {
        if (P[j]==S[i]||P[j]=='?'){
            i++; j++;
        } else if (P[j]=='*'){
            if (j+1==plen) return -1; // * at end matches everything
            while (i<slen&&S[i]!=P[j+1]) i++; // move i to match next character in P
            j++;
        } else{
            return i;
        }
    }
    return (i<slen) ? i : -1;
}

int main() {
    string S,P;
    cin>>S>>P;
    int ans=dpsolve(S,P);
    if (ans==-1) cout<<"true"<<endl;
    else cout<<ans<<endl;
    return 0;
}