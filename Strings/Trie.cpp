struct Vertex
{
    vector <int> next;
    bool leaf;
    Vertex (): next (26, -1), leaf (false) {}
};

struct Trie
{
    vector <Vertex> tree;
    Trie (): tree (1) {}
    void add (string& value);
    bool check (string& value);
};

void Trie::add (string& value)
{
    int current = 0;
    for (int i = 0; i < value.size (); i++)
    {
        int c = value[i] - 'a';
        if (tree[current].next[c] == -1)
        {
            tree.push_back (Vertex ());
            tree[current].next[c] = tree.size () - 1;
        }
        current = tree[current].next[c];
    }
    tree[current].leaf = true;
}

bool Trie::check (string& value)
{
    int current = 0;
    for (int i = 0; i < value.size (); i++)
    {
        int c = value[i] - 'a';
        if (tree[current].next[c] == -1)
            return false;
        current = tree[current].next[c];
    }
    return (tree[current].leaf);
}
