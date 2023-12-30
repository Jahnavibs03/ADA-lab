//Implement Quick Sort algorithm and perform its by generating best case and worst case data

#include <stdio.h>
#include <stdlib.h>
#define n1 10
#define n2 100
    int cnt = 0;

void swap(int *a, int *b) {
  int temp = *a;
  *a = *b;
  *b = temp;
}

int partition(int *a, int low, int high) {
  int pivot = a[high];
  int i = (low - 1);
  for (int j = low; j <= high - 1; j++) {
    cnt++;
    if (a[j] < pivot) {
      i++;
      swap(&a[i], &a[j]);
    }
  }
  swap(&a[i + 1], &a[high]);
  return (i + 1);
}

int sort(int *a, int low, int high) {
  if (low < high) {
    int pi = partition(a, low, high);
    sort(a, low, pi - 1);
    sort(a, pi + 1, high);
  }
  return cnt;
}

void analysis() {
  int *a, n;
  FILE *f1, *f2;
  f1 = fopen("BC.txt", "a");
  f2 = fopen("WC.txt", "a");
  for (n = n1; n <= n2; n += 10) {
    a = (int *)malloc(n * sizeof(int));
    // BEST CASE
    for (int i = 0; i < n; i++)
      a[i] = rand() % 100;
    swap(&a[n - 1], &a[n / 2]);
    cnt = 0;
    cnt = sort(a, 0, n - 1);
    fprintf(f1, "%d\t%d\n", n, cnt);

    // WORST CASE
    for (int i = n - 1; i >= 0; i--)
      a[i] = n - i + 1;
    cnt = 0;
    cnt = sort(a, 0, n - 1);
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
  sort(a, 0,n-1);
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
