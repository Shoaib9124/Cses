#include <bits/stdc++.h>
using namespace std;

long long ans=0;


void rec(vector<string>&board,vector<bool>&leftRow,vector<bool>&upperD,vector<bool>&lowerD,int col){

    if(col==8){
        ans++;
        return;
    }

    for(int row=0;row<8;row++){

        if(board[row][col]=='.' && !leftRow[row] && !upperD[row-col+8-1] && !lowerD[row+col]){

            board[row][col]='Q';
            leftRow[row]=true;
            upperD[row-col+7]=true;
            lowerD[row+col]=true;
            
            rec(board,leftRow,upperD,lowerD,col+1);
            
            board[row][col]='.';
            leftRow[row]=false;
            upperD[row-col+7]=false;
            lowerD[row+col]=false;

        }

    }

}



int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    vector<string>board(8);

    for(int i=0;i<8;i++){
        cin>>board[i];
    }
    //have to place 8 queens

    vector<bool>leftRow(8,false),upperD(2*8-1,false),lowerD(2*8-1,false);

    rec(board,leftRow,upperD,lowerD,0);

    cout<<ans;

    return 0;
}

//diagonals are usually defined by some of coodinates or difference of coodinates