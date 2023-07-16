//
// Created by Owner on 23/11/2021.
//
#include "../include/RestoreStudio.h"
#include "../include/Studio.h"
extern Studio* backup;
using namespace std;

RestoreStudio::RestoreStudio() {

}

void RestoreStudio::act(Studio &studio) {
    if(backup== nullptr){
        cout<<"No backup available";
    }
studio=*backup;
}

std::string RestoreStudio::toString() const {
    return "restore";
}

BaseAction *RestoreStudio::clone() {
    return new RestoreStudio(*this);
}

RestoreStudio::~RestoreStudio() = default;
