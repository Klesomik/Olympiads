vector <int> num;
vector <vector <vector <vector <int>>>> dp;

int GetResult (int pos, int first, int last, int f)
{
    if (pos == num.size ())
    {
        if ((first != 0) && (first == last))
            return 1;
        else
            return 0;
    }
    if (dp[pos][first][last][f] != -1)
        return dp[pos][first][last][f];
    int res = 0;
    int LMT = (f == 0? num[pos] : 9);
    for (int dgt = 0; dgt <= LMT; dgt++)
    {
        int nf = f;
        if (f == 0 && dgt < LMT)
            nf = 1;
        if (first != 0)
        {
            res += GetResult (pos + 1, first, dgt, nf);
        }
        else
        {
            if (dgt != 0)
                res += GetResult (pos + 1, dgt, dgt, nf);
            else
                res += GetResult (pos + 1, first, dgt, nf);
        }
    }
    return (dp[pos][first][last][f] = res);
}

int CalcDp (int b)
{
    num.clear ();
    while (b > 0)
    {
        num.push_back (b % 10);
        b /= 10;
    }
    reverse (all (num));
    dp.assign (20, vector <vector <vector <int>>> (10, vector <vector <int>> (10, vector <int> (2, -1))));
    int res = GetResult (0, 0, 0, 0);
    return res;
}

inline void Solve ()
{
    int l = 0, r = 0;
    cin >> l >> r;
    cout << CalcDp (r) - CalcDp (l - 1);
}
