#pragma once
#include "set"
#include "Board.hpp"
#include "Color.hpp"
#include "CityObj.hpp"
const int number_for_cure = 5;
namespace pandemic {
class Player
{
    protected:
        Board& my_board;
        City my_city;
        const std::string player_role;
        set<City> cards;
        std::string name;
        Player(Board& b,City c);
        ~Player(){}
        
    public: 
        Player & take_card( City c);
        void remove_cards(){this->cards.clear();}
        virtual Player & discover_cure( Color c);
        virtual std::string role();
        virtual Player& drive ( City c);
        virtual Player& fly_direct(City c);
        virtual Player& fly_charter (City c);
        virtual Player& fly_shuttle (City c);
        virtual Player& treat(City city);
        virtual Player& build();
};
}