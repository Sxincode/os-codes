#include<bits/stdc++.h>
#include<iostream>
using namespace std;
int main()
{
    int n;
    cout<<"Enter no. of processes:";
    cin>>n;
    vector<int> at, bt, ct(n), tat(n), wt(n);
    float avg_tat=0.0,avg_wt=0.0;
    cout<<"Enter Arrival time:";
    for(int i=0;i<n;i++)
    {
        int x;
        cin>>x;
        at.push_back(x);
    }
    cout<<"Enter burst time:";
    for(int i=0;i<n;i++)
    {
        int x;
        cin>>x;
        bt.push_back(x);
    }
    vector<pair<int,pair<int,int>>> v; // {at,{bt,pid}}    
    for(int i=0;i<n;i++)
    {
        v.push_back({at[i],{bt[i],i}});
    }
    sort(v.begin(),v.end());
    int count =n;
    int i=0;
    int time =0;
    int tq=2; // Time Quantum
    queue<pair<int,int>> q; // bt, pid
    while(count>0)
    {
        if(time< v[0].first) time++;
        else
        {
            while(i<n && v[i].first<=time)
            {
                 q.push({v[i].second.first, v[i].second.second});
                 i++;
            }
            if(q.front().first > tq)
            {
                time+=tq;
                while(i<n && v[i].first<=time)
                {
                    q.push({v[i].second.first, v[i].second.second});
                    i++;
                }
                q.push({q.front().first-tq, q.front().second});
            }
            else if(q.front().first<=tq)
            {
                time+=q.front().first;
                ct[q.front().second]=time;
                count--;
            }
            q.pop();
        }
    }
    for(int i=0;i<n;i++)
    {
        tat[i] = ct[i]-at[i];
        wt[i] = tat[i]-bt[i];
        avg_tat+=tat[i];
        avg_wt+=wt[i];
    }
    cout<<"Average Turn Around Time:"<<fixed<<setprecision(2)<<avg_tat/n<<endl;
    cout<<"Average Waiting Time:"<<fixed<<setprecision(2)<<avg_wt/n<<endl;

    return 0;
}