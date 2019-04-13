#include <iostream>
#include <string>
#include <cstring>
using namespace std;
template <class T>
class myclass {
	// 在此处补充你的代码
public:
	int size;
	T* p = nullptr;

	myclass(T* data, int len):size(len)
	{
		p = new T[len];
		//这里一开始写的len,应该是len*sizeof(T),第三个参数是字节的长度，不是数组的长度
		memcpy(p, data, len*sizeof(T));

	}
	~myclass() {
		delete[] p;
	}
	void Show()
	{
		for (int i = 0; i < size; i++) {
			cout << p[i] << ",";
		}
		cout << endl;
	}
};
int a[100];
//int main() {
//	char line[100];
//	while (cin >> line) {
//		myclass<char> obj(line, strlen(line));;
//		obj.Show();
//		int n;
//		cin >> n;
//		for (int i = 0; i < n; ++i)
//			cin >> a[i];
//		myclass<int> obj2(a, n);
//		obj2.Show();
//	}
//	return 0;
//}