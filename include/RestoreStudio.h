//
// Created by Owner on 23/11/2021.
//

#ifndef UNTITLED_RESTORESTUDIO_H
#define UNTITLED_RESTORESTUDIO_H


#include "Action.h"

class RestoreStudio : public BaseAction {
public:
    RestoreStudio();
    void act(Studio &studio);
    std::string toString() const;
    BaseAction* clone();
    RestoreStudio::~RestoreStudio();
};


#endif //UNTITLED_RESTORESTUDIO_H
