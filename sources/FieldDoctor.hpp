#pragma once

#include "Board.hpp"
#include "City.hpp"
#include "Player.hpp"

namespace pandemic {
class FieldDoctor : public Player
 {
   private:
   public:
          FieldDoctor(Board& board, City city) : Player(board, city){}
          ~FieldDoctor() {}
          std::string role() ;
          FieldDoctor& treat(City city);
 };
 }