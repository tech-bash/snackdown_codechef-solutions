#include <bits/stdc++.h>
using namespace std;

#define ll  long long
#define endl '\n'
#define ff first
#define ss second
#define pb push_back
int mod = 1e9 + 7;
const int N = 1e9 + 10;


void init_code()
{
#ifndef ONLINE_JUDGE
  freopen("input.txt", "r", stdin);
  freopen("output.txt", "w", stdout);
#endif

  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
}
bool cmp(pair<int, int>v1, pair<int, int>v2) {
  return v1.second < v2.second;
}
vector<int> printFibb(int n)
{
  //code here
  vector<int> dp(2, 1);
  for (int i = 2; i < n; i++)
    dp.push_back(dp[i - 1] + dp[i - 2]);
  return dp;

}
int main()
{

  init_code();
  int t; cin >> t;
  while (t--) {
    int n , k;
    cin >> n >> k;
    if (k == 0) {
      cout << "Yes" << endl;
      cout << 0 << endl;
      continue;
    }
    if (k % 2 == 0) {
      cout << "No" << endl;;
      continue;
    }
    ll sz = 0;
    for (ll i = 31; i >= 0; i--) {
      if (((1 << i)&k) != 0) {
        sz = i + 1;
        break;
      }
    }
    k = (k + (1 << sz) - 1) / 2;
    cout << "Yes" << endl;
    cout << sz << endl;
    int ans = 1;
    vector<int> a;
    for (int i = sz - 2; i >= 0; i--) {
      if (((1 << i)&k) != 0) {
        a.push_back(ans);
        ans += (1 << i);
      }
      else {
        ans -= (1 << i);
        a.push_back(ans);
      }
    }
    for (int i = sz - 2; i >= 0; i--)
      cout << a[i] << endl;
    cout << ans << endl;
  }
}

