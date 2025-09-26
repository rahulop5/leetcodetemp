#include <bits/stdc++.h>
using namespace std;

string removeOuterParentheses(string s){
    string ans="";
    stack<char> yo;
    int curr=0;
    for(int i=0;i<s.length();i++){
        if(s[i]=='('){
            yo.push('1');
        }
        else{
            yo.pop();
            if(yo.empty()){
                ans+=s.substr(curr+1, i-curr-1);
                curr=i+1;
            }
        }
    }
    return ans;
}

int main(){
    string s="(()())(())";
    // string s="( ( ) ( ) ) ( ( ) )";
    //           0 1 2 3 4 5 6 7 8 9
    string ans=removeOuterParentheses(s);
    for(char i:ans){
        cout<<i;
    }

    return 0;
}