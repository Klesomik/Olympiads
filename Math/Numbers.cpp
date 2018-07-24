int GCD (int a, int b)
{
    if (b == 0)
        return a;
    return GCD (b, a % b);
}

int LCM (int a, int b)
{
    return a / GCD (a, b) * b;
}

int GCDEx (int a, int b, int& x, int& y)
{
    if (b == 0)
    {
        x = 1;
        y = 0;
        return a;
    }
    int x1 = 0, y1 = 0;
    int d = GCDEx (b, a % b, x1, y1);
    x = y1;
    y = x1 - a / b * y1;
    return d;
}

bool IsPrime (int x)
{
    for (int i = 2; i * i <= x; i++)
        if (x % i == 0)
            return false;
    return true;
}

vector <int> Factorize (int x)
{
    vector <int> result;
    for (int i = 2; i * i <= x; i++)
    {
        while (x % i == 0)
        {
            result.push_back (i);
            x /= i;
        }
    }
    return result;
}

vector <bool> Eratosphen (int n)
{
}

int Phi (int x)
{
}
