//
// Created by Owner on 23/11/2021.
//

#ifndef UNTITLED_BACKUPSTUDIO_H
#define UNTITLED_BACKUPSTUDIO_H


#include "Action.h"

class BackupStudio : public BaseAction {
public:
    BackupStudio();
    void act(Studio &studio);
    std::string toString() const;
    BaseAction* clone();
BackupStudio::~BackupStudio();
private:
};


#endif //UNTITLED_BACKUPSTUDIO_H
