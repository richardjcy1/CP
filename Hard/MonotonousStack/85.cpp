class Solution {
public:
    int largestRectangleArea(vector<int>& h) {
        int n = h.size();
        if (n == 0) return 0;
        vector<int> left(n, -1), right(n, n);
        stack<int> S;
        S.push(0);
        for (int i = 1; i < n; i++)
        {
            while (!S.empty() && h[S.top()] >= h[i]) S.pop();
            if (!S.empty()) left[i] = S.top();
            S.push(i);
        }
        S = {};
        S.push(n - 1);
        for (int i = n - 2; ~i; i--)
        {
            while (!S.empty() && h[S.top()] >= h[i]) S.pop();
            if (!S.empty()) right[i] = S.top();
            S.push(i);
        }
        int ans = 0;
        for (int i = 0; i < n; i++)
        {
            ans = max(ans, h[i] * (right[i] - left[i] - 1));
        }
        return ans;
    }
    
    int maximalRectangle(vector<vector<char>>& matrix) {
        if (matrix.size() == 0 || matrix[0].size() == 0) return 0;
        int m = matrix.size(), n = matrix[0].size();
        vector<int> h(n);
        int ans = 0;
        // find maximal histogram for each row
        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (matrix[i][j] == '0') h[j] = 0;
                else h[j]++;
            }
            ans = max(ans, largestRectangleArea(h));
        }
        return ans;
    }
};