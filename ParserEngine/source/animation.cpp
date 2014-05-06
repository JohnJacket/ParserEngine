/*
 * animation.cpp
 *
 *  Created on: 06.05.2014
 *      Author: dmitry
 */

#include "engine.h"

using namespace std;

animation::animation()
{
	//anim_type = 0;
	CurrentTexture = 0;
	CurrentFrame = 0;

	AnimSpeed = 0;
	SpeedTicks = SDL_GetTicks();
	Paused = false;

	Repeats = -1; // Без повторов

	frames.clear();
}
animation::~animation()
{
	Delete();
}
void animation::Delete()
{
	if(CurrentTexture)
		delete CurrentTexture;

	CurrentTexture = 0;
	CurrentFrame = 0;

	AnimSpeed = 0;
	SpeedTicks = 0;
	Paused = false;

	Repeats = 0;

	frames.clear();
}
void animation::Pause()
{
	Paused = true;
}
void animation::Resume()
{
	Paused = false;
	SpeedTicks = SDL_GetTicks();
}
void animation::Reset()
{
	CurrentFrame = 0;
	SpeedTicks = SDL_GetTicks();
}
void animation::Update()
{
	// Получаем следующий фрейм

	if((Paused)||(!CurrentTexture)||(frames.empty()))
	{
		// Выходим если хоть один из случаев выше верен
		return;
	}

	if(AnimSpeed)
	{
		if(1000/AnimSpeed > (SDL_GetTicks() - SpeedTicks))
		{
			return;
		}
	}
	SpeedTicks = SDL_GetTicks();

	CurrentFrame++; // Следющий фрейм

	if(CurrentFrame >= frames.size())
	{
		// Фрейм выходит за пределы массива фреймов
		CurrentFrame = 0;
	}
}
void animation::Draw()
{

}
void animation::SetTexture(image *Texture)
{
	CurrentTexture = Texture;
}
void animation::SetSpeed(Uint32 Speed)
{
	AnimSpeed = Speed;
	SpeedTicks = SDL_GetTicks();
}

// Устанавливаем количество повторов, после которых не проигрываем анимацию
void animation::SetRepeats(int rep)
{
	Repeats = rep;
}

// Добавляем новый фрейм в индекс или в конец
void animation::AddNewFrame(PE_Rect Rect, int index)
{
	if((index < 0)||(unsigned int)index > frames.size())
	{
		frames.push_back(Rect);
	}
	else
	{
		frames.insert(frames.begin() + index, Rect);
	}
}

// Прыгаем на фрейм с заданным индексом
void animation::JumpToFrame(unsigned int index)
{
	if(index > frames.size())
		return;

	CurrentFrame = index;
	SpeedTicks = SDL_GetTicks();
}

// Пауза
bool animation::IsPaused()
{
	return Paused;
}

// Получаем главную текстуру
image *animation::GetTexture()
{
	return CurrentTexture;
}

// Получаем фрейм с индексом или текущий фрейм
PE_Rect animation::GetFrame(unsigned int index)
{
	if(index > frames.size())
		return frames[CurrentFrame];
	else
	{
		return frames[index];
	}
}

// Получаем номер текущего фрейма
int animation::GetTrackNumber()
{
	return CurrentFrame;
}

// Получаем количество повторов, которые остались
int animation::GetRepeats()
{
	return Repeats;
}

// Получаем скорость анимации
Uint32 animation::GetSpeed()
{
	return AnimSpeed;
}

