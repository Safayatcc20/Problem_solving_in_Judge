#include "bits/stdc++.h"

using namespace std;
using ll = long long;
using uint = unsigned int;

//storing the values in unsigned int
//since it prevents exceeding memory limit
//also, it automatically makes the numbers
//modulo 2^32

const int mx = 1e8 + 9; //max value of n
const int mxprm = 6e6 + 9; //max number of primes

int psz = 0; //keeping count the number of primes discovered

bitset <mx> mark; //to keep track of primes
uint primes[mxprm]; //to store the primes
uint mul[mxprm];  //to store the cumulative product of the primes

void sieve() { //just a prime sieve code
    mark[0] = mark[1] = 1;
    primes[psz++] = 2;
    int lim = sqrt(mx * 1.0) + 2;
    for (int i = 4; i < mx; i += 2) mark[i] = 1;
    for (int i = 3; i < mx; i += 2) {
        if (!mark[i]) {
            primes[psz++] = i;
            if (i <= lim)
                for (int j = i * i; j < mx; j += i)
                    mark[j] = 1;
        }
    }
}

int main() {
    sieve();

    mul[0] = 2; //first prime is 2, so cumulative product till first prime is 2
    for (int i = 1; i < psz; i++)
        mul[i] = (primes[i] * mul[i - 1]); //calculating cumulative product

    int tc; scanf("%d", &tc);
    int kase = 0;
    while (tc--) {
        int n; scanf("%d", &n);
        printf("Case %d: ", ++kase);

        uint ans = 1;

        int idx =  upper_bound(primes, primes + psz, n) - primes;
        //upper_bound gives the iterator to the smallest prime greater than n
        //idx contains it's index

        idx--; //now, idx contains the index of the largest prime not greater than n

        ans *= mul[idx];
        for (int i = 0; i < idx; i++) {
            ll p = primes[i];
            ll x = n;
            ll a = 0;

            if (p * p > n) break; //checking primes till sqrt(n) is enough

            //for each prime p, let's find the maximum power of p till n
            //stored in the variable a
            while (x >= p) {
                x /= p;
                a++;
            }

            ans *= pow(p, a - 1); //multiplying by p^(a-1) since we took these primes once before
        }

        //answer is already calculated modulo 2^32 because of taking unsigned integer
        printf("%lld\n", ans);
    }
}