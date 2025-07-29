#include <bits/stdc++.h>
using namespace std;


void solve(string &s,int index,set<string>&ans){

    if(index==s.size()){
        ans.insert(s);
        return;
    }
    for(int j=index;j<s.size();j++){
        swap(s[index],s[j]);
        solve(s,index+1,ans);
        swap(s[j],s[index]);
    }

}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    string s;
    cin>>s;
    set<string>ans;

    solve(s,0,ans);

    cout<<ans.size()<<endl;
    for(string s:ans){
        cout<<s<<endl;
    }

    return 0;
}