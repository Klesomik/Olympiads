#include <bits/stdc++.h>

typedef long long int lli;

const lli Neutral = 0, None = -1e10;

struct SegmentTree
{
    std::vector <lli> tree, tAdd;

    void build_ (std::vector <lli>& data, lli v, lli tl, lli tr);
    lli query_ (lli v, lli tl, lli tr, lli l, lli r);
    void modify_ (lli v, lli tl, lli tr, lli l, lli r, lli value);
    void push_ (lli v, lli tr, lli tl);
};

void build_ (std::vector <lli>& data, lli v, lli tl, lli tr)
{
    if (tl == tr)
    {
        tree[v] = data[tl];

        return;
    }

    lli tm = (tl + tr) / 2;

    build_ (data, 2 * v + 1, tl + 0, tm);
    build_ (data, 2 * v + 2, tm + 1, tr);

    tree[v] = tree[2 * v + 1] + tree[2 * v + 2];
}

lli query_ (lli v, lli tl, lli tr, lli l, lli r)
{
    push_ (v, tl, tr);

    if (r < tl || tr < l)
        return Neutral;

    if (l <= tl && tr <= r)
        return tree[v];

    lli tm = (tl + tr) / 2;

    lli q1 = query_ (2 * v + 1, tl + 0, tm, l, r),
        q2 = query_ (2 * v + 2, tm + 1, tr, l, r);

    return q1 + q2;
}

void modify_ (lli v, lli tl, lli tr, lli l, lli r, lli value)
{
    push_ (v, tl, tr);

    if (r < tl || tr < l)
        return;

    if (l <= tl && tr <= r)
    {
        tAdd[v] = value;

        push_ (v, tl, tr);

        return;
    }

    lli tm = (tl + tr) / 2;

    modify_ (2 * v + 1, tl + 0, tm, l, r, value);
    modify_ (2 * v + 2, tm + 1, tr, l, r, value);

    tree[v] = tree[2 * v + 1] + tree[2 * v + 2];
}

void push_ (lli v, lli tr, lli tl)
{
    if (tAdd[v] == None)
        return;

    tree[v] = tAdd[v];

    if (tl != tr)
    {
        tAdd[2 * v + 1] = tAdd[v];
        tAdd[2 * v + 2] = tAdd[v];
    }

    tAdd[v] = None;
}

int main ()
{
    lli n = 0;
    std::cin >> n;

    std::vector <lli> data (n);

    for (lli i = 0; i < data.size (); i++)
        std::cin >> data[i];

    tree.resize (4 * data.size ());
    tAdd.resize (4 * data.size (), None);

    Build (data, 0, 0, data.size () - 1);

    lli k = 0;
    std::cin >> k;

    for (lli i = 0; i < k; i++)
    {
        char cmd = 0;
        std::cin >> cmd;

        if (cmd == 'g')
        {
            lli index = 0;
            std::cin >> index;

            index--;

            std::cout << Query (0, 0, data.size () - 1, index, index) << '\n';
        }

        else
        {
            lli l = 0, r = 0, value = 0;
            std::cin >> l >> r >> value;

            l--;
            r--;

            Modify (0, 0, data.size () - 1, l, r, value);
        }
    }

    return 0;
}
