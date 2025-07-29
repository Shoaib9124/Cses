#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);


    int n;
    cin>>n;

    vector<vector<int>>grid(n,vector<int>(n));
    //does not appear on left or above

    for(int row=0;row<n;row++){
        for(int col=0;col<n;col++){

            unordered_set<int>s;
            for(int r=0;r<row;r++){
                s.insert(grid[r][col]);
            }
            for(int c=0;c<col;c++){
                s.insert(grid[row][c]);
            }

            for(int val=0;val<=2*n;val++){
                if(s.find(val)==s.end()){
                    grid[row][col]=val;
                    break;
                }
            }

        }
    }    

    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cout<<grid[i][j]<<" ";
        }
        cout<<"\n";
    }


    return 0;
}


/*
i \ j	0	    1	    2	    3
0	    0^0=0	0^1=1	0^2=2	0^3=3
1	    1^0=1	1^1=0	1^2=3	1^3=2
2	    2^0=2	2^1=3	2^2=0	2^3=1
3	    3^0=3	3^1=2	3^2=1	3^3=0

#include <iostream>

int main() {
    // Faster I/O
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    int n;
    std::cin >> n;

    // Generate the grid using the XOR pattern
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            // Print the value followed by a space (or not if it's the last element)
            std::cout << (i ^ j);
        }
        std::cout << "\n";
    }

    return 0;
}








*/