struct MQueue
{
    deque <int> buffer;
    MQueue (): buffer () {}

    bool empty () { return buffer.empty (); }

    void push (int value);
    void pop (int value);
    int query ();
};

void MQueue::push (int value)
{
    while ((!buffer.empty ()) && (buffer.back () < value))
        buffer.pop_back ();
    buffer.push_back (value);
}

void MQueue::pop (int value)
{
    if ((!buffer.empty ()) && (buffer.front () == value))
        buffer.pop_front ();
}

int MQueue::query ()
{
    assert (!buffer.empty ());
    return buffer.front ();
}
