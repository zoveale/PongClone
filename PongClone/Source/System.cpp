#include "..\Header\System.h"



System::System() {
  window = NULL;
  renderer = NULL;

}

void System::Init() {
  if (SDL_Init(SDL_INIT_EVERYTHING) < 0) {
    std::cout << SDL_GetError();
  }

  //FIX ME:: add fuctions for screen Height and width
  window = SDL_CreateWindow("Archer BROS!",
    SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED,
    640, 480,
    SDL_WINDOW_SHOWN);


  renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_PRESENTVSYNC);

  // load support for the JPG and PNG image formats
  int flags = IMG_INIT_PNG;
  int initted = IMG_Init(flags);
  if ((initted&flags) != flags) {
    printf("IMG_Init: Failed to init required jpg and png support!\n");
    printf("IMG_Init: %s\n", IMG_GetError());
  }


}

void System::GameLoop() {

  //Background Color (rgb, alpha)

  SDL_SetRenderDrawColor(renderer, 255, 0, 0, 255);

  //Clear Screen
  SDL_RenderClear(renderer);

  SDL_RenderPresent(renderer);

  SDL_Delay(1000);
}


System::~System() {

  //Destroy window
  SDL_DestroyWindow(window);

  //Quit SDL subsystems
  SDL_Quit();
}
