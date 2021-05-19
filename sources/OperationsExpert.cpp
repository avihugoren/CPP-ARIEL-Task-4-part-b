
#include "OperationsExpert.hpp"
 namespace pandemic{
OperationsExpert& OperationsExpert::build ()
{
    this->my_board(this->my_city) = true;
    
    return *this;

}
}