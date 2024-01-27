#include <bits/stdc++.h>
using namespace std;

#define parent(i) (i / 2)
#define left_child(i) (2 * i)
#define right_child(i) (2 * i + 1)
#define pb push_back

class BinaryHeap
{
    int sz;
    vector<int> tree;
    void bubble_up(int idx)
    {
        if (idx == 1)
            return;
        if (tree[parent(idx)] > tree[idx])
            swap(tree[idx], tree[parent(idx)]), bubble_up(parent(idx));
    }
    void bubble_down(int idx)
    {
        int left = left_child(idx), right = right_child(idx);
        if (left > sz)
            return;
        if (right > sz)
            right = left;
        int min_idx = (tree[left] <= tree[right] ? left : right);
        if (tree[min_idx] >= tree[idx])
            return;
        swap(tree[min_idx], tree[idx]);
        bubble_down(min_idx);
    }

public:
    BinaryHeap()
    {
        sz = 0;
        tree.pb(0);
    }

    BinaryHeap(vector<int> &arr)
    {
        tree.pb(0);
        tree.insert(tree.end(), arr.begin(), arr.end());
        for (int i = (int)(tree.size()) - 1; i; i--)
            bubble_up(i);
        sz = (int)tree.size() - 1;
    }

    void push(int val)
    {
        tree.pb(val);
        sz++;
        bubble_up(sz);
    }

    void pop()
    {
        assert(!is_empty());
        swap(tree[1], tree[sz]);
        tree.pop_back();
        sz--;
        bubble_down(1);
    }

    int find_min()
    {
        assert(!is_empty());
        return tree[1];
    }

    bool is_empty()
    {
        return sz == 0;
    }

    friend ostream &operator<<(ostream &os, BinaryHeap &heap)
    {
        int c = 0, k = 1;
        for (int i = 1; i < (int)heap.tree.size(); i++)
        {
            if (!k)
            {
                cout << "\n";
                c++;
                k = (1 << c);
            }
            k--;
            os << heap.tree[i] << " ";
        }
        return os;
    }
};

int main()
{
    return 0;
}
