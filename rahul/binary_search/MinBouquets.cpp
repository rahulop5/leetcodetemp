#include <bits/stdc++.h>
using namespace std;

bool checker(vector<int>& a, int m, int k, int mid){
    
}

int minDays(vector<int>& a, int m, int k){
    int s=0, e=INT_MIN, ans=-1;
    for(int i:a){
        e=max(e, i);
    }
    int mid=(s+e)/2;
    while(s<=e){
        if(checker(a, m, k, mid)){
            ans=mid;
            e=mid-1;
        }
        else{
            s=mid+1;
        }
        mid=(s+e)/2;
    }

    return ans;
}

int main(){
    vector<int> a={1,10,3,10,2};
    int m=3, k=1;
    cout<<minDays(a, m, k);

    return 0;
}