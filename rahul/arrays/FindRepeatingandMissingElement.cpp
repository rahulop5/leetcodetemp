#include <bits/stdc++.h>
using namespace std;

// setmismatch in leetcode

// basic maths
vector<int> findErrorNums(vector<int> &a)
{
    int n = a.size();
    int sum = (n * (n + 1)) / 2, sum2 = (n * (n + 1) * (2 * n + 1)) / 6;
    vector<int> ans;
    for (int i : a)
    {
        sum -= i;
        sum2 -= (i * i);
    }
    int yplusx = sum2 / sum;
    int y = (yplusx + sum) / 2;
    int x = y - sum;
    ans.push_back(x);
    ans.push_back(y);

    return ans;
}

// my fav approach
vector<int> findErrorNums2(vector<int> &a)
{
    int n = a.size();
    int xorr;
    vector<int> ans;
    switch (n % 4)
    {
    case 0:
        xorr = n;
        break;
    case 1:
        xorr = 1;
        break;
    case 2:
        xorr = n + 1;
        break;
    case 3:
        xorr = 0;
        break;
    }
    for (int i : a)
    {
        xorr= xorr^i;
    }
    int bit=1;
    while (bit <= INT_MAX){
        if((xorr&bit)==bit){
            break;
        }
        bit=bit<<1;
    }
    int grp0xor=0, grp1xor=0;
    for(int i=0;i<n;i++){
        if((a[i]&bit)==bit){
            grp1xor=grp1xor^a[i];
        }
        else{
            grp0xor=grp0xor^a[i];
        }
        if(((i+1)&bit)==bit){
            grp1xor=grp1xor^(i+1);
        }
        else{
            grp0xor=grp0xor^(i+1);
        }
    }
    ans.push_back(grp1xor);
    ans.push_back(grp0xor);

    return ans;
}

int main()
{
    vector<int> a = {1, 2, 4, 3, 3};
    vector<int> aa = findErrorNums2(a);
    for(int i:aa){
        cout<<i<<" ";
    }
    

    return 0;
}