/*Implement the following elementary sorting algorithms and perform their analysis by generating best case and worst case data. (Note: Any two may be asked in the test/exam) 
a) Selection Sort b) Bubble Sort c) Insertion Sort*/

//a
#include<stdio.h>
#include<stdlib.h>
#define n1 10
#define n2 100

int cnt;

void sort(int *a,int n){
    int p,t;
    for(int i=0;i<n-1;i++){
        p=i;
        for(int j=i+1;j<n;j++){
            cnt++;
            if(a[j]<a[p]){
                p=j;
            }}
            t=a[p];
            a[p]=a[i];
            a[i]=t;
        }
}

void analysis(){
    int *a,n;
    FILE *f1,*f2;
    f1=fopen("BC.txt","a");
    f2=fopen("WC.txt","a");
    for(n=n1;n<=n2;n+=10){
        a=(int*)malloc(n*sizeof(int));
        //BEST CASE
        for(int i=0;i<n;i++)
          a[i] = i+1;  
        cnt = 0;
        sort(a,n);
        fprintf(f1,"%d\t%d\n",n,cnt);
        //WORST CASE
        for(int i=n-1;i>=0;i--)
          a[i] = n-i+1;
        cnt = 0;
        sort(a,n);
        fprintf(f2,"%d\t%d\n",n,cnt);
    }system("gnuplot>load 'command.txt'");
    fclose(f1);
    fclose(f2);
}

void correctness(){
  int a[20],n,key,pos;
  printf("enter the number of elements required: ");
  scanf("%d",&n);
  printf("enter the elements: ");
  for(int i=0;i<n;i++)
    scanf("%d",&a[i]);
  printf("array elements after sorting:\n");
  sort(a,n);
  for(int i=0;i<n;i++)
    printf("%d\t",a[i]);
  printf("\n");
}

void main(){
  int ch;
  printf("1.analysis\t\t2.correctness\t\t0.exit\n");
  for(;;){
    printf("enter choice: ");
    scanf("%d",&ch);
    switch(ch){
      case 1:analysis();break;
      case 2:correctness();break;
      case 0:printf("exiting..\n");exit(0);
      default:printf("wrong choice!!\n");break;
    }
  }
}

// b
#include <stdio.h>
#include <stdlib.h>
#define n1 10
#define n2 100

int cnt;

void sort(int *a, int n) {
  int t, s = 0;
  for (int i = 0; i < n - 1; i++) {
    s = 0;
    for (int j = 0; j < n - i - 1; j++) {
      cnt++;
      if (a[j] > a[j + 1]) {
        t = a[j];
        a[j] = a[j + 1];
        a[j + 1] = t;
        s = 1;
      }
    }
    if (s == 0)
      break;
  }
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
      a[i] = i + 1;
    cnt = 0;
    sort(a, n);
    fprintf(f1, "%d\t%d\n", n, cnt);
    // WORST CASE
    for (int i = n - 1; i >= 0; i--)
      a[i] = n - i + 1;
    cnt = 0;
    sort(a, n);
    fprintf(f2, "%d\t%d\n", n, cnt);
  }
  system("gnuplot>load 'command.txt'");
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

// c
#include <stdio.h>
#include <stdlib.h>
#define n1 10
#define n2 100

int cnt;

int sort(int *a, int n) {
  int key, j;
  for (int i = 0; i < n; i++) {
    key = a[i];
    for (j = i - 1; j >= 0 && a[j] > key; j--) {
      cnt++;
      a[j + 1] = a[j];
    }
    a[j + 1] = key;
  }
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
      a[i] = i + 1;
    cnt = 0;
    sort(a, n);
    fprintf(f1, "%d\t%d\n", n, cnt);
    // WORST CASE
    for (int i = n - 1; i >= 0; i--)
      a[i] = n - i + 1;
    cnt = 0;
    sort(a, n);
    fprintf(f2, "%d\t%d\n", n, cnt);
  }
  system("gnuplot>load 'command.txt'");
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
