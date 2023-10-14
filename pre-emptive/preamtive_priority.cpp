#include<bits/stdc++.h>
using namespace std;
class sjf{
public:
	int process_no,arrival_time,burst_time,index,priority;
};
int find_index(int time,vector<sjf>&process){
	int ind=-1,n=process.size(),max_time=INT_MAX;
	for(int i=0;i<n;++i){
		if(process[i].arrival_time<=time and process[i].priority<max_time){
			ind=i;
			max_time=process[i].priority;
		}
	}
	return ind;
}
bool cmp(const sjf &a,const sjf &b){
	return a.arrival_time<b.arrival_time;	
}
int main(){
	int n; cin>>n;
	vector<sjf>process(n),temp;
	for(int i=0;i<n;++i){
		cin>>process[i].process_no>>process[i].arrival_time>>process[i].burst_time>>process[i].priority;
		process[i].index=i;
	}
	temp=process;
	int time=0;
	vector<int>gant_chart,completion_time(n),turn_around_time(n),Burst_time(n);
	while(temp.size()>0){
		int ind=find_index(time,temp);
		if(ind>=0) {
			gant_chart.push_back(temp[ind].process_no);
			temp[ind].burst_time--;
			if(temp[ind].burst_time==0){
				completion_time[temp[ind].index]=time+1;
				temp[ind].arrival_time=INT_MIN;
				sort(temp.begin(),temp.end(),cmp);
				temp.erase(temp.begin());
			}
		}else gant_chart.push_back(-1);
		time++;
	}
	for(auto &i:gant_chart) cout<<i<<" "; cout<<endl;
	for(int i=0;i<n;++i) cout<<i<<" "<<completion_time[i]<<endl;
	for(int i=0;i<n;++i) turn_around_time[i]=completion_time[i]-process[i].arrival_time;
	for(int i=0;i<n;++i) Burst_time[i]=turn_around_time[i]-process[i].burst_time;
	for(int i=0;i<n;++i) {
				cout<<process[i].process_no<<" "<<process[i].arrival_time<<" "<<process[i].burst_time<<"   "<<completion_time[i]<<"    "<<turn_around_time[i]<<"    "<<Burst_time[i]<<endl;
	}
	
	
	

}
