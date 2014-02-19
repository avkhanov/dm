#include <iostream>
#include "window/Window.h"
#include "window/GLUTWindow.h"

using namespace std;

int main(int argc, char** argv) {
	cout << "HELLO WORLD!!!" << endl;
	GLUTWindow* w = new GLUTWindow(0, 0, 640, 480, argc, argv);
	return 0;
}
