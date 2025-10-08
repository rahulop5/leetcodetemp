#include <bits/stdc++.h>
using namespace std;

bool checker(vector<int> &a, int k, int mid)
{
    int curr=0, j=0;
    for(int i=0;i<k;i++){
        while(j<a.size()&&curr+a[j]<=mid){
            curr+=a[j++];
        }
        if(j>=a.size()){
            return true;
        }
        curr=0;
        if(a[j]>mid){
            return false;
        }
    }
    if(j<a.size()){
        return false;
    }
    return true;
}

int findLargestMinDistance(vector<int> &a, int k)
{
    int ans=-1, e=0;
    for(int i=0;i<a.size();i++){
        e+=a[i];
    }
    int s=a[0];
    int mid=(s+e)/2;
    while(s<=e){
        if(checker(a, k, mid)){
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
    vector<int> a={2, 1, 5, 6, 2, 3}; int k = 2;
    cout<<findLargestMinDistance(a, k);

    return 0;
}