#include <iostream>
#include <conio.h>
#include <vector>
#include <deque>
#include <list>
#include <stack>
using namespace std;


template <class T> class Queue;

template <class T>

Queue<T> operator +(const Queue<T> &s1, const Queue<T> &s2) {
	Queue <T> result = s1;
	for (unsigned i = 0;i<s1.items.size();++i) {
		result.items.push_back(s2.items[i]);
	}
	return result;
}
template <class T>
ostream &operator <<(ostream &o, Queue<T> &s1) {
	
	o << "   /\  " << endl;
	o << "  /  \  " << endl;
	o << " /    \ " << endl;
	o << "/      \ "<< endl;
	o << "--------" << endl;
	for (unsigned i = 0;i<s1.items.size();++i) {

		o << "  " << "|" << s1.items[i] << "|" << endl;
		o << "  " << "---" << endl;

	}
	o << "**    **" << endl;
	o << "**    **" << endl;
	o << "^^    ^^" << endl;

	return o;

}
template <class T>
class Queue {
	friend ostream &operator <<<>(ostream &o, Queue<T> &s1);
	friend Queue<T> operator +<>(const Queue<T> &s1, const Queue<T> &s2);
	friend Queue<T> operator -<>(const Queue<T> &s1, const Queue<T> &s2);
	vector<T> items;
public:
	bool empty() const { return items.empty(); }
	void push(const T &item) { items.push_back(item); }

	T pop() {
		T last = items.back();

		items.pop_back();
		return last;
	}

}
;

template <class T>

Queue<T> operator -(const Queue<T> &s1, const Queue<T> &s2) {
	Queue<T> result;
	vector<int> c1;
	for (unsigned i = 0;i < s1.items.size();i++) {
		bool repite = true;
		for (unsigned j = 0;j < s2.items.size();j++) {
			if (s1.items[i] == s2.items[j]) {
				c1.push_back(s1.items[i]);
				repite = false;
				break;

			}
		
		}
		if (repite == true) {
			result.push(s1.items[i]);
		}
		
	}
	for (unsigned i = 0;i < s2.items.size();i++) {
		for(unsigned j=0;j<c1.size();j++){
			if (s2.items[i] != c1[j]) {
				result.items.push_back(s2.items[i]);
			}
		}
	}
	return result;
}



int main() {
	Queue<int> a, b;
	a.push(3);
	a.push(1);
	a.push(4);

	b.push(6);
	b.push(1);
	b.push(2);
	Queue<int> c = a - b;
	cout<<c << endl;;





	system("pause");
	return 0;
}