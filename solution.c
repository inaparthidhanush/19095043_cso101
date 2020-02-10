#include <stdio.h>
#include<math.h>
#include<limits.h>
struct stackno
{
int *stacks,top1,top2;
};
struct stackno s;
void xsort(int *a,int n){
    int i,j,tmp;
    for(i=0;i<n-1;i++){
        for(j=i+1;j<n;j++)
        {
            if(a[i]>a[j])
            {
                tmp=a[i];
                a[i]=a[j];
                a[j]=tmp;
            }
        }
    }
}

int mode(int *a, int n) 
{ 
    int i,t=a[n-1]+1; 
    int count[t];
    for(i=0;i<n;i++) count[i]=0;
    for(i=0;i<n;i++) 
        count[a[i]]++; 
    int mode=0; 
    int k=count[0]; 
    for(i=1;i<t;i++){ 
        if (count[i]>k){ 
            k=count[i]; 
            mode=i; 
        } 
    } 
  
    return mode; 
}
 void push1(int num)
   {
       s.top1++;
       s.stacks[s.top1]=num;
   }
   void push2(int num)
   {
       s.top2--;
       s.stacks[s.top2]=num;
   }
   void pop1()
   {
       s.top1--;
   }
   void pop2()
   {
       s.top2++;
   }
int main() {
   int n,m,command,stackno,no;
   scanf("%d %d",&n,&m);
   s.stacks=(int *)malloc(2*m*sizeof(int));
   s.top1=-1;
   s.top2=2*m;
   int no_of_operations=m;
   int *arr=(int *)malloc(n*sizeof(int));
   int i=0,j;
   while(no_of_operations--)
   {
       scanf("%d%d%d",&command,&stackno,&no);
       if(command==1)
       {
           arr[i]=no;
           i++;
           if(stackno==1) push1(no);
           else if(stackno==2) push2(no);
       }
       else if(command==2)
       {
           if(stackno==1) pop1();
           else if(stackno==2) pop2();
       }

   }
   int sum=0;
   for(j=0;j<i;j++) sum+=arr[j];
   float mean=sum*1.0/i;
   printf("%f ",mean);
   xsort(arr,i);
   float median;
   if(i%2==1) median=arr[i/2];
   else median=(arr[i/2-1]+arr[i/2])/2.0;
   printf("%f ",median);
   printf("%d ",mode(arr,i));
   float stnddeviation;
   float sum2;
   for(j=0;j<i;j++) sum2+=(arr[j]*arr[j]);
   sum2=sum2*1.0/i;
   stnddeviation=sqrt(sum2-mean*mean);
   printf("%f\n",stnddeviation);
   while(s.top1>=0)
   {
       printf("%d ",s.stacks[s.top1]); 
       s.top1--;
   }
   printf("\n");
   while(s.top2<=2*m-1)
   {
       printf("%d ",s.stacks[s.top2]);  
       s.top2++;
   }
}
