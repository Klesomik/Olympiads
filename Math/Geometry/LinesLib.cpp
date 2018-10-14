Line Init (Vector f, Vector s)
{
    return Line (f.y - s.y, s.x - f.x, cross (f, s));
}

void InitNorm (Vector f, Vector s)
{
    return Line (s.x, s.y, -a * f.x - b * f.y);
}

void InitDir (Vector f, Vector s)
{
    return Line (s.y, -s.x, -a * f.x - b * f.y);
}

Vector Norm (Line tmp)
{
    return Vector (tmp.a, tmp.b);
}

Vector Dir (Line tmp)
{
    return Vector (-tmp.b, tmp.a);
}

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

bool OnLine (Line f, Vector s)
{
    return (f.a * s.x + f.b * s.y + f.c == 0);
}
