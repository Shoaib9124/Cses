#include <bits/stdc++.h>
using namespace std;

#define ll long long

long long MOD=1e9+7;

long long rec(int n,long long curr,vector<long long>&dp){

    if(curr==n){
        return 1;
    }
    if(curr>n) return 0;

    if(dp[curr]!=-1) return dp[curr];

    long long ways=0;

    for(int i=1;i<=6;i++){
        ways=(ways+rec(n,curr+i,dp))%MOD;
    }
    return dp[curr]=ways;
}



int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n;
    cin>>n;

    //dice can be thrown any number of times
     
    // long long ways=rec(n,0,dp);

    vector<long long>dp(n+1,0);

    //dp[s] is the novector<long long>dp(n+1,-1); of ways to get sum s 
    dp[0]=1; //to get 0 sum i have a 

    for(int s=0;s<n;s++){
        for(int i=1;i<=6;i++){
            if(s+i<=n)dp[s+i]=(dp[s+i]+dp[s])%MOD;
        }
    }

    cout<<dp[n];

    return 0;
}