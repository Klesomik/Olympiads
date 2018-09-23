int Rotate (Vector o, Vector a, Vector b)
{
    return cross (Vector (o, a), Vector (o, b));
}

void GrahamScan (vector <Vector>& data, vector <Vector>& hull)
{
    for (int i = 1; i < data.size (); i++)
        if (data[i].x < data[0].x)
            swap (data[0], data[i]);
    sort (data.begin () + 1, data.end (), [data[0]] (const Vector& f, const Vector& s)
    {
        Vector a (data[0], f), b (data[0], s);
        int value = Rotate (data[0], f, s);
        if (value != 0)
            return value > 0;
        return a.len2 () < b.len2 ();
    });
    hull.push_back (data[0]);
    for (int i = 1; i < data.size (); i++)
    {
        while ((hull.size () >= 2) && (Rotate (hull[hull.size () - 1], data[i], hull[hull.size () - 2]) <= 0))
            hull.pop_back ();
        hull.push_back (data[i]);
    }
}
