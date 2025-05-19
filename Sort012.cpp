#include <bits/stdc++.h>
using namespace std;

void sortColors(vector<int>& a)
{
    int p=0, q=0;
    while(q<a.size()){
        if(a[q]!=0){
            q++;
            continue;
        }
        swap(a[p++], a[q++]);
    }
    int temp=p; p=a.size()-1; q=a.size()-1;
    while(q>=temp){
        if(a[q]!=2){
            q--;
            continue;
        }
        swap(a[p--], a[q--]);
    }
}

int main()
{
    vector<int> nums = {2,0,2,1,1,0};
    sortColors(nums);
    for(int i:nums){
        cout<<i<<" ";
    }

    return 0;
}