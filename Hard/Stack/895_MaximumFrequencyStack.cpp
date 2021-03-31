// Use freq map to store val's frequency
// Use mp to store list of vals with the same frequency
// Time complexity: O(1)
// Space complexity: O(n)
class FreqStack {
public:
    map<int, vector<int>> mp;
    map<int, int> freq;
    
    FreqStack() {

    }
    
    void push(int val) {
        if (freq.find(val) == freq.end())
        {
            freq[val] = 1;
            mp[1].push_back(val);
        }
        else
        {
            mp[freq[val] + 1].push_back(val);
            freq[val]++;
        }
    }
    
    int pop() {
        int last = (*mp.rbegin()).first;
        int ans = mp[last].back();
        mp[last].pop_back();
        freq[ans]--;
        if (freq[ans] == 0) freq.erase(ans);
        if (mp[last].empty()) mp.erase(last);
        return ans;
    }
};

/**
 * Your FreqStack object will be instantiated and called as such:
 * FreqStack* obj = new FreqStack();
 * obj->push(val);
 * int param_2 = obj->pop();
 */