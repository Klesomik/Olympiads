vector <int> ZFunction (string& data)
{
    int n = data.size ();
    vector <int> z (n);
    for (int i = 1, l = 0, r = 0; i < n; i++)
    {
        if (i <= r)
            z[i] = min (r - i + 1, z[i - l]);
        while ((i + z[i] < n) && (data[z[i]] == data[i + z[i]]))
            z[i]++;
        if (i + z[i] - 1 > r)
            l = i, r = i + z[i] - 1;
    }
    return z;
}
