using ll = long long;

// use three multiset to represent three parts: lower, mid, and upper
// insert element: compare cur with max in lower, min in upper
// erase element: find in either lower, mid, or upper
// then balance lower and upper to exactly k elements
// keep track of mid sum
class MKAverage {
public:
    int m, k;
    multiset<int> lower, mid, upper;
    queue<int> q;
    ll sum = 0;
    
    MKAverage(int m, int k) {
        this->m = m;
        this->k = k;
    }
    
    void shiftLeft(multiset<int>& left, multiset<int>& right)
    {
        left.insert(*right.begin());
        right.erase(right.begin());
    }
    
    void shiftRight(multiset<int>& left, multiset<int>& right)
    {
        right.insert(*left.rbegin());
        left.erase(--left.end());
    }
    
    void addElement(int num) {
        q.push(num);
        if (lower.size() && num <= *lower.rbegin()) lower.insert(num);
        else if (upper.size() && num >= *upper.begin()) upper.insert(num);
        else mid.insert(num), sum += num;
        
        while (lower.size() > k) sum += *lower.rbegin(), shiftRight(lower, mid);
        while (upper.size() > k) sum += *upper.begin(), shiftLeft(mid, upper);
        
        if (q.size() > m)
        {
            int d = q.front(); q.pop();
            if (lower.find(d) != lower.end()) lower.erase(lower.find(d));
            else if (mid.find(d) != mid.end()) mid.erase(mid.find(d)), sum -= d;
            else if (upper.find(d) != upper.end()) upper.erase(upper.find(d));
        }
        if (q.size() >= m)
        {
            while (lower.size() < k) sum -= *mid.begin(), shiftLeft(lower, mid);
            while (upper.size() < k) sum -= *mid.rbegin(), shiftRight(mid, upper);
        }
    }
    
    int calculateMKAverage() {
        if (q.size() < m) return -1;
        return sum / (m - 2 * k);
    }
};

/**
 * Your MKAverage object will be instantiated and called as such:
 * MKAverage* obj = new MKAverage(m, k);
 * obj->addElement(num);
 * int param_2 = obj->calculateMKAverage();
 */