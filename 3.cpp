#include<bits/stdc++.h>
using namespace std;

int main()
{
	auto solve=[&]()->void{
		int k,n,m; cin>>k>>n>>m;
		vector<int>a(n),b(m),ans;
		for(auto &i:a) cin>>i;
		for(auto &i:b) cin>>i;
		int i=0,j=0;
		while(i<n or j<m) {
			while(i<n and a[i]==0){
				ans.push_back(a[i++]);
				k++;
			}
			while(j<m and b[j]==0){
				ans.push_back(b[j++]);
				k++;
			}
			while(i<n and a[i]<=k and a[i]!=0){
				ans.push_back(a[i++]);
			}
			while(j<m and b[j]<=k and b[j]!=0){
				ans.push_back(b[j++]);
			}
			if(a[i]>k){
				cout<<-1;
				return;
			}
			if(b[j]>k){
				cout<<-1;
				return;
			}
		}
	};
	int T; cin>>T;
	while(T--){
		solve();
		cout<<endl;
	}
}
