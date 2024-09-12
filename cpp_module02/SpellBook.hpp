#pragma once

#include "ASpell.hpp"
#include <map>

class SpellBook {
    private:
        std::map<std::string, ASpell*>  _spellBook;
        SpellBook(const SpellBook& other);
        SpellBook& operator=(const SpellBook& other);

    public:
        SpellBook();
        ~SpellBook();
        void learnSpell(ASpell* spell);
        void forgetSpell(const std::string& spell_name);
        ASpell* createSpell(const std::string& spell_name);
};