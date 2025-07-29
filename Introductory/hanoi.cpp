#include <bits/stdc++.h>
using namespace std;

void solve(int n,int from,int to){

    if(n==0) return;

    int other=6-from-to;

    solve(n-1,from,other);
    cout<<from<<" "<<to<<" "<<endl;
    solve(n-1,other,to);

}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n;
    cin>>n;
    cout<<(1<<n)-1<<endl;
    solve(n,1,3);

    return 0;
}