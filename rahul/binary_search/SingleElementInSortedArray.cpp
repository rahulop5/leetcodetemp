#include <bits/stdc++.h>
using namespace std;

int singleNonDuplicate(vector<int>& a){
    int s=0, e=a.size()-1;
    int mid=(s+e)/2;
    if(a.size()==1){
        return a[0];
    }
    while(s<=e){
        if(mid==0&&a[mid]!=a[mid+1]){
            return a[mid];
        }
        if(mid==a.size()-1&&a[mid]!=a[mid-1]){
            return a[mid];
        }
        if(mid+1<a.size()&&mid-1>=0&&a[mid]!=a[mid-1]&&a[mid]!=a[mid+1]){
            return a[mid];
        }
        if(mid-1>=0&&a[mid]==a[mid-1]){
            if(mid%2==0){
                e=mid-1;
            }
            else{
                s=mid+1;
            }
        }
        else{
            if(mid%2==0){
                s=mid+1;
            }
            else{
                e=mid-1;
            }
        }
        mid=(s+e)/2;
    }
    return -1;
}

int main(){
    vector<int> a={1,1,2};
    // vector<int> a={1,1,2,3,3,4,4,8,8};
    cout<<singleNonDuplicate(a);

    return 0;
}