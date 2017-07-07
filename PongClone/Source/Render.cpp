#include "..\Header\Render.h"



Render::Render() {
  newTexture = NULL;
  loadedSurface = NULL;
  renderer = NULL;
}

SDL_Texture* Render::loadTexture(std::string path) {
  //Load image at specified path
  loadedSurface = IMG_Load(path.c_str());
  if (loadedSurface == NULL) {
    printf("Unable to load image %s! SDL_image Error: %s\n", path.c_str(), IMG_GetError());
  }
  else {
    //Create texture from surface pixels
    newTexture = SDL_CreateTextureFromSurface(this->renderer, loadedSurface);
    if (newTexture == NULL) {
      printf("Unable to create texture from %s! SDL Error: %s\n", path.c_str(), SDL_GetError());
    }

    //Get rid of old loaded surface
    SDL_FreeSurface(loadedSurface);
  }

  return newTexture;
}

void Render::Window() {

  //FIX ME:: add fuctions for screen Height and width
  window = SDL_CreateWindow("Pong_Clone",
    SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED,
    640, 480,
    SDL_WINDOW_SHOWN);


  this ->renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_PRESENTVSYNC);

  // load support for the JPG and PNG image formats
  int flags = IMG_INIT_PNG;
  int initted = IMG_Init(flags);
  if ((initted&flags) != flags) {
    printf("IMG_Init: Failed to init required jpg and png support!\n");
    printf("IMG_Init: %s\n", IMG_GetError());
  }

  //Background Color (rgb, alpha)
  SDL_SetRenderDrawColor(renderer, 0, 128, 0, 255);

}

SDL_Renderer * Render::base() {
  return this->renderer;
}

Render::~Render() {}
