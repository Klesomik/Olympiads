# Лайфхаки в C++

### Сделать элементы вектора уникальными
```cpp
vector <int> v;
sort (all (v));
v.erase (unique (all (v)), v.end ());
```

### Удалить одно вхождение x в multiset
```cpp
multiset <int> ms;
ms.erase (ms.find (x));
```

### Перенаправление потоков
```cpp
freopen ("input.txt", "r", stdin);
freopen ("output.txt", "w", stdout);
```

### Считать long long с помощью scanf
```cpp
long long x = 0;
scanf ("%I64d", &x); // Windows
scanf ("%lld", &x);  // Linux
```

### Считать время в формате hh:mm:ss
```cpp
int h = 0, m = 0, s = 0;
scanf ("%02d:02d:02d", &h, &m, &s);
```

### Ускорение iostream
```cpp
ios_base::sync_with_stdio (false);
cin.tie (nullptr);
cout.tie (nullptr);
```

### Методы cout'а
```cpp
cout.width (x); // ширина вывода = x
cin.get ();     // считать 1 символ
```

### Декартово дерево в g++
```cpp
#include <ext/pb_ds/assoc_container.hpp>
using namespace __gnu_pbds;

template <class key, class cmp = less <key>>
using ordered_set = tree <key, null_type, cmp, rb_tree_tag, tree_order_statistics_node_update>;
ordered_set <int> my_set;

template <class key, class value, class cmp = less <key>>
using ordered_map = tree <key, value, cmp, rb_tree_tag, tree_order_statistics_node_update>;
ordered_map <int, int> my_map;

my_set.order_of_key (x);  // сколько элементов в множестве меньше x
my_set.find_by_order (k); // k-ый по величине элемент в множестве
```

### Тестовые функции из g++
```cpp
__gcd (a, b);         
__builtin_ffs (x);
__builtin_clz (x);      // количество лидирующих нулей
__builtin_ctz (x);
__builtin_popcount (x); // количество единичных битов
```

### Прагмы иногда ускоряют код
```cpp
#pragma GCC optimize("Ofast")
#pragma GCC optimize("no-stack-protector")
#pragma GCC optimize("unroll-loops")
#pragma GCC target("sse,sse2,sse3,ssse3,popcnt,abm,mmx,tune=native")
#pragma GCC optimize("fast-math")

#pragma comment(linker, "/stack:200000000") // расширение стека, актуально для Visual Studio
```

### Рандом
```cpp
#define rand() (rand()<<15+rand()) // рандом на Windows
mt19937 rnd (time (nullptr));
mt19937_64 rnd (system_clock ().now ().time_since_epoch ().count ());
```

### Как измерить время
```cpp
double GetTime ()
{
    return 1.0 * clock () / CLOCKS_PER_SEC;
}
```

### Компаратор для set'а
```cpp
struct Cmp
{
    bool operator () (const pair <int, int>& a, const pair <int, int>& b)
    {
        return a.first < b.first;
    }
};

set <pair <int, int>, Cmp> data;
```

### Использование memset
```cpp
int dp[100][100];

memset (dp, -1, sizeof (dp)); // 0 or -1
```

### Предподсчет логарифмов за линию
```cpp
vector <lli> LOG (1e6);
LOG[1] = 0;
for (lli i = 2; i < LOG.size (); i++)
    LOG[i] = LOG[i / 2] + 1;
```
