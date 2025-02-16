#ifndef MYWINDOW_H
#define MYWINDOW_H

#include <GL/glew.h>
#include <GL/freeglut.h>
#include "glApplication.h"
#include "glutwindow.h"
#include "glsl.h"
#include <time.h>
#include <cmath>
#include "queue.h"

class myWindow : public cwc::glutWindow {

protected:
   cwc::glShaderManager SM;
   cwc::glShader *shader;
   GLuint ProgramObject;
   clock_t time0,time1;
   float timer010;  // timer counting 0->1->0
   bool bUp;        // flag if counting up or down.
   Queue *myQueue;

public:

	myWindow();

    virtual void OnRender(void);
    virtual void OnIdle();
    virtual void OnInit();
    virtual void OnResize(int w, int h);
    virtual void OnClose(void);
	virtual void OnMouseDown(int button, int x, int y);    
	virtual void OnMouseUp(int button, int x, int y);
	virtual void OnMouseWheel(int nWheelNumber, int nDirection, int x, int y);
    virtual void OnKeyDown(int nKey, char cAscii);
    virtual void OnKeyUp(int nKey, char cAscii);
    void UpdateTimer();
    void DemoLight(void);
    void DrawTeapotAt(float x, float y, float z);
    void DrawCube(float x, float y, float z, float angle);
    void DrawEquilateralTriangle(float x, float y, float z, float sideLength);
    void DrawChessboard(float size, int rows, int cols);

};

#endif // MYWINDOW_H
