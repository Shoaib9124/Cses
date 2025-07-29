#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    string s;
    cin>>s;

    map<char,int>freq;

    for(char ch:s){
        freq[ch]++;
    }
    int oddCount=0;
    char oddChar='.';

    for (auto& [ch,count] : freq) {
        if (count & 1) {
            oddCount++;
            oddChar = ch;
        }
    }

    if (oddCount > 1) {
        cout << "NO SOLUTION" << endl;
        return 0;
    }

    string left="";
    string right="";

    for(auto &[ch,count]:freq){

        string temp(count/2,ch);
        left+=temp;
        right=temp+right;
    }

    if(oddCount==1){
        string middle(1,oddChar);
        cout<<left+middle+right;
    }
    else{
        cout<<left+right;
    }


    return 0;
}