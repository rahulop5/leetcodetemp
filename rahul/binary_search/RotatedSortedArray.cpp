#include <bits/stdc++.h>
using namespace std;

//nice approach
int search(vector<int>& a, int target){
    int s=0, e=a.size()-1;
    int mid=(s+e)/2;
    while(s<=e){
        if(a[mid]==target){
            return mid;
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
    return -1;
}

//ep approach
int search2(vector<int>& a, int target) {
    int s=0, e=a.size()-1, mid=(s+e)/2;
    int k=e;
    if(s==e){
        if(a[0]==target){
            return 0;
        }
        return -1;
    }   
    while(s<=e){
        if(mid+1<a.size()&&a[mid]>a[mid+1]){
            k=mid;
            break;
        }
        else if(a[mid]<a[0]){
            e=mid-1;
        }
        else{
            s=mid+1;
        }
        mid=(s+e)/2;
    }
    if(target>=a[0]){
        s=0, e=k;
    }
    else{
        s=k+1, e=a.size()-1;
    }
    mid=(s+e)/2;
    while(s<=e){
        if(a[mid]==target){
            return mid;
        }
        else if(a[mid]>target){
            e=mid-1;
        }
        else{
            s=mid+1;
        }
        mid=(s+e)/2;
    }
    return -1;
}

int main(){
    vector<int> a={1,2};
    // vector<int> a={7,0};
    // vector<int> a={4,5,6,7,0,1,2};
    int target=1;
    cout<<search(a, target);

    return 0;
}