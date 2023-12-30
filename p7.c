/*Implement DFS algorithm to check for connectivity and acyclicity of a graph. If not connected, display the connected components. Perform its analysis by generating best case and worst case data.
 Note: while showing correctness, input should be given for both connected/disconnected and cyclic/acyclic graphs.*/

#include <stdio.h>
#include <stdlib.h>
#define n1 3
#define n2 10
int a[100][100], visited[100], n, acyclic, cnt = 0;

void analysis();

void dfs(int v) {
  visited[v] = 1;
  for (int i = 1; i <= n; i++) {
    cnt++;
    if (a[v][i] && visited[i]) {
      acyclic = 0;
      printf("-->%d-->%d\n", v, i);
    }
    if (a[v][i] && !visited[i]) {
      printf("-->%d-->%d\n", v, i);
      dfs(i);
    }
  }
}

void connected_cyclic(int start) {
  int i;
  for (i = 1; i <= n; i++)
    if (!visited[i])
      break;
  if (i == n + 1)
    printf("The graph is connected\n");
  else
    printf("Graph is not connected\n");

  if (acyclic)
    printf("Graph is acyclic\n");
  else
    printf("Graph is cyclic\n");
}

void analysis() {
  int i, j;
  FILE *f1, *f2;
  f1 = fopen("BC.txt", "a");
  f2 = fopen("WC.txt", "a");
  for (n = n1; n <= n2; n += 1) {
    for (i = 1; i <= n; i++)
      visited[i] = 0;
    // BEST CASE
    printf("BEST CASE : vertices:%d\n", n);
    printf("connected components are:\n");
    for (i = 1; i <= n; i++)
      for (j = 1; j <= n; j++)
        if (i == j - 1)
          a[i][j] = 1;
        else
          a[i][j] = 0;

    for (i = 1; i <= n; i++)
      visited[i] = 0;
    acyclic = 1;
    cnt = 0;
    visited[1]=1;
    dfs(1);
    connected_cyclic(1);
    fprintf(f1, "%d\t%d\n", n, cnt);
    // WORST CASE
    printf("WORST CASE : vertices:%d\n", n);
    printf("connected components are:\n");
    for (i = 1; i <= n; i++)
      for (j = 1; j <= n; j++)
        a[i][j] = 1;
    for (i = 1; i <= n; i++)
      visited[i] = 0;
    acyclic = 1;
    cnt = 0;
    visited[1]=1;
    dfs(1);
    connected_cyclic(1);
    fprintf(f2, "%d\t%d\n", n, cnt);
  } // system("gnuplot>load 'command.txt'");
  fclose(f1);
  fclose(f2);
}

void correctness() {
  int i, j, start;
  printf("Enter the number of vertices: ");
  scanf("%d", &n);
  for (i = 1; i <= n; i++)
    visited[i] = 0;
  printf("Enter the adjacency matrix\n");
  for (i = 1; i <= n; i++)
    for (j = 1; j <= n; j++)
      scanf("%d", &a[i][j]);
  printf("Enter the start vertex: ");
  scanf("%d", &start);
  visited[start] = 1;
  acyclic = 1;
  dfs(start);
  connected_cyclic(start);
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
