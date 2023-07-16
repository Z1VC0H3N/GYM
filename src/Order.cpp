//
// Created by Owner on 23/11/2021.
//

#include "../include/Order.h"
#include <sstream>
using namespace std;
Order::Order(int id) : trainerId(id) {

}

void Order::act(Studio &studio) {
    Trainer *trainer = studio.getTrainer(trainerId);
    string output="";
    vector<Workout> workoutvector = studio.getWorkoutOptions();
    if ((trainer == nullptr) | !trainer->isOpen()) {
        error("Trainer does not exist or is not open");
    }
    else {
        vector<Customer *> customerlist = trainer->getCustomers();
        /*for (int i = 0; i < customerlist.size(); i++) {
            vector<int> workoutidvector = customerlist[i]->order(workoutvector);
            trainer->order(customerlist[i]->getId(), workoutidvector, workoutvector);
            for (int k = 0; k < workoutidvector.size(); k++) {
                output = output + customerlist[i]->getName() + " " + "Is Doing " + workoutvector[k].getName();
                cout << output;
            }
        }
        */
        for(Customer *customer:customerlist){
            vector<int> workidvec=customer->order(workoutvector);
            trainer->order(customer->getId(),workidvec,workoutvector);
            for (int k = 0; k < workidvec.size(); k++) {
                output = output + customer->getName() + " " + "Is Doing " + workoutvector[workidvec[k]].getName()+'\n';
            }

        }
        cout << output<<endl;
        complete();
    }
}

std::string Order::toString() const {

        string output = "";
        output = output + "order ";
        string Trainerid;
        stringstream ss;
        ss << trainerId;
        ss >> Trainerid;
        output=output+Trainerid;
        return output;

}

BaseAction *Order::clone() {
    return new Order(*this);
}

Order::~Order() = default;

