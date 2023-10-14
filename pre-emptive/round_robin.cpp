#include<bits/stdc++.h>
using namespace std;
class round_robin{
public:
	int arrival_time,brust_time,process_no;
};
bool cmp(round_robin &a,round_robin &b){
	if(a.arrival_time==b.arrival_time) return a.process_no<b.process_no;
	return a.arrival_time<b.arrival_time;
}
int main()
{
	cout<<"enter the no of process"<<endl;
	int no_of_process,time_frame; cin>>no_of_process>>time_frame;
	vector<round_robin>process(no_of_process),gant_chart,print;
	cout<<"enter arrival times and burst time"<<endl;
	for(int i=0;i<no_of_process;++i){
		cin>>process[i].arrival_time>>process[i].brust_time;
		process[i].process_no=i;
	}
	print=process;
	sort(process.begin(),process.end(),cmp);
	deque<round_robin>ready_queue;
	int time=0;
	ready_queue.push_back(process[0]);
	vector<int>vis(no_of_process+1),completion_time(no_of_process+1);
	while(!ready_queue.empty()){
		int mn=min(ready_queue.front().brust_time,time_frame);	
		time+=mn;
		ready_queue.front().brust_time-=mn;
		gant_chart.push_back(ready_queue.front());
		process[ready_queue.front().process_no].brust_time-=mn;
		vis[ready_queue.front().process_no]=1;
		for(auto &i:process){
			if(i.arrival_time<=time and i.brust_time>0 and vis[i.process_no]==0){
				ready_queue.push_back(i);
			}	
		}
		if(ready_queue.front().brust_time==0){
			completion_time[ready_queue.front().process_no]=time;
		}
		if(ready_queue.front().brust_time>0) ready_queue.push_back(ready_queue.front());
		ready_queue.pop_front();
	}
	for(auto &i:gant_chart){
		cout<<i.process_no+1<<" ";
	}
	cout<<endl;
	for(auto &i:print){
		cout<<i.process_no<<" "<<i.arrival_time<<" "<<i.brust_time<<" "<<completion_time[i.process_no]<<endl;
	}
	
	
}
