#include <bits/stdc++.h>
using namespace std;

int maxLength(vector<int>& arr) {
    unordered_map<int, int> prefixes;
    int soln = 0;
    int sum = 0;
    
    for(int i = 0; i < arr.size(); i++){
        sum = sum + arr[i];
        
        if(sum == 0) soln = i + 1;
        
        if(prefixes.find(sum) != prefixes.end()){
            soln = max(soln, i - prefixes[sum]);
        } else {
            prefixes[sum] = i;
        }
    }
    return soln;
}

int main(){
    vector<int> nums = {0, 0, 0};
    int soln = maxLength(nums);
    cout << soln << endl;
}