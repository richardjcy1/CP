#include <bits/stdc++.h>
 
using namespace std;
 
const long long MOD=1e9+7;
 
long long quick_power(long long x, long long y, long long p) {
    long long ans=1;
    while (y) {
        if (y&1) {
            ans=(ans*x)%p; 
        }
        y>>=1;
        x=(x*x)%p;
    }
    return ans%p;
}
 
int main() {
    long long n;
    long long zeros = 0;
    long long ans=1;
 
    map<pair<long long,long long>,long long> m;
    map<pair<long long,long long>,long long>::iterator it;
 
    scanf("%lld", &n);
    for (long long i=1; i<=n; i++) {
        long long u,v,now;
        scanf("%lld%lld", &u, &v);
 
        if (u==0&&v==0) {
            zeros++;
            continue;
        }
 
        now=__gcd(u,v);
        u/=now;
        v/=now;
 
        if (u<0) {
            u=-u;
            v=-v;
        }
        m[make_pair(u,v)]++;
    }
 
    for (it=m.begin();it!=m.end();it++) {
        if (it->second==0) {
            continue;
        }
 
        long long x=it->first.first,y=it->first.second;
        long long p=quick_power(2, m[make_pair(x,y)], MOD);
 
        y=-y;
        if (y<0) {
            x=-x;
            y=-y;
        } 
 
        if (m.count(make_pair(y,x))) {
            p=(p+quick_power(2, m[make_pair(y,x)], MOD)-1);
            m[make_pair(y,x)]=0;
        }
        ans=(ans*p)%MOD;
    }
 
    printf("%lld\n", ((ans+zeros-1)%MOD+MOD)%MOD);
	
    return 0;
}