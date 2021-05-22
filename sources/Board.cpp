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
         ostream& pandemic::operator<<(ostream& output, const Board& board)
        {
                map<City,string> trasform_City_to_string;
                map<Color,string> trasform_Color_to_string;
                trasform_City_to_string[City::Atlanta]="Atlanta";
                trasform_City_to_string[City::Baghdad]="Baghdad";
                trasform_City_to_string[City::Bangkok]="Bangkok";
                trasform_City_to_string[City::Beijing]="Beijing";
                trasform_City_to_string[City::Bogota]="Bogota";
                trasform_City_to_string[City::BuenosAires]="BuenosAires";
                trasform_City_to_string[City::Chennai]="Chennai";
                trasform_City_to_string[City::Cairo]="Cairo";
                trasform_City_to_string[City::Delhi]="Delhi";
                trasform_City_to_string[City::Essen]="Essen";
                trasform_City_to_string[City::HongKong]="HongKong";
                trasform_City_to_string[City::Istanbul]="Istanbul";
                trasform_City_to_string[City::Algiers]="Algiers";
                trasform_City_to_string[City::Jakarta]="Jakarta";
                trasform_City_to_string[City::Johannesburg]="Johannesburg";
                trasform_City_to_string[City::Karachi]="Karachi";
                trasform_City_to_string[City::Khartoum]="Khartoum";
                trasform_City_to_string[City::Kinshasa]="Kinshasa";
                trasform_City_to_string[City::Kolkata]="Kolkata";
                trasform_City_to_string[City::Lagos]="Lagos";
                trasform_City_to_string[City::Lima]="Lima";
                trasform_City_to_string[City::London]="London";
                trasform_City_to_string[City::LosAngeles]="LosAngeles";
                trasform_City_to_string[City::Madrid]="Madrid";
                trasform_City_to_string[City::Chicago]="Chicago";
                trasform_City_to_string[City::Manila]="Manila";
                trasform_City_to_string[City::Washington]="Washington";
                trasform_City_to_string[City::MexicoCity]="MexicoCity";
                trasform_City_to_string[City::HoChiMinhCity]="HoChiMinhCity";
                trasform_City_to_string[City::Miami]="Miami";
                trasform_City_to_string[City::Milan]="Milan";
                trasform_City_to_string[City::Montreal]="Montreal";
                trasform_City_to_string[City::Moscow]="Moscow";
                trasform_City_to_string[City::Mumbai]="Mumbai";
                trasform_City_to_string[City::NewYork]="NewYork";
                trasform_City_to_string[City::Shanghai]="Shanghai";
                trasform_City_to_string[City::Osaka]="Osaka";
                trasform_City_to_string[City::Paris]="Paris";
                trasform_City_to_string[City::Riyadh]="Riyadh";
                trasform_City_to_string[City::SanFrancisco]="SanFrancisco";
                trasform_City_to_string[City::Santiago]="Santiago";
                trasform_City_to_string[City::SaoPaulo]="SaoPaulo";
                trasform_City_to_string[City::Seoul]="Seoul";
                trasform_City_to_string[City::StPetersburg]="StPetersburg";
                trasform_City_to_string[City::Sydney]="Sydney";
                trasform_City_to_string[City::Taipei]="Taipei";
                trasform_City_to_string[City::Tehran]="Tehran";
                trasform_City_to_string[City::Tokyo]="Tokyo";
                trasform_Color_to_string[Color::Red]="Red";
                trasform_Color_to_string[Color::Black]="Black";
                trasform_Color_to_string[Color::Blue]="Blue";
                trasform_Color_to_string[Color::Yellow]="Yellow";
                set<string>stations;
            for ( const auto &p : board.cities ) 
            {
                CityObj temp = p.second;
                output<<trasform_City_to_string.at(p.first)<<" disease lvl:"<<temp.disease_lvl()<<endl;
                if (temp.station)
                {
                   stations.insert(trasform_City_to_string.at(p.first));
                }
            }
            output <<"Stations: ";
            for ( const auto &p : stations) 
            {
              cout<<p<<" ";
            }
            cout<<endl;
            output << "Cures:";
            for ( const auto &p : board.cures) 
            {
                output << trasform_Color_to_string.at(p)<<" ";
            }
            output<<endl;
                return output;
        }
       
        
