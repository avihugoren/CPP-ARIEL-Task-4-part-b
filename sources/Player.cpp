#include "Player.hpp"
 namespace pandemic{
       
        // Player::Player(const Board& b,const City c)
        // {
        //     this->my_board = b;
        //     CityObj city = this->my_board.Trasform_enum_to_CityObj(c);
        //     this->curr_city= city;
  
        // }

        Player::Player(Board& b, City c):my_board(b),curr_city(b.Trasform_enum_to_CityObj(c)),my_city(c){}
        Player & Player::take_card( City c)
        {   
            this->cards.insert(c);
            return *this;
        }
         Player & Player::discover_cure(Color c)
        {
             if (!this->my_board(my_city))
             {
                 throw std::invalid_argument("there is no station on this city\n");
             }
             if (this->my_board.cures.find(c)!= this->my_board.cures.end())
             {
                 return *this;
             }
             set<City> temp_set;
             for (const auto elem : this->cards)
             {
                 if (my_board.Trasform_enum_to_CityObj(elem).color == c)
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
                 for (const auto elem : temp_set)
                 {
                     this->cards.erase(elem);
                 }
                 this->my_board.cures.insert(c);
                 return *this;;
             }
             throw std::invalid_argument("not enough cards in with color\n");  
             return *this;//shouldnt get here
             
        }
         Player& Player::drive (City c)
        {
            if (this->my_city == c)
             {
                throw std::invalid_argument("cant drive from city to itself\n");
             }
            if (!this->my_board.is_neighbors(this->my_city,c))
            {
                throw std::invalid_argument("Cities not neighbor\n");
            }
                 this->my_city = c;
                 return *this;
        }
         Player& Player::fly_direct(City c)
        {
            if (this->my_city == c)
             {
                throw std::invalid_argument("cant fly from city to itself\n");
             }
            if(this->cards.find(c) == this->cards.end())
            {
                throw std::invalid_argument("trying to fly direct but dosnt have the card\n");
            }
            this->cards.erase(c);
            this->my_city = c;
            return *this;

        }
         Player& Player::fly_charter (City c)
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
            // this->curr_city=this->my_board.Trasform_enum_to_CityObj(c);
            this->my_city = c;
            return *this;
        }
         Player& Player::fly_shuttle (City c)
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
        //    this->curr_city=this->my_board.Trasform_enum_to_CityObj(c);
           this->my_city = c;
           return *this;
         }
         Player& Player::treat(City city)
         {
             if (this->my_city != city)
             {
                 throw std::invalid_argument("not at the city cant treat \n");
             }
             if (this->my_board.Trasform_enum_to_CityObj(city).disease_lvl() == 0)
             {
                throw std::invalid_argument("city diseese lvl is 0 \n");
             }
             if(this->my_board.cures.find(this->my_board.Trasform_enum_to_CityObj(city).color) != this->my_board.cures.end())
             {
                 this->my_board.Trasform_enum_to_CityObj(city).disease_lvl()=0;
                 return *this;
             }
            
                this->my_board.Trasform_enum_to_CityObj(city).disease_lvl()--;
                return *this;
             
         }
        Player& Player::build()

        {
             if(this->my_board(this->my_city))//alredy have station
            {
                return *this;
            }
            if(this->cards.find(this->my_city) == this->cards.end())//try to build but dosnt have city card
            {
                
                throw std::invalid_argument("try to build but dont have the card\n");
            }
            
           
            this->my_board(this->my_city) = true;
            this->cards.erase(this->my_city);
            return *this;
        }
      std::string  Player:: role(){return "Player";}

}
        //  Player& Player::treat(const City&){return *this;}