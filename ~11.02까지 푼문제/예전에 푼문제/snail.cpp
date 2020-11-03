#include <bits/stdc++.h>
using namespace std;

int main(){
    vector<int> answer;
    int n;
    cin>>n;
    
    int arr[n][n]={0,};
    
    int x=0,y=0,diag=0;
    int count=0;
    int num=1;
    int check=0;
    int loopidx=(n%3)?n/3+1:n/3;
    
    arr[0][0]=1;
    while(loopidx!=check){
        while(arr[y+1][x]==0){
        	y++;
        	arr[y][x]=++num;
		}
        
        while(arr[y][x+1]==0){
        	x++;
        	arr[y][x]=++num;
		}
		while(arr[y-1][x-1]==0){
			x--;y--;
			arr[y][x]=++num;
		}
        check++;
    }
    
    for(int i=0;i<n;i++){
        for(int j=0;j<=i;j++){
            cout<<arr[i][j]<<" ";
        }
        cout<<"\n";
    }
    
    
    return 0;
}
