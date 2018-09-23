struct Vector
{
    int x, y;
    Vector (int x0 = 0, int y0 = 0): x (x0), y (y0) {}
    Vector (Vector a, Vector b): x (b.x - a.x), y (b.y - a.y) {}
};

int dot (Vector a, Vector b)
{
    return a.x * b.x + a.y * b.y;
}

int cross (Vector a, Vector b)
{
    return a.x * b.y - a.y * b.x;
}

struct Line
{
    int a, b, c;

    Line (int a0 = 0, int b0 = 0, int c0 = 0): a (a0), b (b0), c (c0) {}
    Line (Vector f, Vector s): a (f.y - s.y), b (s.x - f.x), c (cross (f, s)) {}

    void init_norm (Vector f, Vector s) { a = s.x; b = s.y; c = -a * f.x - b * f.y; }
    void init_dir (Vector f, Vector s) { a = s.y; b = -s.x; c = -a * f.x - b * f.y; }

    Vector norm () { return Vector (a, b); }
    Vector dir ()  { return Vector (-b, a); }
};

void Crossing (Line first, Line second, vector <pair <double, double>>& result)
{
    int a1 = first.a, b1 = first.b, c1 = first.c,
        a2 = second.a, b2 = second.b, c2 = second.c;
    int down = (b1 * a2 - b2 * a1);
    if (down == 0)
        return;
    double x = 1.0 * (b2 * c1 - b1 * c2) / down;
    double y = 1.0 * (a2 * c1 - a1 * c2) / (-down);
    result.push_back ({ x, y });
}

Line Perpendicular (Line f, Vector s)
{
    return Line (f.b, -f.a, cross (f.norm (), s));
}

void Parallel (Line f, double dist, vector <Line>& result)
{
    double d = dist * f.norm ().len ();
    result.push_back (Line (f.a, f.b, f.c - d));
    result.push_back (Line (f.a, f.b, f.c + d));
}

double Distance (Line f, Vector s)
{
    return 1.0 * abs (f.a * s.x + f.b * s.y + f.c) / f.norm ().len ();
}

struct Circle
{
    int x, y, r;
    Circle (int x0 = 0, int y0 = 0, int r0 = 0): x (x0), y (y0), r (r0) {}
};

void Crossing (Circle from, Line to, vector <pair <double, double>>& result)
{
    double a = to.a, b = to.b, c = to.c, r = from.r;
    c = a * from.x + b * from.y + c;
    /*from.x = 0;
    from.y = 0;*/
    double d = (double) fabs (c) / sqrt (a * a + b * b);
    double x0 = (double) -(a * c) / (a * a + b * b);
    double y0 = (double) -(b * c) / (a * a + b * b);
    if (c * c > r * r * (a * a + b * b))
    {
        return;
    }
    else if (c * c < r * r * (a * a + b * b))
    {
        double up = (r * r - (double) c * c / (a * a + b * b));
        double down = a * a + b * b;
        double val = sqrt (up / down);
        result.push_back ({ x0 - b * val, y0 + a * val });
        result.push_back ({ x0 + b * val, y0 - a * val });
    }
    else
    {
        result.push_back ({ x0, y0 });
    }
    for (auto &it : result)
    {
        it.first += from.x;
        it.second += from.y;
    }
}

void Crossing (Circle from, Circle to, vector <pair <double, double>>& result)
{
    if ((fabs (from.x - to.x) < eps) && (fabs (from.y - to.y) < eps))
    {
        if (fabs (from.r - to.r) < eps)
            result.resize (3);
        return;
    }
    to.x -= from.x;
    to.y -= from.y;
    Line buffer (-2 * to.x, -2 * to.y, to.x * to.x + to.y * to.y + from.r * from.r - to.r * to.r);
    Crossing (Circle (0, 0, from.r), buffer, result);
    for (auto &it : result)
    {
        it.first += from.x;
        it.second += from.y;
    }
}
