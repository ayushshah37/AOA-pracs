//merge sort

#include <stdio.h>
#include<time.h>

#include<stdio.h>
#include<time.h>
#define MAX 150000
void merge(int a[],int left,int mid,int right)
{
    int i,j,k,temp[MAX],index;
    i=left;
    j=mid+1;
    index=left;
    while(i<=mid && j<=right)
    {
        if(a[i]<a[j])
        {
            temp[index]=a[i];
            i++;
        }
        else
        {
            temp[index]=a[j];
            j++;
        }
        index++;
    }
    if(i>mid)
    {
        while(j<=right)
        {
            temp[index]=a[j];
            j++;
            index++;
        }
    }
    else
    {
        while(i<=mid)
        {
            temp[index]=a[i];
            i++;
            index++;
        }
    }
    for(k=left;k<index;k++)
        {a[k]=temp[k];}
        
}
void mergesort(int a[],int left,int right)
{
    int mid;
    if(left<right)
    {
        mid=(left+right)/2;
        mergesort(a,left,mid);
        mergesort(a,mid+1,right);
        merge(a,left,mid,right);
    }
}

int main()
{
    int n,a[100];
    float t;
    printf("enter number of elements: ");
    scanf("%d",&n);
    /*printf("enter elements:");
    
    for(int i=0;i<n;i++){
        scanf("%d",a[i]);
    }*/
    for(int i=0;i<n;i++){
        a[i]=i;
    }
    t=clock();
    mergesort(a,0,n-1);
    t=clock()-t;
    printf("best case time:%f\n",t);
    
    for(int i=0,j=n;i<n,j>0;i++,j--){
        a[i]=j;
    }
    t=clock();
    mergesort(a,0,n-1);
    t=clock()-t;
    printf("worst case time: %f\n",t);
    
    for(int i=0;i<n;i++){
        a[i]=rand();
    }
    t=clock();
    mergesort(a,0,n-1);
    t=clock()-t;
    printf("avg case time: %f\n",t);
    
    
    return 0;
}
