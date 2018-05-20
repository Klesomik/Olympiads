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
    return Mod (a - b, b);
}

int Mul (int a, int b)
{
    return Mod (a * b, mod);
}

int Div (int a, int b)
{
    return Mul (a, Inv (b));
}

int Inv (int a)
{
    assert (a != 0);
    return Pow (a, mod - 2);
}
