#ifndef GAMEOBJECTS_H
#define GAMEOBJECTS_H

#include <SDL.h>
#include <string>

#include "Render.h"


class GameObjects {
  protected:
  SDL_Renderer* object_renderer;
  SDL_Rect rect;
  SDL_Texture* texture;

  Render render;

  public:
  GameObjects();
  void Initialization(int x, int y, int w, int h);
  void SetRender(SDL_Renderer* r);
  virtual void Draw() = 0;

  virtual void Update() = 0;
  void Textures(std::string x);
  virtual void Start() = 0;

  ~GameObjects();
};



class Player : public GameObjects{
  
  public:

  void Start() {
    Initialization(50,50,50,150);
    Textures("resources/player_idel.png");
  }

  void Draw() {
    SDL_RenderCopy(object_renderer, texture, NULL, &rect);
  }

  void Update() {
    std::cout << rect.x << "\t" << rect.y << "\n";
  }
};

#endif // !GAMEOBJECTS_H