class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        unordered_set<string> st(wordList.begin(), wordList.end());
        if (st.find(endWord) == st.end()) return 0;
        unordered_set<string> vis;
        int d = 1;
        queue<string> q;
        q.push(beginWord);
        vis.insert(beginWord);
        while (!q.empty())
        {
            int sz = q.size();
            for (int i = 0; i < sz; i++)
            {
                auto tmp = q.front(); q.pop();
                if (tmp == endWord) return d;
                for (int j = 0; j < tmp.size(); j++)
                {
                    char ch = tmp[j];
                    for (int k = 0; k < 26; k++)
                    {
                        tmp[j] = (char)('a' + k);
                        if (st.find(tmp) != st.end() && vis.find(tmp) == vis.end())
                        {
                            vis.insert(tmp);
                            q.push(tmp);
                        }
                    }
                    tmp[j] = ch;
                }
            }
            ++d;
        }
        return 0;
    }
};