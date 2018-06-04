#include <bits/stdc++.h>

struct Vector
{
    int x, y;

    Vector (): x (0), y (0) {}
    Vector (int x0, int y0): x (x0), y (y0) {}
    Vector (const Vector& A, const Vector& B): x (B.x - A.x), y (B.y - A.y) {}

    double len () { return hypot (x, y); };
};

int dot(const Vector& a, const Vector& b);
int cross(const Vector& a, const Vector& b);
std::ostream& operator << (std::ostream& out, const Vector& a);
std::istream& operator >> (std::istream& in, Vector& a);

int dot (const Vector& a, const Vector& b)
{
    return a.x * b.x + a.y * b.y;
}

int cross (const Vector& a, const Vector& b)
{
    return a.x * b.y - a.y * b.x;
}

std::ostream& operator << (std::ostream& out, const Vector& a)
{
    return out << a.x << ' ' << a.y;
}

std::istream& operator >> (std::istream& in, Vector& a)
{
    return in >> a.x >> a.y;
}
