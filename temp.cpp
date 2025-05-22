#include <bits/stdc++.h>
using namespace std;

//this is like the brute force code if u take an array
//i would suggest using a heap as its only logn for retrieval and insertion
vector<vector<int>> findmax(vector<vector<int>>& a)
{
    vector<vector<int>> answer;
    vector<int> sol;
    int max1=INT_MIN, max2=INT_MIN, tsum=0, i;
    for(vector<int> temp: a){
        for(i=0;i<temp.size();i++){
            tsum+=temp[i];
        }
        if(tsum>max1){
            max1=tsum;
            sol=temp;
        }
        tsum=0;
    }
    answer.push_back(sol);
    for(vector<int> temp: a){
        for(i=0;i<temp.size();i++){
            tsum+=temp[i];
        }
        if(tsum>max2&&temp!=answer[0]){
            max2=tsum;
            sol=temp;
        }
        tsum=0;
    }
    answer.push_back(sol);
    return answer;
    
}

int main()
{
    vector<vector<int>> a={{1,2,3}, {6,4,3}, {9,1,0}, {9,9,9}};
    vector<vector<int>> sol=findmax(a);
    for(vector<int> temp:sol){
        for(int i:temp){
            cout<<i<<" ";
        }
        cout<<endl;
    }

    return 0;
}