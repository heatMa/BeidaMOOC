#include <iostream>
#include <string>

using namespace std;
template <class T>
class CMyistream_iterator
{
public:
	// �ڴ˴�������Ĵ���
	T data;
	CMyistream_iterator(const istream& in)
	{

	}
	T operator*()
	{
		cin >> data;
		return data;
	}
	CMyistream_iterator& operator++(int)
	{
		return *this;
	}


};



int main()
{
	int t;
	cin >> t;
	while (t--) {
		CMyistream_iterator<int> inputInt(cin);
		int n1, n2, n3;
		n1 = *inputInt; //���� n1
		int tmp = *inputInt;
		cout << tmp << endl;
		inputInt++;
		n2 = *inputInt; //���� n2
		inputInt++;
		n3 = *inputInt; //���� n3
		cout << n1 << " " << n2 << " " << n3 << " ";
		CMyistream_iterator<string> inputStr(cin);
		string s1, s2;
		s1 = *inputStr;
		inputStr++;
		s2 = *inputStr;
		cout << s1 << " " << s2 << endl;
	}
	return 0;
}