
#include "Researcher.hpp"
 namespace pandemic{
Researcher& Researcher:: discover_cure(Color c)
{
    if (this->my_board.cures.find(c)!= this->my_board.cures.end())
    {
        return *this;
    }
    set<City> temp_set;
    for (auto elem : this->cards)
    {
        if (this->my_board.Trasform_enum_to_CityObj(elem).color == c)
        {
            temp_set.insert(elem);
            if (temp_set.size() == number_for_cure)
            {
                break;
            }
        }
    }    
        if(temp_set.size() == number_for_cure)
        {
            for (auto elem : temp_set)
            {
            this->cards.erase(elem);
            }
            this->my_board.cures.insert(c);
            return *this;
        }
        throw std::invalid_argument("not enough cards in with color\n");
        return *this;  
}
}