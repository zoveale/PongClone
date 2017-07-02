#ifndef SYSTEM_H
#define SYSTEM_H
#include <SDL.h>
#include <SDL_image.h>
#include <iostream>

class System {
  private:
  SDL_Window* window;
  SDL_Renderer* renderer;

  public:
  System();
  void Init();
  void GameLoop();
  ~System();
};

#endif // !SYSTEM_H