#include <bits/stdc++.h>
using namespace std;

#define int long long
int mod = 1e9 + 7;
int Highest = 1e6;

//---------------Mod_Multiplication-------------------//

int mod_mul(int a, int b)
{
    a = a % mod;
    b = b % mod;
    return (((a * b) % mod) + mod) % mod;
}

//-------------------Factorial------------------------//

int *fact;
void calFact()
{
    fact = new int[Highest];
    fact[0] = 1;
    fact[1] = 1;
    for (int i = 2; i < Highest; i++)
        fact[i] = mod_mul(fact[i - 1], i);
}

int myPow(int a, int b)
{
    int ans = 1;
    while (b)
    {
        if (b & 1)
            ans = ans * a % mod;
        b >>= 1;
        a = (a * a) % mod;
    }
    return ans % mod;
}

int my(int n, int m)
{
    if (m == 0 || m == n)
        return 1;
    int res = fact[n];
    res = res * myPow(fact[m], mod - 2) % mod;
    res = res * myPow(fact[n - m], mod - 2) % mod;
    return res;
}

signed main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int h, w, a, b;
    cin >> h >> w >> a >> b;
    calFact();
    int r = 0, ans = 0;
    for (int i = b + 1; i <= w; i++)
    {
        r = my(i - 1 + h - a - 1, h - a - 1) * my(a - 1 + w - i, a - 1) % mod;
        ans = (ans % mod + r % mod) % mod;
    }
    cout << ans << endl;
    return 0;
}
