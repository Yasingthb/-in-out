#include <glut.h>
#include <stdlib.h>
#include <stdio.h>
#include <iostream>
float r, g, b, a, z;
bool kntrl = true;
const char *_in = "iceride", *_out = "Disarida";




void mouse(int button, int state, int x, int y) {


       

    glClear(GL_COLOR_BUFFER_BIT);
    glColor3f(0.0, 0.4, 0.2);
    
    if (button == GLUT_LEFT_BUTTON && state == GLUT_DOWN) {//sol mouse butonu aktifse yani basýlýysa if'e girecek iþlemleri yapacak
        kntrl = true;
        a = x;
        z = (480 - y);
        r = (rand() % 5 / (4));
        g = (rand() % 5 / (4));
        b = (rand() % 5 / (4));    
        printf(":%f: \t :%f:\t", a, z);//koordinatlarýný konsol ekranýnda görüyorum.
       

    }
    else if (button == GLUT_RIGHT_BUTTON && state == GLUT_DOWN) {
        glClearColor(1, 1, 1, 0);
        glClear(GL_COLOR_BUFFER_BIT);
        kntrl = false;
    }
    glutPostRedisplay();
}
static void ciz(void) {// üçgeni çizen fonksiyon

    glBegin(GL_TRIANGLES);
    glVertex3i(150, 200, 0);
    glVertex3i(300, 200, 0);
    glVertex3i(228, 350, 0);



    glEnd();
    glFlush();
}

void display() {
    glColor3f(r, g, b);
    glPointSize(25);

    glMatrixMode(GL_PROJECTION);
    
    ciz();
    glLoadIdentity();
    gluOrtho2D(0.0, 640.0, 0.0, 480.0);
    if (kntrl)
    {
        glBegin(GL_POINTS);
        glVertex2i(a, z);//týkladýðýmýz yere mouse koordinatlarýnda nokta koyuyor
        glEnd();
        

        
    }
    if (a <= 300 && a>= 150 && z <= 350 && z >= 200) {
        glRasterPos2i(549, 45);
        for (size_t i = 0; i < strlen(_in); i++)
        {
            glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, _in[i]);

        }
        
    }
    else if (a > 300 || a < 150 || z > 350 || z < 200) {
        glRasterPos2i(549, 45);
        for (size_t i = 0; i < strlen(_out); i++)
        {
        glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, _out[i]);//cons char olarak yazdýrýyoruz
            
        }
    }
   
    

    glFlush();
   
}

int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutInitWindowSize(640, 480);
    glutInitWindowPosition(10, 10);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutCreateWindow("Noktalar");
    glClearColor(1, 1, 1, 0);
    glutDisplayFunc(display);
    glutMouseFunc(mouse);
   // init();
    glutMainLoop();
    
}