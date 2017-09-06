#include "..\Header\GameObjects.h"

GameObjects::GameObjects() {
  
  rect = {0, 0, 0, 0};
  texture = NULL;
  object_renderer = NULL;
}

void GameObjects::Initialization(int x, int y, int w, int h) {
  this->rect = {x, y, w, h};
}

void GameObjects::SetRender(SDL_Renderer * r) {
  this->object_renderer = r;
}

SDL_Rect GameObjects::Rect() {
  return rect;
}

void GameObjects::Textures(std::string x) {
  texture = render.loadTexture(x, this->object_renderer);
}

GameObjects::~GameObjects() {}
