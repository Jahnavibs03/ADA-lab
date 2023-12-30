//Implement Prim’s algorithm to find Minimum Spanning Tree of a graph and perform its analysis giving minimum 5 graphs with different number of vertices and edges (starting with 4 vertices)

#include <stdio.h>
#include<stdlib.h>
#define n1 4
#define n2 8
int cost[40][40], n, visited[40],cnt;

void prims() {
  int i, j, edges = 0;
  int a, b, min, min_cost = 0;
  visited[0] = 1;
  while (edges < n - 1) {
    min = 9999;
    for (i = 0; i < n; i++) {
      cnt++;
      if (visited[i]) {
        for (j = 0; j < n; j++) {
          if (cost[i][j] && min > cost[i][j] && !visited[j]) {
            min = cost[i][j];
            a = i;
            b = j;
          }
        }
      }
    }
    printf("%d-->%d | Cost: %d\n", a, b, min);
    visited[b] = 1;
    min_cost += min;
    edges++;
  }
  printf("Minimum Cost: %d\n", min_cost);
}

void correctness() {
  printf("No. of vertices: ");
  scanf("%d", &n);
  printf("Enter cost matrix:\n");
  for (int i = 0; i < n; i++)
    for (int j = 0; j < n; j++)
      scanf("%d", &cost[i][j]);
  for(int i=0;i<n;i++)
    visited[i] = 0;
  prims();
}

void analysis() {
    int i, j;
    FILE *f;
    f = fopen("BC.txt", "a");
    for (n = n1; n <= n2; n += 1) {

      for (i = 0; i < n; i++)
        for (j = 0; j < n; j++)
          if (i == j)
            cost[i][j] = 0;
          else
            cost[i][j] = rand() % 10;
      
      for(int i=0;i<n;i++)
        visited[i] = 0;
      cnt = 0;
      prims();
      fprintf(f, "%d\t%d\n", n, cnt);
    } // system("gnuplot>load 'command.txt'");
    fclose(f);
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
