#ifndef SYSTEM_H
#define SYSTEM_H

#include <SDL.h>
#include <SDL_image.h>
#include <iostream>

#include "Input.h"
#include "GameObjects.h"

class System {
  private:
 
  SDL_Renderer* base_renderer;
  SDL_Window* window;

  //Render render;
  Input input;
  Player player;
  Ball ball;
  Computer computer;

  public:
  System();
  void Init();
  void LoadMedia();
  void GameLoop();
  
  ~System();
};

#endif // !SYSTEM_H