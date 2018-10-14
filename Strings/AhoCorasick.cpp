//{

#include <bits/stdc++.h>

#define forn(i, a, b) for (auto i = a; i <= b; i++)
#define all(x) x.begin (), x.end ()
#define rall(x) x.rbegin (), x.rend ()
#define mp make_pair
#define pii pair <int, int>
#define pb push_back

//#define LOCAL

using namespace std;

using lli = long long;
using ld = long double;

mt19937 rnd (time (nullptr));

//}

vector <bool> answer;
vector <int> buffer;

struct Vertex
{
    int leaf;
    int p;
    int pch;
    int link;
    int go[26];
    int up;
    Vertex (): leaf (-1), p (-1), pch (0), link (-1), up (-1) { for (int i = 0; i < 26; i++) go[i] = -1; }
};

struct Trie
{
    vector <Vertex> tree;
    Trie (): tree (1) {}
    void add (string& value, int index);
    int get_link (int v);
    int get_go (int v, int c);
    int get_up (int v);
    void bfs ();
    void process (string& text);
};

void Trie::add (string& value, int index)
{
    int current = 0;
    for (int i = 0; i < value.size (); i++)
    {
        int c = (value[i] - 'a');
        if (tree[current].go[c] == -1)
        {
            tree.push_back (Vertex ());
            tree[current].go[c] = tree.size () - 1;
            tree[tree.size () - 1].p = current;
            tree[tree.size () - 1].pch = c;
        }
        current = tree[current].go[c];
    }
    if (tree[current].leaf == -1)
        tree[current].leaf = index;
    else
        buffer[index] = tree[current].leaf;
}

int Trie::get_link (int v)
{
    if (tree[v].link == -1)
    {
        if ((v == 0) || (tree[v].p == 0))
            tree[v].link = 0;
        else
            tree[v].link = get_go (get_link (tree[v].p), tree[v].pch);
    }
    return tree[v].link;
}

int Trie::get_go (int v, int c)
{
    if (tree[v].go[c] == -1)
    {
        /*if (tree[v].next[c] != -1)
            tree[v].go[c] = tree[v].next[c];
        else*/
            tree[v].go[c] = (v == 0? 0 : get_go (get_link (v), c));
    }
    return tree[v].go[c];
}

int Trie::get_up (int v)
{
    if (tree[v].up == -1)
    {
        int prev = get_link (v);
        if ((tree[prev].leaf != -1) || (prev == 0))
            tree[v].up = prev;
        else
            tree[v].up = get_up (prev);
    }
    return tree[v].up;
}

void Trie::bfs ()
{
    queue <int> q;
    vector <bool> used (tree.size ());
    q.push (0);
    used[0] = true;
    while (!q.empty ())
    {
        int v = q.front ();
        q.pop ();
        get_link (v);
        for (int c = 0; c < 26; c++)
        {
            get_go (v, c);
            if (!used[tree[v].go[c]])
            {
                q.push (tree[v].go[c]);
                used[tree[v].go[c]] = true;
            }
        }
        get_up (v);
    }
}

void Trie::process (string& text)
{
    int current = 0;
    for (int i = 0; i < text.size (); i++)
    {
        int c = text[i] - 'a';
        current = tree[current].go[c];
        for (int vertex = current; vertex != 0;)
        {
            if ((tree[vertex].leaf == -1) && (vertex != current))
                break;
            if (tree[vertex].leaf != -1)
            {
                answer[tree[vertex].leaf] = true;
                tree[vertex].leaf = -1;
            }
            vertex = tree[vertex].up;
        }
    }
}

inline void Solve ()
{
    int n = 0;
    cin >> n;
    answer.resize (n);
    buffer.resize (n, -1);
    Trie from;
    for (int i = 0; i < n; i++)
    {
        string current;
        cin >> current;
        from.add (current, i);
    }
    string data;
    cin >> data;
    from.bfs ();
    from.process (data);
    for (int i = 0; i < n; i++)
    {
        if (answer[i])
            cout << "YES\n";
        else
        {
            if ((buffer[i] != -1) && (answer[buffer[i]]))
                cout << "YES\n";
            else
                cout << "NO\n";
        }
    }
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
