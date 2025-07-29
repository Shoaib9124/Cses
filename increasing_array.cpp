#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin>>n;

    vector<long long>v(n);
    for(int i=0;i<n;i++){
        cin>>v[i];
    }

    long long prev=v[0]; //prev_largest

    long long count=0;

    for(int i=1;i<v.size();i++){

        if(v[i]<prev){
            count+=prev-v[i];
        }
        else prev=v[i];
    }

    cout<<count;

    return 0;
}