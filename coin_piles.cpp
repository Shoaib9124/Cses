#include <bits/stdc++.h>
using namespace std;

string solve(int a,int b){
    if((a+b)%3!=0) return "NO";
    
    if(2*min(a,b)<max(a,b)) return "NO";

    return "YES";
}   

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    //1l 2r
    //2l 1r
    int t;
    cin>>t;
    vector<string>ans;
    while(t--){
        int a,b;
        cin>>a>>b;
        ans.push_back(solve(a,b));
    }

    for(string s:ans){
        cout<<s<<endl;
    }

    return 0;
}