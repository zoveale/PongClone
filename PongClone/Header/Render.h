#ifndef RENDER_H
#define REDNER_H

#include <SDL.h>
#include <SDL_image.h>
#include <string>
#include <iostream>

class Render {
  private:
  
  SDL_Texture* newTexture;
  SDL_Surface* loadedSurface;
  //SDL_Renderer* renderer;

  public:
  Render();
  SDL_Texture* loadTexture(std::string path, SDL_Renderer* r);
  
  
  ~Render();
};

#endif // !RENDER