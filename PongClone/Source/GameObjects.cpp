#include "..\Header\GameObjects.h"



GameObjects::GameObjects() {
  
  rect = {0, 0, 0, 0};
  texture = NULL;
  renderer = NULL;
}

void GameObjects::Initialization(int x, int y, int w, int h) {
  this->rect = {x, y, w, h};
}

void GameObjects::SetRender(SDL_Renderer * r) {
  this->renderer = r;
}

void GameObjects::Draw() {
  SDL_RenderCopy(renderer, texture, NULL, &rect);
}


void GameObjects::Textures(std::string x) {
  texture = render.loadTexture(x);
}

GameObjects::~GameObjects() {}