// Test1.cpp: Definiert den Einstiegspunkt für die Konsolenanwendung.
//

#include "stdafx.h"
#include<iostream>
#include<vector>
#include<string>
#include<iterator> 
#include<thread>
#include <windows.h>

using namespace std;

string ausgabeparam = "a";

void cinThread() {
	while (ausgabeparam != "e") {
		cin >> ausgabeparam;
	}
}

void coutThread() {

	while (true) {
		string* ausgabe =  &ausgabeparam;
		for (int i = 0; i < 10; i++) {
			cout << *ausgabe;
		}
		Sleep(2000);
		cout << endl;
	}
}


int main()
{
	thread t1(coutThread);
	thread t2(cinThread);

	t2.join();
	t1.detach();
	
	return 0;
}

