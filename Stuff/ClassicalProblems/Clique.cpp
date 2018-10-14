int Clique (vector <vector <int>>& data)
{
    int n = data.size ();
    int a = n / 2, b = n - n / 2;
    vector <int> neighbours1 (a), neighbours2 (b), neighbours3 (a);
    for (int i = 0; i < a; i++)
    {
        for (int j = 0; j < a; j++)
            if (data[i][j] == 1)
                neighbours1[i] |= (1 << j);
    }
    for (int i = 0; i < b; i++)
    {
        for (int j = 0; j < b; j++)
            if (data[i + a][j + a] == 1)
                neighbours2[i] |= (1 << j);
    }
    for (int i = 0; i < a; i++)
    {
        for (int j = 0; j < b; j++)
            if (data[i][j + a] == 1)
                neighbours3[i] |= (1 << j);
    }
    vector <bool> clique1 (1 << a), clique2 (1 << b);
    for (int i = 0; i < a; i++)
        clique1[(1 << i)] = true;
    for (int mask = 0; mask < (1 << a); mask++)
    {
        if (!clique1[mask])
            continue;
        for (int j = 0; j < a; j++)
            if ((neighbours1[j] & mask) == mask)
                clique1[mask | (1 << j)] = true;
    }
    for (int i = 0; i < b; i++)
        clique2[(1 << i)] = true;
    for (int mask = 0; mask < (1 << b); mask++)
    {
        if (!clique2[mask])
            continue;
        for (int j = 0; j < b; j++)
            if ((neighbours2[j] & mask) == mask)
                clique2[mask | (1 << j)] = true;
    }
    vector <int> dp (1 << b);
    for (int mask = 0; mask < (1 << b); mask++)
    {
        if (clique2[mask])
            dp[mask] = __builtin_popcount (mask);
        else
        {
            for (int j = 0; j < b; j++)
                if ((mask >> j) & 1)
                    dp[mask] = max (dp[mask], dp[mask ^ (1 << j)]);
        }
    }
    int result = 0;
    for (int mask = 0; mask < (1 << a); mask++)
    {
        if (!clique1[mask])
            continue;
        int mask1 = (1 << b) - 1;
        for (int j = 0; j < a; j++)
            if ((mask >> j) & 1)
                mask1 &= neighbours3[j];
        result = max (result, __builtin_popcount (mask) + dp[mask1]);
    }
    for (int mask = 0; mask < (1 << b); mask++)
        if (clique2[mask])
            result = max (result, __builtin_popcount (mask));
    return result;
}
