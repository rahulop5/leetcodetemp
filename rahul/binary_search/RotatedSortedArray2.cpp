#include <bits/stdc++.h>
using namespace std;

//works but its not O(log n)
bool search(vector<int>& a, int target){
    int s=0, e=a.size()-1;
    int mid=(s+e)/2;
    while(s<=e){
        if(a[mid]==target){
            return true;
        }
        if(a[s]==a[mid]&&a[mid]==a[e]){
            s++; e--;
            continue;
        }
        //left sorted
        if(a[s]<=a[mid]){
            if(target>=a[s]&&target<a[mid]){
                e=mid-1;
            }
            else{
                s=mid+1;
            }
        }
        //right sorted
        else{
            if(target>a[mid]&&target<=a[e]){
                s=mid+1;
            }
            else{
                e=mid-1;
            }
        }
        mid=(s+e)/2;
    }
    return false;
}

//doesnt work

int main(){
    vector<int> a={1,1,1,1,1,1,1,1,1,1,1,1,1,2,1,1,1,1,1};
    int target=2;
    cout<<search(a, target);

    return 0;
}