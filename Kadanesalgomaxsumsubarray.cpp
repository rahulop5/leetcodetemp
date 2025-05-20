#include <bits/stdc++.h>
using namespace std;

int maxSubArray(vector<int>& a)
{
    int sum=0, maxi=a[0];
    for(int i=0;i<a.size();i++){
        sum+=a[i];
        maxi=max(sum, maxi);
        if(sum<0){
            sum=0;
        }
    }
    return maxi;
}

int main()
{
    vector<int> a={-2,1,-3,4,-1,2,1,-5,4};
    cout<<maxSubArray(a);

    return 0;
}