#ifndef Seat_h
#define Seat_h

#include <iostream>
#include <string>

class Seat{
public:
  Seat(int row, int col);
  int sell();
  const std::string showSeatInfo();
  ~Seat();
private:
  int row;
  int col;
  int sold;
};

inline Seat::Seat(int row, int col){
  this->row = row;
  this->col = col;
  this->sold = 0;
}

inline int Seat::sell(){
  int status = 0;
  this->sold = 1;
  return status;
}

inline const std::string Seat::showSeatInfo(){
  return std::to_string(this->row)+'-'+std::to_string(this->col)+':'+std::to_string(this->sold)+' ';
}

inline Seat::~Seat(){}

#endif //Seat_h
