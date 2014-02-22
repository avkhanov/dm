#include <iostream>
#include "window/LinuxWindow.h"
#include "renderer/renderer.h"
using namespace std;

int main(int argc, char** argv) {
	cout << "HELLO WORLD!!!" << endl;
        LinuxWindow* w = new LinuxWindow();
        w->setSetupFunc(renderer_setup);
        w->setRenderFunc(renderer);
        w->show();
	return 0;
}
