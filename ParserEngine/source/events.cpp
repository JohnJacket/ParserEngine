/*
 * events.cpp
 *
 *  Created on: 19.05.2014
 *      Author: dmitry
 */

#include "Events.h"

using namespace std;

//////////////////////////////////////////////////////////////////////////
// CONSTRUCTORS
//////////////////////////////////////////////////////////////////////////

//-----------------------------------------------------------------------

events::events(input *In, window *Win)
{
	Input = In;
	Window = Win;
}

//-----------------------------------------------------------------------

events::~events()
{
	Input = 0;
	Window = 0;

#ifdef DEBUG_SYS
	cout << "Events clean up - success" << endl;
#endif
}

//-----------------------------------------------------------------------

//////////////////////////////////////////////////////////////////////////
// PUBLIC METODS
//////////////////////////////////////////////////////////////////////////

//-----------------------------------------------------------------------

int events::init()
{

#ifdef DEBUG_SYS
	cout << "Events initialization - success" << endl;
#endif
	return 0;
}

//-----------------------------------------------------------------------

int events::handle_events()
{
	while(SDL_PollEvent(&event))
	{
		if(event.type == SDL_QUIT)
		{
			return 1;
			break;
		}

		if(Input)
		{
			if(Input->handle_event(event))
				continue;
		}

		if(Window)
		{
			if(Window->handle_event(event))
				continue;
		}
	}

	return 0;
}

//-----------------------------------------------------------------------

