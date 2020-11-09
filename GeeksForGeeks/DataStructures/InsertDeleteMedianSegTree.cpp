#include <bits/stdc++.h>
using namespace std;
#define maxn 3000005
#define max_elem 1000000

int segmentTree[maxn];

void update(int node, int a, int b, int x, int diff)
{
    if (a == b && a == x)
    {
        segmentTree[node] += diff;
        return;
    }
    if (x >= a && x <= b)
    {
        update(node * 2, a, (a + b) / 2, x, diff);
        update(node * 2 + 1, (a + b) / 2 + 1, b, x, diff);
        segmentTree[node] = segmentTree[node * 2] + segmentTree[node * 2 + 1];
    }
}

int findKth(int node, int a, int b, int k)
{
    if (a != b)
    {
        if (segmentTree[node * 2] >= k)
        {
            return findKth(node * 2, a, (a + b) / 2, k);
        }
        return findKth(node * 2 + 1, (a + b) / 2 + 1, b, k - segmentTree[node * 2]);
    }
    return (segmentTree[node]) ? a : -1;
}

void insert(int x)
{
    update(1, 0, max_elem, x, 1);
}

void delet(int x)
{
    update(1, 0, max_elem, x, -1);
}

int median()
{
    int k = (segmentTree[1] + 1) / 2;
    return findKth(1, 0, max_elem, k);
}

int main() 
{ 
    insert(1); 
    insert(4); 
    insert(7); 
    cout << "Median for the set {1,4,7} = " 
         << median() << endl; 
    insert(8); 
    insert(9); 
    cout << "Median for the set {1,4,7,8,9} = "
         << median() << endl; 
    delet(1); 
    delet(8); 
    cout << "Median for the set {4,7,9} = "
         << median() << endl; 
    return 0; 
} 