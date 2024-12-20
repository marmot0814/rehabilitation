/*
   CSES - Stick Lengths
     * Time limit: 1.00 s
     * Memory limit: 512 MB

   There are n sticks with some lengths. Your task is to modify the sticks
   so that each stick has the same length.

   You can either lengthen and shorten each stick. Both operations cost x
   where x is the difference between the new and original length.

   What is the minimum total cost?

Input

   The first input line contains an integer n: the number of sticks.

   Then there are n integers: p_1,p_2,…,p_n: the lengths of the
   sticks.

Output

   Print one integer: the minimum total cost.

Constraints

     * 1 ≤ n ≤ 2 ⋅ 10^5
     * 1 ≤ p_i ≤ 10^9

Example

   Input:
5
2 3 1 5 2

   Output:
5
*/
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair<int, int>;

int main() {
  cin.tie(0)->sync_with_stdio(0);
  int n; cin >> n;
  auto a = vector<ll>(n);
  for (auto &v : a) cin >> v;
  sort(a.begin(), a.end());

  ll rsum = 0, lsum = 0;
  for (int i = 0; i < n; i++)
    rsum += a[i];

  ll ans = LLONG_MAX;
  for (int i = 0; i < n; i++) {
    rsum -= a[i];
    ans = min(ans, i * a[i] - lsum + rsum - (n - i - 1) * a[i]);
    lsum += a[i];
  }
  cout << ans << '\n';
}
