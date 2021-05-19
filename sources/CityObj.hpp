#pragma once
#include <map>
#include <set>
#include <string.h>
#include "City.hpp"
#include "Color.hpp"

using namespace std;

namespace pandemic {
 class CityObj 
 {
    private:
            
            int disease;
           
            
    public:
            Color color;
            bool station;
            CityObj(Color city_color,City city);
            ~CityObj(){}
            CityObj(){}
            bool& is_there_station(){return this->station;}
            int& disease_lvl(){return this->disease;}
            
 };       
}