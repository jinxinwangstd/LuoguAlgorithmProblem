#include <bits/stdc++.h>

using namespace std;

struct BigInteger {
    static const int BASE = 100000000;
    static const int WIDTH = 8;

    vector<int> s;
    BigInteger(long long num = 0) { *this = num; }
};