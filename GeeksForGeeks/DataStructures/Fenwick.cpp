#pragma GCC optimize ("Ofast")
#include <bits/stdc++.h>
using namespace std;
#define MD (1000000007U)

void* wmem;
char memarr[96000000];

typedef long long ll;
const int INF = 0x3f3f3f3f;
const int mod = 1e9 + 7;

template <class S, class T> inline S min_L(S a, T b)
{
    return a <= b ? a : b;
}

template <class S, class T> inline S max_L(S a, T b)
{
    return a >= b ? a : b;
}

template <class T> inline void walloc1d(T** arr, int x, void** mem = &wmem)
{
    static int skip[16] = {0,15,14,13,12,11,10,9,8,7,6,5,4,3,2,1};
    (*mem) = (void*)( ((char*)(*mem)) + skip[((unsigned long long)(*mem)) & 15]);
    (*arr) = (T*)(*mem);
    (*mem) = ((*arr) + x);
}

template <class T> inline void walloc1d(T** arr, int x1 ,int x2, void** mem = &wmem)
{
    walloc1d(arr, x2 - x1, mem);
    (*arr) -= x1;
}

struct Modint
{
    unsigned val;
    
    Modint()
    {
        val = 0;
    }
    
    Modint(int a)
    {
        val = ord(a);
    }
    
    Modint(unsigned a)
    {
        val = ord(a);
    }
    
    Modint(long long a)
    {
        val = ord(a);
    }
    
    Modint(unsigned long long a)
    {
        val = ord(a);
    }
    
    inline unsigned ord(unsigned a)
    {
        return a % MD;
    }
    
    inline unsigned ord(int a)
    {
        a %= (int)MD;
        if (a < 0)
        {
            a += MD;
        }
        return a;
    }
    
    inline unsigned ord(unsigned long long a)
    {
        return a % MD;
    }
    
    inline unsigned ord(long long a)
    {
        a %= (int)MD;
        if (a < 0)
        {
            a += MD;
        }
        return a;
    }
    
    inline unsigned get()
    {
        return val;
    }
    
    inline Modint &operator+=(Modint a)
    {
        val += a.val;
        if (val >= MD)
        {
            val -= MD;
        }
        return *this;
    }
    
    inline Modint &operator-=(Modint a)
    {
        if (val < a.val)
        {
            val = val + MD - a.val;
        }
        else
        {
            val -= a.val;
        }
        return *this;
    }
    
    inline Modint &operator*=(Modint a)
    {
        val = ((unsigned long long )val * a.val) %MD;
        return *this;
    }
    
    inline Modint &operator/=(Modint a)
    {
        return *this *= a.inverse();
    }
    
    inline Modint operator+(Modint a)
    {
        return Modint(*this) += a;
    }
    
    inline Modint operator-(Modint a)
    {
        return Modint(*this) -= a;
    }
    
    inline Modint operator*(Modint a)
    {
        return Modint(*this) *= a;
    }
    
    inline Modint operator/(Modint a)
    {
        return Modint(*this) /= a;
    }
    
    inline Modint operator+(int a)
    {
        return Modint(*this) += Modint(a);
    }
    
    inline Modint operator-(int a)
    {
        return Modint(*this) -= Modint(a);
    }
    
    inline Modint operator*(int a)
    {
        return Modint(*this) *= Modint(a);
    }
    
    inline Modint operator/(int a)
    {
        return Modint(*this) /= Modint(a);
    }
    
    inline Modint operator+(long long a)
    {
        return Modint(*this) += Modint(a);
    }
    
    inline Modint operator-(long long a)
    {
        return Modint(*this) -= Modint(a);
    }
    
    inline Modint operator*(long long a)
    {
        return Modint(*this) *= Modint(a);
    }
    
    inline Modint operator/(long long a)
    {
        return Modint(*this) /= Modint(a);
    }
    
    inline Modint operator-(void)
    {
        Modint res;
        if (val)
        {
            res.val = MD - val;
        }
        else
        {
            res.val = 0;
        }
        return res;
    }
    
    inline operator bool(void)
    {
        return val != 0;
    }
    
    inline operator int(void)
    {
        return get();
    }
    
    inline operator long long (void)
    {
        return get();
    }
    
    inline Modint inverse()
    {
        int a = val;
        int b = MD;
        int u = 1;
        int v = 0;
        int t;
        Modint res;
        while (b)
        {
            t = a / b;
            a -= t * b;
            swap(a, b);
            u -= t * v;
            swap(u, v);
        }
        if (u < 0)
        {
            u += MD;
        }
        res.val = u;
        return res;
    }
    
    inline Modint pw(unsigned long long b)
    {
        Modint a(*this);
        Modint res;
        res.val = 1;
        while (b)
        {
            if (b & 1)
            {
                res *= a;
            }
            b >>= 1;
            a *= a;
        }
        return res;
    }
    
    inline bool operator==(int a)
    {
        return ord(a) == val;
    }
    
    inline bool operator!=(int a)
    {
        return ord(a) != val;
    }
};

inline Modint operator+(int a, Modint b)
{
    return Modint(a) + b;
}

inline Modint operator-(int a, Modint b)
{
    return Modint(a) -= b;
}

inline Modint operator*(int a, Modint b)
{
    return Modint(a) *= b;
}

inline Modint operator/(int a, Modint b)
{
    return Modint(a) /= b;
}

inline Modint operator+(long long a, Modint b)
{
    return Modint(a) += b;
}

inline Modint operator-(long long a, Modint b)
{
    return Modint(a) -= b;
}

inline Modint operator*(long long a, Modint b)
{
    return Modint(a) *= b;
}

inline Modint operator/(long long a, Modint b)
{
    return Modint(a) /= b;
}

template<class T> struct fenwick {
    int size;
    int memory;
    T* data;
    void malloc(int mem);
    void malloc(int mem, int fg);
    void walloc(int mem, void** workMemory = &wmem);
    void walloc(int mem, int fg, void** workMemory = &wmem);
    void free(void);
    void init(int N);
    void add(int k, T val);
    T get(int k);
    T range(int a, int b);
    int kth(T k);
};

template <class T> void fenwick<T>::malloc(int mem)
{
    memory = mem;
    data = (T*) std::malloc(sizeof(T) * mem);
}

template <class T> void fenwick<T>::malloc(int mem, int fg)
{
    memory = mem;
    data = (T*)std::malloc(sizeof(T) * mem);
    if (fg)
    {
        init(mem);
    }
}

template <class T> void fenwick<T>::walloc(int mem, void** workMemory /* = *wmem */)
{
    memory = mem;
    walloc1d(&data, mem, workMemory);
}

template <class T> void fenwick<T>::walloc(int mem, int fg, void** workMemory /* = &wmem */)
{
    memory = mem;
    walloc1d(&data, mem, workMemory);
    if (fg)
    {
        init(mem);
    }
}

template <class T> void fenwick<T>::free(void)
{
    memory = 0;
    free(data);
}

template <class T> void fenwick<T>::init(int N)
{
    size = N;
    memset(data, 0, sizeof(T) * N);
}

template <class T> void fenwick<T>::add(int k, T val)
{
    while (k < size)
    {
        data[k] += val;
        k |= k + 1;
    }
}

template <class T> T fenwick<T>::get(int k)
{
    T res = 0;
    while (k >= 0)
    {
        res += data[k];
        k = (k & (k + 1)) - 1;
    }
    return res;
}

template <class T> T fenwick<T>::range(int a, int b)
{
    if (b == -1) b = size - 1;
    return get(b) - get(a - 1);
}

template <class T> int fenwick<T>::kth(T k)
{
    int i = 0, j = size, c;
    T v;
    while (i < j)
    {
        c = (i + j) / 2;
        v = get(c);
        if (v <= k)
        {
            i = c + 1;
        }
        else
        {
            j = c;
        }
    }
    return i == size ? -1 : i;
}

#define main dummy_main
int main()
{
    wmem = memarr;
    return 0;
}
#undef main

struct Solution
{
    int createSortedArray(vector<int>& A)
    {
        int i;
        dummy_main();
        int N = A.size();
        Modint res = 0;
        int mx;
        fenwick<int> t;
        {
            int x, y;
            if (N == 0) y = 0;
            else
            {
                y = A[0];
                for (i = 1; i < N; i++) y = max_L(y, A[i]);
            }
            mx = y + 1;   
        }
        t.walloc(mx + 1, 1);
        for (i = 0; i < N; i++)
        {
            t.add(A[i], 1);
            res += min_L(t.get(A[i] - 1), t.range(A[i] + 1, mx));
        }
        return res;
    }
};

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    vector<vector<int>> A{{1,5,6,2}, {1,2,3,6,5,4},{1,3,3,3,2,4,2,1,2}};
    Solution s;
    for (auto v: A)
    {
        cout << s.createSortedArray(v) << endl;
    }
    return 0;
}