#ifndef GAMEOBJECTS_H
#define GAMEOBJECTS_H

#include <SDL.h>
#include <string>

#include "Render.h"
#include "Input.h"


class GameObjects {
  protected:
  SDL_Renderer* object_renderer;
  SDL_Rect rect;
  SDL_Texture* texture;
  SDL_Point velocity;

  Render render;
  Input input;

  public:
  GameObjects();
  void Initialization(int x, int y, int w, int h);
  void SetRender(SDL_Renderer* r);
  SDL_Rect Rect();

  virtual void Draw() = 0;

  virtual void Update(KEY_STATE key) = 0;
  void Textures(std::string x);
  virtual void Start() = 0;

  ~GameObjects();
};



class Player: public GameObjects {

  public:

  void Start() {
    Initialization(15, 25, 25, 125);
    Textures("resources/player.png");
    velocity.x = 10;
    velocity.y = 10;
  }

  void Draw() {
    SDL_RenderCopy(object_renderer, texture, NULL, &rect);
  }

  void Update(KEY_STATE key) {

    //std::cout << rect.x << "\t" << rect.y << "\n";

    if (key.UP) {
      if (rect.y >= 0) {
        rect.y -= velocity.y = 10;;
      }
    }
    else if (key.DOWN) {
      if ((rect.y + rect.h) <= 470)
        rect.y += velocity.y = 10;
    }
  }

};

class Computer: public GameObjects {

  public:

  void Start() {
    Initialization(600, 25, 25, 125);
    Textures("resources/computer.png");
    velocity.x = 10;
    velocity.y = 10;
  }

  void Draw() {
    SDL_RenderCopy(object_renderer, texture, NULL, &rect);
  }

  void Update(KEY_STATE key) {

    //std::cout << rect.x << "\t" << rect.y << "\n";

    if (key.UP) {
      if (rect.y >= 0) {
        rect.y -= velocity.y = 10;;
      }
    }
    else if (key.DOWN) {
      if ((rect.y + rect.h) <= 470)
        rect.y += velocity.y = 10;
    }
  }

};
class Ball: public GameObjects {
  public:

  void Start() {
    Initialization(200, 200, 25, 25);
    Textures("resources/ball.png");
    velocity.x = 3;
    velocity.y = 3;
  }

  void Draw() {
    SDL_RenderCopy(object_renderer, texture, NULL, &rect);
  }

  void Update(KEY_STATE key) {

    if (((rect.y + rect.h) >= 480) || rect.y <= 0) {
      velocity.y *= -1;
    }
    else if (((rect.x + rect.w) >= 640) || rect.x <= 0) {
      velocity.x *= -1;

    }
    if (rect.x <= 0) {
      std::cout << "POINT COMPUTER \n";
    }
    if (rect.x + rect.w >= 640) {
      std::cout << "POINT PLAYER\n";
    }
    rect.x += velocity.x;
    rect.y += velocity.y;

  }

  void Collision(SDL_Rect a, SDL_Rect b) {
    //The sides of the rectangles
    int leftA, leftB;
    int rightA, rightB;
    int topA, topB;
    int bottomA, bottomB;

    //Calculate the sides of rect A
    leftA = a.x;
    rightA = a.x + a.w;
    topA = a.y;
    bottomA = a.y + a.h;

    //Calculate the sides of rect B
    leftB = b.x;
    rightB = b.x + b.w;
    topB = b.y;
    bottomB = b.y + b.h;

    //If any of the sides from A are outside of B
    if (bottomA <= topB) {
      return;
    }

    if (topA >= bottomB) {
      return;
    }

    if (rightA <= leftB) {
      return;
    }

    if (leftA >= rightB) {
      return;
    }
    else {
      velocity.x *= -1;

      /*
      if () {
        velocity.y *= -1;
      }
      else {
        return;
      }
      */
      return;
    }



  }
};
#endif // !GAMEOBJECTS_H