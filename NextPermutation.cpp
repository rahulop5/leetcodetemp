#include <bits/stdc++.h>
using namespace std;

void nextPermutation(vector<int>& a){
    int p,q;
    if(a.size()==1){
        cout<<"size 1";
        return;
    }
    p=a.size()-2;
    q=a.size()-1;
    //to find breaking point
    while(q!=0&&a[p]>=a[q]){
        p--;
        q--;
    }
    if(q==0){
        sort(a.begin(), a.end());
        return;
    }
    //to find second largest
    int max=q;
    for(int i=q;i<a.size();i++){
        if(a[i]>a[p]&&a[i]<a[max]){
            max=i;
        }
    }
    swap(a[max], a[p]);
    sort(a.begin()+q, a.end());
}

int main()
{
    vector<int> a={1,2,3,4};
    for(int j=0;j<25;j++){
        nextPermutation(a);
        cout<<endl;
        for(int i=0;i<a.size();i++){
            cout<<a[i]<<" ";
        }
    }
}