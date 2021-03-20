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
        int n;
        cin >> n;
        vector<ll> c(n);
        for (int i = 0; i < n; i++) cin >> c[i];
        ll mi1 = 0, mi2 = 1;
        for (int i = 2; i < n; i++)
        {
            if ((i & 1) && (c[i] < c[mi2]))  mi2 = i;
            else if (i % 2 == 0 && c[i] < c[mi1]) mi1 = i;
        }
        ll ans = 0;
        for (int i = 0; i <= mi1; i += 2) ans += c[i];
        for (int i = 1; i <= mi2; i += 2) ans += c[i];
        ans = ans - c[mi1] + (n - mi1 / 2) * c[mi1];
        ans = ans - c[mi2] + (n - (mi2 - 1) / 2) * c[mi2];
        cout << ans << endl;
    }
    return 0;
}