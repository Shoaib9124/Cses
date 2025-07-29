#include <bits/stdc++.h>
using namespace std;

int solve(int x,int y){
    int n=max(x,y);//which square i am on

    int value;

    if(n%2==0){

        if(y==n) value=n*n -(x-1);
        else{
            value=(n-1)*(n-1)+y;
        }
    }

    else{
        if(x==n) value=n*n-(y-1);

        else{
            value=(n-1)*(n-1)+x;
        }
    }

    
    return value;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int t;
    cin>>t;

    vector<int>res;

    while(t--){
        int x,y;
        cin>>x>>y;
        res.push_back(solve(x,y));
    }

    for(int v:res){
        cout<<v<<endl;
    }   

    return 0;
}