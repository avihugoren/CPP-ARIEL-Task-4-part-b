#include "Scientist.hpp"
using namespace pandemic;
//player constructor plus the special field of Scientist// 
Scientist:: Scientist(Board& board, City city,int num):Player(board, city)
{
    this->n_parm = num;
}
Scientist& Scientist:: discover_cure(Color c)
{   
    //No station at this city//
    if (!this->my_board(this->my_city))
    {
        throw std::invalid_argument("there is no station on this city scientist\n");
    }
    //There is alredy a cure//
    if (this->my_board.cures.find(c)!= this->my_board.cures.end())
    {
        return *this;
    }
    //Temp set to count all the cards with the right color//
    set<City> temp_set;
    //check all the cards//
    for (const auto & elem : this->cards)
    {
        //if the card have the same color//
        if (this->my_board.Trasform_enum_to_CityObj(elem).color== c)
        {
            temp_set.insert(elem);
            //if there alredy enough cards//
            if (temp_set.size() == this->n_parm)
            {
                break;
            }
        }
    }
            //if there is enough cards from the right color//
            if(temp_set.size() == this->n_parm)
            {
                //delete the card from the hand of the player//
                for ( const auto &elem : temp_set)
                {
                    this->cards.erase(elem);
                }
                //update that a cure is find//
                this->my_board.cures.insert(c);
                return *this;
            }
            //there wasnt enough cards from the right color// 
            throw std::invalid_argument("not enough cards in with color sci \n");  
}
