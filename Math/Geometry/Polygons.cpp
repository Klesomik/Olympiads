double Perimeter (vector <Vector>& data)
{
    double result = 0;
    for (int i = 0; i < int (data.size ()) - 1; i++)
        result += Vector (data[i], data[i + 1]).len ();
    result += Vector (data.back (), data[0]).len ();
    return result;
}

double Square (vector <Vector>& hull)
{
    double result = 0;
    for (int i = 1; i < int (hull.size ()) - 1; i++)
        result += abs (cross (Vector (hull[0], hull[i]), Vector (hull[0], hull[i + 1])));
    return result / 2;
}

bool IsConvex (vector <Vector>& data)
{
    int n = data.size ();
    int cnt1 = 0, cnt2 = 0;
    for (int i = 0; i < n; i++)
    {
        Vector first (data[i], data[(i + 1) % n]),
               second (data[(i + 1) % n], data[(i + 2) % n]);
        int buffer = cross (first, second);
        if (buffer > 0)
            cnt1++;
        else
            cnt2++;
    }
    if ((cnt1 > 0) && (cnt2 > 0))
        return false;
    return true;
}
