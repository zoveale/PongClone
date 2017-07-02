#include "../Header/System.h"

int main(int argc, char* args[]) {
  
  System system;
  
  
  system.Init();
  system.GameLoop();
  system.~System();

  return 0;
}