#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int INF = 0x3f3f3f3f;
const int mod = 1e9 + 7;

struct BIT
{
    BIT(vector<int> list)
    {
        m_array = vector<int>(list.size() + 1);
        for (int i = 0; i < list.size(); i++)
        {
            m_array[i + 1] = list[i];
        }
        for (int i = 1; i < m_array.size(); i++)
        {
            int j = i + (i & -i);
            if (i < m_array.size())
            {
                m_array[j] += m_array[i];
            }
        }
    }
    
    int prefix_query(int idx)
    {
        int result = 0;
        for (++idx; idx > 0; idx -= idx & -idx)
        {
            result += m_array[idx];
        }
        return result;
    }
    
    int range_query(int from_idx, int to_idx)
    {
        if (from_idx == 0) return prefix_query(to_idx);
        return prefix_query(to_idx) - prefix_query(from_idx - 1);
    }
    
    void update(int idx, int add)
    {
        for (++idx; idx < m_array.size(); idx += idx & -idx)
        {
            m_array[idx] += add;
        }
    }
    
    vector<int> m_array;
};

void print(BIT& bit, int length)
{
    std::cout << "Index: ";
	for (int idx = 0; idx < length; ++idx)
		std::cout << std::setw(2) << idx << " ";
	std::cout << std::endl;
	std::cout << "Array: ";
	for (int idx = 0; idx < length; ++idx)
		std::cout << std::setw(2) << bit.range_query(idx, idx) << " ";
	std::cout << std::endl << std::endl;

	std::cout << "Prefix sum of first 13 elements: \t" << bit.prefix_query(12) << std::endl;
	std::cout << "Prefix sum of first 7 elements: \t" << bit.prefix_query(6) << std::endl;
	std::cout << "Range sum from index 1 to index 5: \t" << bit.range_query(1, 5) << std::endl;
	std::cout << std::endl;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    vector<int> array{ 1, 7, 3, 0, 5, 8, 3, 2, 6, 2, 1, 1, 4, 5 };
    int length = array.size();
	BIT bit(array);
    print(bit, length);

	bit.update(4, 2);
	cout << "Add 2 to element at index 4" << endl << endl;
    print(bit, length);
    return 0;
}