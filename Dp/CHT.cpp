struct Value
{
    int k, b, id;
};

double Crossing (Value f, Value s)
{
    assert (f.k != s.k);
    return (double) (s.b - f.b) / (f.k - s.k);
}

struct CHT
{
    vector <Value> lines;
    vector <double> coords;
    CHT (): lines (), coords () {}
    void add (Value current);
    int query (int x0);
};

void CHT::add (Value current)
{
    while (lines.size () >= 2)
    {
        Value curr1 = lines[lines.size () - 1],
              curr2 = lines[lines.size () - 2];
        if ((curr1.k != current.k) && (Crossing (curr1, curr2) < Crossing (curr1, current)))
            break;
        lines.pop_back ();
        coords.pop_back ();
    }
    lines.push_back (current);
    if (lines.size () >= 2)
        coords.push_back (Crossing (lines[lines.size () - 1], lines[lines.size () - 2]));
}

int CHT::query(int x0)
{
    auto it = lower_bound (all (coords), (double) x0);
    if (it == coords.end ())
        return lines.back ().id;
    int index = it - coords.begin ();
    return lines[index].id;
}
