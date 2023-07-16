//
// Created by Owner on 23/11/2021.
//

#include "../include/PrintActionsLog.h"
#include "../include/Studio.h"
using namespace std;

PrintActionsLog::PrintActionsLog() {

}

void PrintActionsLog::act(Studio &studio) {
    string output="";
    vector<BaseAction *> actionslogvector = studio.getActionsLog();
    for (BaseAction *baseAction: actionslogvector) {
        if (baseAction->getStatus() == COMPLETED) {
            output = output + baseAction->toString()  + " " + "Completed";
        }
        else {
            string output;
            output = output + baseAction->toString() + getErrorMsg();
        }

    }
    cout<<output;
}

std::string PrintActionsLog::toString() const {
    return "log";
}

BaseAction *PrintActionsLog::clone() {
    return new PrintActionsLog(*this);
}

PrintActionsLog::~PrintActionsLog() = default;
