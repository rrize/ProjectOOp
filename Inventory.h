#ifndef INVENTORY_H
#define INVENTORY_H

#include "Condiment.h"
#include <vector>

class Inventory {
private:
    std::vector<Condiment*> condiments;

public:
    ~Inventory();
    void addCondiment(Condiment* condiment);
    void removeCondiment(const std::string &name);
    void listCondiments() const;
};

#endif
