#include <iostream>
#include "ASpell.hpp"
#include "ATarget.hpp"
#include "SpellBook.hpp"
#include <map>

class Warlock {
    private:
        std::string _name;
        std::string _title;
        SpellBook*  _spellBook;
        Warlock& operator=(const Warlock& other);
        Warlock(const Warlock& other);

    public:
        Warlock(const std::string& name, const std::string& title);
        ~Warlock();
        const std::string& getName() const;
        const std::string& getTitle() const;
        void setTitle(const std::string& title);
        void introduce() const;
        void learnSpell(ASpell* spell);
        void forgetSpell(std::string spell);
        void launchSpell(std::string spell_name, const ATarget& target);
};