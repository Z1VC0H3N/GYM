//
// Created by Owner on 23/11/2021.
//

#include "../include/BackupStudio.h"
#include "../include/Studio.h"
extern  Studio* backup;
BackupStudio::BackupStudio()  {

}

void BackupStudio::act(Studio &studio) {
backup=new Studio(studio);
}

std::string BackupStudio::toString() const {
    return "backup";
}

BaseAction *BackupStudio::clone() {
    return new BackupStudio(*this);
}

BackupStudio::~BackupStudio() = default;
