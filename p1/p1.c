//Implement Euclid’s, Consecutive integer checking and Modified Euclid’s algorithms to find GCD of two nonnegative integers and perform comparative analysis by generating best case and worst case data.


#include<stdio.h>
#include<stdlib.h>
#define n1 10
#define n2 100

int c1,c2,c3;



int cic(int m,int n,int sm){
  c1++;
  int x=m%sm;
  int y = n%sm;
  if(x == 0&& y==0)
    return sm;
  else{
    sm--;
    cic(m,n,sm);}   
}

int euclid(int m,int n){
  int r;
  c2 =0;
  while(n != 0){
    c2++;
    r = m%n;
    m = n;
    n = r;
  }
  return m;
}

int repsub(int m,int n){
c3 =0;
  while(m!=n){
    c3++;
    if(m > n)
      m = m-n;
    else
      n = n-m;
  }
  return m;
}

void analysis(){
  FILE *f1,*f2,*f3,*f4,*f5,*f6;
  int max1 =0, max2=0, max3 =0,min1 = 100000,min2 =100000,min3 =100000;
  int m,n,sm,x;
  f1 = fopen("BC1.txt","a");
  f2 = fopen("WC1.txt","a");
  f3 = fopen("BC2.txt","a");
  f4 = fopen("WC2.txt","a");
  f5 = fopen("BC3.txt","a");
  f6 = fopen("WC3.txt","a");
  for(x = n1;x<=n2;x+=10){
  	max1 = max2= max3 = 0;min1 = min2 =min3 =100000;
    for(int i = 2;i<= x;i++){
      for(int j = 2;j<= x;j++){
        m=i;n=j;
        sm = (m>n)?n:m;
        c3 = 0;c1 =0;c2 =0;
        cic(m,n,sm); 
        euclid(m,n);
        repsub(m,n);
        max1 = c1 > max1?c1:max1;
        min1 = c1 < min1?c1:min1;
        max2 = c2 > max2?c2:max2;
        min2 = c2 < min2?c2:min2;
        max3 = c3 > max3?c3:max3;
        min3 = c3 < min3?c3:min3;
      }
    }
    fprintf(f1,"%d\t%d\n",x,min1);
    fprintf(f2,"%d\t%d\n",x,max1);
    fprintf(f3,"%d\t%d\n",x,min2);
    fprintf(f4,"%d\t%d\n",x,max2);
    fprintf(f5,"%d\t%d\n",x,min3);
    fprintf(f6,"%d\t%d\n",x,max3);
  }system("gnuplot>load 'command1.txt'");
  fclose(f1);
  fclose(f2);
  fclose(f3);
  fclose(f4);
  fclose(f5);
  fclose(f6);
}

void correctness(){
    int m,n;
    printf("enter two numbers: ");
    scanf("%d %d",&m,&n);
    int sm = m>n?n:m;
    int res=cic(m,n,sm);
    printf("cosecutive integer checking = %d\n",res);
    res = euclid(m,n);
    printf("Euclid's = %d\n",res);
    res = repsub(m,n);
    printf("Repetitive subtraction = %d\n",res);
}

void main(){
    int ch;
    printf("1.Analysis\t\t2.correctness\t\t0.Exit\n");
    for(;;){ 
    printf("enter choice: ");
    scanf("%d",&ch);
    switch(ch){
        case 1:analysis();break;
        case 2:correctness();break;
        case 0:printf("exiting\n");exit(0);
        default:printf("invalid choice.\n");break;
        }
    }
}
