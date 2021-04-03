// Use a hashtable to store dx and dy
// and check if the number of points on a line
// Time complexity: O(n^2)
// Space complexity: O(n)
class Solution {
public:
    int maxPoints(vector<vector<int>>& a) {
        int n = a.size();
        int ans = 0;
        for (int i = 0; i < n; i++)
        {
            map<int, map<int, int>> mp;
            int overlap = 0;
            int tmp_max = 0;
            for (int j = i + 1; j < n; j++)
            {
                int dx = a[i][0] - a[j][0];
                int dy = a[i][1] - a[j][1];
                if (dx == 0 && dy == 0)
                {
                    ++overlap;
                    continue;
                }
                int g = __gcd(dx, dy);
                dx /= g;
                dy /= g;
                if (mp.find(dx) != mp.end())
                {
                    if (mp[dx].find(dy) != mp[dx].end())
                    {
                        mp[dx][dy]++;
                        tmp_max = max(tmp_max, mp[dx][dy]);
                    }
                    else
                    {
                        mp[dx][dy] = 1;
                        tmp_max = max(tmp_max, mp[dx][dy]);
                    }
                }
                else
                {
                    map<int, int> tmp;
                    tmp[dy] = 1;
                    mp[dx] = tmp;
                    tmp_max = max(tmp_max, mp[dx][dy]);
                }
            }
            ans = max(ans, 1 + tmp_max + overlap);
        }
        return ans;
    }
};