#pragma once
#include<iostream>
#include<list>

using namespace std;

template<class T>
class List {
protected:
	virtual void add(T*) = 0;
	virtual void remove(size_t) = 0;
	virtual void read() = 0;
	virtual void write() = 0;
	virtual void display() = 0;
	virtual T* get(size_t) = 0;
	//virtual void sort() = 0;
};
