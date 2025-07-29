#include <bits/stdc++.h>
using namespace std;

long long solve(int x, int y) {
    int n = max(x, y);
    long long value;

    if (n % 2 == 0) {
        if (x == n) value = (long long)n * n - (y - 1);
        else value = (long long)(n - 1) * (n - 1) + x;
    } else {
        if (y == n) value = 1LL*n * n - (x - 1);
        else value = 1LL*(n - 1) * (n - 1) + y;
    }

    return value;
}


int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int t;
    cin>>t;

    vector<long long>res;

    while(t--){
        int x,y;
        cin>>x>>y;
        res.push_back(solve(x,y));
    }

    for(long long v:res){
        cout<<v<<endl;
    }   

    return 0;
}