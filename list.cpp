#include <stdio.h>
#include <iostream>
using namespace std;

const int DefaultListSize = 10;

template <class T> class List {
public:
	virtual void clear() = 0;//清空
	virtual bool insert(const T&) = 0;//在当前位置插入
	virtual bool append(const T&) = 0;//追加
	virtual bool remove(T&) = 0;//移除当前位置
	virtual void setStart() = 0;//移动到开头
	virtual void setEnd() = 0;//移动到末尾
	virtual void next() = 0;//移动到后继
	virtual void prev() = 0;//移动到前驱
	virtual void setPos(int pos) = 0;//指定任意位置
	virtual T getValue()const = 0;//获取当前位置值
	virtual	bool IsEmpty() = 0;//判断是否为空
	virtual bool IsFull() = 0;//判断是否为满
	virtual void print() const = 0;//打印
};

template <class T>
class Alist :public List<T> {
public:
	Alist(const int size = DefaultListSize)
	{
		maxSize = size;
		listSize = curr = 0;
		listArray = new T[maxSize];
	}
	~Alist() { delete[] listArray; }
	void clear() { listSize = curr = 0; }
	bool insert(const T&);
	bool append(const T&);
	bool remove(T& it);
	void setStart() { curr = 0; }
	void setEnd() { curr = listSize - 1; }
	void next() { if (curr < listSize - 1)curr++; }
	void prev() { if (curr > 0)curr--; }
	void setPos(int pos) { if (pos < listSize && pos >= 0)curr = pos; }
	T getValue() const { return listArray[curr]; }
	bool IsFull() { if (listSize < maxSize)return false; else return true; }
	bool IsEmpty() { if (listSize == 0)return true; else return false; }
	void print()const;

private:
	int maxSize;
	int listSize;
	int curr;
	T* listArray;
};

int main()
{
	Alist <int> a(9);
	a.append(9);
	a.append(4);
	a.append(6);
	a.append(3);
	a.append(67);
	a.print();
	return 0;
}

template<class T>
bool Alist<T>::insert(const T& it)//插入
{
	if (IsFull())
	{
		return false;
	}
	if (curr<0 || curr>listSize - 1)
	{
		return false;
	}
	for (int i = listSize; i > curr; i--)listArray[i] = listArray[i - 1];
	listArray[curr] = it;
	listSize++;
	return true;
}

template<class T>
bool Alist<T>::append(const T& it)
{
	if (IsFull())return false;
	listArray[listSize] = it;
	listSize++;
	return true;
}

template<class T>
bool Alist<T>::remove(T& it)
{
	if (IsEmpty())return false;
	if (curr < 0 || curr >= listSize)return false;
	it = listArray[curr];
	for (int i = curr; i < listSize - 1; i++) {
		listArray[i] = listArray[i + 1];
	}
	listSize--;
	return true;
}

template<class T>
void Alist<T>::print() const
{
	if (listSize == 0)
	{
		return;
	}
	for (int i = 0; i < listSize - 1; i++)
	{
		cout << listArray[i] << endl;
	}
	cout << listArray[listSize - 1];
}


