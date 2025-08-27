#include <bits/stdc++.h>
using namespace std;

int mySqrt(int x){
    int ans;
    if(x==1){
        return 1;
    }
    int s=0, e=x/2;
    long long mid=(s+e)/2;
    while(s<=e){
        if(mid*mid==x){
            return mid;
        }
        if(mid*mid>x){
            e=mid-1;
        }
        else if(mid*mid<x){
            ans=mid;
            s=mid+1;
        }
        mid=(s+e)/2;
    }
    return ans;
}

int main(){
    cout<<mySqrt(8);

    return 0;
}