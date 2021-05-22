#include "Player.hpp"
 namespace pandemic{
        Player::Player(Board& b, City c):my_board(b),my_city(c)
        {
        //  this->my_board.players.push_back(this);
        }

        Player & Player::take_card( City c)
        {   
            this->cards.insert(c);
            return *this;
        }

         Player & Player::discover_cure(Color c)
        {
             //There is no station at this city so cant dicover cure here//
             if (!this->my_board(my_city))
             {
                 throw std::invalid_argument("there is no station on this city\n");
             }
             //There is already a cure for this color//
             if (this->my_board.cures.find(c)!= this->my_board.cures.end())
             {
                 return *this;
             }
             //Temp set to hold the cards//
             set<City> temp_set;
             for (const auto elem : this->cards)
             {
                 //If the cards has the right color (of the disease)
                 if (my_board.Trasform_enum_to_CityObj(elem).color == c)
                 {
                     temp_set.insert(elem);
                     //Checks if there is enough cards
                     if (temp_set.size() == number_for_cure)
                     {
                        break;
                     }
                 }
             }     
             //if there is enough cards delete them from the player cards//
             if(temp_set.size() == number_for_cure)
             {
                 for (const auto elem : temp_set)
                 {
                     this->cards.erase(elem);
                 }
                 //update that a cure is found//
                 this->my_board.cures.insert(c);
                 return *this;;
             }
             //There wasnt enough cards with the right color// 
             throw std::invalid_argument("There wasnt enough cards with the right color\n");  
             
        }

         Player& Player::drive (City c)
        {
            if (this->my_city == c)
             {
                throw std::invalid_argument("cant drive from city to itself\n");
             }
             //Checks if the city are neighbors//
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
            //Checks if the player got the cards for target city//
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
            //Checks if the player got the cards of his current city//
            if(this->cards.find(this->my_city) == this->cards.end())
            {
                throw std::invalid_argument("trying to fly charter but dosnt have the card\n");
            }
            this->cards.erase(this->my_city);
            this->my_city = c;
            return *this;
        }

         Player& Player::fly_shuttle (City c)
         {
             if (this->my_city == c)
             {
                throw std::invalid_argument("cant fly from city to itself\n");
             }
            //Check if there is station in current city// 
           if(!this->my_board(this->my_city))
           {
               throw std::invalid_argument("current city dosnt have station\n");
           }
            //Checks if target city has station//
           if(!this->my_board(c))
           {
               throw std::invalid_argument("target city dosnt have station\n");
           }
           this->my_city = c;
           return *this;
         }
         Player& Player::treat(City city)
         {
             if (this->my_city != city)
             {
                 throw std::invalid_argument("not at the city cant treat \n");
             }
            //Checks if city disease lvl is 0//
             if (this->my_board[city]== 0)
             {
                throw std::invalid_argument("city diseese lvl is 0 \n");
             }
            //Checks fi there is already a cure for this color//
             if(this->my_board.cures.find(this->my_board.Trasform_enum_to_CityObj(city).color) != this->my_board.cures.end())
             {
                 this->my_board[city]=0;
                 return *this;
             }

                this->my_board[city]--;
                return *this;
             
         }
        Player& Player::build()

        {
            //alredy have station//
             if(this->my_board(this->my_city))
            {
                return *this;
            }
            //try to build but dosnt have city card//
            if(this->cards.find(this->my_city) == this->cards.end())
            {
                
                throw std::invalid_argument("try to build but dont have the card\n");
            }
            
           
            this->my_board(this->my_city) = true;
            this->cards.erase(this->my_city);
            return *this;
        }
      std::string  Player:: role(){return "Player";}

}
