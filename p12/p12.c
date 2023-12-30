//a) Implement Warshall’s Algorithm to find the transitive closure of a directed graph and perform its analysis giving minimum 5 graphs with different number of vertices and edges. (starting with 4 vertices). 
//b) Implement Floyd’s Algorithm to find All-pair shortest paths for a graph and perform its analysis giving minimum 5 graphs with different number of vertices and edges(starting with 4 vertices).


// a
#include <stdio.h>
#include<stdlib.h>
#define n1 4
#define n2 8
int graph[40][40], n,cnt;

void warshall() {
  for (int k = 0; k < n; k++) {
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < n; j++) {
        cnt++;
        graph[i][j] = (graph[i][j] | (graph[i][k] & graph[k][j]));
      }
    }
  }
}

void analysis() {
  int i, j;
  FILE *f;
  f = fopen("BC.txt", "a");
  for (n = n1; n <= n2; n += 1) {

    for (i = 0; i < n; i++)
      for (j = 0; j < n; j++)
        if (i == j)
          graph[i][j] = 0;
        else
          graph[i][j] = rand()%2;
    
    cnt = 0;
    warshall();
    fprintf(f, "%d\t%d\n", n, cnt);
  } //system("gnuplot>load 'command.txt'");
  fclose(f);
}

void correctness() {
  printf("No. of vertices: ");
  scanf("%d", &n);
  printf("Enter adjacency matrix:\n");
  for (int i = 0; i < n; i++)
    for (int j = 0; j < n; j++)
      scanf("%d", &graph[i][j]);
  printf("Applying Warshall's Algorithm\n");
  warshall();
  printf("Transitive Closure Matrix:\n");
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      printf("%d ", graph[i][j]);
    }
    printf("\n");
  }
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

//b
#include <stdio.h>
#include<stdlib.h>
#define n1 4
#define n2 8
int graph[40][40], n,cnt;

void floyd() {
  for (int k = 0; k < n; k++) {
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < n; j++) {
        cnt++;
        if (graph[i][k] + graph[k][j] < graph[i][j])
          graph[i][j] = graph[i][k] + graph[k][j];
      }
    }
  }
}

void analysis() {
  int i, j;
  FILE *f;
  f = fopen("BC.txt", "a");
  for (n = n1; n <= n2; n += 1) {

    for (i = 0; i < n; i++)
      for (j = 0; j < n; j++)
        if (i == j)
          graph[i][j] = 0;
        else
          graph[i][j] = rand()%99;
    
    cnt = 0;
    floyd();
    fprintf(f, "%d\t%d\n", n, cnt);
  } //system("gnuplot>load 'command.txt'");
  fclose(f);
}
	
void correctness() {
  printf("No. of vertices: ");
  scanf("%d", &n);
  printf("Enter adjacency matrix:\n");
  printf("enter 999 for infinity: \n");
  for (int i = 0; i < n; i++)
    for (int j = 0; j < n; j++)
      scanf("%d", &graph[i][j]);

  printf("Applying Floyd's Algorithm\n");
  floyd();
  printf("All Pair Shortest Path Matrix:\n");
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      printf("%d ", graph[i][j]);
    }
    printf("\n");
  }
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
