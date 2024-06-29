#ifndef RELISHFEATURE_H
#define RELISHFEATURE_H

#include "Feature.h"

class RelishFeature : public Feature {
public:
    std::string applyFeature() const override {
        return "Relish: Adding a sweet, tangy flavor.";
    }
};

#endif
