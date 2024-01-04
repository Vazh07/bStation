#ifndef Bus_h
#define Bus_h

#include <iostream>
#include "seat.h"

class Bus{
public:
    Bus(int id, int rows, int cols);
    void showSeats();
    ~ Bus();
private:
    int id;
    int rows;
    int cols;
    Seat*** seats;
    void setSeats(int rows, int cols);
    void clearSeats();
};

inline Bus::Bus(int id, int rows, int cols){
    this->rows = rows;
    this->cols = cols;
    this->id = id;
    this->setSeats(rows,cols);
}

inline void Bus::setSeats(int rows, int cols){
    this->id = id;
    this->seats = new Seat**[rows];
    for(int i =0;  i<rows; i++){
      this->seats[i] = new Seat*[cols];
      for(int j = 0; j<cols; j++){
        this->seats[i][j]=new Seat(i,j);
      }
    }
}

inline void Bus::showSeats() {
    for (int i = 0; i < this->rows; i++) {
        for (int j = 0; j < this->cols; j++) {
            std::cout << this->seats[i][j]->showSeatInfo();
        }
        std::cout<<std::endl;
    }
}

inline void Bus::clearSeats(){
  for(int i =0;  i < this->rows; i++){
    for(int j =0;  j < this->cols; j++){
      delete this->seats[i][j];
    }
    delete[] this->seats[i];
  }
  delete[] this->seats;
  this->seats = nullptr;
}

inline Bus::~Bus(){
  this->clearSeats();
}

#endif //Bus_h
