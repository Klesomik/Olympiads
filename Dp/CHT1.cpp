struct Value
{
    lli k, b, id;
};

double Crossing(Value f, Value s)
{
    if (f.k == s.k)
    {
        cout << "jgiogjsogpdgjdsih";
        exit (0);
    }
    return 1.0 * (s.b - f.b) / (f.k - s.k);
}

struct CHT
{
    vector <Value> lines;
    vector <double> coords;
    CHT (): lines (), coords () {}
    void add (Value current);
    lli query (lli x0);
};

void CHT::add (Value current)
{
    if ((lines.size () >= 1) && (lines.back ().k == current.k) && (current.b >= lines.back ().b))
        return;
    while ((lines.size () >= 1) && (lines.back ().k == current.k) && (current.b < lines.back ().b))
    {
        lines.pop_back ();
        if (coords.size () >= 1)
            coords.pop_back ();
    }
    while (lines.size () >= 2)
    {
        Value curr1 = lines[lines.size() - 1],
              curr2 = lines[lines.size() - 2];
        if (Crossing (curr1, curr2) < Crossing (curr1, current))
            break;
        lines.pop_back ();
        coords.pop_back ();
    }
    lines.push_back (current);
    if (lines.size () >= 2)
    {
        coords.push_back (Crossing (lines[lines.size () - 1], lines[lines.size () - 2]));
    }
}

lli CHT::query (lli x0)
{
    auto it = lower_bound (all (coords), 1.0 * x0);
    if (it == coords.end ())
        return lines.back ().id;
    lli index = it - coords.begin ();
    return lines[index].id;
}
