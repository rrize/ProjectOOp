#include "Ketchup.h"
#include "Mustard.h"
#include "Relish.h"
#include "Inventory.h"
#include <iostream>

int main() {
    Inventory inventory;

    inventory.addCondiment(new Ketchup());
    inventory.addCondiment(new Mustard());
    inventory.addCondiment(new Relish());

    std::cout << "Condiments in inventory:" << std::endl;
    inventory.listCondiments();

    return 0;
}
