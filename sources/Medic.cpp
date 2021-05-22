
#include "Medic.hpp"
 namespace pandemic{
Medic & Medic::treat(City city)
{
    if (this->my_city != city)
             {
                 throw std::invalid_argument("not at the city cant treat \n");
             }
             if (this->my_board[city] == 0)
             {
                throw std::invalid_argument("city diseese lvl is 0 \n");
             }
                 this->my_board[city]=0;
                 return *this;
             }
             
Medic& Medic::drive ( City c)
{
    if (this->my_city == c)
    {
        throw std::invalid_argument("cant fly from city to itself\n");
    }
    if (!this->my_board.is_neighbors(this->my_city,c))
    {
        throw std::invalid_argument("Cities not neighbor\n");
    }
    this->my_city=c;
    if(this->my_board.cures.find(this->my_board.Trasform_enum_to_CityObj(c).color) != this->my_board.cures.end())
    {
        this->my_board[my_city] = 0;
    }
    return *this;
                


}
Medic& Medic:: fly_direct(City c)

{
    if (this->my_city == c)
    {
        throw std::invalid_argument("cant fly from city to itself\n");
    }
    if(this->cards.find(c) == this->cards.end())
   {
        throw std::invalid_argument("trying to fly direct but dosnt have the card\n");
   }
   //If there is a cure for this color//
   if(this->my_board.cures.find(this->my_board.Trasform_enum_to_CityObj(c).color) != this->my_board.cures.end())
    {
        this->my_board[c]=0;
    }
    this->cards.erase(c);
    this->my_city=c;
    return *this;
}
Medic& Medic::fly_charter (City c)

{
    if (this->my_city == c)
     {
        throw std::invalid_argument("cant fly from city to itself\n");
     }
     if(this->cards.find(this->my_city) == this->cards.end())
      {
          throw std::invalid_argument("trying to fly charter but dosnt have the card\n");
      }
      this->cards.erase(this->my_city);
      this->my_city=c;
      //If there is a cure for this color//
      if(this->my_board.cures.find(this->my_board.Trasform_enum_to_CityObj(c).color) != this->my_board.cures.end())
      {
            this->my_board[c]=0;
      }
      return *this;

}
Medic & Medic::fly_shuttle(City c)
{
    if (this->my_city == c)
    {
        throw std::invalid_argument("cant fly from city to itself\n");
    }
    if(!this->my_board(this->my_city))
    {
        throw std::invalid_argument("current city dosnt have station\n");
    }
    if(!this->my_board(c))
    {
        throw std::invalid_argument("target city dosnt have station\n");
    }
    //If there is a cure for this color//
    if(this->my_board.cures.find(this->my_board.Trasform_enum_to_CityObj(c).color) != this->my_board.cures.end())
    {
        this->my_board[c]=0;
    }
    this->my_city=c;
    return *this;
}
 }

