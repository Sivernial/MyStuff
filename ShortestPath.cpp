#include <bits/stdc++.h>
using namespace std;
#define INF 1e9
typedef long long int ll;

int minIndex(int arr[],int n,bool visited[]){
    int min=0;
    for (int i = 0; i < n; i++)
    {
        if(visited[min]>visited[i]){
            min=i;
        }
        else if(visited[min]==visited[i] && arr[min]>arr[i] ){
            min=i;
        }
    }
    return min;
    
}

void printArray(int arr[], int size)
{
    int i;
    for (i = 0; i < size; i++)
        cout << arr[i] <<' ' ;
    cout << endl;
}


int main()
{
   
    int n;
    cin>>n;
    int Matrix[n][n];

    int m;
    cin>>m; 
    int weight[n][n];
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            Matrix[i][j]=0;
            weight[i][j]=0;
        }
        
    }
    
    
    int distance[n];
    bool visited[n];
    for (int i = 0; i < n; i++)
    {
        distance[i]=INF;
        visited[i]=0;
    }
    
    for (int i = 0; i < m; i++)
    {
        int x,y;
        cin>>x>>y;
        Matrix[x-1][y-1]=1;
        Matrix[y-1][x-1]=1;       //Friends Marked
        int w;
        cin>>w;
        weight[x-1][y-1]=w;
        weight[y-1][x-1]=w;
    }
    distance[0]=0;
    // for (int i = 0; i < n; i++)
    // {
    //     for (int j = 0; j < n; j++)
    //     {
    //         cout<<weight[i][j]<<" ";
    //     }
    //     cout<<endl;
        
    // }
    
    for (int i = 0; i < n; i++)
    {
        int u=minIndex(distance,n,visited);
        // cout<<u<<endl;
        visited[u]=1;
        for (int j = 0; j < n; j++)
        {
            if(Matrix[u][j] && !visited[j] && distance[j]>distance[u]+weight[u][j]){
                distance[j]=distance[u]+weight[u][j];
                
            }
        }
        
        
    // cout<<endl;
    }
    
    
    
    
    
    for (int i = 0; i < n; i++)
    {
        if(distance[i]==INF){
            cout<<"-1 ";
        }
        else{
            cout<<distance[i]<<" ";
        }
    }
    return 0;
}