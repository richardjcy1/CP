#include <bits/stdc++.h>
using namespace std;

struct Node
{
    Node* a[2];
    bool isWord{};
    Node() { memset(a, 0, sizeof a); }
};

struct Trie
{
    Node* root;
    
    Trie()
    {
        root = new Node();
    }
    
    void insert(int num)
    {
        Node* node = root;
        for (int i = 31; ~i; i--)
        {
            int curBit = (num >> i) & 1;
            if (!node->a[curBit]) node->a[curBit] = new Node();
            node = node->a[curBit];
        }
    }
    
    int findMaxXor(int num)
    {
        int sum = 0;
        Node* node = root;
        for (int i = 31; ~i; i--)
        {
            int curBit = (num >> i) & 1;
            int otherChoice = 1 - curBit;
            if (!node->a[otherChoice])
            {
                node = node->a[curBit];
            }
            else
            {
                sum += (1 << i);
                node = node->a[otherChoice];
            }
        }
        return sum;
    }
    
    bool search(string word)
    {
        Node* node = root;
        for (char c: word)
        {
            if (!node->a[c - 'a']) return false;
            node = node->a[c - 'a'];
        }
        return node->isWord;
    }
    
    bool startsWith(string prefix)
    {
        Node* node = root;
        for (char c: prefix)
        {
            if (!node->a[c - 'a']) return false;
            node = node->a[c - 'a'];
        }
        return true;
    }
};


class Solution {
public:
    int findMaximumXOR(vector<int>& nums) {
        int res = INT_MIN;
        Trie* trie = new Trie();
        for (int num: nums) trie->insert(num);
        for (int num: nums)
        {
            res = max(res, trie->findMaxXor(num));
        }
        return res;
    }
};