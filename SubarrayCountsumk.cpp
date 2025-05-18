#include <bits/stdc++.h>
using namespace std;

int subarraySum(vector<int>& nums, int k) {
    unordered_map<int, int> prefixSumCount;
    prefixSumCount[0] = 1; 
    int sum = 0, count = 0;
    for (int num : nums) {
        sum += num;
        if (prefixSumCount.find(sum - k) != prefixSumCount.end()) {
            count += prefixSumCount[sum - k];
        }
        prefixSumCount[sum]++;
    }
    return count;
}

void temp(){}

int main()
{
    vector<int> a={5,3,8,6,10,6,1};
    int k=17;
    cout<<subarraySum(a,k);

    return 0;
}