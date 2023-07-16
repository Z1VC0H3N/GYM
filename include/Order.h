//
// Created by Owner on 23/11/2021.
//

#ifndef UNTITLED_ORDER_H
#define UNTITLED_ORDER_H


#include "Studio.h"

class Order : public BaseAction {
public:
    Order(int id);
    void act(Studio &studio);
    std::string toString() const;
    BaseAction* clone();
    Order::~Order();
private:
    const int trainerId;
};


#endif //UNTITLED_ORDER_H
