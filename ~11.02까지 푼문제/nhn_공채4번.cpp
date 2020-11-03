#include <iostream>
#include <sstream>
#include<bits/stdc++.h>
using namespace std;

void solution(int numOfOrder, string *orderArr) {
  // TODO: 이곳에 코드를 작성하세요. 추가로 필요한 함수와 전역변수를 선언해서 사용하셔도 됩니다.
	// 스택 순열?
	for(int i=0;i<numOfOrder;i++){	
		stack <char> S;
		string answer="";
		for(int j=0;j<orderArr[i].length();j++){
			char c=orderArr[i][j];//현재의 문자.
			char last;
			if(!S.empty()){//스택이 비어있지 않을때.
				string temp="";
				string ts="";
				if(c=='R'||c=='G'||c=='B'){//문자일때
					S.push(c);
				}
				else if(c>='1'&&c<='9'){//숫자일때
					S.push(c);
				}
				else if(c=='('){
					S.push(c);
				}
				else if(c==')'){
					while(S.top()!='('){//(괄호를 만날때까지.
						temp+=S.top();
						S.pop();
					}
					if(last>='1'&&last<='9'){//숫자일때  
						int num=last-'0';
						for(int k;k<temp.length();k++){
							for(int l=0;l<num;l++){
								 ts+=temp[k];
							}
						}
					}
					else{//문자열 
						for(int k;k<temp.length();k++){
							ts+=last;
							ts+=temp[k];
						} 
					}
				}
				answer+=temp;
			}else{//스택이 비어있을때
				if(c=='('){//괄호 문자가오면.
					S.push(c);
				}else{
					answer+=c;
					last=c;//마지막의 인덱스
				}
			}
		}
		// 1. 숫자일때
		// 	1-1.숫자 뒤가 문자일때
		// 	1-2.숫자 뒤가 괄호일때
		// 2. 괄호가 있을때
		// 	2-1.괄호 앞이 문자일때
		// 	2-2.괄호 앞이 숫자일때
		// 3. 문자일때
		cout<<answer<<"\n";
	}	
}

struct input_data {
  int numOfOrder;
  string *orderArr;
};

void process_stdin(struct input_data& inputData) {
  string line;
  istringstream iss;

  getline(cin, line);
  iss.str(line);
  iss >> inputData.numOfOrder;

  inputData.orderArr = new string[inputData.numOfOrder];
  for (int i = 0; i < inputData.numOfOrder; i++) {
    getline(cin, line);
    iss.clear();
    iss.str(line);
    iss >> inputData.orderArr[i];
  }
}

int main() {
  struct input_data inputData;
  process_stdin(inputData);

  solution(inputData.numOfOrder, inputData.orderArr);
  return 0;
}
