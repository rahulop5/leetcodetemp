#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> generate(int numRows){
    vector<vector<int>> a;
    vector<int> temp;
    vector<int> prev;
    for(int i=0;i<numRows;i++){
        for(int j=0;j<=i;j++){
            if(j==0||j==i){
                temp.push_back(1);
                continue;
            }
            temp.push_back(prev[j]+prev[j-1]);
        }
        a.push_back(temp);
        prev=temp;
        temp={};
    }
    return a;
}

int main(){
    vector<vector<int>> a;
    int num=10;
    a=generate(num);
    for(vector<int> i: a){
        for(int j:i){
            cout<<j<<" ";
        }
        cout<<endl;
    }

    return 0;
}