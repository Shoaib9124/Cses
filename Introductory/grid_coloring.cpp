#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int r;
    int c;
    cin>>r>>c;

    vector<string>grid(r);

    for(string &k:grid){
        cin>>k;
    }

    for(int i=0;i<r;i++){

        for(int j=0;j<c;j++){

            set<char>s;
            if(i!=0) s.insert(grid[i-1][j]);
            if(j!=0) s.insert(grid[i][j-1]);
            s.insert(grid[i][j]);

            for(char val='A';val<='D';val++){
                if(!s.count(val)){
                    grid[i][j]=val;
                    break;
                }
            }
        }
        cout<<grid[i]<<'\n';
    }

    

    return 0;
}