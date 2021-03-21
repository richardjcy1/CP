#include <bits/stdc++.h>
using namespace std;

struct Node
{
    Node* a[26];
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
    
    void insert(string word)
    {
        Node* node = root;
        for (char c: word)
        {
            if (!node->a[c - 'a'])
            {
                node->a[c - 'a'] = new Node();
            }
            node = node->a[c - 'a'];
        }
        node->isWord = true;
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
