#include <stdio.h>
#include <limits.h>

int main() {
    int n, m;
    scanf("%d %d", &n, &m);
    int graph[n][n];
    for(int i=0;i<n;i++)
        for(int j=0;j<n;j++)
            graph[i][j]=0;

    for(int i=0;i<m;i++) {
        int u,v,w;
        scanf("%d %d %d",&u,&v,&w);
        u--; v--;
        graph[u][v]=w;
        graph[v][u]=w;
    }

    int key[n], mst[n], parent[n];
    for(int i=0;i<n;i++) {
        key[i]=INT_MAX;
        mst[i]=0;
    }

    key[0]=0;
    parent[0]=-1;

    for(int count=0;count<n-1;count++) {
        int min=INT_MAX, u;
        for(int v=0;v<n;v++)
            if(!mst[v] && key[v]<min)
                min=key[v], u=v;

        mst[u]=1;

        for(int v=0;v<n;v++)
            if(graph[u][v] && !mst[v] && graph[u][v]<key[v])
                parent[v]=u, key[v]=graph[u][v];
    }

    int sum=0;
    for(int i=1;i<n;i++)
        sum+=key[i];

    printf("%d",sum);
    return 0;
}