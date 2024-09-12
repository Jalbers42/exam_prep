#include "SpellBook.hpp"

SpellBook::SpellBook() {

}

SpellBook::~SpellBook() {
    for (std::map<std::string, ASpell*>::iterator it = _spellBook.begin(); it != _spellBook.begin(); it++) {
        delete it->second;
    }
    _spellBook.clear();
}

SpellBook::SpellBook(const SpellBook& other)
    : _spellBook(other._spellBook)
{
}

SpellBook& SpellBook::operator=(const SpellBook& other) {
    if (this != &other) {
        _spellBook = other._spellBook;
    }
    return (*this);
}

void SpellBook::learnSpell(ASpell* spell) {
    if (_spellBook.find(spell->getName()) == _spellBook.end()) {
        _spellBook[spell->getName()] = spell->clone();
        // _spellBook[spell->getName()] = spell;
    }
}

void SpellBook::forgetSpell(const std::string& spell_name) {
    if (_spellBook.find(spell_name) != _spellBook.end()) {
        delete _spellBook[spell_name];
        _spellBook.erase(_spellBook.find(spell_name));
    }
}

ASpell* SpellBook::createSpell(const std::string& spell_name) {
    if (_spellBook.find(spell_name) != _spellBook.end()) {
        return (_spellBook[spell_name]);
        // return (_spellBook[spell_name]);
    }
    return (NULL);
}