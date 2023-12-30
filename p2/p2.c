//Implement the following searching algorithms and perform their analysis by generating best case and worst case data. a) Sequential Search b) Binary Search( Recursive)

//a
#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#define n1 10
#define n2 100

int cnt;

int search(int *a,int n,int key){
    for(int i=0;i<n;i++){
        cnt++;
        if(key==a[i])
            return i+1;
    }
    return -1;
}

void analysis(){
    FILE *f1,*f2;
    int *a,n,key;
    f1=fopen("BC.txt","a");
    f2=fopen("WC.txt","a");
    for(n=n1;n<=n2;n+=10){
        a=(int*)malloc(n*sizeof(int));
      
        for(int i=0;i<n;i++)
            a[i]=rand()%100;
            //BEST CASE
            key=a[0];
            cnt = 0;
            search(a,n,key);
            fprintf(f1,"%d\t%d\n",n,cnt);
            //WORSTCASE
            key=999;
            cnt = 0;
            search(a,n,key);
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
  printf("enter the key to search: ");
  scanf("%d",&key);
  pos = search(a,n,key);
  pos > 0?printf("key found at position %d\n",pos):printf("not found!!\n");
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

//b
#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#define n1 10
#define n2 100

int cnt;

int search(int f,int l,int *a,int key){
    cnt++;
    if(f>l)
    return -1;
    int m=(f+l)/2;
    if(a[m]==key)
    return m+1;
    if(a[m]<key)
    return search(m+1,l,a,key);
    else
    return search(f,m-1,a,key);
}

void analysis(){
    int key,n;
    FILE *f1,*f2;
    f1=fopen("BC.txt","a");
    f2=fopen("WC.txt","a");
    for(n=n1;n<=n2;n+=10){
        int *a=(int*)malloc(n*sizeof(int));
      
        for(int i =0;i<n;i++)
          a[i] = i+1;
        //BEST CASE
        key=a[(n-1)/2];
        cnt=0;
        search(0,n-1,a,key);
        fprintf(f1,"%d\t%d\n",n,cnt);
        //WORST CASE
        key=999;
        cnt=0;
        search(0,n-1,a,key);
        fprintf(f2,"%d\t%d\n",n,cnt);
    }//system("gnuplot>load 'command.txt'");
    fclose(f1);
    fclose(f2);
}


void correctness(){
  int a[20],n,key,pos;
  printf("enter the number of elements required: ");
  scanf("%d",&n);
  printf("enter the elements in ascending order: ");
  for(int i=0;i<n;i++)
    scanf("%d",&a[i]);
  printf("enter the key to search: ");
  scanf("%d",&key);
  pos = search(0,n-1,a,key);
  pos > 0?printf("key found at position %d\n",pos):printf("not found!!\n");
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
