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
#include <atomic>
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
        ll n, m;
        cin >> n >> m;
        vector<ll> a(n);
        for (ll i = 0; i < n; i++) cin >> a[i];
        vector<ll> x(m);
        for (ll i = 0; i < m; i++) cin >> x[i];
        ll sum = 0;
        unordered_map<ll, ll> mp;
        for (ll i = 0; i < n; i++)
        {
            sum += a[i];
            if (mp.find(sum) == mp.end()) mp[sum] = i + 1;
        }
        for (ll i = 0; i < m; i++)
        {
            if (mp.find(x[i]) != mp.end()) cout << mp[x[i]] - 1 << " ";
            else
            {
                if (!sum)
                {
                    cout << -1 << " ";
                    continue;
                }
                ll rem = x[i] % sum;
                if (mp.find(rem) == mp.end()) cout << -1 << " ";
                else
                {
                    if (rem == 0) cout << abs(x[i] / sum) * n - 1 << " ";
                    else cout << abs(x[i] / sum) * n + mp[rem]  - 1 << " ";
                }
            }
        }
        cout << endl;
    }
    return 0;
}