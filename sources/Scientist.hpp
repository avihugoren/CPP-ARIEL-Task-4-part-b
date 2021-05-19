#pragma once

#include "Board.hpp"
#include "City.hpp"
#include "Player.hpp"

namespace pandemic {
class Scientist : public Player
 {
   private:
        int n_parm;
   public:
    Scientist(Board& board, City city) : Player(board, city) {};
    Scientist(Board& board, City city,int num);
    ~Scientist() {};
    std::string role(){return "Scientist";}
    Scientist& discover_cure(Color color);
 };
}