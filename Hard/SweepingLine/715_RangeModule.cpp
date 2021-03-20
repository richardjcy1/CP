class RangeModule {
public:
    set<array<int, 2>> st;
    
    RangeModule() {
        
    }
    
    void addRange(int left, int right) {
        array<int, 2> a{left, right};
        auto it = st.lower_bound(a);
        if (it != st.begin() && ((*prev(it))[1] >= a[0])) --it;
        while (it != st.end())
        {
            if ((*it)[1] < a[0] || (*it)[0] > a[1])
            {
                ++it;
            }
            else
            {
                a[0] = min(a[0], (*it)[0]);
                a[1] = max(a[1], (*it)[1]);
                it = st.erase(it);
            }
        }
        st.insert(a);
    }
    
    bool queryRange(int left, int right) {
        auto it = st.lower_bound({left, right});
        if (it != st.end() && ((*it)[0] <= left) && (*it)[1] >= right) return true;
        if (it != st.begin())
        {
            --it;
            if ((*it)[1] >= right) return true;
        }
        return false;
    }
    
    void removeRange(int left, int right) {
        auto it = st.lower_bound({left, right});
        if (it != st.begin() && (*prev(it))[1] > left) --it;
        while (it != st.end() && right > (*it)[0])
        {
            if (left > (*it)[0]) st.insert({(*it)[0], left});
            if (right < (*it)[1]) st.insert({right, (*it)[1]});
            it = st.erase(it);
        }
    }
};

/**
 * Your RangeModule object will be instantiated and called as such:
 * RangeModule* obj = new RangeModule();
 * obj->addRange(left,right);
 * bool param_2 = obj->queryRange(left,right);
 * obj->removeRange(left,right);
 */