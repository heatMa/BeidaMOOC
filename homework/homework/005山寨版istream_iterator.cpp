#include <iostream>
#include <string>

using namespace std;
template <class T>
class CMyistream_iterator
{
	// 在此处补充你的代码
private:
	T *data = nullptr;
	//一定要定义为引用，不然会报错，然而这是什么原理？
	istream &is;
public:
	//这里传参也不能const传参，为啥？
	CMyistream_iterator(istream& in):is(in)
	{
	}
	T operator*()
	{
		if (data)
			return *data;
		else
		{
			data = new T;
			is >> *data;
			return *data;
		}
		
	}
	CMyistream_iterator& operator++(int)
	{
		if (data)
			delete data;
		//这句话一定要加！！！因为delete后，data虽然是个空指针了，但是if（data)还是为真，if语句只有0时为就假，正数负数都为真！！！
		data = nullptr;
		return *this;
	}
	~CMyistream_iterator()
	{
		if (data)
			delete data;
	}

};



//int main()
//{
//	int t;
//	cin >> t;
//	while (t--) {
//		CMyistream_iterator<int> inputInt(cin);
//		int n1, n2, n3;
//		n1 = *inputInt; //读入 n1
//		int tmp = *inputInt;
//		cout << tmp << endl;
//		inputInt++;
//		n2 = *inputInt; //读入 n2
//		inputInt++;
//		n3 = *inputInt; //读入 n3
//		cout << n1 << " " << n2 << " " << n3 << " ";
//		CMyistream_iterator<string> inputStr(cin);
//		string s1, s2;
//		s1 = *inputStr;
//		inputStr++;
//		s2 = *inputStr;
//		cout << s1 << " " << s2 << endl;
//	}
//	return 0;
//}