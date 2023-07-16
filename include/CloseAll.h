//
// Created by Owner on 23/11/2021.
//

#ifndef UNTITLED_CLOSEALL_H
#define UNTITLED_CLOSEALL_H


#include "Action.h"
using namespace std;
class CloseAll : public BaseAction {
public:
    CloseAll();
    void act(Studio &studio);
    std::string toString() const;
    BaseAction* clone();
    CloseAll::~CloseAll();
private:
};


#endif //UNTITLED_CLOSEALL_H
