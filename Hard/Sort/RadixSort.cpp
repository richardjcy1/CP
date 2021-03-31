#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int INF = 0x3f3f3f3f;
const int mod = 1e9 + 7;

void countSort(vector<int>& arr, int n, int exp)
{
    vector<int> output(n);
    int i;
    vector<int> count(10);
    for (i = 0; i < n; i++) count[(arr[i] / exp) % 10]++;
    for (i = 1; i < 10; i++) count[i] += count[i - 1];
    for (i = n - 1; ~i; i--)
    {
        output[count[(arr[i] / exp) % 10] - 1] = arr[i];
        count[(arr[i] / exp) % 10]--;
    }
    for (i = 0; i < n; i++) arr[i] = output[i];
}

void radixSort(vector<int>& arr)
{
    int mx = *max_element(arr.begin(), arr.end());
    for (int exp = 1; mx / exp > 0; exp *= 10) countSort(arr, arr.size(), exp);
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    vector<int> arr{10,21,17,34,44,11,654,123};
    radixSort(arr);
    for (int i: arr) cout << i << " ";
    return 0;
}