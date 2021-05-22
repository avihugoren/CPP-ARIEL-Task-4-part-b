
#include "Researcher.hpp"
 namespace pandemic{
Researcher& Researcher:: discover_cure(Color c)
{
    //There is already a cure for this color//
    if (this->my_board.cures.find(c)!= this->my_board.cures.end())
    {
        return *this;
    }
    //Set the count the cards//
    set<City> temp_set;
    for (auto elem : this->cards)
    {
        //If the cards has the right color so add it to the temp set// 
        if (this->my_board.Trasform_enum_to_CityObj(elem).color == c)
        {
            temp_set.insert(elem);
            //check if there is alredy enough cards//
            if (temp_set.size() == number_for_cure)
            {
                break;
            }
        }
    }    
        //check if there is enough cards if true delete them from the player hand
        //and update that a cure is found//
        if(temp_set.size() == number_for_cure)
        {
            for (auto elem : temp_set)
            {
            this->cards.erase(elem);
            }
            this->my_board.cures.insert(c);
            return *this;
        }
        //no enough cards with the right color 
        throw std::invalid_argument("not enough cards with the right color\n");
        return *this;  
}
}