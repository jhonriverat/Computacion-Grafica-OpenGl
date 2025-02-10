#include "myWindow.h"
#include "myApplication.h"

int main(void) {
    myApplication* pApp = new myApplication;
    myWindow* myWin = new myWindow();
    pApp->run();
    delete pApp;
    return 0;
}