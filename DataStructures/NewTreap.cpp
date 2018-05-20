struct Treap
{
    int x, y;
    int sz;
    Treap *left, *right;
    Treap (int x0 = 0): x (x0), y (rnd ()), sz (1), left (nullptr), right (nullptr) {}
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
        if (root->x <= x0)
        {
            Split (root->right, x0, root->right, r), l = root;
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

void Insert (PTreap& root, PTreap current)
{
    PTreap first = nullptr, second = nullptr;
    Split (root, current->x - 1, first, second);
    Merge (first, first, current);
    Merge (first, first, second);
    root = first;
}
