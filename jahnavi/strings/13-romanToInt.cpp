#include <bits/stdc++.h>
using namespace std;

int romanToInt(string s) {
    unordered_map<char, int> roman;
    roman['I'] = 1;
    roman['V'] = 5;
    roman['X'] = 10;
    roman['L'] = 50;
    roman['C'] = 100;
    roman['D'] = 500;
    roman['M'] = 1000;

    int soln = 0;
    int n = s.size();

    for(int i = 0; i < n - 1; i++){
        if(roman[s[i]] < roman[s[i+1]]) soln -= roman[s[i]];
        else soln += roman[s[i]];
    }

    soln += roman[s[n-1]];

    return soln;
}

int main(){
    string s = "MMMMM";
    int num = romanToInt(s);
    cout << num;
}