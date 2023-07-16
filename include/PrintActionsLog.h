//
// Created by Owner on 23/11/2021.
//

#ifndef UNTITLED_PRINTACTIONSLOG_H
#define UNTITLED_PRINTACTIONSLOG_H


#include "Action.h"

class PrintActionsLog : public BaseAction {
public:
    PrintActionsLog();
    void act(Studio &studio);
    std::string toString() const;
    BaseAction* clone();
    PrintActionsLog::~PrintActionsLog();
private:
};


#endif //UNTITLED_PRINTACTIONSLOG_H
