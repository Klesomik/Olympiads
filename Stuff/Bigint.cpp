struct Bigint
{
    vector <int> digits;
    Bigint (): digits (1, 0) {}
    void normalize ();

    int size () { return digits.size (); }
    void resize (int sz) { digits.resize (sz); }
    void push_back (int x) { digits.push_back (x); }
    int& operator [] (int id) { return digits[id]; }
};

void Bigint::normalize ()
{
    while ((digits.size () > 1) && (digits.back () == 0))
        digits.pop_back ();
}

ostream& operator << (ostream& out, Bigint& a)
{
    for (int i = (int) a.size () - 1; i >= 0; i--)
        out << a[i];
    return out;
}

istream& operator >> (istream& in, Bigint& a) // a >= 0
{
    string buffer;
    in >> buffer;
    reverse (all (buffer));
    a.resize (buffer.size ());
    for (int i = 0; i < buffer.size (); i++)
        a[i] = (buffer[i] - '0');
    a.normalize ();
    return in;
}

Bigint operator + (Bigint& a, Bigint& b)
{
    int sz = max (a.size (), b.size ());
    Bigint c;
    c.resize (sz);
    int carry = 0;
    for (int i = 0; i < sz; i++)
    {
        c[i] = (i < a.size ()? a[i] : 0) + (i < b.size ()? b[i] : 0) + carry;
        carry = 0;
        if (c[i] >= 10)
        {
            c[i] -= 10;
            carry = 1;
        }
    }
    if (carry > 0)
        c.push_back (carry);
    c.normalize ();
    return c;
}

Bigint operator - (Bigint& a, Bigint& b) // a >= b
{
    Bigint c;
    c = a;
    int carry = 0;
    for (int i = 0; (i < b.size ()) || (carry > 0); i++)
    {
        c[i] -= (i < b.size ()? b[i] : 0) + carry;
        carry = (c[i] < 0? 1 : 0);
        if (carry > 0)
            c[i] += 10;
    }
    c.normalize ();
    return c;
}

Bigint operator * (Bigint& a, Bigint& b)
{
    Bigint c;
    c.resize (a.size () + b.size ());
    int carry = 0;
    for (int i = 0; (i < a.size ()) || (carry > 0); i++)
    {
        for (int j = 0; (j < b.size ()) || (carry > 0); j++)
        {
            int current = c[i + j] + (i < a.size ()? a[i] : 0) * (j < b.size ()? b[j] : 0) + carry;
            c[i + j] = current % 10;
            carry = current / 10;
        }
    }
    c.normalize ();
    return c;
}

Bigint Karatsuba (Bigint& a, Bigint& b)
{
    if (min (a.size (), b.size ()) <= 64)
        return (a * b);
    int sz = max (a.size (), b.size ());
    if (sz % 2 != 0)
        sz++;
    a.resize (sz);
    b.resize (sz);
    int k = sz / 2;
    Bigint a_l, a_r, b_l, b_r;
    a_r.digits = { a.digits.begin (), a.digits.begin () + k };
    a_l.digits = { a.digits.begin () + k, a.digits.end () };
    b_r.digits = { b.digits.begin (), b.digits.begin () + k };
    b_l.digits = { b.digits.begin () + k, b.digits.end () };
    Bigint p1 = Karatsuba (a_l, b_l);
    Bigint p2 = Karatsuba (a_r, b_r);
    Bigint tmp1 = a_l + a_r, tmp2 = b_l + b_r;
    Bigint p3 = Karatsuba (tmp1, tmp2);
    p3 = p3 - p1;
    p3 = p3 - p2;
    Bigint p4;
    p4.resize (p1.size () + 2 * k);
    for (int i = 0; i < p1.size (); i++)
        p4[2 * k + i] = p1[i];
    Bigint p5;
    p5.resize (p3.size () + k);
    for (int i = 0; i < p3.size (); i++)
        p5[k + i] = p3[i];
    Bigint c;
    c = c + p4;
    c = c + p5;
    c = c + p2;
    c.normalize ();
    return c;
}
