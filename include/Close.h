//
// Created by Owner on 23/11/2021.
//

#ifndef UNTITLED_CLOSE_H
#define UNTITLED_CLOSE_H


#include "Action.h"

class Close : public BaseAction {
public:
    Close(int id);
    void act(Studio &studio);
    std::string toString() const;
    BaseAction* clone();
    Close::~Close();
private:
    const int trainerId;
};


#endif //UNTITLED_CLOSE_H
