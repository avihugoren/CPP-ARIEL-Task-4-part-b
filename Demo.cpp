
#include "Board.hpp"
#include "City.hpp"
#include "Color.hpp"
#include "OperationsExpert.hpp"
#include "Researcher.hpp"
#include "Medic.hpp"
#include "Dispatcher.hpp"
#include "Virologist.hpp"

using namespace pandemic;

#include <iostream>
#include <stdexcept>
using namespace std;

int main() {
	// Initialize an empty board//
	Board board;
	cout<<"Print the board all disease lvl should be 0 no station and cures \n" <<board<<endl;
	// put 5 blue disease cubes in Madrid//  
	board[City::Madrid] = 5;   
	// put 1 black disease cubes in Delhi to 1// 
	board[City::Delhi] = 1;
	// put 4 yellow disease cubes in Bogota//      
	board[City::Bogota] = 4;
	 // put 1 red disease cube in HoChiMinhCity// 
	board[City::HoChiMinhCity] = 1;
	// put 1 black disease cube in Kolkata//
	board[City::Kolkata] = 1;
	// put 5 blue disease cubes in Montreal//
	board[City::Montreal]=5;       
	// initialize an "Researcher" in Algiers//
	Researcher researcher {board, City::Algiers};
	cout<<"Print the board after the disease level is changed \n" <<board<<endl;
	//give the Researcher 5 blue cards//  
	researcher.take_card(City::Washington)
	 .take_card(City::NewYork)
	 .take_card(City::Montreal)
	 .take_card(City::Chicago)
	 .take_card(City::SanFrancisco);
	 //researcher can discover cure even if there isnt a station at his city//
	 researcher.discover_cure(Color::Blue);
     cout<<"Blue cure is added to cures \n" <<board<<endl;
	Medic medic {board,City::Tokyo};
	 medic.take_card(City::Tokyo);
	 medic.fly_charter(City::Madrid);
	 cout<<"print madrid disease level should be zero because the Medic arrived madrid and blue cure is discoverd already.\n" <<"Madrid lvl: "<<board[City::Madrid]<<endl;
	 try{
       medic.treat(Madrid) ; 
     }
    catch (const exception& ex){
        cout << "Cant treat at madrid because disease level is Zero!" <<  endl;
     }
	 //operations_expert build//

	 OperationsExpert operations_expert{board,Bogota};
	 //operations_expert  build station at bogota dosnt need card//
	 operations_expert.build();

	 //Dispatcher fly_direct//
	 Dispatcher dispatcher{board,Bogota};
	 //can fly because there is a station in bogota 
	 dispatcher.fly_direct(City::Delhi);
	 dispatcher.treat(City::Delhi);
	 cout << "dispathcer treat Delhi. " << "Delhi lvl: " << board[Delhi] << endl;

	 //Virologist treat from other city//
	 Virologist virologist{board,City::Riyadh};
	 virologist.take_card(City::Montreal);
	 //virologist can treat even if his not in the city but he have the card of the target city//
	 virologist.treat(City::Montreal);
	 cout<<"montreal disease level after virologist treat should be 0 because there is already a cure for blue disease\n" <<"Montreal level: "<<board[City::Montreal]<<endl;

	 


}


	
	

