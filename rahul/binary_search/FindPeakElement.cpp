#include <bits/stdc++.h>
using namespace std;

int findPeakElement(vector<int>& a){
    int s=0, e=a.size()-1;
    int mid=(s+e)/2;
    if(a[0]>a[1]){
        return 0;
    }
    if(a[e]>a[e-1]){
        return e;
    }
    while(s<=e){
        if(mid-1>=0&&mid+1<a.size()&&a[mid]>a[mid+1]&&a[mid]>a[mid-1]){
            return mid;
        }
        else if(mid-1>=0&&mid+1<a.size()&&a[mid]>a[mid-1]&&a[mid]<a[mid+1]){
            s=mid+1;
        }
        else if(mid-1>=0&&mid+1<a.size()&&a[mid]<a[mid-1]&&a[mid]>a[mid+1]){
            e=mid-1;
        }
        else{
            s++;
        }
        mid=(s+e)/2;
    }
    return -1;
}

int main(){
    // vector<int> a={1,2,3,1};
    vector<int> a={1,2,3,4,3,2};
    // vector<int> a={1,2,1,3,5,4};
    
    cout<<findPeakElement(a);

    return 0;
}