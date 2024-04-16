// Jakub Daszkiewicz
// zadanie Orzeł czy Reszka?
//
// test 1: 4 1 1 1 2 1 3 1 4 => 2 2
// test 2: 5 19 44 18 31 5 2 5 44 27 31 => 1 4
// test 3: 5 35 13 43 31 38 45 31 5 47 22 => 3 2

#include <stdio.h>

using namespace std;

bool even(int n)
{
  return (n%2 == 0);
}

int main()
{
  int n, w, k, r_w = 0, r_b = 0;
  scanf("%d", &n);
  for (int i=0; i<n; ++i)
  {
    scanf("%d%d", &w, &k);
    if (even(w) == even(k))
      ++r_w;
    else
      ++r_b;
  }
  printf("%d %d", r_w, r_b);
  return 0;
}
