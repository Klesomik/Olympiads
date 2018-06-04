#include <bits/stdc++.h>

typedef long long int lli;

const lli mod = 1e9 + 7;

std::vector <lli> p;

lli Mod (lli a, lli b);
void FillP ();
void Hash (std::string& current, lli& hash);
void Hash (std::string& current, std::vector <lli>& hash);
lli SubHash (std::vector <lli>& hash, lli l, lli r);

lli Mod (lli a, lli b)
{
    return (a % b + b) % b;
}

void FillP ()
{
    p.resize (100);

    p[0] = 1;

    for (lli i = 1; i < p.size (); i++)
        p[i] = Mod(p[i - 1] * 31, mod);

    std::reverse (p.begin (), p.end ());
}

void Hash (std::string& current, lli& hash)
{
    for (lli i = 0; i < current.size (); i++)
        hash = Mod (hash + Mod (current[i] * p[i], mod), mod);
}

void Hash (std::string& current, std::vector <lli>& hash)
{
    hash[0] = Mod(current[0] * p[0], mod);

    for (lli i = 1; i < hash.size(); i++)
        hash[i] = Mod(hash[i - 1] + Mod(current[i] * p[i], mod), mod);
}

lli SubHash (std::vector <lli>& hash, lli l, lli r)
{
    if (l == 0)
        return hash[r];

    return Mod (hash[r] - hash[l - 1], mod);
}
