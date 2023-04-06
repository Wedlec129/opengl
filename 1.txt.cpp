#include <iostream>
#include <GL/glut.h>
#include <GL/glu_.h>
#include <SFML/Graphics.hpp>
using namespace std;



 void DarwPoligon() {
	glEnable(GL_POINT_SMOOTH); //сглаживание

	//glPolygonMode(GL_FRONT_AND_BACK, GL_FILL); // см. выше
	glBegin(GL_POLYGON);
	glColor3d(1, 0, 0);      // рисуем 
	glVertex3d(-100, -100, 0);
	glVertex3d(-400, 100, 0);
	glVertex3d(100, -100, 0);
	glVertex3d(400, 100, -100);
	glVertex3d(-400, 100, 0);
	glEnd();




}

void DrawLinie() {


	glLineWidth(5);       // ширину линии
					  
	glBegin(GL_LINES);

	glColor3d(1, 0, 0);     // красный цвет

	glVertex3d(0, 0, 0); // перва€ лини€ начало 
	glVertex3d(100, 100,100);   //конец
	
	
	glEnd();

	

}

void DrawPoint() 
{
	glColor3f(1.0, 1.0, 1.0);    //цвет 1-max


	glBegin(GL_POINTS);  //начать отрисовку (точек)
	glVertex3f(0, 0, 0);   //просто вершина
	glColor3f(0, 1, 1.0);   
	glVertex3f(5, 5, 5);

	glEnd();                  //закончить отрисовку точек


	glPointSize(10);       //размер точки 
	glBegin(GL_POINTS);  //начать отрисовку (точек)
	glColor3f(1.0, 0, 0);
	glVertex3f(-10, 0, 0);

	glEnd();                  //закончить отрисовку точек
}




void display() {

	glClear(GL_COLOR_BUFFER_BIT); //окрасить окно в базовый цвет
	
	//DrawPoint(0,0,0);

	DrawLinie();

	//DarwPoligon();

	glFlush();       //вернуть все обьекты
	
}


int main(int argc, char* argv[]) {

	
	glutInit(&argc, argv);  //простотипо инийилизаци€ глут

	
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);  //типо решим 3д и цвета rgb

	
	
	glutInitWindowSize(500, 500);         //размеры окна
	glutInitWindowPosition(400, 40);        //его позици€
    glutCreateWindow("window");             //сознаЄм окно с иминем winodow
	glClearColor(0, 0, 0, 1.0);        //типо задать базовый цвет

	glOrtho(-500 , 500 , 500 , -500 , -500, 500); //задаЄм 3д дикартовую систему корардинат и рисуем то что видим  //типо макс по -w , w ,-h,h ,z,-z
	glutDisplayFunc(display); //типо каждый раз когда нужно отристовать окно то вызываем эту ф-€
	

	
	glutMainLoop();  //запуск основного цикла проверки (типо что бы окно работало всегда итд)

	




	return 0;

}