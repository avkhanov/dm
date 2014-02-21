#include <iostream>
#include "window/LinuxWindow.h"
using namespace std;

int main(int argc, char** argv) {
	cout << "HELLO WORLD!!!" << endl;
        LinuxWindow* w = new LinuxWindow();
        w->show();
	return 0;
}
