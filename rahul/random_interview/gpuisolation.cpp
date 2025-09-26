#include <bits/stdc++.h>
using namespace std;

//k is switchcount
int findMinIsolation(string s, int k){
    priority_queue<int> store;
    char prev=s[0];
    int count=0;
    for(int i=0;i<s.length();i++){
        if(s[i]==prev){
            count++;
        }
        else{
            store.push(count);
            count=1;
            prev=s[i];
        }
    }
    store.push(count);
    int temp;
    for(int i=0;i<k;i++){
        temp=store.top();
        store.pop();
        store.push(temp/2);
        if(temp%2==0){
            store.push(temp/2-1);
        }
        else{
            store.push(temp/2);
        }
    }
    return store.top();
}

int main(){
    string s="aabbbaaaa";
    cout<<findMinIsolation(s, 2);

    return 0;
}