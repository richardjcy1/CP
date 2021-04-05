class Solution {
public:
    int g = 0, l = 0;
    
    void mergeSort(vector<int>& a, int left, int right)
    {
        if (left >= right) return;
        int mid = left + (right - left) / 2;
        mergeSort(a, left, mid);
        mergeSort(a, mid + 1, right);
        merge(a, left, mid, right);
    }
    
    void merge(vector<int>& a, int left, int mid, int right)
    {
        if (left >= right) return;
        vector<int> ans(right - left + 1);
        int i = left, j = mid + 1, k = 0;
        while (i <= mid && j <= right)
        {
            if (a[i] <= a[j])
            {
                ans[k++] = a[i++];
            }
            else
            {
                g += (mid - i + 1);
                ans[k++] = a[j++];
            }
        }
        while (i <= mid) ans[k++] = a[i++];
        while (j <= right) ans[k++] = a[j++];
        for (int i = 0; i < ans.size(); i++)
        {
            a[i + left] = ans[i];
        }
    }
    
    bool isIdealPermutation(vector<int>& a) {
        int n = a.size();
        vector<int> b = a;
        mergeSort(b, 0, n - 1);
        for (int i = 0; i < n - 1; i++)
        {
            if (a[i] > a[i + 1]) ++l;
        }
        return g == l;
    }
};