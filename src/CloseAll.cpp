//
// Created by Owner on 23/11/2021.
//

#include <sstream>
#include "../include/CloseAll.h"
#include "../include/Trainer.h"
#include "../include/Close.h"

using namespace std;
CloseAll::CloseAll() {

}

void CloseAll::act(Studio &studio) {
    vector<Trainer *> trainervector = studio.getTrainers();
    for (Trainer *trainer: trainervector) {
        if (trainer->isOpen()) {
            Close *close=new Close(trainer->getid());
            close->act(studio);
            delete close;
            delete trainer;
            trainer= nullptr;
        }
    }

    complete();
}

std::string CloseAll::toString() const {
    return "closeall";
}

BaseAction *CloseAll::clone() {
    return new CloseAll(*this);
}

CloseAll::~CloseAll() = default;
