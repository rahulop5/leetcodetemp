#include <bits/stdc++.h>
using namespace std;

int countt = 0;

void print1d(vector<int> &a)
{
    cout << endl;
    for (int i : a)
    {
        cout << i << " ";
    }
}

void merge(vector<int> &a, int left, int mid, int right)
{
    int j = mid + 1;
    for (int i = left; i <= mid; i++)
    {
        while (j <= right && (long long)a[i] > (long long)2 * a[j])
        {
            j++;
        }
        countt += (j - (mid + 1));
    }
    vector<int> temp;
    int p = left, q = mid + 1;
    while (p <= mid && q <= right)
    {
        if (a[p] <= a[q])
        {
            temp.push_back(a[p]);
            p++;
        }
        else
        {
            temp.push_back(a[q]);
            q++;
        }
    }
    while (p <= mid)
    {
        temp.push_back(a[p++]);
    }
    while (q <= right)
    {
        temp.push_back(a[q++]);
    }
    for (int i = 0; i < temp.size(); i++)
    {
        a[i + left] = temp[i];
    }
}

void merge_sort(vector<int> &a, int left, int right)
{
    int mid = (left + right) / 2;
    if (left == right)
    {
        return;
    }
    merge_sort(a, left, mid);
    merge_sort(a, mid + 1, right);
    merge(a, left, mid, right);
}

int reversePairs(vector<int> &a)
{
    merge_sort(a, 0, a.size() - 1);
    return countt;
}

int main()
{
    // vector<int> a={1,3,2,3,1};
    // vector<int> a={1,2,3,4,5};
    vector<int> a = {-5, -5};
    // vector<int> a={2,4,3,5,1};
    cout << endl;
    cout << "Answer " << reversePairs(a);
    cout << endl;
    print1d(a);

    return 0;
}