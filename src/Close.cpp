//
// Created by Owner on 23/11/2021.
//

#include <sstream>
#include "../include/Close.h"
#include "../include/Trainer.h"
using namespace std;
Close::Close(int id) : trainerId(id) {

}

void Close::act(Studio &studio) {
    Trainer *trainer = studio.getTrainer(trainerId);
    if ((trainer == nullptr) | !trainer->isOpen()) {
        error("Trainer does not exist or is not open");
    }
    else {
        if(trainer->getCustomers().size()!=0) {
            cout << "Trainer" << " " << trainerId << " " << "closed. Salary" << " " << trainer->getSalary() << "NIS"
                 << endl;
            trainer->closeTrainer();
            complete();
        }
    }
}

std::string Close::toString() const {

        string output = "";
        string Trainerid;
        output = output + "close";
        string revah = " ";
        stringstream trainerid;
        trainerid << trainerId;
        output = output + revah;
        trainerid >> Trainerid;
        output=output+Trainerid;
        return output;
    }

BaseAction *Close::clone() {
    return new Close(*this);
}

Close::~Close() = default;

