#ifndef CONDIMENTDECORATOR_H
#define CONDIMENTDECORATOR_H

#include "Condiment.h"
#include <string>

class CondimentDecorator : public Condiment {
protected:
    Condiment* condiment;

public:
    CondimentDecorator(Condiment* condiment) : Condiment(condiment->getName(), nullptr), condiment(condiment) {}
    ~CondimentDecorator() { delete condiment; }

    std::string getName() const override { return condiment->getName(); }
    std::string applyFeature() const override { return condiment->applyFeature(); }
    void setPrice(double p) override { condiment->setPrice(p); }
    double getPrice() const override { return condiment->getPrice(); }
};

#endif
