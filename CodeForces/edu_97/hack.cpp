#pragma GCC optimize("Ofast", "O3", "unroll-loops", "omit-frame-pointer", "inline")
#pragma GCC target("sse", "sse2", "sse3", "ssse3", "sse4", "popcnt", "abm", "mmx", "avx", "avx2")
#pragma GCC option("tune = native", "arch = native", "no-zero-upper")
#pragma comment(linker, "/stack:200000000")


#include <bits/stdc++.h>

typedef bool bo;
typedef short sh;
typedef long long ll;
typedef unsigned long long ull;
typedef double de;
typedef long double ld;
typedef char ch;
typedef size_t sit;

#define spd ios::sync_with_stdio(false); cin.tie(0); cout.tie(0)
#define file(i, o) freopen((i), "rt", stdin); freopen((o), "wt", stdout)
#define pr pair
#define str string
#define vec vector
#define vint vec <int>
#define vll vec <ll>
#define vull vec <ull>
#define vld vec <ld>
#define vch vec <ch>
#define vstr vec <str>
#define vbo vec <bo>
#define qint queue <int>
#define sint set <int>
#define ph push
#define phf push_front
#define phb push_back
#define ins insert
#define sub substr
#define re reverse
#define bn begin()
#define ed end()
#define rbn rbegin()
#define red rend()
#define sz size()
#define ey empty()
#define tp top()
#define pp pop()
#define ft front()
#define ppf pop_front()
#define bk back()
#define ppb pop_back()
#define cr clear()
#define ee erase
#define rsz resize
#define te true
#define fe false
#define st first
#define nd second
#define antihype signed main()
#define all(x) (x).bn, (x).ed
#define allc(x) (x).bn, (x).ed, cmp
#define rall(x) (x).rbn, (x).red
#define rallc(x) (x).rbn, (x).red, cmp
#define coutf(x) cout << fixed << setprecision(x)
#define gle(x) getline(cin, (x))
#define lp(i, n) for (int i = 0; i < (n); ++i)
#define rlp(i, n) for (int i = (n - 1); i > -1; --i)
#define lpl(i, n) for (ll i = 0; i < (n); ++i)
#define rlpl(i, n) for (ll i = (n - 1); i > -1; --i)
#define inc(i, x, y) for (int i = (x); i < (y); ++i)
#define dec(i, x, y) for (int i = (x); i > (y); --i)
#define incl(i, x, y) for (ll i = (x); i < (y); ++i)
#define decl(i, x, y) for (ll i = (x); i > (y); --i)
#define step(i, x, y, z) for (int i = (x); i < (y); i += (z))
#define stepl(i, x, y, z) for (ll i = (x); i < (y); i += (z))
#define lpst(i, n) for (size_t i = 0; i < (n); ++i)
#define incst(i, x, y) for (size_t i = (x); i < (y); ++i)
#define cinvint(v, n) vint v(n); lpst(i, n) cin >> v[i]
#define cinvll(v, n) vll v(n); lpst(i, n) cin >> v[i]
#define cinvull(v, n) vull v(n); lpst(i, n) cin >> v[i]
#define cinvld(v, n) vld v(n); lpst(i, n) cin >> v[i]
#define cinvch(v, n) vch v(n); lpst(i, n) cin >> v[i]
#define cinvstr(v, n) vstr v(n); lpst(i, n) cin >> v[i]
#define sqr(a) (a) * (a)

using namespace std;

inline void cringe() {
	spd;
#ifdef LOCAL_PROJECT
	file("input.in", "output.out");
#endif
}

antihype {
	cringe();
	int t, a, b;
	cin >> t;
	lp(o, t) {
		cin >> a >> b;
		cout << ((ld)(a % (b + 1)) >= (ld)(b + 1) / 2.0 ? "YES" : "NO") << '\n';
	}
	return 0;
}