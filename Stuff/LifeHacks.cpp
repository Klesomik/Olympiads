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
// Compare with it
buffer.resize (unique (all (buffer)) - buffer.begin ());

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

// TODO: how does it work? (Win)
long long val1 = 0;
scanf ("%I64d", &val);
// Or (Linux)
scanf ("%lld", &val);

int val2 = 0;
scanf ("%02d", &val2);

// перебор всех подмасок заданной маски
for (int mask = 0; mask < (1 << n); mask++)
    for (int sub = mask; sub > 0; sub = (sub - 1) & mask)

// декартово дерево из C++
#include <ext/pb_ds/assoc_container.hpp>
using namespace __gnu_pbds;

// set is Treap
template <class key, class cmp = less <key>>
using ordered_set = tree <key, null_type, cmp, rb_tree_tag, tree_order_statistics_node_update>;
ordered_set <int> my_set;

// map is Treap
template <class key, class value, class cmp = less <key>>
using ordered_map = tree <key, value, cmp, rb_tree_tag, tree_order_statistics_node_update>;
ordered_map <int, int> my_map;

// предподсчет логарифмов по основанию 2, основание может быть произвольным
vector <lli> LOG (1e6);
LOG[1] = 0;
for (lli i = 2; i < LOG.size (); i++)
    LOG[i] = LOG[i / 2] + 1;

// прагмы вроде иногда ускор€ют код
#pragma GCC optimize("Ofast")
#pragma GCC optimize("no-stack-protector")
#pragma GCC optimize("unroll-loops")
#pragma GCC target("sse,sse2,sse3,ssse3,popcnt,abm,mmx,tune=native")
#pragma GCC optimize("fast-math")

// g++ в codeblocks имеет маленький стек
#pragma comment(linker, "/stack:200000000")

// Output with n symbols
http://cppstudio.com/post/319/
cout.width(3);
// считать один символ
cin.get ();

// Find information about it
Debug in CodeBlocks
Cntrl+H -> Cntrl+R
GDB c++ CodeBlocks
теори€ веро€тностей, комбинаторика, теори€ чисел
√енераци€ выпуклого многоугольника

lhs, rhs

for (int _ = 0; _ < 150; _++)
{
	cout << "OK\n";
}

// рандом на Windows (MinGW)
#define rand() (rand()<<15+rand())

// Which is better?
mt19937 rnd (time (nullptr));
mt19937_64 rnd (system_clock ().now ().time_since_epoch ().count ());

// Which is better?
int main ()
main ()

// Which is better?
(double) x
double (x)

// GetTime
double GetTime ()
{
    return 1.0 * clock () / CLOCKS_PER_SEC;
}

int UpperDiv (int a, int b)
{
    return (a + b - 1) / b;
}

int UpperDiv (int a, int b)
{
    return (a - 1) / b + 1;
}

int UpperDiv (int a, int b)
{
    if (a % b == 0)
        return a / b;
    return a / b + 1;
}

// не будет работать, если b < 0
int UpperDiv (int a, int b)
{
    if (a * b < 0)
        return a / b;
    if (a % b == 0)
        return a / b;
    return a / b + 1;
}
