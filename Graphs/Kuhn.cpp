int n = 0;
vector <int> values;
vector <vector <int>> graph;
vector <bool> used;
vector <int> link;
vector <int> order;

void Kuhn ();
bool TryDFS (int v);

void Kuhn ()
{
    used.resize (n);
    link.resize (2 * n, -1);
    for (int i = 0; i < n; i++)
    {
        used.assign (n, false);
        TryDFS (i);
    }
}

bool TryDFS (int v)
{
    if (used[v])
        return false;
    used[v] = true;
    for (auto it : graph[v])
    {
        if ((link[it] == -1) || (TryDFS (link[it])))
        {
            link[it] = v;
            return true;
        }
    }
    return false;
}
