#include<stdio.h>
#include<conio.h>
int a[10],n;
void merge(int a[10],int low,int mid,int high)
{
    int i,j,k,c[100];
    i=low;
    j=mid+1;
    k=low;
    while(i<=mid && j<=high)
    {
        if(a[i]<a[j])
            c[k++]=a[i++];
        else
            c[k++]=a[j++];
    }
    while(i<=mid)
        c[k++]=a[i++];
    while(j<=high)
        c[k++]=a[j++];
    for(i=low;i<=high;i++)
        a[i]=c[i];
}
void mergesort(int a[10],int low,int high)
{
    int mid;
    if(low<high)
    {
        mid=(low+high)/2;
        mergesort(a,low,mid);
        mergesort(a,mid+1,high);
        merge(a,low,mid,high);
    }
}
void main()
{
    int i;
    printf("Enter the number of elements:");
    scanf("%d",&n);
    printf("\nEnter the elements:");
    for(i=0;i<n;i++)
    {
        scanf("%d",&a[i]);
    }
    mergesort(a,0,n-1);
    for(i=0;i<n;i++)
    {
        printf("%d\t",a[i]);
    }
}

