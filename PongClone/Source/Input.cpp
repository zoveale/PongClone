#include "..\Header\Input.h"




Input::Input() {
  quit = false;
}

bool Input::Quit() {
  return quit;
}

void Input::Process() {

  while (SDL_PollEvent(&event)) {
    if (event.type == SDL_QUIT) {
      quit = true;
    }
    if (event.type == SDL_KEYDOWN &&
      event.key.keysym.sym == SDLK_UP) {
      KEY.UP = true;
    }
    if (event.type == SDL_KEYUP &&
      event.key.keysym.sym == SDLK_UP) {
      KEY.UP = false;
    }
    if (event.type == SDL_KEYDOWN &&
      event.key.keysym.sym == SDLK_DOWN) {
      KEY.DOWN = true;
    }
    if (event.type == SDL_KEYUP &&
      event.key.keysym.sym == SDLK_DOWN) {
      KEY.DOWN = false;
    }
    if (event.type == SDL_KEYDOWN &&
      event.key.keysym.sym == SDLK_LEFT) {
      KEY.LEFT = true;
    }
    if (event.type == SDL_KEYUP &&
      event.key.keysym.sym == SDLK_LEFT) {
      KEY.LEFT = false;
    }

    if (event.type == SDL_KEYDOWN &&
      event.key.keysym.sym == SDLK_RIGHT) {
      KEY.RIGHT = true;
    }
    if (event.type == SDL_KEYUP &&
      event.key.keysym.sym == SDLK_RIGHT) {
      KEY.RIGHT = false;
    }

  }

}


Input::~Input() {}
