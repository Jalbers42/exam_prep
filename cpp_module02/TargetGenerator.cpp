#include "TargetGenerator.hpp"

TargetGenerator::TargetGenerator() {

}

TargetGenerator::~TargetGenerator() {
    for (std::map<std::string, ATarget*>::iterator it = _targetBook.begin(); it != _targetBook.begin(); it++) {
        delete it->second;
    }
    _targetBook.clear();
}

TargetGenerator::TargetGenerator(const TargetGenerator& other)
    : _targetBook(other._targetBook)
{
}

TargetGenerator& TargetGenerator::operator=(const TargetGenerator& other) {
    if (this != &other) {
        _targetBook = other._targetBook;
    }
    return (*this);
}

void TargetGenerator::learnTargetType(ATarget* target) {
    if (_targetBook.find(target->getType()) == _targetBook.end()) {
        _targetBook[target->getType()] = target->clone();
        // _targetBook[target->getName()] = target;
    }
}

void TargetGenerator::forgetTargetType(const std::string& target_name) {
    if (_targetBook.find(target_name) != _targetBook.end()) {
        delete _targetBook[target_name];
        _targetBook.erase(_targetBook.find(target_name));
    }
}

ATarget* TargetGenerator::createTarget(const std::string& target_name) {
    if (_targetBook.find(target_name) != _targetBook.end()) {
        return (_targetBook[target_name]);
        // return (_targetBook[target_name]);
    }
    return (NULL);
}