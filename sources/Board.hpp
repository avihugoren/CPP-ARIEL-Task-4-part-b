#pragma once
#include "City.hpp"
#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <set>
#include <map>
#include <vector>
#include "Color.hpp"
// #include "Player.hpp"
#include "CityObj.hpp"
using namespace std;

namespace pandemic 
{
    class Board {
    private:
            static City Trasform_string_to_enum(std::string city_name)
            {
                if (Board::trasform_map.find(city_name)== Board::trasform_map.end())
                {
                    throw("wrong city name");
                }
                return Board::trasform_map.at(city_name);
            }
    public:
            map<City,set<City>>neighbors;
            map<City,CityObj> cities;
            set<Color> cures;
            
            //maps to trasform string to enums//
            inline static map <std::string,City>trasform_map;
            inline static map <std::string,Color>Color_trasform_map;
            
            //function that gets to Citys enums and return true if and only if they are neighbors
            bool is_neighbors (City source,City Target)
            {
                if(this->neighbors.at(source).find(Target)==this->neighbors.at(source).end())
                {
                    return false;
                }
                return true;
            }
            
            Board(); 

            ~Board(){}

            //return refernce to city disease lvl//
            int& operator[](City city);

            //return refernce to city bool flag that indicate if it has station//
            bool& operator()(City city);

            void remove_cures();

            void remove_stations();
          
            bool is_clean();

            friend ostream& operator<<(ostream& output, const Board& b);
            
            CityObj& Trasform_enum_to_CityObj(City city_name);
            
            Color Trasform_string_to_Color(std::string color)
            {
                return this->Color_trasform_map[color];
            }
             void initialize_trasform_map()
            
            {
                pandemic::Board::trasform_map["Atlanta"]=City::Atlanta;
                pandemic::Board::trasform_map["Baghdad"]=City::Baghdad;
                pandemic::Board::trasform_map["Bangkok"]=City::Bangkok;
                pandemic::Board::trasform_map["Beijing"]=City::Beijing;
                pandemic::Board::trasform_map["Bogota"]=City::Bogota;
                pandemic::Board::trasform_map["BuenosAires"]=City::BuenosAires;
                pandemic::Board::trasform_map["Chennai"]=City::Chennai;
                pandemic::Board::trasform_map["Cairo"]=City::Cairo;
                pandemic::Board::trasform_map["Delhi"]=City::Delhi;
                pandemic::Board::trasform_map["Essen"]=City::Essen;
                pandemic::Board::trasform_map["HongKong"]=City::HongKong;
                pandemic::Board::trasform_map["Istanbul"]=City::Istanbul;
                pandemic::Board::trasform_map["Algiers"]=City::Algiers;
                pandemic::Board::trasform_map["Jakarta"]=City::Jakarta;
                pandemic::Board::trasform_map["Johannesburg"]=City::Johannesburg;
                pandemic::Board::trasform_map["Karachi"]=City::Karachi;
                pandemic::Board::trasform_map["Khartoum"]=City::Khartoum;
                pandemic::Board::trasform_map["Kinshasa"]=City::Kinshasa;
                pandemic::Board::trasform_map["Kolkata"]=City::Kolkata;
                pandemic::Board::trasform_map["Lagos"]=City::Lagos;
                pandemic::Board::trasform_map["Lima"]=City::Lima;
                pandemic::Board::trasform_map["London"]=City::London;
                pandemic::Board::trasform_map["LosAngeles"]=City::LosAngeles;
                pandemic::Board::trasform_map["Madrid"]=City::Madrid;
                pandemic::Board::trasform_map["Chicago"]=City::Chicago;
                pandemic::Board::trasform_map["Manila"]=City::Manila;
                pandemic::Board::trasform_map["Washington"]=City::Washington;
                pandemic::Board::trasform_map["MexicoCity"]=City::MexicoCity;
                pandemic::Board::trasform_map["HoChiMinhCity"]=City::HoChiMinhCity;
                pandemic::Board::trasform_map["Miami"]=City::Miami;
                pandemic::Board::trasform_map["Milan"]=City::Milan;
                pandemic::Board::trasform_map["Montreal"]=City::Montreal;
                pandemic::Board::trasform_map["Moscow"]=City::Moscow;
                pandemic::Board::trasform_map["Mumbai"]=City::Mumbai;
                pandemic::Board::trasform_map["NewYork"]=City::NewYork;
                pandemic::Board::trasform_map["Shanghai"]=City::Shanghai;
                pandemic::Board::trasform_map["Osaka"]=City::Osaka;
                pandemic::Board::trasform_map["Paris"]=City::Paris;
                pandemic::Board::trasform_map["Riyadh"]=City::Riyadh;
                pandemic::Board::trasform_map["SanFrancisco"]=City::SanFrancisco;
                pandemic::Board::trasform_map["Santiago"]=City::Santiago;
                pandemic::Board::trasform_map["SaoPaulo"]=City::SaoPaulo;
                pandemic::Board::trasform_map["Seoul"]=City::Seoul;
                pandemic::Board::trasform_map["StPetersburg"]=City::StPetersburg;
                pandemic::Board::trasform_map["Sydney"]=City::Sydney;
                pandemic::Board::trasform_map["Taipei"]=City::Taipei;
                pandemic::Board::trasform_map["Tehran"]=City::Tehran;
                pandemic::Board::trasform_map["Tokyo"]=City::Tokyo;
                pandemic::Board::Color_trasform_map["Red"]=Color::Red;
                pandemic::Board::Color_trasform_map["Black"]=Color::Black;
                pandemic::Board::Color_trasform_map["Blue"]=Color::Blue;
                pandemic::Board::Color_trasform_map["Yellow"]=Color::Yellow;
            }
        

    };        
}  