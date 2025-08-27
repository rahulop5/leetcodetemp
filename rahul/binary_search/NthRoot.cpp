#include <bits/stdc++.h>
using namespace std;

//nlogm
int nthRoot(int n, int m){
    int temp=1;
    int s=0, e=m;
    int mid=(s+e)/2;
    while(s<=e){
        for(int i=0;i<n;i++){
            temp=temp*mid;
        }
        if(temp==m){
            return mid;
        }
        if(temp>m){
            e=mid-1;
        }
        else{
            s=mid+1;
        }
        temp=1;
        mid=(s+e)/2;
    }
    return -1;
}

int main(){
    cout<<nthRoot(3, 28);
    
    return 0;
}