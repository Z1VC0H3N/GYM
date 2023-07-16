//
// Created by Owner on 23/11/2021.
//

#include <sstream>
#include "../include/PrintTrainerStatus.h"
#include "../include/Trainer.h"

PrintTrainerStatus::PrintTrainerStatus(int id) : trainerId(id) {

}

void PrintTrainerStatus::act(Studio &studio) {
    Trainer *trainer = studio.getTrainer(trainerId);
    vector<Customer *> trainersCustomers = trainer->getCustomers();
    string output;
    string trainerid;
    stringstream ss;
    ss << trainerId;
    ss >> trainerid;
    if (trainer->isOpen()) {
        output = output + "Trainer" + " " + trainerid + " " + "status:" + trainer->getStatus(trainer->isOpen());
        cout << output+'\n';
        cout << "Customers :";
        cout<<'\n';
        for (Customer *customer: trainersCustomers) {
            stringstream customersid;
            string output1;
            customersid << customer->getId();
            customersid >> output1;
            output1 = output1 + " " + customer->getName();
            cout << output1+'\n';
        }
        cout << "orders:";
        cout<< '\n';
        for (Customer *customer: trainersCustomers) {
            for (OrderPair orderPair: trainer->getOrders()) {
                if (customer->getId() == orderPair.first) {
                    stringstream customerid1;
                    stringstream workoutprice;
                    string output2;
                    string customersid;
                    customerid1 >> customersid;
                    workoutprice << orderPair.second.getPrice();
                    workoutprice >> output2;
                    output2 = output2 + "NIS" + " ";
                    output2=output2 + customersid;
                    output2 = orderPair.second.getName() + " " + output2;
                    cout << output2+'\n';
                }
            }
        }
        stringstream salary;
        salary << trainer->getSalary();
        string output3;
        salary >> output3;
        output3 = output3 + "NIS";
        string finaloutput;
        finaloutput = finaloutput + "Current Trainer's Salary:" + output3;
        cout << finaloutput;
    } else {
        string finalcloseoutput;
        finalcloseoutput =
                finalcloseoutput + "Trainer" + " " + trainerid + " " + "status:" + " " + trainer->getStatus(false);
        cout << finalcloseoutput;
    }
    complete();
}


std::string PrintTrainerStatus::toString() const {
    stringstream ss;

    ss << trainerId;
    string output;
    string final;
    string Trainrerid;
    ss >> Trainrerid;
    output=output+Trainrerid;
    final = final + "status"+" " + output;
    return final;
}

BaseAction *PrintTrainerStatus::clone() {
    return new PrintTrainerStatus(*this);
}

PrintTrainerStatus::~PrintTrainerStatus() = default;

