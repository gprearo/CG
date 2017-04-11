#include <stdio.h>
#include <stdlib.h>

#include <GL/glew.h>
#include <GL/glut.h>

#include "poligono.h"

#define HEIGHT 400
#define WIDTH 400 

poligono p ;

//OpenGL Stuff
void update_fade_factor(void) {}

void render(void) {
	//Não sei
	//OpenGL Stuff
	glClearColor(1.0f, 1.0f, 1.0f, 1.0f) ;
	glClear(GL_COLOR_BUFFER_BIT) ;

	glutSwapBuffers() ;

}

void mouseClick(int button, int state, int x, int y) {
	//Se o clique for com o botão esquerdo, grava o pixelque foi clicado na
	//estrutura de dados do poligono, imprime as coordenadas, colore o ponto
	//que foi clicado e cria uma reta com o ponto anterior, se existente
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
	} else {
		//Se for clicado com o botão direito, fecha o polígono
		if (button == GLUT_RIGHT_BUTTON && state == GLUT_UP) {
			glBegin(GL_LINES) ;
			glVertex2i(p.inicio->x, HEIGHT - p.inicio->y) ;
			glVertex2i(p.fim->x, HEIGHT - p.fim->y) ;
			glEnd() ;
			glFlush() ;

		}
	}
}


//Inicializa a janela
//OpenGL Stuff
void initWindow(int argc, char **argv) {

	glutInit(&argc, argv) ;
	glutInitDisplayMode(GLUT_RGB | GLUT_SINGLE) ;
	glutInitWindowSize(WIDTH, HEIGHT) ;
	glutCreateWindow("Hello World") ;
	glutDisplayFunc(&render) ;
	glutIdleFunc(&update_fade_factor) ;
	glMatrixMode(GL_PROJECTION);
	glEnable(GL_BLEND) ;
	glViewport( 0,0, WIDTH, HEIGHT);
	glMatrixMode( GL_PROJECTION );
	glLoadIdentity();
	glOrtho( 0.0, WIDTH, 0.0, HEIGHT, 1.0, -1.0 );
	//Define a função que trata o click do mouse
	glutMouseFunc(mouseClick);
	glewInit() ;
	glutMainLoop() ;

}

int main(int argc, char **argv)  {
	initWindow(argc, argv) ;

	initPoligono(&p) ;


	return 0 ;
	
}
