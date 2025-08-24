#include <bits/stdc++.h>
using namespace std;

//did this using ring wise changing of elements
//bet no one did it like this
void rotate(vector<vector<int>>& a)
{
    int n=a[0].size()-1;
    int nx, ny, x, y, temp, ntemp;
    for(int i=0;i<a[0].size()/2;i++){
        for(int j=i;j<a[0].size()-i-1;j++){
            x=i; y=j; temp=a[x][y];
            for(int k=0;k<4;k++){
                nx=y; ny=n-x;
                ntemp=a[nx][ny];
                a[nx][ny]=temp;
                temp=ntemp;
                x=nx; y=ny;
            }
        }
    }
}

int main()
{
    // vector<vector<int>> a={{1,2,3,4,5},{6,7,8,9,10},{11,12,13,14,15},{16,17,18,19,20},{21,22,23,24,25}};
    // vector<vector<int>> a={{1,2},{3,4}};
    vector<vector<int>> a={{1,2,3,4},{5,6,7,8},{9,10,11,12},{13,14,15,16}};

    rotate(a);
    for(vector<int> temp:a){
        for(int i:temp){
            cout<<i<<" ";
        }
        cout<<endl;
    }

    return 0;
}