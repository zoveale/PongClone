#ifndef GAMEOBJECTS_H
#define GAMEOBJECTS_H

#include <SDL.h>
#include <string>
#include "Render.h"


class GameObjects {
  protected:
  SDL_Renderer* renderer;
  SDL_Rect rect;
  SDL_Texture* texture;

  Render render;

  public:
  GameObjects();
  void Initialization(int x, int y, int w, int h);
  void SetRender(SDL_Renderer* r);
  void Draw();
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
  void Update() {

  }
};

#endif // !GAMEOBJECTS_H