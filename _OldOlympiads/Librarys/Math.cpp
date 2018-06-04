int GCD (int a, int b)
{
    if (b == 0)
        return a;

    return GCD (b, a % b);
}

int Mod (int a, int b)
{
    return (a % b + b) % b;
}

int UpperDiv (int a, int b)
{
    // (a - 1) / b + 1

    if (a % b == 0)
        return a / b;

    return a / b + 1;
}

int Pow ()
{
}

int Sqrt ()
{
}

int Log ()
{
}
