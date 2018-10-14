struct Node
{
    int value;
    int l, r;
    Node (int value0 = 0): value (value0), l (-1), r (-1) {}
};

struct Segtree
{
    vector <Node> tree;
    Segtree (): tree () {}
    int make (int value0 = 0, int left0 = -1, int right0 = -1);
    int create (int tl, int tr);
    int query (int left, int right, int v, int tl, int tr);
    int update (int index, int value, int v, int tl, int tr);
};

int Segtree::make (int value0, int left0, int right0)
{
    Node tmp;
    tmp.value = value0;
    tmp.l = left0;
    tmp.r = right0;
    tree.push_back (tmp);
    return int (tree.size ()) - 1;
}

int Segtree::create (int tl, int tr)
{
    if (tl == tr)
    {
        return make ();
    }
    int tm = (tl + tr) / 2;
    int new_l = create (tl, tm);
    int new_r = create (tm + 1, tr);
    return make (0, new_l, new_r);
}

int Segtree::query (int left, int right, int v, int tl, int tr)
{
    if (tr < left || tl > right)
        return 0;
    if (tl >= left && tr <= right)
        return tree[v].value;
    int tm = (tl + tr) / 2;
    auto q1 = query (left, right, tree[v].l, tl, tm),
         q2 = query (left, right, tree[v].r, tm + 1, tr);
    return (q1 + q2);
}

int Segtree::update (int index, int value, int v, int tl, int tr)
{
    if (tl == tr)
        return make (value);
    int tm = (tl + tr) / 2;
    if (index <= tm)
    {
        int new_l = update (index, value, tree[v].l, tl, tm);
        return make (tree[new_l].value + tree[tree[v].r].value, new_l, tree[v].r);
    }
    else
    {
        int new_r = update (index, value, tree[v].r, tm + 1, tr);
        return make (tree[tree[v].l].value + tree[new_r].value, tree[v].l, new_r);
    }
}

inline void Solve ()
{
    int n = 4;
    Segtree from;
    int root = from.create (0, n - 1);
    for (int i = 0; i < n; i++)
    {
        root = from.update (i, i + 1, root, 0, n - 1);
    }
    cout << from.query (0, n - 1, root, 0, n - 1);
}
