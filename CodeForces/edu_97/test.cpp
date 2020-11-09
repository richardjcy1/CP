    #include <bits/stdc++.h>
        
    using namespace std;
        
    #define ll long long
    #define ull unsigned long long
    #define all(v) (v).begin(), (v).end()
    
    const int N = 1e5+1;
    vector<int> g[N];
    bool vis[N] = {0};
    int a[N];

    bool ifprime(ll x)
    {
        if(x == 1 || x == 2)
            return true;
        if(x%2 == 0)
            return false;
        for(ll i=3 ; i<=sqrt(x) ; i+=2)
        {
            if(x%i == 0)
                return false;
        }
        return true;
    }
        
    int alp[26] = {0};
        
    ll fsum(string s)
    {
        int x = s.size();
        ll ans = 0;

        for(int i=0 ; i<x ; ++i)
            ans += (s[i]-'0');

        return ans;
    }

    int first_div(int n)
    {
        for(int i=2 ; i<=sqrt(n) ; ++i)
        {
            if(n%i == 0)
                return i;
        }
        return n;
    }

    int dfs(int x)
    {
        vis[x]++;

        int val = a[x];
        for(int q : g[x])  
        {
            if(vis[q])
                continue;

            val = min(val, dfs(q));
        }
        
        return val;
    }

    ll fact(ll x)
    {
        ll f = 1;
        for(int i=x ; i>=1 ; --i)
            f *= i;

        return f;
    }
    bool comparep(const pair<int, int>&i, const pair<int, int>&j) 
    { 
        if(i.first == j.first)
            return i.second > j.second; 
        return i.first > j.first;
    } 
    bool comparet(const pair<pair<int, int>, int>&i, const pair<pair<int, int>, int>&j) 
    { 
        if(i.first.first == j.first.first)
            return i.first.second > j.first.second; 
        return i.first.first > j.first.first;
    } 
        
    int main()
    {   
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        
        // #ifndef ONLINE_JUDGE
        //     freopen("input.txt","r",stdin);
        //     freopen("output.txt","w",stdout);
        // #endif

        clock_t start, end; 
        start = clock(); 

        int t = 1;
        cin >> t;
                
        while(t--)
        {   
            int l, r;
            cin >> l >> r;

            int a = r+1;
            float b = a/2.0;
            cout << "b: " << b << endl;
            cout << (l%a>=b ? "YES\n" : "NO\n");
        }
        end = clock(); 
        /*f = 0 '1'
        f = 1 '0'*/
        /*double time_taken = double(end - start) / double(CLOCKS_PER_SEC); 
        cout << "\nTime taken by program is : " << fixed  
            << time_taken << setprecision(5); 
        cout << " sec " << endl;*/

        return 0;
    }