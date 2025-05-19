#include <bits/stdc++.h>
using namespace std;

vector<int> twoSum(vector<int>& a, int target) {
    vector<int> temp(2);
    unordered_map<int, int> hash;
    for(int i=0;i<a.size();i++){
        if(hash.find(a[i])!=hash.end()){
            temp[0]=i;
            temp[1]=hash.find(a[i])->second;
        }
        hash.insert({target-a[i], i});
    }

    return temp;
}

int main()
{
    vector<int> a={2,7,11,15};
    int target=9;
    vector<int> sol=twoSum(a, target);
    cout<<sol[0]<<" "<<sol[1]<<endl; 

    return 0;
}