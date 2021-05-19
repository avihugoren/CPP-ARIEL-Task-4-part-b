#include "City.hpp"
#include "CityObj.hpp"
#include "Board.hpp"
#include <iostream>
#include <fstream>
using namespace std;

using namespace pandemic;
        
        Board::Board()
        {
            //set the map that trastlate from city string to city enum and from color string to color enum
            this->initialize_trasform_map();
            ifstream cities_map{"cities_map.txt"};
            string line;
            while(getline(cities_map, line))
            {
                
                stringstream ss(line);
                string City_name;
                string City_color_string;
                //just initialize//
                Color City_color_enum=Color::Black;
                string negihbor; 
                //first on the line is the city name//
                ss>>City_name;
                //second on the line is the city name//
                ss>>City_color_string;
                //function that change string to enum//
                City_color_enum = this->Trasform_string_to_Color(City_color_string);
                //build new CityObj with color enum and city enum//
                CityObj temp_city(City_color_enum,Trasform_string_to_enum(City_name));
                //set the will hold all the neighbors
                set<City>my_neighbors;
                //while that add all the negihbors
                while (ss >> negihbor)
                {
                    
                     my_neighbors.insert(pandemic::Board::Trasform_string_to_enum(negihbor));
                }
                //map in board that save all the citys with their neighbors<City,set<City>>
                this->neighbors[Trasform_string_to_enum(City_name)]=my_neighbors;
                //adds the CityObj to the map in board <City,CityObj>
                this->cities[Trasform_string_to_enum(City_name)]=temp_city;
                          
            }
        }
    
        int& Board::operator[](City city)
        {   
            //return reference to the city disease lvl
            return this->cities[city].disease_lvl();
        }
        bool& Board::operator()(City city)
        {
            //return reference to a bool field that indicate if the city has station in it
            return this->cities[city].is_there_station();
        }
        void Board::remove_cures()
        {
            this->cures.clear();
        }
        void Board::remove_stations()
        {
            std::map<City, CityObj>::iterator it = this->cities.begin();
                 while (it != this->cities.end())
                 {
                     this->cities[it->first].station=false;
                 }

        }
        bool Board::is_clean()
        {
            for ( const auto &p : this->cities ) 
            {
                CityObj temp = p.second;
                if(temp.disease_lvl() !=0)
                {
                    return false;
                }
            }
            return true;
        }
        CityObj& Board::Trasform_enum_to_CityObj(City city_name)
        {
            if (this->cities.find(city_name) == this->cities.end())
            {
                throw("didnt find enum to city\n");
            }
            return (this->cities[city_name]);
        }
         ostream& pandemic::operator<<(ostream& output, const Board& b)
        {
            return output;
        }
       
        
