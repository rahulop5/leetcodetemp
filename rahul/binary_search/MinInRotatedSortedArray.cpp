#include <bits/stdc++.h>
using namespace std;

int findMin(vector<int>& a){
    int s=0, e=a.size()-1;
    int mid=(s+e)/2, ans=-1;
    if(a[s]<=a[e]){
        return a[s];
    }
    while(s<=e){
        if(mid+1<a.size()&&a[mid]>a[mid+1]){
            return a[mid+1];
        }
        if(a[mid]<a[0]){
            e=mid-1;
        }
        else{
            s=mid+1;
        }
        mid=(s+e)/2;
    }
    return -1;
}

int main(){
    vector<int> a={4,5,6,7,0,1,2};
    cout<<findMin(a);

    return 0;
}