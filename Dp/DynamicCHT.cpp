const int is_query = -(1 << 62);

struct Line
{
    int m, b;
    mutable function<const Line *()> succ;
};

bool operator<(const Line &lhs, const Line &rhs) const
{
    if (rhs.b != is_query)
        return lhs.m < rhs.m;
    const Line *s = succ();
    if (!s)
        return 0;
    int x = rhs.m;
    return lhs.b - s->b < (s->m - lhs.m) * x;
}

struct HuintDynamic : public multiset<Line> // will maintain upper hull for maximum
{
    bool bad(iterator y);
    void add (int m, int b);
    int get (int x);
};

bool bad(iterator y)
{
    auto z = next(y);
    if (y == begin())
    {
        if (z == end()) return 0;
        return y->m == z->m && y->b <= z->b;
    }
    auto x = prev(y);
    if (z == end()) return y->m == x->m && y->b <= x->b;
    return (x->b - y->b) * (long double) (z->m - y->m) >= (y->b - z->b) * (long double) (y->m - x->m);
}

void add (int m, int b)
{
    auto y = insert({m, b});
    y->succ = [=] { return next(y) == end() ? 0 : &*next(y); };
    if (bad(y)) {
        erase(y);
        return;
    }
    while (next(y) != end() && bad(next(y))) erase(next(y));
    while (y != begin() && bad(prev(y))) erase(prev(y));
}

int get (int x)
{
    auto l = *lower_bound((Line) {x, is_query});
    return l.m * x + l.b;
}
