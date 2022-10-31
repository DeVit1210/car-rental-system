#include<iostream>
#include<Windows.h>
#include"StartWindow.h"

using namespace std;

int main() {
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	unique_ptr<StartWindow> startWindowPtr = make_unique<StartWindow>();
	startWindowPtr->run();
	return 0;
}