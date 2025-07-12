#include <bits/stdc++.h>
using namespace std;

long subarrayXor(vector<int> &a, int k){
    long xorr=0;
    int count=0;
    unordered_map<int, int> temp;
    temp[0]=1;
    for(int i=0;i<a.size();i++){
        xorr=xorr^a[i];
        count+=temp[k^xorr];
        temp[xorr]++;
    }
    return count;
}

int main(){
    // vector<int> a={1,1,1,1};
    vector<int> a={5,6,7,8,9};
    // vector<int> a={4, 2, 2, 6, 4};
    int k=6;
    cout<<subarrayXor(a, k);

    return 0;
}