#ifndef MYAPPLICATION_H
#define MYAPPLICATION_H

#include "glApplication.h"
#include <iostream>

class myApplication : public cwc::glApplication
{
public:
    virtual void OnInit();
};

#endif // MYAPPLICATION_H