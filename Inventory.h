#ifndef INVENTORY_H
#define INVENTORY_H

#include "Condiment.h"
#include <vector>
#include <string>

class Inventory {
private:
    std::vector<Condiment*> condiments;

public:
    ~Inventory();
    void addCondiment(Condiment* condiment);
    void removeCondiment(const std::string &name);
    void listCondiments() const;
    void orderCondiment(const std::string &name);
    void setCondimentPrice(const std::string &name, double price);
    void setCondimentFeature(const std::string &name, Feature* feature);
    const std::vector<Condiment*>& getCondiments() const;
};

#endif // INVENTORY_H
