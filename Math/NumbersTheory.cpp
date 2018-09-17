const int mod = 1e9 + 7;

int Mod (int a, int b)
{
    return (a % b + b) % b;
}

int Add (int a, int b)
{
    return Mod (a + b, mod);
}

int Sub (int a, int b)
{
    return Mod (a - b, mod);
}

int Mul (int a, int b)
{
    return Mod (a * b, mod);
}

// mod is prime
int Inv (int a)
{
    assert (a != 0);
    return Pow (a, mod - 2);
}

int Inv (int a)
{
    assert (a != 0);
    int x = 0, y = 0;
    int g = GCDEx (a, mod, x, y);
    assert (g == 1);
    return Mod (x, mod);
}

int Div (int a, int b)
{
    return Mul (a, Inv (b));
}
