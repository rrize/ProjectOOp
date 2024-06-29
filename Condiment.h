#ifndef CONDIMENT_H
#define CONDIMENT_H

#include <string>
#include "Feature.h"

class Condiment {
private:
    std::string name;
    Feature* feature;
    double price;

public:
    Condiment(const std::string& name, Feature* feature) : name(name), feature(feature), price(0.0) {}
    virtual ~Condiment() { delete feature; }

    virtual std::string getName() const { return name; }
    virtual std::string applyFeature() const { return feature->applyFeature(); }
    virtual void setPrice(double p) { price = p; }
    virtual double getPrice() const { return price; }

    void setFeature(Feature* newFeature) {
        delete feature;
        feature = newFeature;
    }
};

#endif // CONDIMENT_H
