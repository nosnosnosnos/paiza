#include <iostream>
#include <stack>

using namespace std;

unsigned int N,M;
int List[100];
int GOTO[100];
unsigned short chk[100];	//1:true 2:false

void loop(){
	for (unsigned int i = 0; i < N; i++){
		GOTO[i] = List[i] + i;
	}

	stack<unsigned int> st;

	unsigned int _i = 0;
	for (unsigned int i = N - 1; i > 0; i--){
		if (List[i] == _i){
			chk[i] = 1;
			st.push(i);
		}
		_i++;
	}

	while (!st.empty()){
		unsigned int index = st.top();
		st.pop();


		for (unsigned int i = N - 1; i > 0; i--){
			if (index == GOTO[i]){
				if (chk[i] == 1){
					continue;
				}

				chk[i] = 1;
				st.push(i);
			}
		}
	}

}

int main(void){
	//8
	//0 6 - 2 - 2 0 1 - 1 0
	//6
	//7
	//3
	//4
	//2
	//5
	//10
	memset(chk, 0, sizeof(chk));
	memset(List, 0, sizeof(List));

	cin >> N;

	for (int i = 0; i < N; i++){
		cin >> List[i];
	}

	cin >> M;

	loop();

	
	for (int i = 0; i < M; i++){
		unsigned int buf;
		cin >> buf;
		cout << ((chk[buf] == 1) ? "Yes" : "No") << endl;
	}


	return 0;
}
