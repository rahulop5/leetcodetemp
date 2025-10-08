#include <bits/stdc++.h>
using namespace std;

string reverseWords(string s){
    string ans="";
    int we=-1, ws=s.length()-1;
    while(ws>=0){
        if(s[ws]!=' '){
            if(we!=-1){
                ans+=' ';
            }
            we=ws;
            while(ws>=0&&s[ws]!=' '){
                ws--;
            }
            ans+=s.substr(ws+1, we-ws);
        }
        ws--;
    }
    return ans;
}

int main(){
    // string s="  the sky   is blue  ";
    string s="the sky is blue";
    string ans=reverseWords(s);
    for(char i:ans){
        cout<<i;
    }

    return 0;
}