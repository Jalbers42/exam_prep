#pragma once

#include "ATarget.hpp"
#include <map>

class TargetGenerator {

    private:
        std::map<std::string, ATarget*>  _targetBook;
        TargetGenerator(const TargetGenerator& other);
        TargetGenerator& operator=(const TargetGenerator& other);


    public:
        TargetGenerator();
        ~TargetGenerator();
        void learnTargetType(ATarget* target);
        void forgetTargetType(const std::string& target_name);
        ATarget* createTarget(const std::string& target_name);

};