vector <int> GetLCP (string& data, vector <int>& suffix)
{
    int n = data.size ();
    vector <int> ord (n);
    for (int i = 0; i < n; i++)
        ord[suffix[i]] = i;
    vector <int> lcp (n - 1);
    int len = 0;
    for (int i = 0; i < n; i++)
    {
        if (ord[i] == n - 1)
            continue;
        if (len > 0)
            len--;
        int j = suffix[ord[i] + 1];
        while ((max (i, j) + len < n) && (data[i + len] == data[j + len]))
            len++;
        lcp[ord[i]] = len;
    }
    return lcp;
}
