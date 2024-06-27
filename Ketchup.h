#ifndef KETCHUP_H
#define KETCHUP_H

#include "Condiment.h"

class Ketchup : public Condiment {
public:
    std::string getName() const override;
};

#endif
