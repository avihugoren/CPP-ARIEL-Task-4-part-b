
#include "Virologist.hpp"
using namespace pandemic;
Virologist& Virologist :: treat(City c)
{
    // diseese lvl is 0//
    if (this->my_board[c] == 0)
    {
        throw std::invalid_argument("city disease lvl is 0 \n");
    }
    //check if it holds the card//
    if(this->cards.find(c) == this->cards.end() && this->my_city !=c)
    {
        throw std::invalid_argument("try to treat but dont have card \n");
    }
    // checks if there alredy a cure for this disease//
    if(this->my_board.cures.find(this->my_board.Trasform_enum_to_CityObj(this->my_city).color) != this->my_board.cures.end())
    {
        this->my_board[c]=0;
        return *this;
    }
        // no cure for the disease//
       this->my_board[c]-=1;
        return *this;
             

}