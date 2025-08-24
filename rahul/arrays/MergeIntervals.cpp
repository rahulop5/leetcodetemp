#include <bits/stdc++.h>
using namespace std;

void print2d(vector<vector<int>>& a){
    cout<<endl;
    for(vector<int> temp: a){
        for(int i: temp){
            cout<<i<<" ";
        }
        cout<<endl;
    }
}

vector<vector<int>> merge(vector<vector<int>>& a){
    sort(a.begin(), a.end());
    vector<vector<int>> ans;
    vector<int> b;
    ans.push_back(a[0]);
    int last=INT_MAX, maxi;
    for(vector<int> temp:a){
        if(temp[0]-last<=0){
            b=ans.back();
            ans.pop_back();
            maxi=max(temp[1], b[1]);
            ans.push_back({b[0], maxi});
            last=maxi;
        }
        else{
            ans.push_back(temp);
            last=temp[1];
        }
    }
    return ans;
}

int main(){
    // vector<vector<int>> a={{1,3},{8,10},{2,6},{15,18}};
    vector<vector<int>> a={{1,3},{8,10},{2,6},{4,8},{9,13},{14,16},{18,22}};
    sort(a.begin(), a.end());
    print2d(a);
    vector<vector<int>> ans=merge(a);
    cout<<endl<<endl;
    print2d(ans);

    return 0;
}