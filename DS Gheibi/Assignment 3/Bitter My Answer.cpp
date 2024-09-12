#include <bits/stdc++.h>
#include <iostream>
using namespace std;

#define p 101
#define MOD 1000000007

struct Query
{
    int L, R;
};

unsigned long long int modPow(unsigned long long int base, unsigned long long int exponent)
{
    if (exponent == 0)
        return 1;
    if (exponent == 1)
        return base;

    unsigned long long int temp = modPow(base, exponent / 2);

    if (exponent % 2 == 0)
        return (temp % MOD * temp % MOD) % MOD;
    else
        return (((temp % MOD * temp % MOD) % MOD)
                * base % MOD)
               % MOD;
}

unsigned long long int findMMI(unsigned long long int n)
{
    return modPow(n, MOD - 2);
}

void computePrefixHash( string str, int n, unsigned long long int prefix[], unsigned long long int power[])
{
    prefix[0] = 0;
    prefix[1] = str[0];

    for (int i = 2; i <= n; i++)
        prefix[i] = (prefix[i - 1] % MOD + (str[i - 1] % MOD * power[i - 1] % MOD) % MOD) % MOD;
    return;
}

void computeSuffixHash(string str, int n, unsigned long long int suffix[], unsigned long long int power[])
{
    suffix[0] = 0;
    suffix[1] = str[n - 1];

    for (int i = n - 2, j = 2; i >= 0 && j <= n; i--, j++)
        suffix[j] = (suffix[j - 1] % MOD + (str[i] % MOD * power[j - 1] % MOD) % MOD) % MOD;
    return;
}

void computePowers(unsigned long long int power[], int n)
{
    power[0] = 1;
    for (int i = 1; i <= n; i++)
        power[i] = (power[i - 1] % MOD * p % MOD) % MOD;
    return;
}

int main()
{
    string input;
    int n;

    cin >> n;
    cin >> input;

    unsigned long long int power[n + 1];

    computePowers(power, n);

    unsigned long long int prefix[n + 1], suffix[n + 1];

    computePrefixHash(input, n, prefix, power);
    computeSuffixHash(input, n, suffix, power);

    Query q[n];
    for(int i = 0; i < n; i++)
    {
        q[i] = {0, i};
    }

    int m =  sizeof(q) / sizeof(q[0]);

    int val[n];
    for (int i = 0; i <= m - 1; i++)
    {
        int L = q[i].L;
        int R = q[i].R;

        unsigned long long hash_LR = ((prefix[R + 1] - prefix[L] + MOD) % MOD * findMMI(power[L]) % MOD) % MOD;
        unsigned long long reverse_hash_LR = ((suffix[n - L] - suffix[n - R - 1] + MOD) % MOD * findMMI(power[n - R - 1]) % MOD) % MOD;
        if (hash_LR == reverse_hash_LR)
        {
            if(i % 2 == 1)
            {
                val[i] = 1 + val[i/2];
            }
            else
            {
                val[i] = 1 + val[i/2 - 1];
            }
        }

        else
        {
            val[i] = 0;
        }
        val[0] = 1;
    }
    int sum = 0;
    for(int i = 0 ; i< n; i++)
    {
        sum += val[i];
    }
    cout << sum;
    return (0);
}
