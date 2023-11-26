#include <cstdio>
#include <cassert>
#include <algorithm>
using namespace std;

const int MAXN = 300;

int matrix[MAXN][MAXN];

void Work() {
  int n;
  assert(scanf("%d", &n) == 1);
  int halfn = n;
  n *= 2;

  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < n; ++j) {
      assert(scanf("%d", &matrix[i][j]) == 1);
    }
  }

  int ans = 0;
  for (int i = 0; i < halfn; ++i) {
    for (int j = 0; j < halfn; ++j) {
      int t_max = matrix[i][j];
      int ti = i;
      int tj = j;

      ti = n - 1 - ti;
      t_max = max(t_max, matrix[ti][tj]);

      tj = n - 1 - tj;
      t_max = max(t_max, matrix[ti][tj]);

      ti = n - 1 - ti;
      t_max = max(t_max, matrix[ti][tj]);

      ans += t_max;
    }
  }
  printf("%d\n", ans);
}

int main() {
  int q;
  assert(scanf("%d", &q) == 1);
  while (q--) {
    Work();
  }
  return 0;
}
