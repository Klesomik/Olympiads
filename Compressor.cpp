struct Compressor
{
    vector <int> buffer;
    Compressor (): buffer () {}
    void init (vector <int>& current);
    int get (int x);
};

void Compressor::init (vector <int>& current)
{
    buffer = current;
    sort (all (buffer));
    buffer.erase (unique (all (buffer)), buffer.end ());
}

int Compressor::get (int x)
{
    int y = lower_bound (all (buffer), x) - buffer.begin ();
    assert ((y != buffer.size ()) && (buffer[y] == x));
    return y;
}
