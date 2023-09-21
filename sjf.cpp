#include<bits/stdc++.h>
using namespace std;
#define arrival first
#define burst   second

bool cmp(pair<int,int>&a,pair<int,int>&b){
	if(a.second==b.second) return a.first<b.first;
	else return a.burst<b.burst;
}

int main()
{

	cout<<"enter the no of processes and their arrival and burst time\n";
	int no_of_process; cin>>no_of_process;
	vector<pair<int,int>>process;
	pair<int,int> mn={999,999};
	for(int i=0;i<no_of_process;i++){
		int x,y; cin>>x>>y;
		process.push_back({x,y});
	}
	pair<int,int>mne=*min_element(process.begin(),process.end());
	process.erase(min_element(process.begin(),process.end()));
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
	
	
	cout<<"AT "<<" BT "<<" CT "<<" TAT "<<" WT "<<endl;
	cout<<"0  "<<" 0  "<<" "<<"0 "<<"  0  "<<"   0  "<<"    0  "<<endl;
	for(int i=0;i<no_of_process;++i){
		cout<<process[i].arrival<<"   "<<process[i].burst<<"   "<<completion_time[i+1]<<"   "<<turn_around_time[i]<<"   "<<waiting_time[i]<<endl;
	}
	
	cout<<"average waiting time :"<<average_waiting_time/(no_of_process*1.0)<<endl;
	
}
