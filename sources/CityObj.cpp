#include "CityObj.hpp"

namespace pandemic
{

  CityObj::CityObj(Color city_color,City city)
  {
    this->color=city_color;
    this->disease=0;
    this->station = false;
  }
}
