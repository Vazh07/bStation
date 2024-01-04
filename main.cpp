#include "bus.h"

int main(){
  Bus* b = new Bus(1,3,3);
  b->showSeats();
  delete b;
  return 0;
}
