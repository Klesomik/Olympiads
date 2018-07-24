vector <int> SuffixArray (string& s)
{
    const int alpha = 1e5 + 100;
    s.push_back (0);
    int n = s.size ();
    vector <int> p (n), c (n), cnt (alpha);
    for (int i = 0; i < n; i++)
        cnt[s[i]]++;
    for (int i = 1; i < alpha; i++)
        cnt[i] += cnt[i - 1];
    for (int i = n - 1; i >= 0; i--)
        p[--cnt[s[i]]] = i;
    c[p[0]] = 0;
    for (int i = 1; i < n; i++)
    {
        c[p[i]] = c[p[i - 1]];
        if (s[p[i]] != s[p[i - 1]])
            c[p[i]]++;
    }
    for (int k = 1; k < n; k *= 2)
    {
        vector <int> p2 (n), c2 (n);
        cnt.assign (alpha, 0);
        for (int i = 0; i < n; i++)
        {
            p2[i] = (p[i] - k);
            if (p2[i] < 0)
                p2[i] += n;
        }
        for (int i = 0; i < n; i++)
            cnt[c[p2[i]]]++;
        for (int i = 1; i < alpha; i++)
            cnt[i] += cnt[i - 1];
        for (int i = n - 1; i >= 0; i--)
            p[--cnt[c[p2[i]]]] = p2[i];
        c2[p[0]] = 0;
        for (int i = 1; i < n; i++)
        {
            c2[p[i]] = c2[p[i - 1]];
            if ((c[p[i]] != c[p[i - 1]]) || (c[(p[i] + k) % n] != c[(p[i - 1] + k) % n]))
                c2[p[i]]++;
        }
        c = c2;
    }
    s.pop_back ();
    p.erase (p.begin ());
    return p;
}
