// Solution to Problem 12 - Finding Lakes I
//  
//   - We can use a two pointer approach, working in from the left and right edges while keeping track of the maximum left height and maximum right height encountered so far
//   - We will process each index one at a time, counting the number of squares of water that can fill that index and adding it to count
//   - For each new index height we process, the amount of water that can be held in that index is equal to the minimum of the left and right maximum heights minus that index's height, with a minimum of zero

#include <bits/stdc++.h>

using namespace std;

int main(){

    //INPUT
    int n;
    cin>>n;
    vector<int> height(n);
    for(int i=0;i<n;i++) cin>>height[i];

    // CALCULATION
    int l=0,r=n-1, cnt=0;
    int lm=height[l], rm=height[r];

    while(l<r-1){
        if(lm<rm){
            l++;
            cnt+=max(0, min(lm,rm)-height[l]);
            if(height[l]>lm) lm=height[l];
        }
        else{ 
            r--;
            cnt+=max(0, min(lm,rm)-height[r]);
            if(height[r]>rm) rm=height[r];
        }
    }

    // OUTPUT
    cout<<cnt<<endl;

    return 0;
}
