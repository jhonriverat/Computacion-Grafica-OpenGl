#include "myWindow.h"

myWindow::myWindow() : timer010(0.0f), bUp(true) {}

void myWindow::OnRender(void) {
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    if (shader) shader->begin();

    myQueue->DrawQueue(10,9,0.0f,1.0f,0.0f);
    myQueue->DrawQueue(5,9,0.0f,1.0f,0.0f);
    myQueue->DrawQueue(-5,9,0.0f,1.0f,0.0f);
    myQueue->DrawQueue(-10,9,0.0f,1.0f,0.0f);
    myQueue->DrawQueue(-15,9,0.0f,1.0f,0.0f);
    myQueue->DrawQueue(-20,1,0.0f,1.0f,0.0f);
    myQueue->DrawQueue(-23,1,0.0f,1.0f,0.0f);
    myQueue->DrawQueue(-25,9,0.0f,1.0f,0.0f);

    myQueue->DrawQueue(15,9,2.0f,1.0f,0.0f);
    myQueue->DrawQueue(10,9,2.0f,1.0f,0.0f);
    myQueue->DrawQueue(5,9,2.0f,1.0f,0.0f);
    myQueue->DrawQueue(-5,9,2.0f,1.0f,0.0f);
    myQueue->DrawQueue(-10,9,2.0f,1.0f,0.0f);
    myQueue->DrawQueue(-15,9,2.0f,1.0f,0.0f);
    myQueue->DrawQueue(-20,1,2.0f,1.0f,0.0f);
    myQueue->DrawQueue(-23,1,2.0f,1.0f,0.0f);
    myQueue->DrawQueue(-25,9,2.0f,1.0f,0.0f);

    myQueue->DrawQueue(15,9,2.0f,2.0f,0.0f);
    myQueue->DrawQueue(10,9,2.0f,2.0f,0.0f);
    myQueue->DrawQueue(5,9,2.0f,2.0f,0.0f);
    myQueue->DrawQueue(-5,9,2.0f,2.0f,0.0f);
    myQueue->DrawQueue(-10,9,2.0f,2.0f,0.0f);
    myQueue->DrawQueue(-15,9,2.0f,2.0f,0.0f);
    myQueue->DrawQueue(-20,11,2.0f,2.0f,0.0f);
    myQueue->DrawQueue(-23,11,2.0f,2.0f,0.0f);
    myQueue->DrawQueue(-25,9,2.0f,2.0f,0.0f);

    myQueue->DrawQueue(-4.5,9,0.0f,1.0f,0.0f);
    myQueue->DrawQueue(-15.5,9,0.0f,1.0f,0.0f);
    myQueue->DrawQueue(-26.5,9,0.0f,1.0f,0.0f);
    
    if (shader) shader->end();
    glutSwapBuffers();
    UpdateTimer();
    Repaint();
}

void myWindow::OnIdle() {}

void myWindow::OnInit() {
    myQueue = new Queue();
    glClearColor(0.5f, 0.5f, 1.0f, 0.0f);
    glShadeModel(GL_SMOOTH);

    shader = SM.loadfromFile("vertexshader.txt", "fragmentshader.txt");
    if (shader == nullptr) 
        std::cout << "Error Loading, compiling or linking shader\n";
    else {
        ProgramObject = shader->GetProgramObject();
    }

    time0 = clock();
    timer010 = 0.0f;
    bUp = true;

    DemoLight();
}

void myWindow::OnResize(int w, int h) {
    if (h == 0) h = 1;
    float ratio = 1.0f * static_cast<float>(w) / static_cast<float>(h);

    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();

    glViewport(0, 0, w, h);
    gluPerspective(70, ratio, 1, 100);
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    gluLookAt(0.0f, 0.0f, 10.0f, 0.0, 0.0, -1.0, 0.0f, 1.0f, 0.0f);
}

void myWindow::OnClose(void) {}

void myWindow::OnMouseDown(int button, int x, int y) {}

void myWindow::OnMouseUp(int button, int x, int y) {}

void myWindow::OnMouseWheel(int nWheelNumber, int nDirection, int x, int y) {}

void myWindow::OnKeyDown(int nKey, char cAscii) {
    if (cAscii == 27) { // 0x1b = ESC
        this->Close(); // Close Window!
    }
}

void myWindow::OnKeyUp(int nKey, char cAscii) {
    if (cAscii == 's') // s: Shader
        shader->enable();
    else if (cAscii == 'f') // f: Fixed Function
        shader->disable();
}

void myWindow::UpdateTimer() {
    time1 = clock();
    float delta = static_cast<float>(time1 - time0) / CLOCKS_PER_SEC;
    delta = delta / 4;
    if (delta > 0.00005f) {
        time0 = clock();
        if (bUp) {
            timer010 += delta;
            if (timer010 >= 1.0f) { timer010 = 1.0f; bUp = false; }
        } else {
            timer010 -= delta;
            if (timer010 <= 0.0f) { timer010 = 0.0f; bUp = true; }
        }
    }
}

void myWindow::DemoLight(void) {
    glEnable(GL_LIGHTING);
    glEnable(GL_LIGHT0);
    glEnable(GL_NORMALIZE);
    glEnable(GL_DEPTH_TEST);
    
    GLfloat lmKa[] = {0.0, 0.0, 0.0, 0.0 };
    glLightModelfv(GL_LIGHT_MODEL_AMBIENT, lmKa);
    
    glLightModelf(GL_LIGHT_MODEL_LOCAL_VIEWER, 1.0);
    glLightModelf(GL_LIGHT_MODEL_TWO_SIDE, 0.0);
    
    GLfloat spot_direction[] = {1.0, -1.0, -1.0 };
    GLint spot_exponent = 30;
    GLint spot_cutoff = 180;
    
    glLightfv(GL_LIGHT0, GL_SPOT_DIRECTION, spot_direction);
    glLighti(GL_LIGHT0, GL_SPOT_EXPONENT, spot_exponent);
    glLighti(GL_LIGHT0, GL_SPOT_CUTOFF, spot_cutoff);

    GLfloat Kc = 1.0;
    GLfloat Kl = 0.0;
    GLfloat Kq = 0.0;
    
    glLightf(GL_LIGHT0, GL_CONSTANT_ATTENUATION, Kc);
    glLightf(GL_LIGHT0, GL_LINEAR_ATTENUATION, Kl);
    glLightf(GL_LIGHT0, GL_QUADRATIC_ATTENUATION, Kq);
    
    GLfloat light_pos[] = {0.0f, 5.0f, 5.0f, 1.0f};
    GLfloat light_Ka[]  = {1.0f, 0.5f, 0.5f, 1.0f};
    GLfloat light_Kd[]  = {1.0f, 0.1f, 0.1f, 1.0f};
    GLfloat light_Ks[]  = {1.0f, 1.0f, 1.0f, 1.0f};

    glLightfv(GL_LIGHT0, GL_POSITION, light_pos);
    glLightfv(GL_LIGHT0, GL_AMBIENT, light_Ka);
    glLightfv(GL_LIGHT0, GL_DIFFUSE, light_Kd);
    glLightfv(GL_LIGHT0, GL_SPECULAR, light_Ks);

    GLfloat material_Ka[] = {0.0f, 1.0f, 1.0f, 1.0f}; 
    GLfloat material_Kd[] = {0.0f, 1.0f, 1.0f, 1.0f}; 
    GLfloat material_Ks[] = {1.0f, 1.0f, 1.0f, 1.0f}; 
    GLfloat material_Ke[] = {0.0f, 1.0f, 1.0f, 1.0f}; 
    GLfloat material_Se = 4.0f; 

    glMaterialfv(GL_FRONT_AND_BACK, GL_AMBIENT, material_Ka);
    glMaterialfv(GL_FRONT_AND_BACK, GL_DIFFUSE, material_Kd);
    glMaterialfv(GL_FRONT_AND_BACK, GL_SPECULAR, material_Ks);
    glMaterialfv(GL_FRONT_AND_BACK, GL_EMISSION, material_Ke);
    glMaterialf(GL_FRONT_AND_BACK, GL_SHININESS, material_Se);
}

void myWindow::DrawTeapotAt(float x, float y, float z){  
    glPushMatrix();
    glTranslatef(x,y,z);
    glRotatef(timer010*360, 0.5, 1.0f, 0.1f);
    glutSolidTeapot(1.0);
    glPopMatrix();
}

void myWindow::DrawCube(float x, float y, float z, float angle){
    glPushMatrix();
    glTranslatef(x, y, z);
    glRotatef(angle, 0.0f, 0.0f, 1.0f);
    glutSolidCube(1);
    glPopMatrix();
}

void myWindow::DrawEquilateralTriangle(float x, float y, float z, float sideLength){
    float height = (sqrt(3) / 2.0f) * sideLength; 

    glDisable(GL_LIGHTING);
    glPushMatrix(); 
    glTranslatef(x, y + height / 2.0f, z);
    glBegin(GL_TRIANGLES);
    glColor3f(1.0f, 1.0f, 0.0f);
    glVertex3f(0.0f, height / 2.0f, 0.0f);
    glVertex3f(-sideLength / 2.0f, -height / 2.0f, 0.0f);
    glVertex3f(sideLength / 2.0f, -height / 2.0f,0.0f);
    glEnd();
    glPopMatrix();
    glEnable(GL_LIGHTING);
}

void myWindow::DrawChessboard(float size, int rows, int cols){
    float squareSize = size / std::max(rows, cols);
    float startX = -size / 2.0f;
    float startZ = -size / 2.0f;

    glDisable(GL_LIGHTING);
    
    for (int row = 0; row < rows; ++row){
        for (int col = 0; col < cols; ++col){
            
            bool isWhite = (row + col) % 2 == 0;
            
            if (isWhite) glColor3f(1.0f, 1.0f, 1.0f); 
            else glColor3f(0.0f, 0.0f, 0.0f);
            
            float x = startX + col * squareSize + squareSize / 2.0f;
            float y = -5.0f;
            float z = startZ + row * squareSize + squareSize / 2.0f;

            glPushMatrix();
            glTranslatef(x, y, z);
            glutSolidCube(squareSize);
            glPopMatrix();
        }
    }
    glEnable(GL_LIGHTING);
}
