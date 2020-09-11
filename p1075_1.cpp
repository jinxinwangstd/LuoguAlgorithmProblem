#include <bits/stdc++.h>

using namespace std;

int N;
vector<int> primes, mark;

void GenPrimes(int n) {
    int i, j, k;
    mark.assign(n + 1, 0);
    for (i = 2, k = 4; i <= n; i++, k +=  i + i - 1) {
        if (!mark[i]) {
            primes.push_back(i);
            if (k <= n)
                for (j = k; j <= n; j += i)
                    mark[j] = 1;
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> N;
    GenPrimes((int)sqrt(N));
    for (int prime: primes) {
        if (N % prime == 0) {
            cout << (N / prime) << "\n";
            break;
        }
    }
    return 0;
}