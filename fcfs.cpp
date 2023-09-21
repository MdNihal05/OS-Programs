#include<bits/stdc++.h>
using namespace std;
#define arrival first
#define burst   second
int main()
{
	cout<<"enter the no of processes and their arrival and burst time\n";
	int n; cin>>n;
	vector<pair<int,int>>process;
	
	for(int i=1;i<=n;++i){
		int x,y; 
		cin>>x>>y;
		process.push_back({x,y});
	}
	
	sort(process.begin(),process.end());
	
	vector<int>completion_time(n+1);
	
	completion_time[0]=process[0].arrival;
	completion_time[1]=process[0].burst;
	
	for(int i=1;i<n;++i){
		completion_time[i+1]=max(completion_time[i],process[i].arrival)+process[i].burst;
	}
	
	vector<int>turn_around_time(n);
	for(int i=0;i<n;++i){
		turn_around_time[i]=completion_time[i+1]-process[i].arrival;
	}
	
	vector<int>waiting_time(n);
	int average_waiting_time=0;
	
	
	for(int i=0;i<n;++i){
		waiting_time[i]=turn_around_time[i]-process[i].burst;
		average_waiting_time+=waiting_time[i];
	}
	
	
	cout<<"AT "<<" BT "<<" CT "<<" TAT "<<" WT "<<endl;
	cout<<"0  "<<" 0  "<<" "<<"0 "<<"  0  "<<"   0  "<<"    0  "<<endl;
	for(int i=0;i<n;++i){
		cout<<process[i].arrival<<"   "<<process[i].burst<<"   "<<completion_time[i+1]<<"   "<<turn_around_time[i]<<"   "<<waiting_time[i]<<endl;
	}
	
	cout<<"average waiting time :"<<average_waiting_time/(n*1.0)<<endl;

}
