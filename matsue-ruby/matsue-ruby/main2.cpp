#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;


struct Node {
	char c[11];
	unsigned long long eval;

	Node(){
		memset(c, 0, sizeof(c));
		eval = 0;
	}

	void setStr(const char* pStr){
		memcpy(c, pStr, sizeof(c));
	}

	bool operator<(const Node& right) const {
		return eval < right.eval;
	}
};

//6
//fdk
//jnv
//vnj
//kdf
//qaq
//bhh

unsigned short offset = 'a';
int N, L;
char in[11];
vector<Node> _v;
vector<string> v, __v;
vector<Node>::iterator v_i;
vector<Node>::const_iterator v_ie;

unsigned long long eval(const char* s){
	unsigned int d = 0;
	unsigned long long ret = 0;

	for (int i = L - 1; i >= 0; i--){
		ret += (s[i] - offset) << d;
		d += 5;
	}

	return ret;
}

bool revChk(const char* s, const char* _s){
	for (int i = 0; i < L; i++){
		if (s[i] != _s[(L - 1) - i]){
			return false;
		}
	}
	return true;
}

int main(void){
	cin >> N;

	memset(in, 0, sizeof(in));

	for (int i = 0; i < N; i++){
		cin >> in;

		Node node;
		node.setStr(in);
		_v.push_back(node);

		if (i == 0)L = strlen(in);
	}

	//ƒyƒA‚ðŒ©‚Â‚¯‚é
	while (!_v.empty()){
		if (_v.size() == 1){
			if (revChk(_v.begin()->c, _v.begin()->c))
				__v.push_back( _v.at(0).c );

			break;
		}
		v_i = _v.begin();
		v_ie = _v.end();

		memcpy(in, &*v_i->c, sizeof(in));

		bool f = false;
		for (v_i++; v_i != v_ie; v_i++){
			if (revChk(in, &*v_i->c)){
				Node node;

				if (in < v_i->c){
					node.setStr(in);
					node.eval = eval(in);
				}
				else{
					node.setStr(&*v_i->c);
					node.eval = eval(&*v_i->c);
				}

				v.push_back(node.c);

				_v.erase(v_i);
				_v.erase(_v.begin());
				f = true;
				break;
			}
		}
		if (f)continue;

		if (revChk(in, in))
			__v.push_back(_v.at(0).c);

		_v.erase(_v.begin());
	}
	_v.clear();

	sort(v.begin(), v.end());
	sort(__v.begin(), __v.end());

	int size = L * ((v.size() * 2) + ((__v.empty()) ? 0 : 1));

	char* ans = new char[size + 1];
	memset(ans, 0, size + 1);


	int index = 0;

	vector<string>::iterator v_s;
	vector<string>::const_iterator v_se;

	for (v_s = v.begin(), v_se = v.end(); v_s != v_se; v_s++){
		for (int i = 0; i < L; i++){
			ans[index + i] = v_s->at(i);
			ans[size - 1 - index - i] = v_s->at(i);
		}
		index += L;
	}

	if (!__v.empty())
		for (int i = 0; i < L; i++){
		ans[index + i] = __v.begin()->at(i);
		}

{
	//L = size;
	//if (!revChk(ans, ans)){
	//while ( N > 900)
	//{
	//	int aa = 0;
	//}
	//}
}

	cout << ans << endl;

	delete ans;
	return 0;
}
