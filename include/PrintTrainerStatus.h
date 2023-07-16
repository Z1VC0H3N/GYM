//
// Created by Owner on 23/11/2021.
//

#ifndef UNTITLED_PRINTTRAINERSTATUS_H
#define UNTITLED_PRINTTRAINERSTATUS_H


#include "Action.h"
using namespace std;
class PrintTrainerStatus : public BaseAction {
public:
    PrintTrainerStatus(int id);
    void act(Studio &studio);
    std::string toString() const;
    BaseAction* clone();
    PrintTrainerStatus::~PrintTrainerStatus();
private:
    const int trainerId;
};


#endif //UNTITLED_PRINTTRAINERSTATUS_H
