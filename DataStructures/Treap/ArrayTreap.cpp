struct Treap
{
    int x, y;
    int left, right;
    Treap (int x0 = 0): x (x0), y (rnd ()), left (-1), right (-1) {}
};

vector <Treap> ram;

int Make (int x0 = 0)
{
    ram.push_back (Treap (x0));
    return int (ram.size ()) - 1;
}

void Update (int root)
{
}

pair <int, int> Split (int root, int x0)
{
    if (root == -1)
        return make_pair (-1, -1);
    if (ram[root].x <= x0)
    {
        auto tmp = Split (ram[root].right, x0);
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

int Insert (int root, int current)
{
    auto tmp = Split (root, ram[current].x - 1);
    return Merge (Merge (tmp.first, current), tmp.second);
}
