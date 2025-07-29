//cpu can do ~ 10^8 operations per second

#include <bits/stdc++.h>
using namespace std;

long long rec(vector<int>&arr,int index,long long sum1,long long sum2){

    if(index==arr.size()){
        return abs(sum1-sum2);
    }

    long long op1=rec(arr,index+1,sum1+arr[index],sum2);
    long long op2=rec(arr,index+1,sum1,sum2+arr[index]);

    return min(op1,op2);
}


int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n;
    cin>>n;

    vector<int>apples(n);
    for(int i=0;i<n;i++){
        cin>>apples[i];
    }

    cout<<rec(apples,0,0,0);


}




/*
#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;
    vector<int> w(n);
    for (int i = 0; i < n; i++) cin >> w[i];

    long long ans = LLONG_MAX;
    for (int mask = 0; mask < (1 << n); ++mask) {
        long long sum1 = 0;
        for (int i = 0; i < n; ++i) {
            if (mask & (1 << i)) sum1 += w[i];
        }
        long long sum2 = accumulate(w.begin(), w.end(), 0LL) - sum1;
        ans = min(ans, abs(sum1 - sum2));
    }
    cout << ans << "\n";
    return 0;
}


*/