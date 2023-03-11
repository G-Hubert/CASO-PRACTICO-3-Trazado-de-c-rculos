#include <GL/glut.h> 
#include <cmath> 
#include <iostream>

int xc = 300;
int yc = 300;
int r = 150;

void pintarPixel(int xc, int yc)
{
    int x = 0;
    int y = r;
    
    int p = 1 - r;

    glBegin(GL_POINTS);
    while (x <= y)
    {
        // Dibuja los 8 puntos  para formar el circulo
        glVertex2i(xc + x, yc + y); 
        glVertex2i(xc + y, yc + x); 
        glVertex2i(xc + y, yc - x); 
        glVertex2i(xc + x, yc - y); 
        glVertex2i(xc - y, yc - x); 
        glVertex2i(xc - x, yc - y); 
        glVertex2i(xc - y, yc + x); 
        glVertex2i(xc - x, yc + y); 

        // Actualiza el valor de p
        if (p < 0)
            p += (2 * x) + 1;
        else
        {
        	p += (2 * x ) + 1 - (2 * y);
            y--;
        }
        x++;
    }
    glEnd();
    
    glBegin(GL_LINES);
	
	glVertex2i(xc,yc);
	glVertex2i(xc+(r*1.4),yc+(r*1.4));
	
	glEnd();
	glFlush();
}


void display()
{
    glClear(GL_COLOR_BUFFER_BIT);
    glColor3f(0.0, 0.0, 0.0); // Color de pixeles
    pintarPixel(xc, yc); // Dibuja el círculo utilizando el algoritmo de punto medio
    glFlush();
}

int main(int argc, char** argv) {
	glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(800, 600);
    glutInitWindowPosition(100, 100);
    glutCreateWindow("Círculo :o");
    glClearColor(0.0, 1.0, 1.0, 1.0); 
    gluOrtho2D(0, 800, 0, 600);
    glutDisplayFunc(display);
    glutMainLoop();
	return 0;
}
