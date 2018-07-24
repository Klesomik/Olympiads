const lli p = 31; //53
const lli mod = 1e9 + 7;
vector <lli> base;

void FillBase (lli sz)
{
    base.resize (sz);
    base[0] = 1;
    for (lli i = 1; i < sz; i++)
        base[i] = Mul (base[i - 1], p);
    reverse (all (base));
}

void Hash (string& data, lli& result)
{
    for (lli i = 0; i < data.size (); i++)
        result = Add (result, Mul ((data[i] - 'a' + 3), base[i]));
}

void Hash (string& data, vector <lli>& result)
{
    result.resize (data.size ());
    result[0] = Mul ((data[0] - 'a' + 3), base[0]);
    for (lli i = 1; i < data.size (); i++)
        result[i] = Add (result[i - 1], Mul ((data[i] - 'a' + 3), base[i]));
}

lli SubHash (vector <lli>& result, lli l, lli r)
{
    if (l == 0)
        return result[r];
    return Mul (base[base.size () - 1 - l], Sub (result[r], result[l - 1]));
}

bool IsEqual (vector <lli>& result, lli l1, lli r1, lli l2, lli r2)
{
    if ((r1 - l1 + 1) != (r2 - l2 + 1))
        return false;
    lli h1 = SubHash (result, l1, r1),
        h2 = SubHash (result, l2, r2);
    return (h1 == h2);
}
