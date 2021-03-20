/* Math, Interval (sorting) problem
思路：
本题首先不能用暴力解，从1开始每个值check是否能构成，必定TLE
然后考虑要是连续的整数都能构成，只需要考虑base 1,2,4,8...
但是最后问题又回到了暴力解，也不行。
从数学的角度出发，如果[0,x]都OK，那么对于y满足y-1<=x,[y,y+x]之间的
所有整数也都ok，自然先排序然后逐步构造原问题的解。当出现空缺时，即y-1>x,说明不能再继续了，跳出循环即可。
Time complexity: O(nlogn)
Space complexity: O(1)
*/
class Solution {
public:
    int getMaximumConsecutive(vector<int>& a) {
        int n = a.size();
        sort(a.begin(), a.end());
        int x = 0;
        for (int i = 0; i < n; i++)
        {
            if (x + 1 < a[i]) break;
            x += a[i];
        }
        return x + 1;
    }
};