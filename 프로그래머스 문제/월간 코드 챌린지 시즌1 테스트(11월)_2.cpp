#include <bits/stdc++.h>
using namespace std;

vector<int> solution(string s) {
    vector<int> answer;
    int c=0,t=0;
    while(s.length()!=1){
        t++;
        string temp="",temp2="";
        for(int i=0;i<s.length();i++){
            if(s[i]=='1') temp+='1';
            else c++;
        }
        int l=temp.length();
        while(l!=0){
            temp2+=l%2+'0';
            l=l/2;
        }
        reverse(temp2.begin(),temp2.end());
        s=temp2;
    }
    answer.push_back(t);
    answer.push_back(c);
    return answer;
}
