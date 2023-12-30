/*Implement DFS based algorithm to list the vertices of a directed graph in Topological ordering. Perform its analysis giving minimum 5 graphs with different number of vertices and edges. (starting with 4 vertices). 
Note: while showing correctness, input should be given for with and without solution.*/

#include <stdio.h>
#define n1 4
#define n2 8
int graph[40][40], n, visited[40], stack[40], stop,cnt,acyclic;
void dfs(int );

void dfstopo(){
  int i,count=0;
  for (i = 0; i < n; i++)
        if (!visited[i])
            dfs(i);
  if(!acyclic){
    printf("invalid input\n");
    return ;
  }
	printf("Topologically Sorted Order:\n");
	for(i=n-1;i>=0;i--)
		printf("%d   ",stack[i]);
	printf("\n");
}

void dfs(int v){
	visited[v]=1;
	for(int i=0;i<n;i++){ 
             cnt++;
            if (graph[v][i] && visited[i])
                acyclic = 0;
		if (graph[v][i] && !visited[i])
			dfs(i);}
	stack[++stop]=v;
}

void correctness(){
	printf("No. of vertices: ");
	scanf("%d", &n);
	printf("Enter adjacency matrix:\n");
	for(int i=0;i<n;i++)
		for(int j=0;j<n;j++)
			scanf("%d",&graph[i][j]);
   for (int i = 0; i < n; i++)
      visited[i] = 0;
  stop = -1;
  acyclic = 1;
  dfstopo();
}

void analysis() {
  int i, j;
  FILE *f;
  f = fopen("BC.txt", "a");
  for (n = n1; n <= n2; n += 1) {
    
    for(i=0;i<n;i++)  
     for(j=0;j<n;j++) 
       if(i==j-1)
         graph[i][j]=1;
       else
          graph[i][j] =0;
    for (i = 0; i < n; i++)
      visited[i] = 0;

    cnt = 0;
    stop = -1;
    acyclic=1;
    dfstopo();
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
