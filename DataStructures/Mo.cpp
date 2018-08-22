//{

#include <bits/stdc++.h>

#define all(x) x.begin (), x.end ()
#define rall(x) x.rbegin (), x.rend ()

#define LOCAL

using namespace std;

using lli = long long;
using ld = long double;

mt19937 rnd (time (nullptr));

//}

const lli block = 350;

struct Value
{
    lli l, r, id;
};

bool operator < (const Value& a, const Value& b)
{
    lli b1 = a.l / block, b2 = b.l / block;
    if (b1 != b2)
        return a.l < b.l;
    return a.r < b.r;
}

lli n = 0, m = 0, k = 0;
vector <lli> data;
vector <Value> qrs;
lli Left = 1, Right = 0; // means empty segment
lli result = 0;
vector <lli> answer;

vector <lli> prefix;
vector <lli> counter;

// All operations make in order!!!
void IncLeft ()
{
    counter[prefix[Left - 1]]--;
    result -= counter[k ^ prefix[Left - 1]];
    Left++;
}

void DecLeft ()
{
    Left--;
    result += counter[k ^ prefix[Left - 1]];
    counter[prefix[Left - 1]]++;
}

void IncRight ()
{
    Right++;
    result += counter[k ^ prefix[Right]];
    counter[prefix[Right]]++;
}

void DecRight ()
{
    counter[prefix[Right]]--;
    result -= counter[k ^ prefix[Right]];
    Right--;
}

void Process (Value& current)
{
    while (Right < current.r)
        IncRight ();
    while (Left < current.l)
        IncLeft ();
    while (Left > current.l)
        DecLeft ();
    while (Right > current.r)
        DecRight ();
    answer[current.id] = result;
}

inline void Solve ()
{
    cin >> n >> m >> k;
    data.resize (n + 1);
    for (lli i = 1; i <= n; i++)
        cin >> data[i];
    qrs.resize (m);
    for (lli i = 0; i < m; i++)
    {
        cin >> qrs[i].l >> qrs[i].r;
        qrs[i].id = i;
    }
    sort (all (qrs));
    answer.resize (m);
    prefix.resize (n + 1);
    prefix[0] = 0;
    for (lli i = 1; i <= n; i++)
        prefix[i] = (prefix[i - 1] ^ data[i]);
    counter.resize (2e6);
    counter[0] = 1;
    for (auto &it : qrs)
        Process (it);
    for (auto &it : answer)
        cout << it << '\n';
}

signed main ()
{
#ifndef LOCAL
    ios_base::sync_with_stdio (false);
    cin.tie (nullptr);
    cout.tie (nullptr);
#endif
    cout << fixed << setprecision (20);
    Solve ();
    return 0;
}
