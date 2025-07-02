#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> fourSum(vector<int>& a, int target)
{
    sort(a.begin(), a.end());
    int k, l, n=a.size();
    vector<vector<int>> sol;
    for(int i=0;i<n-3;i++){
        if(i>0&&a[i]==a[i-1]){
            continue;
        }
        for(int j=i+1;j<n-2;j++){
            if(j>i+1&&a[j]==a[j-1]){
                continue;
            }
            k=j+1; l=n-1;
            while(l>k){
                long long sum=a[i];
                sum+=a[j];
                sum+=a[k];
                sum+=a[l];
                if(sum==target){
                    sol.push_back({a[i], a[j], a[k++], a[l--]});
                    while(l>k&&a[k]==a[k-1]){
                        k++;
                    }
                    while(l>k&&a[l]==a[l+1]){
                        l--;
                    }
                }
                else if(sum>target){
                    l--;
                }
                else{
                    k++;
                }
            }
        }
    }
    return sol;
}

int main()
{
    vector<int> a={1,0,-1,0,-2,2};
    int target=0;
    vector<vector<int>> sol=fourSum(a, target);
    for(vector<int> temp: sol){
        for(int i:temp){
            cout<<i<<" ";
        }
        cout<<endl;
    }

    return 0;
}