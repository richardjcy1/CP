class Solution {
public:
    int i = 0;
    
    int solve(const string& s) {
        vector<int> stk;
        char op = '+';
        int num = 0;
        while (i < s.size())
        {
            char c = s[i++];
            if (isdigit(c)) num = num * 10 + (c - '0');
            if (c == '(') num = solve(s);
            if (i >= s.size() || c == '+' || c == '-' || c == '*' || c == '/' || c == ')')
            {
                if (op == '+') stk.push_back(num);
                else if (op == '-') stk.push_back(-num);
                else if (op == '*')
                {
                    stk.back() *= num;
                }
                else if (op == '/')
                {
                    stk.back() /= num;
                }
                op = c;
                num = 0;
            }
            if (c == ')') break;
        }
        return accumulate(stk.begin(), stk.end(), 0);
    }
    
    int calculate(string s)
    {
        return solve(s);
    }
};