//#include <iostream>
//#include <vector>
//#include <algorithm>
//using namespace std;
//
//
//struct Node {
//	string c;
//	unsigned long long eval;
//
//	Node(){
//		c.clear();
//		eval = 0;
//	}
//
//	void setStr(const string s){
//		c = s;
//	}
//
//	bool operator<(const Node& right) const {
//		return eval < right.eval;
//	}
//};
//
////6
////fdk
////jnv
////vnj
////kdf
////qaq
////bhh
//
//unsigned short offset = 'a';
//int N, L;
//string in;
//vector<Node> _v;
//vector<string> v, __v;
//vector<Node>::iterator v_i;
//vector<Node>::const_iterator v_ie;
//
//unsigned long long eval(const char* s){
//	unsigned int d = 0;
//	unsigned long long ret = 0;
//
//	for (int i = L - 1; i >= 0; i--){
//		ret += (s[i] - offset) << d;
//		d += 5;
//	}
//
//	return ret;
//}
//
//bool revChk(const string s, const string _s){
//	for (int i = 0; i < L; i++){
//		if (s[i] != _s[(L - 1) - i]){
//			return false;
//		}
//	}
//	return true;
//}
//
//int main(void){
//	cin >> N;
//
//	in.clear();
//
//	for (int i = 0; i < N; i++){
//		char aaa[20];
//		memset(aaa, 0, 20);
//		cin >> aaa;
//
//		Node node;
//
//		in = aaa;
//
//		node.setStr(in);
//		_v.push_back(node);
//
//		if (i == 0)L = strlen(aaa);
//	}
//
//	//ƒyƒA‚ðŒ©‚Â‚¯‚é
//	while (!_v.empty()){
//		if (_v.size() == 1){
//			if (revChk(_v.begin()->c, _v.begin()->c))
//				__v.push_back( _v.at(0).c );
//
//			break;
//		}
//		v_i = _v.begin();
//		v_ie = _v.end();
//
//		in = v_i->c;
//		//memcpy(in, &*v_i->c, sizeof(in));
//
//		bool f = false;
//		for (v_i++; v_i != v_ie; v_i++){
//			if (revChk(in, v_i->c)){
//				Node node;
//
//				if (in < v_i->c){
//					node.setStr(in);
//					//node.eval = eval(in);
//				}
//				else{
//					node.setStr(v_i->c);
//					//node.eval = eval(&*v_i->c);
//				}
//
//				v.push_back(node.c);
//
//				_v.erase(v_i);
//				_v.erase(_v.begin());
//				f = true;
//				break;
//			}
//		}
//		if (f)continue;
//
//		if (revChk(in, in))
//			__v.push_back(_v.at(0).c);
//
//		_v.erase(_v.begin());
//	}
//	_v.clear();
//
//	sort(v.begin(), v.end());
//	sort(__v.begin(), __v.end());
//
//	int size = L * ((v.size() * 2) + ((__v.empty()) ? 0 : 1));
//
//	char* ans = new char[size + 1];
//	memset(ans, 0, size + 1);
//
//
//	int index = 0;
//
//	vector<string>::iterator v_s;
//	vector<string>::const_iterator v_se;
//
//	for (v_s = v.begin(), v_se = v.end(); v_s != v_se; v_s++){
//		for (int i = 0; i < L; i++){
//			ans[index + i] = v_s->at(i);
//			ans[size - 1 - index - i] = v_s->at(i);
//		}
//		index += L;
//	}
//
//	if (!__v.empty())
//		for (int i = 0; i < L; i++){
//		ans[index + i] = __v.begin()->at(i);
//		}
//
//{
//	//L = size;
//	//if (!revChk(ans, ans)){
//	//while ( N > 900)
//	//{
//	//	int aa = 0;
//	//}
//	//}
//}
//
//	cout << ans << endl;
//
//	delete ans;
//	return 0;
//}
