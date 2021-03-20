/*
*	author:		richardjcy
*	created:	2020/09/26/07:56.04
*/

#include <bits/stdc++.h>
using namespace std;

unordered_set<string> st = {"01","02","03","04","05","06","07","08","09","10","11","12"};

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    string s;
    cin >> s;
    bool ok1 = false, ok2 = false;
    if (st.find(s.substr(0, 2)) != st.end()) ok1 = true;
    if (st.find(s.substr(2)) != st.end()) ok2 = true;
    if (ok1 && ok2) cout << "AMBIGUOUS" << endl;
    else if (ok1) cout << "MMYY" << endl;
    else if (ok2) cout << "YYMM" << endl;
    else cout << "NA" << endl;
    return 0;
}