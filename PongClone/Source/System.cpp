#include "..\Header\System.h"



System::System() {
 

}

void System::Init() {
  if (SDL_Init(SDL_INIT_EVERYTHING) < 0) {
    std::cout << SDL_GetError();
  }
  //FIX ME:: add fuctions for screen Height and width
  window = SDL_CreateWindow("Pong_Clone",
    SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED,
    640, 480,
    SDL_WINDOW_SHOWN);


  this->base_renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_PRESENTVSYNC);

  // load support for the JPG and PNG image formats
  int flags = IMG_INIT_PNG;
  int initted = IMG_Init(flags);
  if ((initted&flags) != flags) {
    printf("IMG_Init: Failed to init required jpg and png support!\n");
    printf("IMG_Init: %s\n", IMG_GetError());
  }

  //Background Color (rgb, alpha)
  SDL_SetRenderDrawColor(base_renderer, 0, 128, 0, 255);


  
  player.SetRender(base_renderer);
  player.Start();
}

void System::LoadMedia() {

}

void System::GameLoop() {
  while (!input.Quit()) {
    input.Process();
    
    //FIX ME::Update positions
    player.Update();

    
    //Clear Screen
    SDL_RenderClear(base_renderer);

    //draw position
    player.Draw();

    //Update Screem
    SDL_RenderPresent(base_renderer);
  }
}


System::~System() {



  SDL_DestroyRenderer(base_renderer);
  SDL_DestroyWindow(window);
  //render.~Render();
  IMG_Quit();
  SDL_Quit();
}
