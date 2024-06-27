#ifndef RELISH_H
#define RELISH_H

#include "Condiment.h"

class Relish : public Condiment {
public:
    std::string getName() const override;
};

#endif
