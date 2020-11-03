#include<iostream>
#include<algorithm>

using namespace std;

int liquid[100001];
int main(){
	int N;
	cin>>N;
	
	for(int i=0;i<N;i++){
		cin>>liquid[i];
//Ã¹ ÀÎµ¦½º0, ¸¶Áö¸· ÀÎµ¦½º N-1; 
	}
	
	sort(liquid,liquid+N);
	
	int head=0,tail=N-1;
	int idx1,idx2;
	int max=2000000001;
	int count =0;
	
	while(head!=tail){
		if((liquid[head]+liquid[tail])==0){
			idx1=head,idx2=tail;
			break;
		}
		else if((liquid[head]+liquid[tail])>=0){
			if(abs(liquid[head]+liquid[tail])<=max){
				max=abs(liquid[head]+liquid[tail]);
				idx1=head,idx2=tail;
			}
			tail--;
		}
		else{
			if(abs(liquid[head]+liquid[tail])<=max){
				max=abs(liquid[head]+liquid[tail]);
				idx1=head,idx2=tail;
			}
			head++;
		}
	}
	cout<<liquid[idx1]<<" "<<liquid[idx2];
	
	return 0;
}
