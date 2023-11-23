#include<bits/stdc++.h>
using namespace std;
//SSTF Disck sheduling
int total_tracks, head, no_of_process;
vector<int>vis(100);
pair<int, int> get_ans(int head, vector<int>&tasks) {
    int x = INT_MAX, y = INT_MAX, ind = 0, curr1 = 0, curr2 = 0;
    for (int i = 0; i < no_of_process; i++) {
        if (vis[i] == 0) {
            if (tasks[i] >= head and tasks[i] - head < x) {
                x = tasks[i] - head;
                curr1 = tasks[i];
            } else if (head >= tasks[i] and head - tasks[i] < y) {
                y = head - tasks[i];
                curr2 = tasks[i];
            }
        }
    }
    if (x < y) return {x, curr1};
    else return {y, curr2};
}
int main()
{
    cin >> no_of_process >> head >> total_tracks;
    vector<int>tasks(no_of_process);
    for (auto &task : tasks) cin >> task;
    sort(tasks.begin(), tasks.end());
    int seek_time = 0;
    int count = 0;
    while (count != no_of_process) {
        auto [x, y] = get_ans(head, tasks);
        seek_time += x;
        int ind = lower_bound(tasks.begin(), tasks.end(), y) - tasks.begin();
        head = y;
        vis[ind] = 1;
        count++;
    }
    cout << seek_time;
}
