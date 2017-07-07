#include "..\Header\System.h"



System::System() {
 

}

void System::Init() {
  if (SDL_Init(SDL_INIT_EVERYTHING) < 0) {
    std::cout << SDL_GetError();
  }

  render.Window();
  player.SetRender(render.base());
  player.Start();
}

void System::GameLoop() {
  while (!input.Quit()) {
    input.Process();
    
    //FIX ME::Update positions
    player.Update();

    //draw positions
    player.Draw();


    //Clear Screen and update
    SDL_RenderClear(render.base());
    SDL_RenderPresent(render.base());
  }

}


System::~System() {



  SDL_DestroyRenderer(render.base());
  //SDL_DestroyWindow(window);
  IMG_Quit();
  SDL_Quit();
}
