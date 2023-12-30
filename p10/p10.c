/*Implement source removal algorithm to list the vertices of a directed graph in Topological ordering. Perform its analysis giving minimum 5 graphs with different number of vertices and edges. (starting with 4 vertices). 
Note: Use efficient method to identify the source vertex. While showing correctness, Input should be given for with and without solution.*/

#include <stdio.h>
#include <stdlib.h>
#define n1 4
#define n2 8
int graph[10][10], visited[10], indegree[10], n, cnt;

void sourcetopo() {
  int i, j, count = 0;
  for (i = 0; i < n; i++)
    for (j = 0; j < n; j++)
      indegree[i] += graph[j][i];
  for(i=0;i<n;i++)
    if(!indegree[i])
      acyclic = 1;
  if(!acyclic){
    printf("invalid input\n");
    return ;
  }
  printf("\nTopologically sorted order: \n");
  while (count < n) {
    for (i = 0; i < n; i++) {
      if (!visited[i] && !indegree[i]) {
        printf("%d  ", i+1);
        visited[i] = 1;
        for (j = 0; j < n; j++) {
          cnt++;
          if (graph[i][j]) {
            graph[i][j] = 0;
            indegree[j]--;
          }
        }
        count++;
        break;
      }
    }
  }
}

void correctness() {
  printf("Enter no. of vertices: ");
  scanf("%d", &n);
  printf("Enter adjacency matrix:\n");
  for (int i = 0; i < n; i++)
    for (int j = 0; j < n; j++)
      scanf("%d", &graph[i][j]);
  for (int i = 0; i < n; i++) {
    visited[i] = 0;
    indegree[i] = 0;
  }
  sourcetopo();
}

void analysis() {
  int i, j;
  FILE *f;
  f = fopen("BC.txt", "a");
  for (n = n1; n <= n2; n += 1) {

    for (i = 0; i < n; i++)
      for (j = 0; j < n; j++)
        if (i == j - 1)
          graph[i][j] = 1;
        else
          graph[i][j] = 0;
    for (i = 0; i < n; i++) {
      visited[i] = 0;
      indegree[i] = 0;
    }
    cnt = 0;
    sourcetopo();
    fprintf(f, "%d\t%d\n", n, cnt);
  } //system("gnuplot>load 'command.txt'");
  fclose(f);
}

void main() {
  int ch;
  printf("1.analysis\t\t2.correctness\t\t0.exit\n");
  for (;;) {
    printf("\nenter choice: ");
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
