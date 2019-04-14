#include <iostream>
#include <string>

using namespace std;
template <class T>
class CMyistream_iterator
{
	// �ڴ˴�������Ĵ���
private:
	T *data = nullptr;
	//һ��Ҫ����Ϊ���ã���Ȼ�ᱨ��Ȼ������ʲôԭ��
	istream &is;
public:
	//���ﴫ��Ҳ����const���Σ�Ϊɶ��
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
		//��仰һ��Ҫ�ӣ�������Ϊdelete��data��Ȼ�Ǹ���ָ���ˣ�����if��data)����Ϊ�棬if���ֻ��0ʱΪ�ͼ٣�����������Ϊ�棡����
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
//		n1 = *inputInt; //���� n1
//		int tmp = *inputInt;
//		cout << tmp << endl;
//		inputInt++;
//		n2 = *inputInt; //���� n2
//		inputInt++;
//		n3 = *inputInt; //���� n3
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