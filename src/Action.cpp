//
// Created by Owner on 09/11/2021.
//

#include <sstream>
#include "../include/Action.h"
#include "../include/Trainer.h"
#include "../include/Studio.h"

using namespace std;

BaseAction::BaseAction() {
    errorMsg = "";
    status = JustOpen;
}

ActionStatus BaseAction::getStatus() const {
    return status;
}

BaseAction::~BaseAction() = default;

void BaseAction::complete() {
    status = COMPLETED;
}

void BaseAction::error(std::string error_Msg) {
    status = ERROR;
    BaseAction::errorMsg = error_Msg;
    cout<<error_Msg;
}

std::string BaseAction::getErrorMsg() const {
    return errorMsg;
}
/*
OpenTrainer::OpenTrainer(int id, std::vector<Customer *> &customersList) : trainerId(id), customers(customersList) {

}

void OpenTrainer::act(Studio &studio) {
    Trainer *trainer = studio.getTrainer(trainerId);
    if ((trainer == nullptr) | trainer->isOpen()) {
        error("Workout session does not exist or is already open");
    }
    for (int i = 0; i < customers.size() & trainer->getrealtimecapacity() <= trainer->getCapacity(); i++) {
        trainer->addCustomer(customers[i]);
    }
    complete();
}

std::string OpenTrainer::toString() const {
    if (getErrorMsg() == "Workout session does not exist or is already open") {
        return getErrorMsg();
    } else {
        string output = "";
        stringstream ss;
        ss << trainerId;
        ss >> output;
        for (int i = 0; i < customers.size(); i++) {
            output = output + " " + customers[i]->getName() + "," + customers[i]->toString();
        }
        return output;
    }

Order::Order(int id) : trainerId(id) {

}

void Order::act(Studio &studio) {
    Trainer *trainer = studio.getTrainer(trainerId);
    vector<Workout> workoutvector = studio.getWorkoutOptions();
    if ((trainer == nullptr) | !trainer->isOpen()) {
        error("Trainer does not exist or is not open");
    }
    vector<Customer *> customerlist = trainer->getCustomers();
    for (int i = 0; i < customerlist.size(); i++) {
        vector<int> workoutidvector = customerlist[i]->order(workoutvector);
        trainer->order(customerlist[i]->getId(), workoutidvector, workoutvector);

    }
    complete();
}

std::string Order::toString() const {
    if (getErrorMsg() == "Trainer does not exist or is not open") {
        return getErrorMsg();
    } else {
        string output = "";
        output = output + "order";
        stringstream ss;
        ss << trainerId;
        ss >> output;
        return output;
    }
}
MoveCustomer::MoveCustomer(int src, int dst, int customerId) : srcTrainer(src), dstTrainer(dst), id(customerId) {

}

void MoveCustomer::act(Studio &studio) {
    int dstsalarytoadd = 0;
    Trainer *trainerSrc = studio.getTrainer(srcTrainer);
    Trainer *trainerdst = studio.getTrainer(dstTrainer);
    Customer *customer = trainerSrc->getCustomer(id);
    if ((trainerSrc == nullptr) | !trainerSrc->isOpen() | trainerSrc->getCustomer(id) == nullptr) {
        error("Cannot move customer");
    }
    if ((trainerdst == nullptr) | !trainerdst->isOpen() |
        trainerdst->getrealtimecapacity() + 1 > trainerdst->getCapacity()) {
        error("Cannot move customer");
    }

    //when we add customer we need to add his orders to the dstTrainer
    trainerdst->addCustomer(customer);

    vector<OrderPair> srcorderpair = trainerSrc->getOrders();
    for (OrderPair orderPair: srcorderpair) {
        if (orderPair.first == id) {
            trainerdst->addneworder(id, orderPair.second);
            dstsalarytoadd = dstsalarytoadd + orderPair.second.getPrice();
        }
    }
    trainerdst->setsalary(trainerdst->getSalary() + dstsalarytoadd);

    //when we remove customer we already remove his orders from ths srcTrainer and decreasing salary
    trainerSrc->removeCustomer(id);
    //If the
    //origin trainer has no customers left after this move, the program will close his session
    if (trainerSrc->getrealtimecapacity() == 0) {
        trainerSrc->closeTrainer();
    }
    complete();
}

std::string MoveCustomer::toString() const {
    if (getErrorMsg() != "") {
        return getErrorMsg();
    } else {
        string output = "move";
        string revah = " ";
        output = output + revah;
        stringstream src;
        src << srcTrainer;
        src >> output;
        output = output + revah;
        stringstream dst;
        dst << dstTrainer;
        dst >> output;
        output = output + revah;
        stringstream customerid;
        customerid << id;
        return output;
    }
}
Close::Close(int id) : trainerId(id) {

}

void Close::act(Studio &studio) {
    Trainer *trainer = studio.getTrainer(trainerId);
    if ((trainer == nullptr) | !trainer->isOpen()) {
        error("Trainer does not exist or is not open");
    }
    string output = "";
    output = output + "Trainer";
    string revah = " ";
    stringstream trainerid;
    trainerid << trainerId;
    output = output + revah;
    trainerid >> output;
    output = output + revah;
    output = output + "closed. Salary";
    stringstream salary;
    salary << trainer->getSalary();
    output = output + revah;
    salary >> output;
    output = output + "NIS";
    cout << output;
    trainer->closeTrainer();
    //now we delete all the trainer customers;
    vector<Customer *> customervec = trainer->getCustomers();
    for (Customer *customer: customervec) {
        delete customer;
    }
    complete();
}

std::string Close::toString() const {
    if (getErrorMsg() != "") {
        return getErrorMsg();
    } else {
        string output = "";
        output = output + "close";
        string revah = " ";
        stringstream trainerid;
        trainerid << trainerId;
        output = output + revah;
        trainerid >> output;
        return output;
    }
}
CloseAll::CloseAll() {

}

void CloseAll::act(Studio &studio) {
    vector<Trainer *> trainervector = studio.getTrainers();
    for (Trainer *trainer: trainervector) {

        string out;
        string sal;
        stringstream trainerid;
        stringstream trainersalary;
        trainerid << trainer->getid();
        trainersalary << trainer->getSalary();
        trainerid >> out;
        out = "Trainer " + out + " " + "Closed.Salary";
        trainersalary >> sal;
        sal = sal + "NIS";
        out = out + " " + sal;
        cout << out;
        trainer->closeTrainer();
        vector<Customer *> customervec = trainer->getCustomers();
        for (Customer *customer: customervec) {
            delete customer;
        }
        delete trainer;
    }
    complete();
}

std::string CloseAll::toString() const {
    return "closeall";
}
PrintWorkoutOptions::PrintWorkoutOptions() {

}

void PrintWorkoutOptions::act(Studio &studio) {
    vector<Workout> workoutvector = studio.getWorkoutOptions();
    for (Workout workout: workoutvector) {
        stringstream price;
        price << workout.getPrice();
        string output = "";
        price >> output;
        if (workout.getType() == ANAEROBIC) {
            cout << workout.getName() + "," + " " + "ANAEROBIC" + "," + " " + output;
        }
        if (workout.getType() == MIXED) {
            cout << workout.getName() + "," + " " + "Mixed" + "," + " " + output;
        }
        if (workout.getType() == CARDIO) {
            cout << workout.getName() + "," + " " + "Cardio" + "," + " " + output;
        }
    }
    complete();
}

std::string PrintWorkoutOptions::toString() const {
    return "workout_options";
}
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
        cout << output;
        cout << "Customers :";
        for (Customer *customer: trainersCustomers) {
            stringstream customersid;
            string output1;
            customersid << customer->getId();
            customersid >> output1;
            output1 = output1 + " " + customer->getName();
            cout << output1;
        }
        cout << "orders:";
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
                    output2 = output2 + "NIS" + " " + customersid;
                    output2 = orderPair.second.getName() + " " + output2;
                    cout << output2;
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
    ss >> output;
    final = final + "status " + output;
    return final;
}
PrintActionsLog::PrintActionsLog() {

}

void PrintActionsLog::act(Studio &studio) {
    vector<BaseAction *> actionslogvector = studio.getActionsLog();
    for (BaseAction *baseAction: actionslogvector) {
        if (baseAction->getStatus() == COMPLETED) {
            string output;
            output = output + baseAction->toString() + "args" + " " + "Completed";
        } else {
            string output;
            output = output + baseAction->toString() + "args" + " " + getErrorMsg();
        }

    }
}

std::string PrintActionsLog::toString() const {
    return "log";
}
BackupStudio::BackupStudio() {

}

void BackupStudio::act(Studio &studio) {

}

std::string BackupStudio::toString() const {
    return std::string();
}

RestoreStudio::RestoreStudio() {

}

void RestoreStudio::act(Studio &studio) {

}

std::string RestoreStudio::toString() const {
    return std::string();
}
*/