#pragma once

#include "Board.hpp"
#include "City.hpp"
#include "Player.hpp"

namespace pandemic {
class Researcher : public Player
 {
   private:
   public:
    Researcher(Board& board, City city) : Player(board, city) {};
    ~Researcher() {};
     std::string role(){return "Researcher";}
    Researcher& discover_cure(Color c);
 };
}