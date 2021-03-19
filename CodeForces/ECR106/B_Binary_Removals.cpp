#include <algorithm>
#include <bitset>
#include <complex>
#include <deque>
#include <exception>
#include <fstream>
#include <functional>
#include <iomanip>
#include <iostream>
#include <iterator>
#include <istream>
#include <limits>
#include <list>
#include <locale>
#include <map>
#include <memory>
#include <new>
#include <numeric>
#include <ostream>
#include <queue>
#include <set>
#include <sstream>
#include <stack>
#include <stdexcept>
#include <string>
#include <typeinfo>
#include <utility>
#include <valarray>
#include <vector>
#include <array>
//#include <atomic>
#include <chrono>
#include <condition_variable>
#include <forward_list>
#include <future>
#include <initializer_list>
#include <mutex>
#include <random>
#include <ratio>
#include <regex>
#include <thread>
#include <tuple>
#include <type_traits>
#include <unordered_map>
#include <unordered_set>
using namespace std;

typedef long long ll;
const int INF = 0x3f3f3f3f;
const int mod = 1e9 + 7;


int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin >> t;
    while (t--)
    {
        string s;
        cin >> s;
        int n = s.size();
        vector<int> zeroes(n);
        vector<int> ones(n);
        zeroes[0] = (s[0] == '0');
        for (int i = 1; i < n; i++)
        {
            if (s[i] == '0') zeroes[i] = 1 + zeroes[i - 1];
            else zeroes[i] = zeroes[i - 1];
        }
        ones[n - 1] = (s[n - 1] == '1');
        for (int i = n - 2; ~i; i--)
        {
            if (s[i] == '1') ones[i] = 1 + ones[i + 1];
            else ones[i] = ones[i + 1];
        }
        int x = 0, y = 0;
        for (int i = 0; i < n; i++)
        {
            if (x + y < zeroes[i] + ones[i])
            {
                x = zeroes[i];
                y = ones[i];
            }
        }
        string ans = string(x, '0') + string(y, '1');
        vector<bool> v(n);
        int idx = 0;
        int i = 0;
        for (int i = 0; i < n; i++)
        {
            if (idx < ans.size())
            {
                if (ans[idx] == s[i]) 
                {
                    v[i] = true;
                    idx++;
                }
            }
        }
        bool ok = true;
        for (int i = 1; i < n; i++)
        {
            if (!v[i] && !v[i - 1]) ok = false;
        }
        if (ok) cout << "YES" << endl;
        else cout << "NO" << endl;
    }
    return 0;
}