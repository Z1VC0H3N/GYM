//
// Created by Owner on 23/11/2021.
//

#ifndef UNTITLED_OPENTRAINER_H
#define UNTITLED_OPENTRAINER_H
#include "Action.h"

class OpenTrainer : public BaseAction {
public:
    OpenTrainer(int id, std::vector<Customer *> &customersList);
    void act(Studio &studio);
    std::string toString() const override;
    BaseAction* clone();
    OpenTrainer::~OpenTrainer();
private:
    const int trainerId;
    std::vector<Customer *> customers;
};


#endif //UNTITLED_OPENTRAINER_H
