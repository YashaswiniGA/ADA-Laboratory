#include<stdio.h>
#include<conio.h>
int a[10],n;
void qsort(int a[10],int low,int high)
{
    int mid;
    if(low<high)
    {
        mid=partition(a,low,high);
        qsort(a,low,mid-1);
        qsort(a,mid+1,high);
    }
}
int partition(int a[10],int low,int high)
{
    int i,j,temp,pivot;
    pivot=a[low];
    i=low+1;
    j=high;
    while(i<=j)
    {

        while(a[i]<=pivot)
            i++;
        while(a[j]>pivot)
            j--;
        if(i<j)
        {
            temp=a[i];
            a[i]=a[j];
            a[j]=temp;
        }
    }
    temp=a[low];
    a[low]=a[j];
    a[j]=temp;
    return j;
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
    qsort(a,0,n-1);
    for(i=0;i<n;i++)
    {
        printf("%d\t",a[i]);
    }
}
