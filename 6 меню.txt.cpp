#include <iostream>
#include <GL/glut.h>
#include <GL/glu_.h>
#include <SFML/Graphics.hpp>
using namespace std;
using namespace sf;
int winW = 600;
int winH = 600;


class krugs {
private:

	bool gross;


public:

	float x, y, z, r;

	krugs(int X, int Y, int Z, int R) {

		x = X;
		y = Y;
		z = Z;
		r = R;

		gross = false;

	}


	void draw() {

		glColor3f(1.0, 0.0, 0.0);
		glBegin(GL_LINE_LOOP);
		for (float i = 0.0; i < 2 * 3.14; i += 3.14 / 18)
		{
			for (int a = 0; a <= 360; a++)

				glVertex3f(x + r * sin(i), y + r * cos(i), z);




		}



		glEnd();

	}

	void animSetSizePost(int Max, float speed) {

		if (gross == false) {
			r += 1 * speed;
			if (r > Max) gross = true;


		}

		else {

			r -= 1 * speed;

			if (r <= 1) gross = false;

		}

	}


};

krugs krug(0,0,0,1);

void DarwPoligon() {




	glBegin(GL_LINES);
	glColor3ub(150, 90, 20);      // рисуем 
	for (int i = -winW / 2; i <= winW / 2; i += 20) {
		glVertex2d(i, -winH / 2);
		glVertex2d(i, winH / 2);

	}
	for (int i = -winH / 2; i <= winH / 2; i += 20) {
		glVertex2d(-winW / 2, i);
		glVertex2d(winW / 2, i);

	}
	glEnd();



	krug.draw();
	krug.animSetSizePost(10, 1);





}




void display() {

	glClear(GL_COLOR_BUFFER_BIT); //окрасить окно в базовый цвет






	if (Keyboard::isKeyPressed(Keyboard::W))  glRotated(1, 0, 0, 1); //поворот по оси Z

	if (Keyboard::isKeyPressed(Keyboard::A))  glRotated(1, 0, 1, 0); //поворот по оси Z

	if (Keyboard::isKeyPressed(Keyboard::D))  glRotated(1, 1, 0, 0); //поворот по оси Z
	if (Keyboard::isKeyPressed(Keyboard::Q))  glScaled(1.1f, 1.1f, 1.1f);
	if (Keyboard::isKeyPressed(Keyboard::E))  glScaled(0.9f, 0.9f, 0.9f);

	DarwPoligon();



	glutSwapBuffers(); //вернуть все обьекты
}




void update(int) {




	glutPostRedisplay();               // заставляем дисплей работать
	glutTimerFunc(50, update, 0);      //вызываем эту функцию ещё раз

}





void mouseMove(int ax, int ay) {

	//cout << "мышь двигается" << endl;


}


void mousePressded(int botton, int state, int x, int y) {


	//cout << "мышь нажата" << endl;



}


void mousePressedMove(int ax, int ay) {


	//cout << "мышь нажата и двиг" << endl;


}



void menuCheck(int w) {

	switch (w)
	{

	case 1:cout << "первое меню" << endl; break;
	case 2:cout << "второе меню" << endl; break;
	case 3:cout << "третье меню" << endl; break;

	}


}


void menuInput() {

 
	glutSetMenu(glutCreateMenu(menuCheck));
	glutAddMenuEntry("первое", 1);
	glutAddMenuEntry("второе", 2);
	glutAddMenuEntry("третье", 3);
	glutAttachMenu(GLUT_RIGHT_BUTTON);



}







void initialize() {

	glClearColor(0, 0, 0, 1.0);        //типо задать базовый цвет
	glOrtho(-winW / 2, winW / 2, winH / 2, -winH / 2, -500, 500); //задаём 3д дикартовую систему корардинат и рисуем то что видим  //типо макс по -w , w ,-h,h ,z,-z

	glMatrixMode(GL_MODELVIEW);  //все изменения какаются видимых объектов
	glTranslated(0, 0, 0); // типо сдвигаем все обь
	glScaled(0.9, 0.9, 0.9); //увеличить все во сколько раз
	//glRotated(45, 0, 0, 1); //поворот по оси Z


}



int main(int argc, char* argv[]) {

	setlocale(LC_ALL, "RUS");
	glutInit(&argc, argv);  //простотипо инийилизация глут
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);  //типо решим 3д и цвета rgb



	glutInitWindowSize(winW, winH);         //размеры окна
	glutInitWindowPosition(400, 40);        //его позиция
	glutCreateWindow("window");             //сознаём окно с иминем winodow
	initialize();   //типо просто отдельная ф-я для задания параметров окна 



	glutDisplayFunc(display); //типо каждый раз когда нужно отристовать окно то вызываем эту ф-я
	glutTimerFunc(50, update, 0);


	glutPassiveMotionFunc(mouseMove);
	glutMouseFunc(mousePressded);
	glutMotionFunc(mousePressedMove);


	menuInput();






	glutMainLoop();  //запуск основного цикла проверки (типо что бы окно работало всегда итд)






	return 0;

}