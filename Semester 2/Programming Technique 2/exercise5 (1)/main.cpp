// ? EXERCISE 5: POLYMORPHISM

// Programming Technique II
// Semester 2, 2021/2022

// Section: 01
// Member 1's Name: _____________    Location: ____________ (i.e. where are you currently located)
// Member 2's Name: _____________    Location: ____________

// Log the time(s) your pair programming sessions
//  Date         Time (From)   To             Duration (in minutes)
//  _________    ___________   ___________    ________
//  _________    ___________   ___________    ________

// Video link:
//   _________



#include <graphics.h>
#include <cmath>
#include <stdlib.h>
#include <time.h>

#include "shape.hpp"
#include "circle.hpp"
#include "rect.hpp"

using namespace std;

// ? Notes: Choose the debug mode "Multi-File Graphic Project" to run this program.

// You may change the max size of the list
#define COUNT 5

Shape *shapes[COUNT];
Shape *selectedShape;

void generateListOfShape(int width, int height)
{

	for(int i = 0; i < COUNT; i++)
	{
		int side = rand() % 2;
		int x = 1 + rand() % width;
		int y = 1 + rand() % height;
		if (side == 0)
		{
			int r = 50 + rand() % 200;
			shapes[i] = new Circle(x, y, r);
		}
		else
		{
			int w = 50 + rand() % 200;
			int h = 50 + rand() % 200;
			shapes[i] = new Rect(x, y, w, h);
		}
	}

}

void processMouseClick()
{
	int mx, my;

	if (ismouseclick(WM_LBUTTONDOWN))
	{
		// capture mouse location (mx,my)
		getmouseclick(WM_LBUTTONDOWN, mx, my);

		// Test location (mx,my) all over the shapes
		for (int i = 0; i < COUNT; i++)
		{
			if(shapes[i]->isMouseClicked(mx, my))
			{
				// defensive coding
				if (selectedShape)
					selectedShape->toggleSelected();
					
				selectedShape = (selectedShape == shapes[i])? nullptr : shapes[i];

				if (selectedShape)
					selectedShape->toggleSelected();
				break;
			}

		}
		// find to which the mouse is click on (s) 
		// selected = yellow, unselected = white
	}
}

int main()
{
	int width = getmaxwidth();
	int height = getmaxheight();
	initwindow(width, height, "Exercise 5");
	

	/* initialize random seed: */
	srand(time(NULL));
	generateListOfShape(width, height);

	for(int i = 0; i < COUNT; i++)
		shapes[i]->draw();

	char ch = 0;

	while (ch != 27)  // 27 is ESC key
	{
		if (kbhit())
		{
			ch = getch();
			switch (toupper(ch))
			{
			case '+':
				if(selectedShape)
				selectedShape->resize(2.0);
				break;

			case '-':
				if(selectedShape)
				selectedShape->resize(0.5);
				break;

			case KEY_LEFT:
				if(selectedShape)
				selectedShape->move(-10, 0);
				break;

			case KEY_RIGHT:
				if(selectedShape)
				selectedShape->move(10, 0);
				break;

			case KEY_UP:
				if(selectedShape)
				selectedShape->move(0, -10);
				break;

			case KEY_DOWN:
				if(selectedShape)
				selectedShape->move(0, 10);
				break;
			}
		}

		processMouseClick();
	}
	return 0;
}