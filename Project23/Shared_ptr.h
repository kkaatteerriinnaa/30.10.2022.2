#pragma once
#include <iostream>
using namespace std;

template<class T>
class MySharedPtr
{
	T* ptr;
	static int count;
public:
	MySharedPtr()
	{
		T* ptr = nullptr;
		count++;
	}
	MySharedPtr(T* a)
	{
		ptr = a;
		count++;
	}
	~MySharedPtr()
	{
		cout << "Destruct\n";
		if (count == 1)
		{
			delete ptr;
			count = 0;
			cout << "DELETE\n";
		}
		else
		{
			count--;
			cout << "Count--\n";
		}
	}
	T* get() // ???????? ?????? 
	{
		return ptr;
	}
	T GetCount() //  ??????? ???-??
	{
		return *ptr;
	}
};

template<class T>
int MySharedPtr<T>::count = 0;
