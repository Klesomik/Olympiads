#include <bits/stdc++.h>

using namespace std;

typedef long long int lli;

const lli Inf = 1e10;

struct Treap
{
    lli value, y;
    lli sz, minimum;
    bool reversed;

    Treap *left, *right;

    Treap (lli value0 = 0, lli y0 = 0): value (value0), y (y0), sz (1), minimum (value0), reversed (false), left (nullptr), right (nullptr) {}

    void recalc ();
    void push ();
};

typedef Treap* PTreap;

lli GetSz (PTreap root)
{
    return (root == nullptr? 0 : root->sz);
}

lli GetMin (PTreap root)
{
    return (root == nullptr? Inf : root->minimum);
}

lli KthElement (PTreap root, lli k)
{
    lli sl = GetSz (root->left);

    if (sl == k)
        return root->value;

    if (sl > k)
        return KthElement (root->left, k);

    return KthElement (root->right, k - (sl + 1));
}

void Split (PTreap root, lli x0, PTreap& l, PTreap& r)
{
    if (!root)
    {
        l = r = nullptr;

        return;
    }

    root->push ();

    lli sl = GetSz (root->left);

    if (sl + 1 <= x0)
    {
        Split (root->right, x0 - (sl + 1), root->right, r), l = root;

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
    if ((!l) && (!r))
        root = nullptr;

    else if (!l)
    {
        r->push ();
        root = r;
    }

    else if (!r)
    {
        l->push ();
        root = l;
    }

    else
    {
        l->push ();
        r->push ();

        if (l->y > r->y)
            Merge (l->right, l->right, r), root = l;

        else
            Merge (r->left, l, r->left), root = r;

        root->recalc ();
    }
}

void Treap::recalc ()
{
    sz = GetSz (left) + GetSz (right) + 1;
    minimum = min (value, min (GetMin (left), GetMin (right)));
}

void Treap::push ()
{
    if (reversed)
    {
        if (left)
            left->reversed ^= true;

        if (right)
            right->reversed ^= true;

        PTreap tmp = left;
                     left = right;
                            right = tmp;

        reversed = false;
    }
}

void Cat (PTreap& root, PTreap current)
{
    if (!root)
    {
        root = current;

        return;
    }

    Merge (root, root, current);
}

void Insert (PTreap& root, PTreap current, lli position)
{
    PTreap first = nullptr, second = nullptr;

    Split (root, position, first, second);

    Merge (first, first, current);
    Merge (first, first, second);

    root = first;
}

lli Min (PTreap root, lli l, lli r)
{
    PTreap first = nullptr, second = nullptr, third = nullptr;

    Split (root, l, first, second);
    Split (second, r - l + 1, second, third);

    lli result = GetMin (second);

    Merge (first, first, second);
    Merge (first, first, third);

    root = first;

    return result;
}

void RevSubTree (PTreap& root, lli l, lli r)
{
    PTreap first = nullptr, second = nullptr, third = nullptr;

    Split (root, l, first, second);
    Split (second, r - l + 1, second, third);

    second->reversed ^= true;

    Merge (first, first, second);
    Merge (first, first, third);

    root = first;
}

int main ()
{
    lli n = 0, m = 0;
    cin >> n >> m;

    vector <lli> priors (n);

    for (lli i = 0; i < n; i++)
        priors[i] = i;

    random_shuffle (priors.begin (), priors.end ());

    PTreap root = nullptr;

    for (lli i = 0; i < n; i++)
    {
        lli value = 0;
        cin >> value;

        PTreap current = new Treap (value, priors[i]);

        Merge (root, root, current);
    }

    for (lli i = 0; i < m; i++)
    {
        lli cmd = 0, l = 0, r = 0;
        cin >> cmd >> l >> r;
        l--, r--;

        if (cmd == 1)
            RevSubTree (root, l, r);

        else if (cmd == 2)
            cout << Min (root, l, r) << '\n';
    }

    return 0;
}
