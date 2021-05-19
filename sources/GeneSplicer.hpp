#pragma once

#include "Board.hpp"
#include "City.hpp"
#include "Player.hpp"

namespace pandemic {
class GeneSplicer : public Player
 {
   private:
   public:
        GeneSplicer(Board &board, City city) : Player(board, city) {}
        ~GeneSplicer() {}
        std::string role(){return "GeneSplicer";}
        GeneSplicer & discover_cure(Color c);
 };
}