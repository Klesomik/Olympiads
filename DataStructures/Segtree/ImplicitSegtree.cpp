struct Vertex
{
    int minimum, counter;
    int tadd;
    int left, right;
    //Vertex (): sum (0), tadd (0), left (-1), right (-1), tl (-1), tr (-1) {}
};

const int MAX_N = 3e9;
const int shift = 1e9 + 100;

struct Segtree
{
    //const pair <int, int> Neutral = { 1e9, 0 };
    const int None = 0;
    vector <Vertex> tree;
    Segtree (int sz = 0): tree () { tree.push_back ({ 0, sz, None, -1, -1 }); }
    pair <int, int> query (int v, int tl, int tr);
    void update (int left, int right, int value, int v, int tl, int tr);
    void create_left (int v, int tl, int tr);
    void create_right (int v, int tl, int tr);
    void push (int v, int tl, int tr);
};

pair <int, int> Segtree::query (int v, int tl, int tr)
{
    create_left (v, tl, tr);
    create_right (v, tl, tr);
    push (v, tl, tr);
    return make_pair (tree[v].minimum, tree[v].counter);
}

void Segtree::update (int left, int right, int value, int v, int tl, int tr)
{
    create_left (v, tl, tr);
    create_right (v, tl, tr);
    push (v, tl, tr);
    if (tr < left || tl > right)
        return;
    if (tl >= left && tr <= right)
    {
        tree[v].tadd += value;
        push (v, tl, tr);
        return;
    }
    int tm = (tl + tr) / 2;
    update (left, right, value, tree[v].left, tl, tm);
    update (left, right, value, tree[v].right, tm + 1, tr);
    if (tree[tree[v].left].minimum == tree[tree[v].right].minimum)
    {
        tree[v].minimum = tree[tree[v].left].minimum;
        tree[v].counter = tree[tree[v].left].counter + tree[tree[v].right].counter;
    }
    else if (tree[tree[v].left].minimum < tree[tree[v].right].minimum)
    {
        tree[v].minimum = tree[tree[v].left].minimum;
        tree[v].counter = tree[tree[v].left].counter;
    }
    else
    {
        tree[v].minimum = tree[tree[v].right].minimum;
        tree[v].counter = tree[tree[v].right].counter;
    }
}

void Segtree::create_left (int v, int tl, int tr)
{
    if (tl == tr)
        return;
    if (tree[v].left == -1)
    {
        int tm = (tl + tr) / 2;
        tree.push_back ({ 0, tm - tl + 1, None, -1, -1 });
        tree[v].left = tree.size () - 1;
    }
}

void Segtree::create_right (int v, int tl, int tr)
{
    if (tl == tr)
        return;
    if (tree[v].right == -1)
    {
        int tm = (tl + tr) / 2;
        tree.push_back ({ 0, tr - (tm + 1) + 1, None, -1, -1 });
        tree[v].right = tree.size () - 1;
    }
}

void Segtree::push (int v, int tl, int tr)
{
    if (tree[v].tadd == None)
        return;
    tree[v].minimum += tree[v].tadd;
    if (tl != tr)
    {
        assert ((tree[v].left != -1) && (tree[v].right != -1));
        tree[tree[v].left].tadd += tree[v].tadd;
        tree[tree[v].right].tadd += tree[v].tadd;
    }
    tree[v].tadd = None;
}
