// Link: https://www.codechef.com/submit/LGSEG

#include <bits/stdc++.h>
using namespace std;
#define max(a, b) ((a) > (b) ? (a) : (b))
#define min(a, b) ((a) < (b) ? (a) : (b))
#define gcd(a, b) __gcd(a, b)
#define lcm(a, b) (a * b) / gcd(a, b)
#define GOLD ((1 + sqrt(5)) / 2)
#define ll long long
const double PI = 3.14159265358979323846264338327950288419716939937510582097494459230;

void compute()
{
    ll n, k, s, ans = 0, t, LOG = 0, po;
    cin >> n >> k >> s;

    t = k;
    while (t)
        LOG++, t >>= 1;

    vector<ll> v(n + 1);
    vector<vector<ll>> up(n + 1, vector<ll>(LOG + 1));
    for (int i = 1; i <= n; ++i)
    {
        cin >> v[i];
        v[i] += v[i - 1];
        auto it = lower_bound(v.begin(), v.begin() + i, v[i] - s);
        if (it != v.end())
        {
            int idx = it - v.begin();
            up[i][0] = idx;
            for (int j = 1; j <= LOG; ++j)
                up[i][j] = up[up[i][j - 1]][j - 1];

            idx = i, t = k, po = 0;
            while (t)
            {
                if (t & 1)
                    idx = up[idx][po];
                ++po;
                t >>= 1;
            }
            ans = max(ans, i - idx);
        }
        else
        {
            for (int j = 0; j <= LOG; ++j)
                up[i][j] = i;
        }
    }

    cout << ans << "\n";
}

int main()
{
#ifdef debug
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    freopen("log.txt", "w", stderr);
#endif
    int t;
    scanf("%d", &t);
    while (t--)
    {
        compute();
    }
#ifdef debug
    fprintf(stdout, "\nTIME: %.3lf sec\n", (double)clock() / (CLOCKS_PER_SEC));
#endif
    return 0;
}