#pragma once

#include "ASpell.hpp"

class Polymorph : public ASpell {
    private:

    public:
        Polymorph();
        ~Polymorph();

        ASpell *clone() const;

};