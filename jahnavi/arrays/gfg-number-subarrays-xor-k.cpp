#include <bits/stdc++.h>
using namespace std;

long subarrayXor(vector<int> &arr, int k) {
    // code here
    unordered_map<int, int> map;
    map[0] = 1;
    int sum = 0;
    int temp = 0;
    int soln = 0;
    for(int i = 0; i < arr.size(); i++){
        temp = 0;
        sum = sum ^ arr[i];
        temp = sum ^ k;
        if(map.find(temp) != map.end()){
            soln = soln + map[temp]; 
        }
        map[sum]++;
    }
    return soln;
}

int main(){
    vector<int> arr = {4, 2, 2, 6 ,4};
    int k = 6;
    long soln = subarrayXor(arr, k);
    cout << soln;
}
