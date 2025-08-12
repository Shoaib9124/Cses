#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n,k;

    cin>>n>>k;
    vector<int>nums(n);
    for(int &i:nums) cin>>i;

    //k is the target
    vector<vector<int>>dp(n+1,vector<int>(k+1,1e9));

    for(int t=0;t<=k;t++){
        if(t%nums[0]==0){
            dp[0][t]=t/nums[0];
        }
    }
    //this is the base case{to make target in each row with 0th row coin}

    for(int i=1;i<n;i++){
        for(int t=0;t<=k;t++){
            int not_take=dp[i-1][t];
            int take=1e9;
            if(nums[i]<=t) take=1+dp[i][t-nums[i]];
            dp[i][t]=min(take,not_take);
        }
    }    

    int ans = dp[n - 1][k];
    cout << (ans >= 1e9 ? -1 : ans);

    return 0;
}