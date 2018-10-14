int Bit (int mask, int i)
{
    return (mask >> i) & 1;
}

// перебор всех подмасок заданной маски
for (int mask = 0; mask < (1 << n); mask++)
    for (int sub = mask; sub > 0; sub = (sub - 1) & mask)

// убрать у числа последний единичный бит
i & (i - 1)

// j - подмаска i, i - надмаска j
((i & j) == j)
