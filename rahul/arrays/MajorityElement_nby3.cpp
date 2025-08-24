#include <bits/stdc++.h>
using namespace std;

//the voting algorithm
vector<int> majorityElement(vector<int>& a){
    int c1=0, c2=0, curr1=INT_MIN, curr2=INT_MAX;
    vector<int> ans;
    for(int i:a){
        if(c1==0&&i!=curr2){
            curr1=i;
            c1++;
        }
        else if(c2==0&&i!=curr1){
            curr2=i;
            c2++;
        }
        else if(i==curr1){
            c1++;
        }
        else if(i==curr2){
            c2++;
        }
        else{
            c1--;
            c2--;
        }
    }
    if(count(a.begin(), a.end(), curr1)>a.size()/3){
        ans.push_back(curr1);
    }
    if(count(a.begin(), a.end(), curr2)>a.size()/3){
        ans.push_back(curr2);
    }
    return ans;
}

int main(){
    vector<int> a={5,1,5,3,0,3,5,3,9,7,5,3,3,3,3,5,5,5};
    vector<int> b=majorityElement(a);
    for(int i:b){
        cout<<i<<" ";
    }

    return 0;
}