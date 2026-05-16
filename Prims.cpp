#include <iostream>
using namespace std;

int main()
{
    int n, cost[10][10];
    cin >> n;

    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            cin >> cost[i][j];

            if(cost[i][j]==0)
                cost[i][j]=999;
        }
    }

    bool visited[10]={0};

    visited[0]=1;

    int edges=0,mincost=0;

    while(edges<n-1)
    {
        int min=999,a,b;

        for(int i=0;i<n;i++)
        {
            if(visited[i])
            {
                for(int j=0;j<n;j++)
                {
                    if(!visited[j] && cost[i][j]<min)
                    {
                        min=cost[i][j];
                        a=i;
                        b=j;
                    }
                }
            }
        }

        cout<<a<<" - "<<b<<" = "<<min<<endl;

        mincost += min;
        visited[b]=1;
        edges++;
    }

    cout<<"Minimum Cost = "<<mincost;

    return 0;
}