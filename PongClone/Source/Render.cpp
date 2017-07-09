#include "..\Header\Render.h"

Render::Render() {
  newTexture = NULL;
  loadedSurface = NULL;
  
}

SDL_Texture* Render::loadTexture(std::string path, SDL_Renderer* r) {
  //Load image at specified path
  loadedSurface = IMG_Load(path.c_str());
  if (loadedSurface == NULL) {
    printf("Unable to load image %s! SDL_image Error: %s\n", path.c_str(), IMG_GetError());
  }
  else {
    //Create texture from surface pixels
    newTexture = SDL_CreateTextureFromSurface(r, loadedSurface);
    if (newTexture == NULL) {
      printf("Unable to create texture from %s! SDL Error: %s\n", path.c_str(), SDL_GetError());
    }
    //Get rid of old loaded surface
    SDL_FreeSurface(loadedSurface);
  }
  return newTexture;
}



Render::~Render() {
  
}


