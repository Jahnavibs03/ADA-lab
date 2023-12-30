//Implement heap sort algorithm with bottom-up heap construction. Perform its analysis by generating best case and worst case data.


#include <stdio.h>
#include <stdlib.h>
#define n1 10
#define n2 100

int cnt;

void heapify(int *a, int n, int i) {
  cnt++;
  int largest = i;
  int left = 2 * i + 1;
  int right = 2 * i + 2;
  if (left < n && a[left] > a[largest])
    largest = left;
  if (right < n && a[right] > a[largest])
    largest = right;
  if (largest != i) {
    int temp = a[i];
    a[i] = a[largest];
    a[largest] = temp;

    heapify(a, n, largest);
  }
}

void sort(int *a, int n) {
  for (int i = n / 2 - 1; i >= 0; i--) 
    heapify(a, n, i);
  for (int i = n - 1; i >= 0; i--) {
    int temp = a[0];
    a[0] = a[i];
    a[i] = temp;
    heapify(a, i, 0);
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
        for(int i=n-1;i>=0;i--)
          a[i] = n-i+1; 
        cnt = 0;
        sort(a,n);
        fprintf(f1,"%d\t%d\n",n,cnt);
        //WORST CASE
        for(int i=0;i<n;i++)
          a[i] = i+1;
        cnt = 0;
        sort(a,n);
        fprintf(f2,"%d\t%d\n",n,cnt);
    }//system("gnuplot>load 'command.txt'");
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
