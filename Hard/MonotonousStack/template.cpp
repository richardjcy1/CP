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