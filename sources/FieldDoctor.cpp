#include "FieldDoctor.hpp"
 namespace pandemic{
std::string FieldDoctor:: role() 
{
    return "FieldDoctor";
}
FieldDoctor& FieldDoctor::treat(City city)
{
    if (this->my_city != city)
     {
        //Checks if the cities are neighbors//
        if(!this->my_board.is_neighbors(city,this->my_city))
        {
            throw std::invalid_argument("not at the city cant treat and not neighbors \n");
        }
        }
        if (this->my_board[city]==0)
        {
            throw std::invalid_argument("city diseese lvl is 0 \n");
        }
        //If there is already a cure//
        if(this->my_board.cures.find(this->my_board.Trasform_enum_to_CityObj(city).color) != this->my_board.cures.end())
        {
            this->my_board[city]=0;
        }
        else
        {
            this->my_board[city]-=1;
        }
        return *this;     
        }
 }