#include <iostream>
#include <list>
#include <GL/glut.h>
#include <GL/glu_.h>
#include <SFML/Graphics.hpp>
#include <SFML/Graphics.hpp>
using namespace std;
using namespace sf;


class kubs {
public:

	int x, y, z;

	kubs(int X, int Y, int Z) {

		x = X;
		y = Y;
		z = Z;

	}


	void draw() {

		// ������������ ������� � ��������
		glBegin(GL_POLYGON);

		glColor3f(1.0, 1.0, 0.0);     glVertex3f(0.5 + x, -0.5 + y, -0.5 + z);      // P1 �������
		glVertex3f(0.5 + x, 0.5 + y, -0.5 + z);      // P2 �������
		glVertex3f(-0.5 + x, 0.5 + y, -0.5 + z);      // P3 �����
		glVertex3f(-0.5 + x, -0.5 + y, -0.5 + z);      // P4 ����������

		glEnd();

		// ����� ������� � ������
		glBegin(GL_POLYGON);
		glColor3f(1.0 + x, 1.0 + y, 1.0 + z);
		glVertex3f(0.5 + x, -0.5 + y, 0.5 + z);
		glVertex3f(0.5 + x, 0.5 + y, 0.5 + z);
		glVertex3f(-0.5 + x, 0.5 + y, 0.5 + z);
		glVertex3f(-0.5 + x, -0.5 + y, 0.5 + z);
		glEnd();

		// ���������� ������� � ������
		glBegin(GL_POLYGON);
		glColor3f(1.0, 0.0, 1.0);
		glVertex3f(0.5 + x, -0.5 + y, -0.5 + z);
		glVertex3f(0.5 + x, 0.5 + y, -0.5 + z);
		glVertex3f(0.5 + x, 0.5 + y, 0.5 + z);
		glVertex3f(0.5 + x, -0.5 + y, 0.5 + z);
		glEnd();

		// ������� ������� � �����
		glBegin(GL_POLYGON);
		glColor3f(0.0, 1.0, 0.0);
		glVertex3f(-0.5 + x, -0.5 + y, 0.5 + z);
		glVertex3f(-0.5 + x, 0.5 + y, 0.5 + z);
		glVertex3f(-0.5 + x, 0.5 + y, -0.5 + z);
		glVertex3f(-0.5 + x, -0.5 + y, -0.5 + z);
		glEnd();

		// ����� ������� � �������
		glBegin(GL_POLYGON);
		glColor3f(0.0, 0.0, 1.0);
		glVertex3f(0.5 + x, 0.5 + y, 0.5 + z);
		glVertex3f(0.5 + x, 0.5 + y, -0.5 + z);
		glVertex3f(-0.5 + x, 0.5 + y, -0.5 + z);
		glVertex3f(-0.5 + x, 0.5 + y, 0.5 + z);
		glEnd();

		// ������� ������� � ������
		glBegin(GL_POLYGON);
		glColor3f(1.0, 0.0, 0.0);
		glVertex3f(0.5 + x, -0.5 + y, -0.5 + z);
		glVertex3f(0.5 + x, -0.5 + y, 0.5 + z);
		glVertex3f(-0.5 + x, -0.5 + y, 0.5 + z);
		glVertex3f(-0.5 + x, -0.5 + y, -0.5 + z);
		glEnd();


	}


};


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



int main(int argc, char* argv[]) {



	setlocale(LC_ALL, "RUS");
	

	sf::Window window(sf::VideoMode(800, 600), "OpenGL", sf::Style::Default, sf::ContextSettings(24));
	window.setVerticalSyncEnabled(true);
	glMatrixMode(GL_MODELVIEW);
	glEnable(GL_DEPTH_TEST); //������� ��� ��� �� �� ������ ������ ������
	glMatrixMode(GL_PROJECTION);
	glOrtho(-800, 800, 800, 800, -800, 800); //����� 3� ���������� ������� ���������� � ������ �� ��� �����  //���� ���� �� -w , w ,-h,h ,z,-z
	glLoadIdentity();   //���������� ������� �� 0
	


	



	// activate the window
	window.setActive(true);
	bool running = true;
	while (running)
	{
		// handle events
		sf::Event event;
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
			{
				// end the program
				running = false;
			}
			else if (event.type == sf::Event::Resized)
			{
				// adjust the viewport when the window is resized
				glViewport(0, 0, event.size.width, event.size.height); //��� ���� ��� �� ��� ����� ��� ��� ��� ���
			}
		}



		// clear the buffers
		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
		








		glBegin(GL_LINES);
		glColor3ub(255, 0, 0);
		glVertex3f(0, 0, 0);
		glVertex3f(100, 0, 0); //x-red
		glColor3ub(0, 255, 0);
		glVertex3f(0, 0, 0);
		glVertex3f(0, 100, 0); //Y-Gread
		glColor3ub(0, 0, 255);
		glVertex3f(0, 0, 0);
		glVertex3f(0, 0, 100); //z-blue
		glEnd();




		
		


		if (Keyboard::isKeyPressed(Keyboard::W))  glRotated(1, 0, 0, 1); //������� �� ��� Z
		if (Keyboard::isKeyPressed(Keyboard::A))  glRotated(1, 0, 1, 0); //������� �� ��� y
		if (Keyboard::isKeyPressed(Keyboard::D))  glRotated(1, 1, 0, 0); //������� �� ��� z
		if (Keyboard::isKeyPressed(Keyboard::Q))  glScaled(2, 2, 2);
		if (Keyboard::isKeyPressed(Keyboard::E))  glScaled(0.6f, 0.6f, 0.6f);



		

		// end the current frame (internally swaps the front and back buffers)
		window.display();
	}


		

	return 0;

}