#include <bits/stdc++.h> 
using namespace std; 
int main() {
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        string s;
        cin >> s;
        if (n & 1)
        {
            int odd = 0;
            for (int i = 0; i < n; i += 2)
            {
                if ((s[i] - '0') & 1) ++odd;
            }
            if (odd)
            {
                cout << 1 << endl;
            }
            else
            {
                cout << 2 << endl;
            }
        }
        else
        {
            int even = 0;
            for (int i = 1; i < n; i += 2)
            {
                if ((s[i] - '0') % 2 == 0) ++even;
            }
            if (even)
            {
                cout << 2 << endl;
            }
            else {
                cout << 1 << endl;
            }

        }
    }
    return 0;
}

