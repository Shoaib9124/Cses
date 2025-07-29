#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin>>n;


    //28   ... 5 10 15 20 (25 25)
    int count=0;

    for(int i=5;n/i>=1;i*=5){
        count+=n/i;
    }
    cout<<count;
    return 0;
}