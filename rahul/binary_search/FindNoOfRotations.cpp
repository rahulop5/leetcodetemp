#include <bits/stdc++.h>
using namespace std;

int findKRotation(vector<int> &a){
    int s=0, e=a.size()-1;
    int mid=(s+e)/2;
    if(a[s]<=a[e]){
        return 0;
    }
    while(s<=e){
        if(mid+1<a.size()&&a[mid]>a[mid+1]){
            return mid+1;
        }
        if(a[mid]<a[0]){
            e=mid-1;
        }
        else{
            s=mid+1;
        }
        mid=(s+e)/2;
    }
    return 0;
}

int main(){
    vector<int> a={1, 2, 3, 4, 5};
    // vector<int> a={6, 9, 2, 4};
    cout<<findKRotation(a);

    return 0;
}