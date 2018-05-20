struct Segtree
{
    const int Neutral = 0, None = 0;
    vector <int> tree, tadd;
    Segtree (int sz = 0): tree (4 * sz), tadd (4 * sz, None) {}
    void build (vector <int>& value, int v, int tl, int tr);
    int query (int left, int right, int v, int tl, int tr);
    void update (int left, int right, int value, int v, int tl, int tr);
    void push (int v, int tl, int tr);
    int merge (int x, int y);
};

void Segtree::build (vector <int>& value, int v, int tl, int tr)
{
    if (tl == tr)
        tree[v] = value[tl];
    else
    {
        int tm = (tl + tr) / 2;
        build (value, 2 * v + 1, tl, tm);
        build (value, 2 * v + 2, tm + 1, tr);
        tree[v] = merge (tree[2 * v + 1], tree[2 * v + 2]);
    }
}

int Segtree::query (int left, int right, int v, int tl, int tr)
{
    push (v, tl, tr);
    if (left > tr || right < tl)
        return Neutral;
    if (tl >= left && right >= tr)
        return tree[v];
    int tm = (tl + tr) / 2;
    auto q1 = query (left, right, 2 * v + 1, tl, tm),
         q2 = query (left, right, 2 * v + 2, tm + 1, tr);
    return merge (q1, q2);
}

void Segtree::update (int left, int right, int value, int v, int tl, int tr)
{
    push (v, tl, tr);
    if (left > tr || right < tl)
        return;
    if (tl >= left && right >= tr)
    {
        tadd[v] += value;
        push (v, tl, tr);
        return;
    }
    int tm = (tl + tr) / 2;
    update (left, right, value, 2 * v + 1, tl, tm);
    update (left, right, value, 2 * v + 2, tm + 1, tr);
    tree[v] = merge (tree[2 * v + 1], tree[2 * v + 2]);
}

void Segtree::push (int v, int tl, int tr)
{
    if (tadd[v] == None)
        return;
    tree[v] += tadd[v];
    if (tl != tr)
    {
        tadd[2 * v + 1] += tadd[v];
        tadd[2 * v + 2] += tadd[v];
    }
    tadd[v] = None;
}

int Segtree::merge (int x, int y)
{
    return (x + y);
}
