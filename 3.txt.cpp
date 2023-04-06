#include <iostream>
#include <GL/glut.h>
#include <GL/glu_.h>
#include <SFML/Graphics.hpp>
using namespace std;
using namespace sf;
int winW = 600;
int winH = 600;




void DarwPoligon() {
	



	glBegin(GL_LINES);
	glColor3ub(150, 90, 20);      // ������ 
	for (int i = -winW / 2; i <= winW/2; i+=20) {
		glVertex2d(i, -winH / 2);
		glVertex2d(i, winH / 2);

	}
	for (int i = -winH / 2; i <= winH / 2; i += 20) {
		glVertex2d(-winW/2, i);
		glVertex2d(winW/2, i);

	}
	glEnd();



	
	


	
}




void display() {

	glClear(GL_COLOR_BUFFER_BIT); //�������� ���� � ������� ����



	

	
	if (Keyboard::isKeyPressed(Keyboard::W))  glRotated(1, 0, 0, 1); //������� �� ��� Z
	
	if (Keyboard::isKeyPressed(Keyboard::A))  glRotated(1, 0, 1, 0); //������� �� ��� Z
	
	if (Keyboard::isKeyPressed(Keyboard::D))  glRotated(1, 1, 0, 0); //������� �� ��� Z
	if (Keyboard::isKeyPressed(Keyboard::Q))  glScaled(1.1f,1.1f,1.1f);
	if (Keyboard::isKeyPressed(Keyboard::E))  glScaled(0.9f, 0.9f, 0.9f);

	DarwPoligon();

	

	glutSwapBuffers(); //������� ��� �������
}




void update(int) {

	
	

	glutPostRedisplay();               // ���������� ������� ��������
	glutTimerFunc(50, update, 0);      //�������� ��� ������� ��� ���

}




void initialize() {

	glClearColor(0, 0, 0, 1.0);        //���� ������ ������� ����
	glOrtho(-winW / 2, winW / 2, winH / 2, -winH / 2, -500, 500); //����� 3� ���������� ������� ���������� � ������ �� ��� �����  //���� ���� �� -w , w ,-h,h ,z,-z

	glMatrixMode(GL_MODELVIEW);  //��� ��������� �������� ������� ��������
    glTranslated(0, 0, 0); // ���� �������� ��� ���
	glScaled(0.9,0.9,0.9); //��������� ��� �� ������� ���
	//glRotated(45, 0, 0, 1); //������� �� ��� Z
	
	
}



int main(int argc, char* argv[]) {


	glutInit(&argc, argv);  //���������� ������������ ����
    glutInitDisplayMode(GLUT_DOUBLE| GLUT_RGB);  //���� ����� 3� � ����� rgb



	glutInitWindowSize(winW, winH);         //������� ����
	glutInitWindowPosition(400, 40);        //��� �������
	glutCreateWindow("window");             //������ ���� � ������ winodow
	initialize();   //���� ������ ��������� �-� ��� ������� ���������� ���� 



	glutDisplayFunc(display); //���� ������ ��� ����� ����� ����������� ���� �� �������� ��� �-�
	glutTimerFunc(50,update,0);





	glutMainLoop();  //������ ��������� ����� �������� (���� ��� �� ���� �������� ������ ���)






	return 0;

}