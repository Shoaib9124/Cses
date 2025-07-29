#include <bits/stdc++.h>
using namespace std;

vector<string>solve(int n){

    if(n==1){
        return {"0","1"};   
    }
    vector<string>a=solve(n-1);
    vector<string>b=a;
    reverse(b.begin(),b.end());

    for(string &s:a){
        s+='0';
    }
    for(string &s:b){
        s+='1';
    }

    a.insert(a.end(),b.begin(),b.end());
    return a;

}





int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n;
    cin>>n;

    vector<string>ans=solve(n);

    for(string &s:ans){
        cout<<s<<endl;
    }

    return 0;
}