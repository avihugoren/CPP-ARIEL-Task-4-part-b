#pragma once

#include "Board.hpp"
#include "City.hpp"
#include "Player.hpp"

namespace pandemic {
class Virologist : public Player
 {
   private:
   public:
        Virologist(Board& board, City city) : Player(board, city) {};
        ~Virologist() {};
        std::string role(){return "Virologist";}
        Virologist& treat(City c);
 };
}