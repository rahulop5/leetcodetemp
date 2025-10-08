#include <bits/stdc++.h>
using namespace std;

bool checker(vector<int>& a, int threshold, int mid){
    vector<int> temp(a.size());
    int sum=0;
    for(int i=0;i<a.size();i++){
        temp[i]=a[i]/mid;
        if(a[i]%mid!=0){
            temp[i]++;
        }
        sum+=temp[i];
    }
    if(sum<=threshold){
        return true;
    }
    return false;
}

int smallestDivisor(vector<int>& a, int threshold)
{
    int ans=0, e=a[0];
    for(int i=0;i<a.size();i++){
        e=max(e, a[i]);
    }
    int s=1;
    int mid=(s+e)/2;
    while(s<=e){
        if(checker(a, threshold,  mid)){
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
    // vector<int> a={1,2,5,9};
    vector<int> a={44,22,33,11,1};
    int threshold = 5;
    cout<<smallestDivisor(a, threshold);

    return 0;
}