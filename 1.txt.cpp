#include <iostream>
#include <GL/glut.h>
#include <GL/glu_.h>
#include <SFML/Graphics.hpp>
using namespace std;



 void DarwPoligon() {
	glEnable(GL_POINT_SMOOTH); //�����������

	//glPolygonMode(GL_FRONT_AND_BACK, GL_FILL); // ��. ����
	glBegin(GL_POLYGON);
	glColor3d(1, 0, 0);      // ������ 
	glVertex3d(-100, -100, 0);
	glVertex3d(-400, 100, 0);
	glVertex3d(100, -100, 0);
	glVertex3d(400, 100, -100);
	glVertex3d(-400, 100, 0);
	glEnd();




}

void DrawLinie() {


	glLineWidth(5);       // ������ �����
					  
	glBegin(GL_LINES);

	glColor3d(1, 0, 0);     // ������� ����

	glVertex3d(0, 0, 0); // ������ ����� ������ 
	glVertex3d(100, 100,100);   //�����
	
	
	glEnd();

	

}

void DrawPoint() 
{
	glColor3f(1.0, 1.0, 1.0);    //���� 1-max


	glBegin(GL_POINTS);  //������ ��������� (�����)
	glVertex3f(0, 0, 0);   //������ �������
	glColor3f(0, 1, 1.0);   
	glVertex3f(5, 5, 5);

	glEnd();                  //��������� ��������� �����


	glPointSize(10);       //������ ����� 
	glBegin(GL_POINTS);  //������ ��������� (�����)
	glColor3f(1.0, 0, 0);
	glVertex3f(-10, 0, 0);

	glEnd();                  //��������� ��������� �����
}




void display() {

	glClear(GL_COLOR_BUFFER_BIT); //�������� ���� � ������� ����
	
	//DrawPoint(0,0,0);

	DrawLinie();

	//DarwPoligon();

	glFlush();       //������� ��� �������
	
}


int main(int argc, char* argv[]) {

	
	glutInit(&argc, argv);  //���������� ������������ ����

	
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);  //���� ����� 3� � ����� rgb

	
	
	glutInitWindowSize(500, 500);         //������� ����
	glutInitWindowPosition(400, 40);        //��� �������
    glutCreateWindow("window");             //������ ���� � ������ winodow
	glClearColor(0, 0, 0, 1.0);        //���� ������ ������� ����

	glOrtho(-500 , 500 , 500 , -500 , -500, 500); //����� 3� ���������� ������� ���������� � ������ �� ��� �����  //���� ���� �� -w , w ,-h,h ,z,-z
	glutDisplayFunc(display); //���� ������ ��� ����� ����� ����������� ���� �� �������� ��� �-�
	

	
	glutMainLoop();  //������ ��������� ����� �������� (���� ��� �� ���� �������� ������ ���)

	




	return 0;

}