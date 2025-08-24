#include <bits/stdc++.h>
using namespace std;

int countt=0;

void merge(vector<int> &a, int left, int mid, int right){
    vector<int> temp;
    int p=left, q=mid+1;
    while(p<=mid&&q<=right){
        if(a[p]<=a[q]){
            temp.push_back(a[p]);
            p++;
        }
        else{
            countt+=(mid-p+1);
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

int inversionCount(vector<int> &a){
    merge_sort(a, 0, a.size()-1);
    return countt;
}

int main(){
    vector<int> a={2, 4, 1, 3, 5};
    cout<<inversionCount(a);

    return 0;
}