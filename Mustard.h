#ifndef MUSTARD_H
#define MUSTARD_H

#include "Condiment.h"

class Mustard : public Condiment {
public:
    std::string getName() const override;
};

#endif
