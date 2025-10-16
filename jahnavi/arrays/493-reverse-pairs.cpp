#include <bits/stdc++.h>
using namespace std;

int merge(vector<int>& nums, int l, int mid, int r){
    int p = l;
    int q = mid + 1;
    int inv = 0;
    vector<int> temp;

    int i = l;
    int j = mid + 1;
    while(i <= mid){
        while(j <= r && nums[i] > 2LL * nums[j])  j++;
        inv += (j - mid - 1);
        i++;
    }

    while(p <= mid && q <= r){
        if(nums[p] <= nums[q]){
            temp.push_back(nums[p]);
            p++;
        } else {
            temp.push_back(nums[q]);
            q++;
        }
    }

    while(p<=mid) temp.push_back(nums[p++]);
    while(q<=r) temp.push_back(nums[q++]);

    for(int i = l; i <=r; i++){
        nums[i] = temp[i-l];
    }

    return inv;
}

int mergesort(vector<int>& nums, int l, int r){
    if(l>=r) return 0;
    int inv = 0;
    int mid = (l+r)/2;
    inv += mergesort(nums, l, mid);
    inv += mergesort(nums, mid+1, r);
    inv += merge(nums, l, mid, r);

    return inv;
}

int reversePairs(vector<int>& nums) {
    return mergesort(nums, 0, nums.size()-1);
}

int main(){
    vector<int> a={1,3,2,3,1};
    // vector<int> a={1,2,3,4,5};
    // vector<int> a = {-5, -5};
    // vector<int> a={2,4,3,5,1};

    int soln = reversePairs(a);
    cout << soln;
}
