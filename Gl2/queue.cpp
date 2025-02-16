#include "queue.h"

Queue::Queue() {};

void Queue::DrawQueue(float angle, int n, float x, float y, float z){
    glPushMatrix();
        glTranslatef (x,y,z);
        glTranslatef (-0.5, 0.0, 0.0);
        glRotatef ((GLfloat) angle, 0.0, 0.0, 1.0);
        glTranslatef (1.0, 0.0, 0.0); glPushMatrix();
        glScalef (1.0, 0.4, 1.0);
        glutSolidCube (1.0);
        glPopMatrix();
        for (int i=0; i < n; i++){
            glTranslatef (0.5, 0.0, 0.0);
            glRotatef ((GLfloat) angle, 0.0, 0.0, 1.0);
            glTranslatef (0.5, 0.0, 0.0);
            glPushMatrix();
            glScalef (1.0, 0.4, 1.0);
            glutSolidCube(1.0);
            glPopMatrix();
        }
    glPopMatrix();  
}
