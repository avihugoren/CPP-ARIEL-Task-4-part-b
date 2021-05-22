
#include "GeneSplicer.hpp"
using namespace pandemic;
GeneSplicer & GeneSplicer::discover_cure(Color c)
{
    if (!this->my_board(this->my_city))
    {
        throw std::invalid_argument("there is no station on this city\n");
    }
    //Checks if there is already a cure//
    if (this->my_board.cures.find(c)!= this->my_board.cures.end())
    {
        return *this;
    }
    set<City> temp_set;
    for (auto elem : this->cards)
    {
        temp_set.insert(elem);
        //If there is enough cards//
        if (temp_set.size() == number_for_cure)
        {
            break;
        }
    }  
    //If there is enough cards//
    if(temp_set.size() == number_for_cure)
    {
        for (auto elem : temp_set)
        {
            this->cards.erase(elem);
        }
        this->my_board.cures.insert(c);
        return *this;;
    }
    //There wasnt enough cards//
    throw std::invalid_argument("not enough cards \n");  
    return *this;
    }
            
