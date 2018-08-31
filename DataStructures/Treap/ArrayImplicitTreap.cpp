struct Treap
{
    int y;
    int value;
    int sz;
    int left, right;
    Treap (int value0 = 0): y (rnd ()), value (value0), sz (1), left (-1), right (-1) {}
};

vector <Treap> ram;

int Make (int value0 = 0)
{
    ram.push_back (Treap (value0));
    return int (ram.size ()) - 1;
}

int GetSz (int root)
{
    return (root != -1? ram[root].sz : 0);
}

void Update (int root)
{
    ram[root].sz = GetSz (ram[root].left) + GetSz (ram[root].right) + 1;
}

pair <int, int> Split (int root, int x0)
{
    if (root == -1)
        return make_pair (-1, -1);
    int sl = GetSz (ram[root].left);
    if (sl + 1 <= x0)
    {
        auto tmp = Split (ram[root].right, x0 - (sl + 1));
        ram[root].right = tmp.first;
        Update (root);
        return make_pair (root, tmp.second);
    }
    else
    {
        auto tmp = Split (ram[root].left, x0);
        ram[root].left = tmp.second;
        Update (root);
        return make_pair (tmp.first, root);
    }
}

int Merge (int l, int r)
{
    if (l == -1)
        return r;
    if (r == -1)
        return l;
    if (ram[l].y > ram[r].y)
    {
        ram[l].right = Merge (ram[l].right, r);
        Update (l);
        return l;
    }
    else
    {
        ram[r].left = Merge (l, ram[r].left);
        Update (r);
        return r;
    }
}

// Insert on place i; 0 <= i <= n - 1
int Insert (int root, int current, int index)
{
    auto tmp = Split (root, index);
    return Merge (Merge (tmp.first, current), tmp.second);
}
