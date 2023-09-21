#include<bits/stdc++.h>
using namespace std;
#define arrival first.second
#define processno first.first
#define burst   second.first
#define priority second.second

bool cmp(pair<pair<int,int>,pair<int,int>>&a,pair<pair<int,int>,pair<int,int>>&b){
	if(a.priority==b.priority) a.arrival<b.arrival;
	return a.priority<b.priority;
}

int main()
{
	cout<<"enter the no of processes and their arrival and burst time and prority\n";
	
	int no_of_process; cin>>no_of_process;
	vector<pair<pair<int,int>,pair<int,int>>>process;
	pair<pair<int,int>,pair<int,int>>mne={{999,999},{999,999}};
	for(int i=0;i<no_of_process;i++){
		int x,y,z; cin>>x>>y>>z;
		process.push_back({{i+1,x},{y,z}});
		if(mne.arrival>x) mne={{i+1,x},{y,z}};
	}
	process.erase(find(process.begin(),process.end(),mne));
	sort(process.begin(),process.end(),cmp);
	process.insert(process.begin(),mne);
	
	vector<int>completion_time(no_of_process+1);
	
	completion_time[0]=process[0].arrival;
	completion_time[1]=process[0].burst;
	
	for(int i=1;i<no_of_process;++i){
		completion_time[i+1]=max(completion_time[i],process[i].arrival)+process[i].burst;
	}
	
	vector<int>turn_around_time(no_of_process);
	for(int i=0;i<no_of_process;++i){
		turn_around_time[i]=completion_time[i+1]-process[i].arrival;
	}
	
	vector<int>waiting_time(no_of_process);
	int average_waiting_time=0;
	
	
	for(int i=0;i<no_of_process;++i){
		waiting_time[i]=turn_around_time[i]-process[i].burst;
		average_waiting_time+=waiting_time[i];
	}
	
	
	cout<<"procesno  "<<"AT "<<" BT "<<" "<<"PT"<<"  CT "<<"   TAT "<<"    WT "<<endl;
	cout<<"0  "<<" 0  "<<" "<<"0 "<<"  0  "<<"   0  "<<"    0  "<<endl;
	for(int i=0;i<no_of_process;++i){
		cout<<process[i].processno<<"    "<<process[i].arrival<<"   "<<process[i].burst<<"   "<<process[i].priority<<"   "<<completion_time[i+1]<<"       "<<turn_around_time[i]<<"       "<<waiting_time[i]<<endl;
	}
	
	cout<<"average waiting time :"<<average_waiting_time/(no_of_process*1.0)<<endl;
	
}
