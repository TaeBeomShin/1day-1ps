#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;

int main(){
	int N;
	cin>>N;
	vector <int> v;
	int temp;
	for(int i=0;i<N;i++){
		cin>>temp;
		v.push_back(temp);
	}
	
//	for(int i=0;i<v.size();i++) cout<<v[i]<<" ";
	
	sort(v.begin(),v.end());
	v.erase(unique(v.begin(),v.end()),v.end());
	
	for(int i=0;i<v.size();i++) cout<<v[i]<<" ";
	
	return 0;
}
