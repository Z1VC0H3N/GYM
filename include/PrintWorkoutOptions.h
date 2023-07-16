//
// Created by Owner on 23/11/2021.
//

#ifndef UNTITLED_PRINTWORKOUTOPTIONS_H
#define UNTITLED_PRINTWORKOUTOPTIONS_H


#include "Action.h"
using namespace std;
class PrintWorkoutOptions : public BaseAction {
public:
    PrintWorkoutOptions();
    void act(Studio &studio);
    std::string toString() const;
    BaseAction* clone();
    PrintWorkoutOptions::~PrintWorkoutOptions();
private:
};


#endif //UNTITLED_PRINTWORKOUTOPTIONS_H
