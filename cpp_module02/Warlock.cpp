#include "Warlock.hpp"

Warlock::Warlock(const std::string& name, const std::string& title)
    : _name(name), _title(title), _spellBook(new SpellBook())
{
    std::cout << _name << ": This looks like another boring day." << std::endl;
}

Warlock::~Warlock() {
    std::cout << _name << ": My job here is done!" << std::endl;
    delete _spellBook;
}


Warlock::Warlock(const Warlock& other)
    : _name(other._name), _title(other._title)
{
}

Warlock& Warlock::operator=(const Warlock& other) {
    if (this != &other) {
        _name = other._name;
        _title = other._title;
    }
    return (*this);
}

const std::string& Warlock::getName() const {
    return (_name);
}

const std::string& Warlock::getTitle() const {
    return (_title);
}

void Warlock::setTitle(const std::string& title) {
    _title = title;
}

void	Warlock::introduce() const
{
	std::cout << _name << ": I am " << _name << ", " << _title << "!" << std::endl;
}

void Warlock::learnSpell(ASpell* spell) {
    _spellBook->learnSpell(spell);
    // if (spell && _spell_map.find(spell->getName()) == _spell_map.end()) {
    //     _spell_map[spell->getName()] = spell;
    // }
}

void Warlock::forgetSpell(std::string spell) {
    _spellBook->forgetSpell(spell);
    // if (_spell_map.find(spell) != _spell_map.end()) {
    //     _spell_map.erase(_spell_map.find(spell));
    // }
}

void Warlock::launchSpell(std::string spell_name, const ATarget& target) {
    ASpell* spell = _spellBook->createSpell(spell_name);
    if (spell) {
        spell->launch(target);
    }
}