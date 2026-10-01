#include <stdio.h>

#define MAX 20

int graph[MAX][MAX];
int visited[MAX];
int stack[MAX];
int top = -1;
int n;

void push(int item)
{
    stack[++top] = item;
}

int pop()
{
    return stack[top--];
}

void createNetwork()
{
    int edges, u, v;

    printf("Enter number of devices: ");
    scanf("%d", &n);

    for(int i=0;i<n;i++)
        for(int j=0;j<n;j++)
            graph[i][j]=0;

    printf("Enter number of connections: ");
    scanf("%d",&edges);

    printf("Enter connections (source destination):\n");

    for(int i=0;i<edges;i++)
    {
        scanf("%d%d",&u,&v);

        graph[u][v]=1;
        graph[v][u]=1;
    }
}

void displayTopology()
{
    printf("\nNetwork Topology:\n");

    for(int i=0;i<n;i++)
    {
        printf("Device %d -> ",i);

        for(int j=0;j<n;j++)
        {
            if(graph[i][j])
                printf("%d ",j);
        }

        printf("\n");
    }
}

int dfs(int current, int destination)
{
    visited[current] = 1;

    push(current);

    if(current == destination)
        return 1;

    for(int i=0;i<n;i++)
    {
        if(graph[current][i] && !visited[i])
        {
            if(dfs(i,destination))
                return 1;
        }
    }

    pop();     // Backtracking

    return 0;
}

void sendPacket()
{
    int source, destination;

    printf("Enter source device: ");
    scanf("%d",&source);

    printf("Enter destination device: ");
    scanf("%d",&destination);

    for(int i=0;i<n;i++)
        visited[i]=0;

    top=-1;

    if(dfs(source,destination))
    {
        printf("\nPacket transmitted successfully.\n");

        printf("Path Followed:\n");

        for(int i=0;i<=top;i++)
        {
            printf("%d",stack[i]);

            if(i<top)
                printf(" -> ");
        }

        printf("\n");

        printf("\nReceiving packet...\n");

        while(top!=-1)
        {
            printf("Packet received at device %d\n",pop());
        }
    }
    else
    {
        printf("No path exists between devices.\n");
    }
}

int main()
{
    int choice;

    while(1)
    {
        printf("\n===== COMPUTER NETWORK SIMULATION =====\n");
        printf("1. Create Network\n");
        printf("2. Display Network Topology\n");
        printf("3. Send Packet\n");
        printf("4. Exit\n");

        printf("Enter your choice: ");
        scanf("%d",&choice);

        switch(choice)
        {
            case 1:
                createNetwork();
                break;

            case 2:
                displayTopology();
                break;

            case 3:
                sendPacket();
                break;

            case 4:
                return 0;

            default:
                printf("Invalid Choice\n");
        }
    }

    return 0;
}
