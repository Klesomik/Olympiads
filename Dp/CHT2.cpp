struct CHT
{
    vector <Vector> hull, vecs;
    void add (int k, int b);
    int get (int x);
};

void add (int k, int b)
{
    Vector nw (k, b);
    while ((!vecs.empty ()) && (dot (vecs.back (), nw - hull.back ()) < 0))
    {
        hull.pop_back ();
        vecs.pop_back ();
    }
    if (!hull.empty ())
        vecs.push_back (1i * (nw - hull.back ()));
    hull.push_back (nw);
}

int get (int x)
{
    Vector query (x, 1);
    auto it = lower_bound (all (vecs), query, [] (const Vector& a, const Vector& b)
    {
        return (cross (a, b) > 0);
    });
    return dot (query, hull[it - vecs.begin ()]);
}
