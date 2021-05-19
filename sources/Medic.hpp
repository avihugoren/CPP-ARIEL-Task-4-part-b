#pragma once

#include "Board.hpp"
#include "City.hpp"
#include "Player.hpp"

namespace pandemic {
class Medic : public Player
 {
   private:
   public:
      Medic(Board &board, City city) : Player(board, city) {};
      ~Medic() {};
      std::string role(){return "Medic";}
      Medic& treat(City city);
      Medic& drive( City c);
      Medic& fly_direct(City c);
      Medic& fly_charter (City c);
      Medic& fly_shuttle (City c);
 };
}