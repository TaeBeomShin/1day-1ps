#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

typedef struct point{
	int x;
	int y;
}point;

int comp(point p1,point p2){
	if(p1.y>p2.y){
		return 0;
	}
	else if(p1.y==p2.y){
		if(p1.x>p2.x){
			return 0;
		}
		else{
			return 1;
		}
	}
	else{
		return 1;
	}
}
int main(){
	int N;
	cin>>N;
	
	vector <point> v;
	point temp;
	for(int i=0;i<N;i++){
		cin>>temp.x>>temp.y;
		v.push_back(temp);
	}
	sort(v.begin(),v.end(),comp);
	
	for(int i=0;i<v.size();i++){
		cout<<v[i].x<<" "<<v[i].y<<"\n";
	}
	return 0;
}
