#include <bits/stdc++.h>
using namespace std;

//there in gfg
void printmap(unordered_map<int, int>& a){
    for (const auto& pair : a) {
        cout << pair.first << " : " << pair.second << endl;
    }
}

int maxLen(vector<int>& a){
    int maxi=0, sum=0;
    unordered_map<int, int> temp;
    for(int i=0;i<a.size();i++){
        sum+=a[i];
        temp[0]=-1;
        if(temp.count(-sum)==1){
            maxi=max(maxi, i-temp[-sum]);
        }
        else{
            temp[-sum]=i;
        }
        // cout<<i<<" sum: "<<sum<<endl;
        // printmap(temp);
        // cout<<endl<<endl;
    }
    return maxi;
}

int main(){
    vector<int> a={-31,-48,-90,54,20,95,6,-86,22};
    // vector<int> a={15,10,23,-2,2,-8,1,7};
    cout<<endl<<maxLen(a);

    return 0;
}