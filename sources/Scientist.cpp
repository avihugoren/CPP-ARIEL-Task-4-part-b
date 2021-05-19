#include "Scientist.hpp"
using namespace pandemic;
Scientist:: Scientist(Board& board, City city,int num):Player(board, city)
{
    this->n_parm = num;
}
Scientist& Scientist:: discover_cure(Color c)
{
    if (!this->my_board(this->my_city))
    {
        throw std::invalid_argument("there is no station on this city scientist\n");
    }
    if (this->my_board.cures.find(c)!= this->my_board.cures.end())
    {
        return *this;
    }
    set<City> temp_set;
    for (const auto & elem : this->cards)
    {
        if (this->my_board.Trasform_enum_to_CityObj(elem).color== c)
        {
            temp_set.insert(elem);
            if (temp_set.size() == this->n_parm)
            {
                break;
            }
        }
    }
            if(temp_set.size() == this->n_parm)
            {
                for ( const auto &elem : temp_set)
                {
                    this->cards.erase(elem);
                }
                this->my_board.cures.insert(c);
                return *this;
            }
            throw std::invalid_argument("not enough cards in with color sci \n");  
}
