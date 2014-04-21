/*
 * engine.cpp
 *
 *  Created on: 17.04.2014
 *      Author: dmitry
 */

#include "engine.h"

using namespace std;

int engine::init()
{
	//TODO: доделать инициализацию без аудио
	//Инициируем все системы и создаём элементы движка
	if(SDL_Init(SDL_INIT_EVERYTHING)<0) //Инициализация SDL
	{
#ifdef DEBUG_ERRORS
		cout << "Unable to initialize SDL: " << SDL_GetError() << endl;
#endif
		return -1;
	}

	//Задаём двойную буфферизацию
	//SDL_GL_SetAttribute(SDL_GL_DOUBLEBUFFER, 1);

	screen = SDL_SetVideoMode(SYS_WIDTH, SYS_HEIGTH, SYS_BPP, SDL_OPENGL|SDL_RESIZABLE);
	if(!screen)
	{
#ifdef DEBUG_ERRORS
		cout << "Unable to set screen: " << SDL_GetError() << endl;
#endif
	}

	//Задаём текст для заголовка окна
	std::stringstream title;
	title << "FireFly project " << SYS_VERSION << " prealpha test. Build " << SYS_BUILD << ".";
	SDL_WM_SetCaption(title.str().c_str(), "test icon");

	//Забиваем графику
	Graphics = new graphics();
	Graphics->init();

#ifdef DEBUG_SYS
	cout << "All system initialization - success" << endl;
	cout << "Engine initialization - success" << endl;
#endif
	return 0;
}
void engine::CleanUp()
{
	//Освобождаем ненужную память
	if(screen)
		SDL_FreeSurface(screen);

	if(Graphics)
	{
		Graphics->CleanUp();
		delete Graphics;
	}

#ifdef DEBUG_SYS
	cout << "Engine clean up - success" << endl;
#endif

	SDL_Quit(); //Выходим

#ifdef DEBUG_SYS
	cout << "SDL Quit!" << endl;
#endif

}
void engine::ResizeWin(int win_dX, int win_dY)
{
	//Изменяем рамер окна
	//TODO: доделать тут
	GLfloat ratio;
	if(!win_dY) win_dY = 1;

	ratio = (GLfloat) win_dX/(GLfloat)win_dY;
	glViewport(0, 0, (GLsizei) win_dX, (GLsizei) win_dY);

	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluPerspective(45.5f, ratio, 0.1f, 10.0f);

	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
}
engine::engine()
{
	//Конструктор
	screen = 0;
	Graphics = 0;
}
engine::~engine()
{
	//Деструктор
#ifdef DEBUG_SYS
	cout << "Engine completely clean up - success" << endl;
#endif
}

int graphics::init()
{
	//Инициализация OpenGL
	glClearColor( 0, 0, 0, 0 );
	glClearDepth(1.0f);

	glViewport(0, 0, SYS_WIDTH, SYS_HEIGTH);

	//Инициируем матрице проекции
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	glOrtho(0.0, SYS_WIDTH, SYS_HEIGTH, 0.0, -1.0, 1.0);

	//Инициирцуем матрицу вида
	glMatrixMode(GL_MODELVIEW);
	glEnable(GL_TEXTURE_2D);
	glLoadIdentity();

	//Проверка на ошибки
	GLenum error = glGetError();
	if(error!=GL_NO_ERROR)
	{
#ifdef DEBUG_ERRORS
		cout << "Error initializing OpenGL: " << gluErrorString(error) << endl;
#endif
		return -1;
	}
#ifdef DEBUG_SYS
	cout << "Graphics initialization - success" << endl;
#endif
	return 0;
}
void graphics::CleanUp()
{

}
graphics::graphics()
{

}
graphics::~graphics()
{
#ifdef DEBUG_SYS
	cout << "Graphics clean up - success" << endl;
#endif
}


