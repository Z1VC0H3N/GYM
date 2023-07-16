//
// Created by Owner on 23/11/2021.
//

#ifndef UNTITLED_MOVECUSTOMER_H
#define UNTITLED_MOVECUSTOMER_H


#include "Action.h"

class MoveCustomer : public BaseAction {
public:
    MoveCustomer(int src, int dst, int customerId);
    void act(Studio &studio);
    std::string toString() const;
    BaseAction* clone();
    MoveCustomer::~MoveCustomer();
private:
    const int srcTrainer;
    const int dstTrainer;
    const int id;
};


#endif //UNTITLED_MOVECUSTOMER_H
