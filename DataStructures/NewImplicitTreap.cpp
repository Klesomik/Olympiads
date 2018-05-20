struct Treap
{
    int y;
    int value;
    int sz;
    Treap *left, *right;
    Treap (int value0 = 0): y (rnd ()), value (value0), sz (1), left (nullptr), right (nullptr) {}
    void update ();
};

using PTreap = Treap*;

int GetSz (PTreap root)
{
    return (root? root->sz : 0);
}

void Treap::update ()
{
    sz = GetSz (left) + GetSz (right) + 1;
}

void Split (PTreap root, int x0, PTreap& l, PTreap& r)
{
    if (!root)
        l = r = nullptr;
    else
    {
        int sl = GetSz (root->left);
        if (sl + 1 <= x0)
        {
            Split (root->right, x0 - (sl + 1), root->right, r), l = root;
            l->update ();
        }
        else
        {
            Split (root->left, x0, l, root->left), r = root;
            r->update ();
        }
    }
}

void Merge (PTreap& root, PTreap l, PTreap r)
{
    if ((!l) || (!r))
        root = (l? l : r);
    else
    {
        if (l->y > r->y)
            Merge (l->right, l->right, r), root = l;
        else
            Merge (r->left, l, r->left), root = r;
        root->update ();
    }
}

// Insert on place i; 0 <= i <= n - 1
void Insert (PTreap& root, PTreap current, int index)
{
    PTreap first = nullptr, second = nullptr;
    Split (root, index, first, second);
    Merge (first, first, current);
    Merge (first, first, second);
    root = first;
}
