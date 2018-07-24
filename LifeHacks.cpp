freopen ("", "r", stdin);
freopen ("", "w", stdout);

__gcd (value1, value2);
__builtin_ffs (x);
__builtin_clz (x);
__builtin_ctz (x);
__builtin_popcount (x);

// Make unique elements in vector
vector <int> v;
sort (all (v));
v.erase (unique (all (v)), v.end ());

// Erase only single element
multiset <int> data;
data.erase (data.find (value));

// This type contains more than long long
using ulli = unsigned long long;

// Faster 2 times
bool IsPrime (int x)
{
    if (n == 2)
        return true;
    if (n % 2 == 0)
        return false;
    for (int i = 3; i * i <= n; i += 2)
        if (n % i == 0)
            return false;
    return true;
}

// TODO: how does it work?
long long val1 = 0;
scanf ("%I64d", &val);

int val2 = 0;
scanf ("%02d", &val2);
