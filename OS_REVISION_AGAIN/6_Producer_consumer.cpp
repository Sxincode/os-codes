/*Producer Consumer*/
#include<bits/stdc++.h>
#include<iostream>
using namespace std;
void wait(int &s)
{
    while(s<=0);
    s--;
}
void signal(int &s)
{
    s++;
}

void producer(int &mutex,int &F,int &E,int &i,vector<int> &buffer)
{
    wait(E);
    wait(mutex);

    buffer[i]=90;
    i=(i+1)%buffer.size();

    signal(mutex);
    signal(F);
}
void consumer(int &mutex,int &F,int &E,int &i,vector<int> buffer)
{
    wait(F);
    wait(mutex);

    buffer[i]=0;
    i=(i+1)%buffer.size();

    signal(mutex);
    signal(E);
}
int main()
{
    
    return 0;
}