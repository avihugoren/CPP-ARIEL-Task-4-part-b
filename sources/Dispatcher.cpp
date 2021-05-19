
#include "Dispatcher.hpp"
namespace pandemic{
 Dispatcher& Dispatcher:: fly_direct(City city)
 {
     //cant fly from city to itself//
     if (this->my_city == city)
    {
        throw std::invalid_argument("cant fly from city to itself\n");
    } 
    //if there is station inside my city//       
    if(this->my_board(this->my_city))
    {
         this->my_city = city;
         return *this;
    }
    //there is no station so need card to fly direct so if i dont have one throw invalid_argument
    if(this->cards.find(city) == this->cards.end())
    {
        throw std::invalid_argument("trying to fly direct but dosnt have the card\n");
    }
    this->cards.erase(city);
    this->my_city=city;
    return *this;  

 }
}