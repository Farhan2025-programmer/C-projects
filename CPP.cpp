# include <iostream>
using namespace std;

int main() {
	int food = 10;
	int *test = new int;
	cout << sizeof(test) << endl;
	int *ptr = &food;
	cout << ptr << endl;
	return 0;
}
