// First Fit Algorithm
/* Take the first suitable block for the process*/
#include<bits/stdc++.h>
#include<iostream>
using namespace std;
void first_fit(vector<int> &allocation,vector<int> block, vector<int> process, int n,int m)
{
    for(int i=0;i<m;i++)
    {
        for(int j=0;j<n;j++)
        {
            if(process[i]<=block[j])
            {
                allocation[i]=j+1;
                block[j]-=process[i];
                break;
            }
        }
    }
}
int main()
{
    int n; // no of blocks 
    int m; // no of process 
    cout<<"Enter no of blocks:";
    cin>>n;
    cout<<"Enter no of processes:";
    cin>>m;
    vector<int> block, process;
    cout<<"Enter Block Sizes:";
    for(int i=0;i<n;i++)
    {
        int x;
        cin>>x;
        block.push_back(x);
    }
    cout<<"Enter Process Sizes:";
    for(int i=0;i<m;i++)
    {
        int x;
        cin>>x;
        process.push_back(x);
    }
    vector<int> allocation(m, -1);
    first_fit(allocation, block, process, n,m);
    for(int i=0;i<m;i++)
    {
        cout<<allocation[i]<<" ";
    }
    
    return 0;
}