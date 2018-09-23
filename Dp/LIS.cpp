int LIS (vector <int>& data)
{
    Segtree from (n); // max on segment
    for (int i = 0; i < n; i++)
    {
        int value = (data[i] > 0? from.query (0, data[i] - 1, 0, 0, n - 1) : 0);
        from.update (data[i], value + 1, 0, 0, n - 1);
    }
    int result = 0;
    for (int i = 0; i < n; i++)
        result = max (result, from.query (i, i, 0, 0, n - 1));
    return result;
}
