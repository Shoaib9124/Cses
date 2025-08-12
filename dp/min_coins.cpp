#include <bits/stdc++.h>
using namespace std;

const int inf=1e9;

int rec(int i,int t,vector<int>&nums,vector<vector<int>>&dp){

    if(i==0){
        if(t%nums[0]==0) return t/nums[0];
        else return inf;
    }

    if(dp[i][t]!=-1) return dp[i][t];

    int take=inf;

    if(nums[i]<=t)take=1+rec(i,t-nums[i],nums,dp);

    int not_take=rec(i-1,t,nums,dp);

    return dp[i][t]=min(take,not_take);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n,k;

    cin>>n>>k;
    vector<int>nums(n);
    for(int &i:nums) cin>>i;

    //k is the target

    vector<vector<int>>dp(n+1,vector<int>(k+1,-1));

    int ans=rec(n-1,k,nums,dp);
    int res=(ans>=inf)?-1:ans;
    cout<<res;

    return 0;
}