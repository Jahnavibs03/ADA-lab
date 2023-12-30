//Implement Brute force string matching algorithm to search for a pattern of length ‘M’ in a text of length ‘N’ (M<=N) and perform its analysis by generating best case and worst case data.

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define n1 10
#define n2 100

int cnt;

int stringmatch(char *text, char *pat) {
  int n = strlen(text);
  int m = strlen(pat);
  int i, j;
  for (i = 0; i <= n - m; i++) {
    for (j = 0; j < m; j++) {
      cnt++;
      if (text[i + j] != pat[j])
        break;
    }
    if (j == m)
      return i+1;
  }
  return -1;
}

void analysis() {
  FILE *f1, *f2;
  int n;
  f1 = fopen("BC.txt", "a");
  f2 = fopen("WC.txt", "a");
  for (n = n1; n <= n2; n += 10) {
    char *t = (char *)malloc(101 * sizeof(char));
    char *p = (char *)malloc(n * sizeof(char));
    for (int i = 0; i < 100; i++)
      t[i] = 'a';
    t[100] = '\0';
    // BEST CASE
    for (int i = 0; i < n; i++)
      p[i] = 'a';
    p[n] = '\0';
    cnt = 0;
    stringmatch(t, p);
    fprintf(f1, "%d\t%d\n", n, cnt);
    // WORST CASE
    p[n - 1] = 'b';
    cnt = 0;
    stringmatch(t, p);
    fprintf(f2, "%d\t%d\n", n, cnt);
  } // system("gnuplot>load 'command.txt'");
  fclose(f1);
  fclose(f2);
}

void correctness() {
  char text[50], pat[10];
  printf("enter the text: ");
  scanf("%s", text);
  printf("enter the pattern: ");
  scanf("%s", pat);
  int pos;
  pos = stringmatch(text, pat);
  pos > 0 ? printf("pattern found at position %d of text.\n", pos)
          : printf("pattern not found\n");
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
