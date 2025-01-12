#pragma once

#include <iostream>
#include "ASpell.hpp"

class ASpell;

class ATarget {
    private:

    protected:
        std::string _type;

    public:
        ATarget(const std::string& type);
        ATarget(const ATarget& other);
        ATarget& operator=(const ATarget& other);
        virtual ~ATarget();
        const std::string& getType() const;
        virtual ATarget* clone() const = 0;
        void getHitBySpell(const ASpell& spell) const;
};