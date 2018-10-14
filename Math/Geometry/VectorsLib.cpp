double Angle (Vector a, Vector b)
{
    return fabs (atan2 (cross (a, b), dot (a, b)));
}

bool OnRay (Vector c, Vector a, Vector b)
{
    Vector ab (a, b), ac (a, c);
    if ((cross (ab, ac) == 0) && (dot (ab, ac) >= 0)) // because points can be the same
        return true;
    return false;
}

bool OnSegment (Vector c, Vector a, Vector b)
{
    Vector ab (a, b), ac (a, c), ba (b, a), bc (b, c);
    if ((cross (ab, ac) == 0) && (dot (ab, ac) >= 0) && (dot (ba, bc) >= 0)) // because points can be the same
        return true;
    return false;
}

bool InAngle (Vector a, Vector o, Vector b, Vector p)
{
    Vector oa (o, a), ob (o, b), op (o, p);
    if (cross (ob, oa) < 0)
        swap (oa, ob);
    if ((cross (op, oa) >= 0) && (cross (ob, op) >= 0))
        return true;
    return false;
}

double DistToRay (Vector c, Vector a, Vector b)
{
    Vector ab (a, b), ac (a, c);
    double result = 0;
    if (dot (ab, ac) >= 0)
        result = 1.0 * abs (cross (ab, ac)) / ab.len ();
    else
        result = ac.len ();
    return result;
}

double DistToSegment (Vector c, Vector a, Vector b)
{
    Vector ab (a, b), ac (a, c), ba (b, a), bc (b, c);
    double result = 0;
    if ((dot (ab, ac) >= 0) && (dot (ba, bc) >= 0))
        result = 1.0 * abs (cross (ab, ac)) / ab.len ();
    else
        result = min (ac.len (), bc.len ());
    return result;
}
