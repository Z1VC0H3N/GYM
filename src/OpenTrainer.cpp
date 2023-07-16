//
// Created by Owner on 23/11/2021.
//

#include "../include/OpenTrainer.h"
#include "../include/Trainer.h"
#include <sstream>
using namespace std;
OpenTrainer::OpenTrainer(int id, std::vector<Customer *> &customersList) : trainerId(id), customers(customersList) {

}

void OpenTrainer::act(Studio &studio) {
    Trainer *trainer = studio.getTrainer(trainerId);
    if ((trainer == nullptr) || trainer->isOpen()) {
        error("Workout session does not exist or is already open");
    }
    else {
        trainer->openTrainer();
        complete();
    }
}

std::string OpenTrainer::toString() const {
    if (getErrorMsg() == "Workout session does not exist or is already open") {
        return getErrorMsg();
    } else {
        string output = "open";
        string Trainerid;
        stringstream ss;
        ss << trainerId;
        ss >> Trainerid;
        output=output+Trainerid;
        for (int i = 0; i < customers.size(); i++) {
            output += + " " + customers[i]->getName() + "," + customers[i]->toString();
        }
        return output;
    }
}


OpenTrainer::~OpenTrainer() {
for(Customer *customer:customers){
    delete customer;
}
customers.clear();
}

BaseAction *OpenTrainer::clone() {
    return new OpenTrainer(*this);
}
