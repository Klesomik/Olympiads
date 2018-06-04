#include <bits/stdc++.h>

using namespace std;

struct Treap
{
    int x, y;
    int sz;

    Treap *left, *right;

    Treap (int x0 = 0, int yo = 0): x (x0), y (y0), sz (1), left (nullptr), right (nullptr) {}

    void recalc ();
};

typedef Treap* PTreap;

int GetSz (PTreap root)
{
    return (root == nullptr? 0 : root->sz);
}

int KthElement (PTreap root, int k)
{
    int sl = GetSz (root->left);

    if (sl == k)
        return root->x;

    if (sl > k)
        return KthElement (root->left, k);

    return KthElement (root->right, k - (sl + 1));
}

void Split (PTreap root, int x0, PTreap& l, PTreap& r)
{
    if (!root)
        l = r = nullptr;

    else if (root->x < x0)
    {
        Split (root->right, x0, root->right, r), l = root;

        l->recalc ();
    }

    else
    {
        Split (root->left, x0, l, root->left), r = root;

        r->recalc ();
    }
}

void Merge (PTreap& root, PTreap l, PTreap r)
{
    if ((!l) || (!r))
        root = (l? l : r);

    else
    {
        if (l->y >= r->y)
            Merge (l->right, l->right, r), root = l;

        else
            Merge (r->left, l, r->left), root = r;

        root->recalc ();
    }
}

void Treap::recalc ()
{
    sz = GetSz (left) + GetSz (right) + 1;
}

void Insert (PTreap& root, PTreap current)
{
    if (!root)
    {
        root = current;

        return;
    }

    PTreap l, r;

    Split (root, current->x, l, r);

    Merge (l, l, current);
    Merge (root, l, r);
}

bool Find (PTreap& current, int value)
{
    if (!current)
        return false;

    if (current->x == value)
        return true;

    if (current->x < value)
        return FindElement (current->right, value);

    return FindElement (current->left, value);
}
