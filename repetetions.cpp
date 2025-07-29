#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    string s;
    cin>>s;

    int count=1;
    int max_count=1;
    for(int i=1;i<s.size();i++){
        if(s[i-1]==s[i]) count++;
        else count=1;
        max_count=max(max_count,count);
    }

    cout<<max_count;

    return 0;
}