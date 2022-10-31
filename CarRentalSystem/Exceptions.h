#pragma once
#include<iostream>
#include<string>

using namespace std;

class empty_file_exception : public exception {
public:
	char const* what() const override {
		return " ���������� ������� � ����� ����� 0!";
	}
};

class out_of_bounds_exception {
public:
	virtual void printException() const = 0;
};

class container_out_of_bounds_exception : public out_of_bounds_exception {
	const char* containerName;
public:
	container_out_of_bounds_exception(const char* containerName) {
		this->containerName = containerName;
	}
	void printException() const override {
		cout << "\n  ����� :" << this->containerName << endl
			<< "  �������� � ����� ������� ��� � ������!" << endl;
	}
};


class file_opening_exception {
	string fileName;
	bool isOpeningForWriting;
public:
	file_opening_exception(string fileName, bool isOpeningForWriting) {
		this->fileName = fileName;
		this->isOpeningForWriting = isOpeningForWriting;
	}
	friend ostream& operator<<(ostream& out, const file_opening_exception& obj) {
		out << "\n  ������ �������� ����� " << (obj.isOpeningForWriting ? "��� ������!" : "��� ������!") << endl;
		out << "  ����, ��������� ������: " << obj.fileName << endl;

		return out;
	}
};

class empty_list_exception {
	string exceptionList;
public:
	empty_list_exception(string exceptList) : exceptionList(exceptList) {}
	friend ostream& operator<<(ostream& out, const empty_list_exception& obj) {
		out << obj.exceptionList << "����!" << endl;
	}
};

class no_such_element_exception : public exception {
	string message;
public:
	no_such_element_exception() {};
	no_such_element_exception(string message) {
		this->message = message;
	}
	char const* what() const override {
		return message.c_str();
	}
};

class illegal_access_attempt_exception {};

class string_out_of_bounds_exception : public out_of_bounds_exception {
	int boundary;
	bool isStringTooShort;
public:
	string_out_of_bounds_exception(int bound, bool isTooShort) {
		this->boundary = bound;
		this->isStringTooShort = isTooShort;
	}
	void printException() const override {
		if (isStringTooShort) {
			cout << "  ��� ������ ������ ��������� ��� ������� "
				<< boundary << " ��������!\n  ���������� ��� ���: ";
		} else {
			cout << " ��� ������ ����� ��������� �������� "
				<< boundary << " ��������!\n  ���������� ��� ���: ";
		}
	}
};

class value_size_exception : public out_of_bounds_exception {
	size_t lowerBound;
	size_t upperBound;
public:
	value_size_exception(size_t upper, size_t lower) {
		this->upperBound = upper;
		this->lowerBound = lower;
	}
	void printException() const override {
		cout << "\n  ������! ������� ����� �� " << lowerBound << " �� " << upperBound << ": ";
	}
};

class thread_fairure_exception {
public:
	void clear_bufer() {
		cin.clear();
		cin.ignore(32767, '\n');
	}
};

