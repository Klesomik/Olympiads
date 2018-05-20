Vector start;

lli Rotate (Vector o, Vector a, Vector b)
{
    return cross (Vector (o, a), Vector (o, b));
}

bool operator < (const Vector& f, const Vector& s)
{
    Vector a (start, f), b (start, s);
    lli value = Rotate (start, f, s);
    if (value != 0)
        return value > 0;
    return a.len () < b.len ();
}

void GrahamScan (vector <Vector>& data, vector <Vector>& hull)
{
    for (lli i = 1; i < data.size (); i++)
        if (data[i].x < data[0].x)
            swap (data[0], data[i]);
    start = data[0];
    sort (data.begin () + 1, data.end ());
    hull.push_back (data[0]);
    for (lli i = 1; i < data.size (); i++)
    {
        while ((hull.size () >= 2) && (Rotate (hull[hull.size () - 1], data[i], hull[hull.size () - 2]) <= 0))
            hull.pop_back ();
        hull.push_back (data[i]);
    }
}
