#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int INF = 0x3f3f3f3f;
const int mod = 1e9 + 7;

/*
find a value of a mysterious function closest to target (bit manipulation)
observation: a[i]&a[j]<=a[i] decrease
there are only at most j - i + 1oThe number of unique AND of a subarrays starting at any position will change by atmost LOG( A[i] ) times ( A[i] is first element of subarray) bit flips / different values from a[i] to a[j]
The AND's of subarrays starting at ith index can be calculated from AND's of subarrays starting at (i+1)th index

Time Complexity : O( n * log( max( arr[i] ) ) )
Similar concept can be applied to bitwise OR / GCD because they too are monotonic when applied on a sequence and
the values of cumulative bitwise OR / GCD changes atmost log( max( element) ) times

*/

class Solution {
public:
    int closestToTarget(vector<int>& arr, int target) {
        int n = arr.size();
        vector<set<int>> v(n);
        v[n - 1] = {arr[n - 1]};
        for (int i = n - 2; ~i; i--)
        {
            v[i].insert(arr[i]);
            for (auto& j: v[i + 1])
            {
                v[i].insert(j & arr[i]);
            }
        }
        int ans = INF;
        for (int i = 0; i < n; i++)
        {
            for (auto& j: v[i])
            {
                ans = min(ans, abs(target - j));
            }
        }
        return ans;
    }
};

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    vector<int> a{9,12,3,7,15};
    int target = 5;
    Solution sol;
    cout << sol.closestToTarget(a, target) << endl;
    return 0;
}