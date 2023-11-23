#include<bits/stdc++.h>
using namespace std;
//SCAN Disck sheduling
int total_tracks, head, no_of_process;
int get_ans1(vector<int>tasks) {
    int seek_time = 0;
    auto start = lower_bound(tasks.begin(), tasks.end(), head) - tasks.begin();
    for (int index = start, current = head; index <= no_of_process; index++) {
        seek_time += abs(tasks[index] - current);
        current = tasks[index];
    }
    seek_time += total_tracks - tasks.back();
    for (int index = start - 1 , current = total_tracks; index >= 0; index--) {
        seek_time += abs(tasks[index] - current);
        current = tasks[index];
    }

    return seek_time;
}
int get_ans2(vector<int>tasks) {
    int seek_time = 0;
    auto start = upper_bound(tasks.begin(), tasks.end(), head) - tasks.begin();
    for (int index = start - 1 , current = head; index >= 0; index--) {
        seek_time += abs(tasks[index] - current);
        current = tasks[index];
    }
    seek_time += tasks[0] - 0;
    for (int index = start, current = 0; index < no_of_process; index++) {
        seek_time += abs(tasks[index] - current);
        current = tasks[index];
    }
    return seek_time;
}

int main()
{
    cin >> no_of_process >> head >> total_tracks;
    vector<int>tasks(no_of_process);
    for (auto &task : tasks) cin >> task;
    sort(tasks.begin(), tasks.end());
    cout << min(get_ans1(tasks), get_ans2(tasks));
}
