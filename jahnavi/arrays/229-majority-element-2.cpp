#include <bits/stdc++.h>
using namespace std;

vector<int> majorityElement(vector<int>& nums) {
    int ele1 = 0;
    int ele2 = 0;
    int count1 = 0;
    int count2 = 0;

    for(int i = 0; i < nums.size(); i++){
        if(nums[i] == ele1){
            count1++;
        } else if (nums[i] == ele2){
            count2++;
        } else if(count1 == 0){
            ele1 = nums[i];
            count1++;
        } else if(count2 == 0){
            ele2 = nums[i];
            count2++;
        } else {
            count1--;
            count2--;
        }
    }

    vector<int> soln;
    count1 = 0;
    count2 = 0;
    for(int num : nums){
        if(num == ele1) count1++;
        else if(num == ele2) count2++;
    }

    int act = floor(nums.size() / 3);
    if(count1 > act) soln.push_back(ele1);
    if(count2 > act) soln.push_back(ele2);

    return soln;
}

void printVector(vector<int>& nums){
    if(nums.size() == 0) cout << "Empty";
    for(int num : nums){
        cout << num << " ";
    }
    return ;
}

int main(){
    vector<int> nums = {1, 2, 3};
    vector<int> soln = majorityElement(nums);
    printVector(soln);
}