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

void Tangents (Circle from, Vector to, vector <pair <double, double>>& result)
{
    Circle buffer ((from.x + to.x) / 2, (from.y + to.y) / 2, sqrt ((from.x - to.x) * (from.x - to.x) + (from.y - to.y) * (from.y - to.y)) / 2);
    Crossing (from, buffer, result);
}
