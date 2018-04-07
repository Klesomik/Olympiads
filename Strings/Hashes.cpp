#include <bits/stdc++.h>

using namespace std;

typedef long long int lli;

const lli p = 31; //53
const lli mod = 1e9 + 7;
vector <lli> p_pow;

lli Mod (lli a, lli b)
{
    return (a % b + b) % b;
}

lli Add (lli a, lli b)
{
    return Mod (a + b, mod);
}

lli Sub (lli a, lli b)
{
    return Mod (a - b, mod);
}

lli Mul (lli a, lli b)
{
    return Mod (a * b, mod);
}

void FillPPow ()
{
    p_pow.resize (1e7);

    p_pow[0] = 1;

    for (lli i = 1; i < p_pow.size (); i++)
        p_pow[i] = Mul (p_pow[i - 1], p);

    reverse (p_pow.begin (), p_pow.end ());
}

void Hash (string& data, lli& result)
{
    for (lli i = 0; i < data.size (); i++)
        result = Add (result, Mul ((data[i] - 'a' + 3), p_pow[i]));
}

void Hash (string& data, vector <lli>& result)
{
    result.resize (data.size ());

    result[0] = Mul ((data[0] - 'a' + 3), p_pow[0]);

    for (lli i = 1; i < data.size (); i++)
        result[i] = Add (result[i - 1], Mul ((data[i] - 'a' + 3), p_pow[i]));
}

lli SubHash (vector <lli>& result, lli l, lli r)
{
    if (l == 0)
        return result[r];

    return Sub (result[r], result[l - 1]);
}

bool IsEqual (vector <lli>& result, lli l1, lli r1, lli l2, lli r2)
{
    if ((r1 - l1 + 1) != (r2 - l2 + 1))
        return false;

    lli h1 = SubHash (result, l1, r1),
        h2 = SubHash (result, l2, r2);

    if (r2 > r1)
        h2 = Mul (h2, p_pow[p_pow.size () - 1 - (r2 - r1)]);

    else
        h1 = Mul (h1, p_pow[p_pow.size () - 1 - (r1 - r2)]);

    return (h1 == h2);
}

int main ()
{
    return 0;
}
