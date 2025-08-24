#include <bits/stdc++.h>
using namespace std;

//this is the sol i came up with but if its submitted on leetcode it says memorylimit exceeded but its totally correct
vector<vector<int>> threeSum2(vector<int>& a)
{
    vector<vector<int>> sol;
    unordered_map<int, int> hashh;
    for(int i=0;i<a.size();i++){
        hashh.insert({a[i], i});
    }
    int tsum=0;
    for(int i=0;i<a.size();i++){
        tsum-=a[i];
        for(int j=0;j<a.size();j++){
            if(j==i){
                continue;
            }
            if(hashh.find(tsum-a[j])!=hashh.end()&&hashh.at(tsum-a[j])!=i&&hashh.at(tsum-a[j])!=j){
                sol.push_back({a[i], a[j], tsum-a[j]});
            }
        }
        tsum=0;
    }
    set<vector<int>> uniqueRows;
    for (auto row : sol) {
        sort(row.begin(), row.end());  
        uniqueRows.insert(row);        
    }
    vector<vector<int>> result(uniqueRows.begin(), uniqueRows.end());

    return result;
}

//this is the correct one it seems ok acceptable
vector<vector<int>> threeSum(vector<int>& a)
{
    vector<vector<int>> sol;
    sort(a.begin(), a.end());
    int j, k;
    for(int i=0;i<a.size();i++){
        j=i+1; k=a.size()-1;
        while(k>j){
            if(a[i]+a[j]+a[k]==0){
                sol.push_back({a[i], a[j++], a[k--]});
                while(a[j]==a[j-1]&&j<k){
                    j++;
                }
                while(a[k]==a[k+1]&&k>j){
                    k--;
                }
            }
            else if(a[i]+a[j]+a[k]>0){
                k--;
            }
            else{
                j++;
            }
        }
        while(i+1<a.size()&&a[i]==a[i+1]){
            i++;
        }
    }
    return sol;
}

int main()
{
    vector<int> a={-1,0,1,2,-1,-4};
    vector<vector<int>> sol=threeSum(a);
    for(vector<int> temp: sol){
        for(int i:temp){
            cout<<i<<" ";
        }
        cout<<endl;
    }

    return 0;
}