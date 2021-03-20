// use set to store interval
// for each insert val, find the lower_bound
// check if previous interval can merge with val
// then track the following intervals as well until end
// insert the updated interval
class SummaryRanges {
public:
    set<vector<int>> st;
    /** Initialize your data structure here. */
    SummaryRanges() {
        
    }
    
    void addNum(int val) {
        vector<int> a{val, val};
        auto it = st.lower_bound(a);
        int start = val, end = val;
        if (it != st.begin() && (*prev(it))[1] + 1 >= val) --it;
        while (it != st.end() && (*it)[0] <= val + 1 && (*it)[1] >= val - 1)
        {
            start = min(start, (*it)[0]);
            end = max(end, (*it)[1]);
            it = st.erase(it);
        }
        st.insert(vector<int>{start, end});
    }
    
    vector<vector<int>> getIntervals() {
        vector<vector<int>> ans;
        for (auto& i: st) ans.push_back(i);
        return ans;
    }
};

/**
 * Your SummaryRanges object will be instantiated and called as such:
 * SummaryRanges* obj = new SummaryRanges();
 * obj->addNum(val);
 * vector<vector<int>> param_2 = obj->getIntervals();
 */