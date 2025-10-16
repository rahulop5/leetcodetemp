#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> generate(int numRows) {
    vector<vector<int>> soln;
    for (int i = 0; i < numRows; i++) {
        vector<int> temp(i + 1);
        for (int j = 0; j < temp.size(); j++) {
            if (j == 0 || j == i)
                temp[j] = 1;
            else
                temp[j] = soln[i - 1][j - 1] + soln[i - 1][j];
        }
        soln.push_back(temp);
    }
    return soln;
}

int main() {
    int numRows;
    cout << "Enter the number of rows for Pascal's Triangle: ";
    cin >> numRows;

    vector<vector<int>> result = generate(numRows);

    cout << "Pascal's Triangle (" << numRows << " rows):" << endl;
    for (const auto &row : result) {
        for (int val : row) {
            cout << val << " ";
        }
        cout << endl;
    }

    return 0;
}
