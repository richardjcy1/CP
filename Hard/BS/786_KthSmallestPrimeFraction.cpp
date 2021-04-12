class Solution {
public:
    vector<int> a;
    int n;
    
    vector<int> check(double x)
    {
        int numer = 0, denom = 1, count = 0, i = -1;
        for (int j = 1; j < n; j++)
        {
            while (a[i + 1] < a[j] * x) ++i;
            count += i + 1;
            if (i >= 0 && numer * a[j] < denom * a[i])
            {
                numer = a[i];
                denom = a[j];
            }
        }
        return {count, numer, denom};
    }
    
    vector<int> kthSmallestPrimeFraction(vector<int>& arr, int k) {
        a = arr;
        n = arr.size();
        double left = 0.0, right = 1.0;
        vector<int> ans{0, 1};
        while (right - left > 1e-9)
        {
            double mid = (left + right) / 2;
            vector<int> tmp = check(mid);
            if (tmp[0] < k) left = mid;
            else
            {
                ans[0] = tmp[1];
                ans[1] = tmp[2];
                right = mid;
            }
        }
        return ans;
    }
};