#include<bits/stdc++.h>
using namespace std;
//FCFS Disck sheduling
int main()
{
    int n, head; cin >> n >> head;
    vector<int>processes(n);
    for (auto &process : processes) cin >> process;
    int seek_time = 0;
    for (auto &i : processes) {
        seek_time += abs(head - i);
        head = i;
    }
    cout << seek_time;
}
