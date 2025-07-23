#include <bits/stdc++.h>
using namespace std;

void print1d(vector<int> &a){
    cout<<endl;
    for(int i:a){
        cout<<i<<" ";
    }
}

void merge(vector<int> &a, int left, int mid, int right){
    vector<int> temp;
    int p=left, q=mid+1;
    while(p<=mid&&q<=right){
        if(a[p]<=a[q]){
            temp.push_back(a[p]);
            p++;
        }
        else{
            temp.push_back(a[q]);
            q++;
        }
    }
    while(p<=mid){
        temp.push_back(a[p++]);
    }
    while(q<=right){
        temp.push_back(a[q++]);
    }
    for(int i=0;i<temp.size();i++){
        a[i+left]=temp[i];
    }
}

void merge_sort(vector<int> &a, int left, int right){
    int mid=(left+right)/2;
    if(left==right){
        return;
    }
    merge_sort(a, left, mid);
    merge_sort(a, mid+1, right);
    merge(a, left, mid, right);
}

int main(){
    vector<int> a={3,1,2,4,1,5,6,2,4};
    merge_sort(a, 0, a.size()-1);
    print1d(a);

    return 0;
}