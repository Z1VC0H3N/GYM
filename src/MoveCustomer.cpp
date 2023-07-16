//
// Created by Owner on 23/11/2021.
//

#include <sstream>
#include "../include/MoveCustomer.h"
#include "../include/Studio.h"
using namespace std;
MoveCustomer::MoveCustomer(int src, int dst, int customerId) : srcTrainer(src), dstTrainer(dst), id(customerId) {

}

void MoveCustomer::act(Studio &studio) {
    int dstsalarytoadd = 0;
    Trainer *trainerSrc = studio.getTrainer(srcTrainer);
    Trainer *trainerdst = studio.getTrainer(dstTrainer);
    Customer *customer = trainerSrc->getCustomer(id)->clone();
    if ((trainerSrc == nullptr) | !trainerSrc->isOpen() | trainerSrc->getCustomer(id) == nullptr) {
        error("Cannot move customer");
    }
    else if ((trainerdst == nullptr) | !trainerdst->isOpen() |
        trainerdst->getrealtimecapacity() + 1 > trainerdst->getCapacity()) {
        error("Cannot move customer");
    }
else {
        vector<OrderPair> srcorderpair = trainerSrc->getOrders();
        for (const OrderPair& orderPair: srcorderpair) {
            if (orderPair.first == id) {
                dstsalarytoadd = dstsalarytoadd + orderPair.second.getPrice();
            }
        }
        vector<Workout> workout_options=studio.getWorkoutOptions();
        trainerdst->addCustomer(customer);
        //when we remove customer we already remove his orders from ths srcTrainer and decreasing salary
        trainerSrc->removeCustomer(id);
        //If the
        //origin trainer has no customers left after this move, the program will close his session
        if (trainerSrc->getrealtimecapacity() == 0) {
            trainerSrc->closeTrainer();
        }
        //in order we already increasing salary
        trainerdst->order(customer->getId(),customer->order(workout_options),workout_options);
        complete();
    }
}

std::string MoveCustomer::toString() const {
    if (!getErrorMsg().empty()) {
        return getErrorMsg();
    } else {
        string output = "move";
        string revah = " ";
        string srctrainer;
        string dsttrainer;
        string customerids;
        output = output + revah;
        stringstream src;
        src << srcTrainer;
        src >> srctrainer;
        output = output +srctrainer+ revah;
        stringstream dst;
        dst << dstTrainer;
        dst >> dsttrainer;
        output = output + dsttrainer + revah;
        stringstream customerid;
        customerid << id;
        customerid>>customerids;
        output=output+customerids;
        return output;
    }
}

BaseAction *MoveCustomer::clone() {
    return new MoveCustomer(*this);
}

MoveCustomer::~MoveCustomer() = default;
