
#include "Virologist.hpp"
using namespace pandemic;
Virologist& Virologist :: treat(City c)
{
    if (this->my_board.Trasform_enum_to_CityObj(c).disease_lvl() == 0)
    {
        throw std::invalid_argument("city diseese lvl is 0 \n");
    }
    if(this->cards.find(c) == this->cards.end() && this->my_city !=c)
    {
        throw std::invalid_argument("try to treat but dont have card \n");
    }
    if(this->my_board.cures.find(this->curr_city.color) != this->my_board.cures.end())
    {
        this->my_board.Trasform_enum_to_CityObj(c).disease_lvl()=0;
        return *this;
    }
    
       this->my_board.Trasform_enum_to_CityObj(c).disease_lvl()-=1;
        return *this;
             

}