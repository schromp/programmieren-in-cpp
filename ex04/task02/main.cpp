#include <iostream>

/*
* === Add your code here, implement MAKEVAR macro
*/


/**
* @brief creates a variable of given type with getter and setter methods
*
* Because the macro generates code at compile time type is being replaced with the given keyword
* and name with the given name
*
* set_##name is being used to generate the setter method. this is needed because we dont know the name
* of the variable and have to generate this dynamicly
*
* @param name the name of the variable
* @param type the type of the variable 
*
*/
#define MAKEVAR(name, type) type name; \
    void set_##name (type val) {name = val;} \
    type get_##name (void) {return name;}

MAKEVAR(weight, int)
MAKEVAR(price, float)

int main(void) {
  set_weight(100);
  set_price(1.25);
  std::cout << "Weight: " << get_weight() << ", Price: " << get_price() << std::endl;
}
