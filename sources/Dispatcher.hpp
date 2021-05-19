#pragma once

#include "Board.hpp"
#include "City.hpp"
#include "Player.hpp"

namespace pandemic {
class Dispatcher : public Player
 {
   private:
   public:
        Dispatcher(Board& board, City city): Player(board, city){}
        ~Dispatcher() {}
        std::string role(){return "Dispatcher";}
        //special ability//
        Dispatcher& fly_direct(City city);
 };
}