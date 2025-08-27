#include <bits/stdc++.h>
using namespace std;

//this is the correct one
bool checker(vector<int>& a, int h, int k){
    int hours=0;
    for(int i=0;i<a.size();i++){
        hours+=(a[i]/k);
        if(a[i]%k!=0){
            hours++;
        }
        if(hours>h){
            return false;
        }
    }
    return true;
}

//this checker iterates over hours(10^9) which is why u get tle 
bool checker2(vector<int>& a, int h, int k){
    int pending=0, j=0;
    for(int i=0;i<h;i++){
        if(j==a.size()){
            return true;
        }
        if(pending>0){
            pending-=k;
        }
        else{
            if(a[j]<=k){
                j++;
                continue;
            }
            else{
                pending=a[j++]-k;
            }
        }
    }
    if(j!=a.size()||pending>0){
        return false;
    }
    return true;
}

int minEatingSpeed(vector<int>& a, int h){
    int s=1, e=INT_MIN, ans=-1;
    for(int i:a){
        e=max(e, i);
    }
    int mid=(s+e)/2;
    while(s<=e){
        if(checker(a, h, mid)){
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
    vector<int> a={3,6,7,11};
    cout<<minEatingSpeed(a, 8);

    return 0;
}