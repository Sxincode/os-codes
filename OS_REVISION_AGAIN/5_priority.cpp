// Priority Scheduling 
#include<bits/stdc++.h>
#include<iostream>
using namespace std;
int main()
{
    int n;
    cout<<"Enter no. of processes:";
    cin>>n;
    vector<int> pr, bt, ct(n), tat(n), wt(n);
    float avg_tat=0.0, avg_wt=0.0;
    cout<<"Enter priority:";
    for(int i=0;i<n;i++)
    {
        int x;
        cin>>x;
        pr.push_back(x);
    }
    cout<<"Enter burst time:";
    for(int i=0;i<n;i++)
    {
        int x;
        cin>>x;
        bt.push_back(x);
    }
    vector<pair<int,pair<int,int>>> v; // {pr,{bt,pid}}
    for(int i=0;i<n;i++)
    {
        v.push_back({pr[i],{bt[i],i}});        
    }
    sort(v.begin(), v.end());
    int time=0;
    for(int i=0;i<n;i++)
    {
        time+=v[i].second.first;
        ct[v[i].second.second]=time;
        tat[v[i].second.second]=ct[v[i].second.second];
        wt[v[i].second.second]=tat[v[i].second.second]-v[i].second.first;
        avg_tat+=tat[v[i].second.second];
        avg_wt+=wt[v[i].second.second];
    }

    cout<<"Average Turn Around Time:"<<fixed<<setprecision(2)<<(float)avg_tat/n<<endl;
    cout<<"Average Waiting Time:"<<fixed<<setprecision(2)<<(float)avg_wt/n<<endl;
    
    return 0;
}