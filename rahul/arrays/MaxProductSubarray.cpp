#include <bits/stdc++.h>
using namespace std;

int maxProduct(vector<int>& a){
    int maxi=INT_MIN;
    int ngve=0, zro=0, pro=1;
    for(int i:a){
        pro*=i;
        if(i<0){
            ngve++;
        }
        if(i==0){
            zro++;
        }
    }
    if(ngve%2==0&&zro==0){
        return pro;
    }

    return maxi;
}

int main(){
    vector<int> a={-1,4,-4,5,-2,-1,-1,-2,-3};
    // vector<int> a={2,3,-2,4};
    // vector<int> a={-2,0,-1};

    cout<<maxProduct(a);

    return 0;
}