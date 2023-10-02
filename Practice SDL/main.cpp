/*This source code copyrighted by Lazy Foo' Productions 2004-2023
and may not be redistributed without written permission.*/

//Using SDL and standard IO
#include <SDL.h>
#include <stdio.h>
#include "ConsoleControl.h"
#include <iostream>
#define RECT_WIDTH 100
#define RECT_HEIGHT 80

//Screen dimension constants
const int SCREEN_WIDTH = 1280;
const int SCREEN_HEIGHT = 720;



int main( int argc, char* args[] )
{
	//The window we'll be rendering to
	SDL_Window* window = NULL;
	
	//The surface contained by the window
	SDL_Surface* screenSurface = NULL;
	int colorR = 0x00;
	int colorG = 0x00;
	int colorB = 0x00;
	int option = 0;
	int key = 0;
	bool up = false;
	float a = 0.0f;
	int interval = 1;
	//Initialize SDL
	if( SDL_Init( SDL_INIT_VIDEO ) < 0 )
	{
		printf( "SDL could not initialize! SDL_Error: %s\n", SDL_GetError() );
	}
	else
	{
		//Create window
		window = SDL_CreateWindow( "Firsts SDL", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN );
		if( window == NULL )
		{
			printf( "Window could not be created! SDL_Error: %s\n", SDL_GetError() );
		}
		else
		{
			std::cout << "Write a option: ";
			std::cin >> option;
			//Get window surface
			screenSurface = SDL_GetWindowSurface( window );
			switch (option)
			{
			case 1:
				while (key!=KB_ESCAPE)
				{
					colorR = 0xFF;
					SDL_UpdateWindowSurface(window);
					SDL_FillRect(screenSurface, NULL, SDL_MapRGB(screenSurface->format, colorR, colorG, colorB));
					colorR = (Uint32)((sin(a) + 1) * 128);
					a += 0.01f;
					/*if (colorR<0x00)
					{
						up = true;
					}
					if (colorR>0xFF)
					{
						up = false;
					}
					if (up==true)
					{
						colorR += 0x01;
					}
					if (up==false)
					{
						colorR -= 0x01;
					}*/
				}
				break;
			case 2:
				colorR = 0xFF;
				while (key != KB_ESCAPE)
				{
					SDL_UpdateWindowSurface(window);
					SDL_FillRect(screenSurface, NULL, SDL_MapRGB(screenSurface->format, colorR, colorG, colorB));
					switch (interval)
					{
					case 1:
						colorB += 0x01;
						if (colorB==0xFF)
						{
							interval = 2;
						}
						break;
					case 2:
						colorR -= 0x01;
						if (colorR==0x00)
						{
							interval = 3;
						}
						break;
					case 3:
						colorG += 0x01;
						if (colorG==0xFF)
						{
							interval = 4;
						}
						break;
					case 4:
						colorB -= 0x01;
						if (colorB==0x00)
						{
							interval = 5;
						}
						break;
					case 5:
						colorR += 0x01;
						if (colorR==0xFF)
						{
							interval = 6;
						}
						break;
					case 6:
						colorG -= 0x01;
						if (colorG==0x00)
						{
							interval = 1;
						}
						break;
					default:
						break;
					}
					/*if (colorR<0x00)
					{
						up = true;
					}
					if (colorR>0xFF)
					{
						up = false;
					}
					if (up==true)
					{
						colorR += 0x01;
					}
					if (up==false)
					{
						colorR -= 0x01;
					}*/
				}
				break;
			case 3:
				SDL_FillRect(screenSurface, NULL, SDL_MapRGB(screenSurface->format, colorR, colorG, colorB));
				break;

			default:
				break;
			}

			//Fill the surface white
			//SDL_FillRect( screenSurface, NULL, SDL_MapRGB( screenSurface->format, colorR, colorG, colorB ) );
			
			//Update the surface
			SDL_UpdateWindowSurface( window );
            
            //Hack to get window to stay up
            SDL_Event e; bool quit = false; while( quit == false ){ while( SDL_PollEvent( &e ) ){ if( e.type == SDL_QUIT ) quit = true; } }
		}
	}

	//Destroy window
	SDL_DestroyWindow( window );

	//Quit SDL subsystems
	SDL_Quit();

	return 0;
}
