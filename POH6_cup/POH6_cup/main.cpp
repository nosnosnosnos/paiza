#include <iostream>
using namespace std;

float X, Y;
int N;

int main(void){

	cin >> N;

	for (int i = 0; i < N; i++){
		int m,M;
		cin >> m;
		cin >> M;

		switch (m)
		{
		case 1:
			X += M;

			break;
		case 2:
			Y += M;

			break;
		case 3:
		{
			float _X = X - M*X / (X + Y);
			Y -= M*Y / (X + Y);
			X = _X;
		}
			break;
		default:
			break;
		}
	}

	unsigned int buf = static_cast<unsigned int>(100 * Y / (X + Y));

	cout << buf << endl;

	return 0;
}
