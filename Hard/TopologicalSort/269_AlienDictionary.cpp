#include <bits/stdc++.h>
using namespace std;

struct Graph
{
    unordered_map<char, set<char>> g;
    
    Graph();
    void addEdge(char u, char v);
    string TopologicalSort();
};

Graph::Graph()
{
    
}

void Graph::addEdge(char u, char v)
{
    g[u].insert(v);
}

string Graph::TopologicalSort()
{
    unordered_map<char, int> inDegree;
    string ans;
    for (auto i: g)
    {
        for (char nei: i.second) inDegree[nei]++; 
    }
    queue<char> q;
    for (auto i: g)
    {
        if (!inDegree[i.first]) q.push(i.first);
    }
    int cnt = 0;
    while (!q.empty())
    {
        char cur = q.front(); q.pop();
        ++cnt;
        ans += cur;
        for (char nei: g[cur])
        {
            if (!--inDegree[nei]) q.push(nei);
        }
    }
    return cnt == g.size() ? ans : "";
}

class Solution {
public:
    string alienOrder(vector<string>& words) {
        Graph graph;
        int m = words.size();
        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < words[i].size(); j++)
            {
                if (graph.g.find(words[i][j]) == graph.g.end()) graph.g[words[i][j]] = set<char>();
            }
        }
        for (int i = 0; i < m - 1; i++)
        {
            int j;
            int len = min(words[i].size(), words[i + 1].size());
            for (j = 0; j < len; j++)
            {
                if (words[i][j] != words[i + 1][j])
                {
                    graph.addEdge(words[i][j], words[i + 1][j]);
                    break;
                }
                if (j == len - 1 && words[i].size() > words[i + 1].size()) return "";
            }
        }
        return graph.TopologicalSort();
    }
};