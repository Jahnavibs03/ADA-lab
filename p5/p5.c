//Implement Merge Sort algorithm and perform its analysis by generating best case and worst case data.

#include <stdio.h>
#include <stdlib.h>
#define n1 4
#define n2 1024
int cnt = 0;

void merge(int *a, int *left, int l, int *right, int r) {
  int i = 0, j = 0, k = 0;

  while (i < l && j < r) {
    if (left[i] <= right[j]) {
      a[k++] = left[i++];
    } else {
      a[k++] = right[j++];
    }
    cnt++;
  }

  while (i < l) {
    a[k++] = left[i++];
  }

  while (j < r) {
    a[k++] = right[j++];
  }
}

int sort(int *a, int n) {
  if (n < 2) {
    return cnt;
  }
  int mid = n / 2;
  int *left = (int *)malloc(mid * sizeof(int));
  int *right = (int *)malloc((n - mid) * sizeof(int));

  for (int i = 0; i < mid; i++) {
    left[i] = a[i];
  }

  for (int i = mid; i < n; i++) {
    right[i - mid] = a[i];
  }

  sort(left, mid);
  sort(right, n - mid);
  merge(a, left, mid, right, n - mid);
  return cnt;
}

void generateworstcase(int *a, int l, int r) {
  if (l < r) {
    int m = (l + r) / 2;
    int *left = (int *)malloc((m - l + 1) * sizeof(int));
    int *right = (int *)malloc((r - m) * sizeof(int));
    for (int i = 0; i <= m - l; i++)
      left[i] = a[i * 2];

    for (int i = 0; i < r - m; i++)
      right[i] = a[i * 2 + 1];
    generateworstcase(left, l, m);
    generateworstcase(right, m + 1, r);
    int i;
    for (i = 0; i <= m - l; i++)
      a[i] = left[i];

    for (int j = 0; j < r - m; j++)
      a[i + j] = right[j];
  }
}

void analysis() {
  int *a, n;
  FILE *f1, *f2;
  f1 = fopen("BC.txt", "a");
  f2 = fopen("WC.txt", "a");
  for (n = n1; n <= n2; n *= 2) {
    a = (int *)malloc(n * sizeof(int));

    // BEST CASE
    for (int i = 0; i < n; i++)
      a[i] = i + 1;
    cnt = 0;
    cnt = sort(a, n);
    fprintf(f1, "%d\t%d\n", n, cnt);

    // WORST CASE
    generateworstcase(a, 0, n - 1);
    cnt = 0;
    cnt = sort(a, n);
    fprintf(f2, "%d\t%d\n", n, cnt);
  } // system("gnuplot>load 'command.txt'");
  fclose(f1);
  fclose(f2);
}

void correctness() {
  int a[20], n, key, pos;
  printf("enter the number of elements required: ");
  scanf("%d", &n);
  printf("enter the elements: ");
  for (int i = 0; i < n; i++)
    scanf("%d", &a[i]);
  printf("array elements after sorting:\n");
  sort(a, n);
  for (int i = 0; i < n; i++)
    printf("%d\t", a[i]);
  printf("\n");
}

void main() {
  int ch;
  printf("1.analysis\t\t2.correctness\t\t0.exit\n");
  for (;;) {
    printf("enter choice: ");
    scanf("%d", &ch);
    switch (ch) {
    case 1:
      analysis();
      break;
    case 2:
      correctness();
      break;
    case 0:
      printf("exiting..\n");
      exit(0);
    default:
      printf("wrong choice!!\n");
      break;
    }
  }
}
