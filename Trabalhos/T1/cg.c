#include <stdio.h>
#include <stdlib.h>

#include <GL/glew.h>
#include <GL/glut.h>

#include "poligono.h"

#define HEIGHT 400
#define WIDTH 400 

poligono p ;
int make_resources(void) {
	return 1 ;
}

void update_fade_factor(void) {}

void render(void) {
	glClearColor(1.0f, 1.0f, 1.0f, 1.0f) ;
	glClear(GL_COLOR_BUFFER_BIT) ;

	glutSwapBuffers() ;

}

void mouseClick(int button, int state, int x, int y) {
	if (button == GLUT_LEFT_BUTTON && state == GLUT_UP) {
		printf("x: %d, y: %d\n", x, y) ;
		glBegin(GL_POINTS) ;
		glColor3i(255, 0, 0) ;
		glVertex2i(x, HEIGHT - y) ;
		glEnd();
		if (p.inicio) {
			glBegin(GL_LINES) ;
			glColor3i(255, 0, 0) ;
			glVertex2i(x, HEIGHT - y) ;
			glVertex2i(p.fim->x, HEIGHT - p.fim->y) ;
			glEnd();
		} 
		glFlush() ;
		addVertice(&p, x, y) ;	
	}
}

int main(int argc, char **argv)  {
	glutInit(&argc, argv) ;
	glutInitDisplayMode(GLUT_RGB | GLUT_SINGLE) ;
	glutInitWindowSize(WIDTH, HEIGHT) ;
	glutCreateWindow("Hello World") ;
	glutDisplayFunc(&render) ;
	glutIdleFunc(&update_fade_factor) ;
	glMatrixMode(GL_PROJECTION);
	glEnable(GL_BLEND) ;
	glViewport( 0,0, HEIGHT, WIDTH);
	glMatrixMode( GL_PROJECTION );
	glLoadIdentity();
	glOrtho( 0.0, HEIGHT, 0.0, WIDTH, 1.0, -1.0 );


	initPoligono(&p) ;


	glutMouseFunc(mouseClick);

	glewInit() ;

	glutMainLoop() ;
	return 0 ;
	
}
