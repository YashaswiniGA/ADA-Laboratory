#include<stdio.h>
#include<conio.h>
void dfs(int);
int e[10][3],a[10][10],vis[10],n;
void main()
{
    int i,j,source, destination,edges,flag=0;
    printf("Enter the number of vertices:");
    scanf("%d",&n);
    printf("Enter the number of edges:");
    scanf("%d",&edges);
    printf("Enter edge matrix");
    for(i=0;i<edges;i++)
    {
            scanf("%d",&e[i][0]);
            scanf("%d",&e[i][1]);
    }
    printf("Enter the source:");
    scanf("%d",&source);
    printf("Enter the destination:");
    scanf("%d",&destination);
    for(i=0;i<n;i++)
    {
        vis[i]=0;
    }
    for(i=0;i<n;i++)
    {
        for(j=0;j<n;j++)
        {
            a[i][j]=0;
        }
    }
    for(i=0;i<edges;i++)
    {
        a[e[i][0]][e[i][1]]=1;
    }
    for(i=0;i<n;i++)
    {
        for(j=0;j<n;j++)
        {
            if(i==j)
                a[i][j]=0;
            if(a[i][j]!=1 && i!=j)
            {
                a[i][j]=99;
            }
        }
    }
    dfs(source);
    for(i=0;i<n;i++)
    {
        if(vis[i]==0)
        {
            flag=1;
            break;
        }
    }
    if(flag==1)
        printf("Not connected");
    else
        printf("connected");
    getch();
}
void dfs(int v)
{
    int i;
    vis[v]=1;
    for(i=0;i<n;i++)
    {
        if(a[v][i]==1 && vis[i]==0)
            dfs(i);
    }
}

