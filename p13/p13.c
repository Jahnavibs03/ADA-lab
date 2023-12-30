//a) Implement bottom up Dynamic Programming algorithm to solve Knapsack problem and perform its analysis with different instances (different number of items and Capacity, starting with 4 items) 
//b) Implement a Dynamic Programming algorithm with Memory function to solve Knapsack problem and perform its analysis with different instances (different number of items and Capacity, starting with 4 items).

//a
#include <stdio.h>
#include <stdlib.h>
#define n1 4
#define n2 10
int t[100][100], v[100], w[100], n, m,cnt;

int max(int a, int b){
	return (a>b) ? a : b;
}

void knapsack(){
  int i,j;
  for(i=0;i<n+1;i++){
		for(j=0;j<m+1;j++){
		    cnt++;
			if (i==0||j==0)
				t[i][j] = 0;
			else if (j<w[i])
				t[i][j] = t[i-1][j];
			else
				t[i][j] = max(t[i-1][j], v[i]+t[i-1][j-w[i]]);
		}
	}
	printf("table\n");
		for(i=0;i<n+1;i++){
		for(j=0;j<m+1;j++){
		    printf("%d\t",t[i][j]);
		    }
		printf("\n");
		}
	
	printf("Maximum Value: %d\n",t[n][m]);
}

void correctness(){
  int i,j;
	printf("No. of Items: ");
	scanf("%d",&n);
	printf("Capacity: ");
	scanf("%d",&m);
	
	printf("Weight\tValue\n");
	for(i=1;i<n+1;i++)
		scanf("%d\t%d",&w[i],&v[i]);
  knapsack();

}

void analysis(){
    int i,j;
    FILE *f;
    f = fopen("BC.txt","a");
    m = 10;
    for(n=n1;n<=n2;n++){
        for(i=1;i<n+1;i++){
            w[i] = rand()%12;
            v[i] = rand()%100;
            printf("%d\t%d\n",w[i],v[i]);
        }
        cnt = 0;
        knapsack();
        fprintf(f,"%d\t%d\n",n,cnt);
    }
}

void main(){
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
#include <stdlib.h>
#define n1 4
#define n2 10
int t[100][100], v[100], w[100], n, m,cnt;

int max(int a, int b){
	return (a>b) ? a : b;
}

int knap(int i, int j){
	if (t[i][j]==-1){
		if (j<w[i])
			t[i][j] = knap(i-1,j);
		else
			t[i][j] = max(knap(i-1,j),v[i]+knap(i-1,j-w[i]));
	}
	return t[i][j];
}

void knapsack(){
  int i,j;
  for(i=0;i<n+1;i++){
		for(j=0;j<m+1;j++){
      cnt++;
			if (i==0||j==0)
				t[i][j]=0;
			else
				t[i][j]=-1;
		}
	}
	printf("Maximum Value: %d\n",knap(n,m));
	printf("table\n");
		for(i=0;i<n+1;i++){
		for(j=0;j<m+1;j++){
		    printf("%d\t",t[i][j]);
		}
		printf("\n");
		}
}

void correctness(){
  int i,j;
	printf("No. of Items: ");
	scanf("%d",&n);
	printf("Capacity: ");
	scanf("%d",&m);

	printf("Weight\tValue\n");
	for(i=1;i<n+1;i++)
		scanf("%d\t%d",&w[i],&v[i]);
	knapsack();
}

void analysis(){
  int i,j;
    FILE *f;
    f = fopen("BC.txt","a");
    m = 10;
    for(n=n1;n<=n2;n++){
      printf("Weight\tValue\n");
        for(i=1;i<n+1;i++){
            w[i] = rand()%12;
            v[i] = rand()%100;
            printf("%d\t\t%d\n",w[i],v[i]);
        }
        cnt = 0;
        knapsack();
        fprintf(f,"%d\t%d\n",n,cnt);
    }

}

void main(){
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
