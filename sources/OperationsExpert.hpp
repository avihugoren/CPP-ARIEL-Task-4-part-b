#pragma once

#include "Board.hpp"
#include "City.hpp"
#include "Player.hpp"

namespace pandemic {
class OperationsExpert : public Player
 {
   private:
   public:
        OperationsExpert(Board &board, City city) : Player(board, city) {};
        ~OperationsExpert() {};
        std::string role(){return "OperationsExpert";}
        OperationsExpert& build ();
 };
}