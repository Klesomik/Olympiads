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
};

struct Circle
{
    int x, y, r;
    Circle (int x0 = 0, int y0 = 0, int r0 = 0): x (x0), y (y0), r (r0) {}
};
