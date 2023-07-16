//
// Created by Owner on 09/11/2021.
//

#include "../include/Studio.h"
#include "../include/OpenTrainer.h"
#include "../include/MoveCustomer.h"
#include "../include/Close.h"
#include "../include/PrintTrainerStatus.h"
#include "../include/Order.h"
#include "../include/CloseAll.h"
#include "../include/PrintWorkoutOptions.h"
#include "../include/PrintActionsLog.h"
#include "../include/BackupStudio.h"
#include "../include/RestoreStudio.h"
#include <fstream>
#include <sstream>

using namespace std;

Studio::Studio():open(true),idcustomer(0){

}
Studio::Studio(const Studio & s)  {
    open = s.open;
    for (int i = 0; i < trainers.size(); i++) {
        trainers.push_back(s.trainers[i]);
    }
    for (int i = 0; i < workout_options.size(); i++) {
        workout_options.push_back(s.workout_options[i]);
    }
  for(BaseAction *action:s.actionsLog){
     actionsLog.push_back(action->clone());
  }
idcustomer=s.idcustomer;
}

Studio::Studio(const std::string &configFilePath) {
    idcustomer=0;
    open= true;
    vector<string> sentences;
    std::ifstream file(configFilePath);
    string line;
    while (file) {
        getline(file, line);
        if (line[0] == '#') {
            continue;
        }
        if (line[0] == '\0')
            continue;
        sentences.push_back(line);
    }
    for(int c=0;c<sentences.size();c++){
        string output=sentences[c];
        cout<<output<<'\n';
    }
    int i = 0;
    int numoftrainers = stoi(sentences[0]);
    bool tostop = false;
    int whereur = 0;
    string workoption;
    string worktype;
    string salary;
    string::iterator it;
    string::iterator itnum;

    for(unsigned int t=1;(unsigned)t<sentences.size();t++) {
        vector<string> trainersline = split(sentences[t], ",");
        if (t == 1 & !tostop) {
            for (int k = 0; k < trainersline.size(); k++) {
                trainers.push_back(new Trainer(stoi(trainersline[k])));
                trainers[i]->setid(i);
                i = i + 1;
                if (i > numoftrainers) {
                    tostop = true;
                }
            }
            if (tostop) {
                break;
            }
        } else
        {
            /*vector<string> workoutline = split(sentences[t], ",");
            string bypsik="";
            for (unsigned int h = 0; h < workoutline.size(); h++) {
                bypsik = bypsik + workoutline[h];
            }
            vector<string> bypsik1 = split(bypsik, " ");
             */
            vector<string> bypsik1=split(sentences[t], ", ");
            workoption = bypsik1[0];
            worktype = bypsik1[1];
            salary = bypsik1[2];

            if (worktype == "Anaerobic") {
                workout_options.emplace_back(t-2, workoption, stoi(salary), ANAEROBIC);
            }
            if (worktype == "Mixed") {
                workout_options.emplace_back(t-2, workoption, stoi(salary), MIXED);
            }
            if (worktype == "Cardio") {
                workout_options.emplace_back(t-2, workoption, stoi(salary), CARDIO);
            }
        }

    }

}

void Studio::start() {
    cout << "Studio is now open!"<<std::endl;
    open = true;
    string action;
    while(open){
        getline(cin, action);
        string order;
        //this is the sentence after pharse by revahim use this:
        vector<string> sentence = split(action, " ");
        order = sentence[0];
        //for split between customer name and customer type;
        string sent2 = "";
        int i = 0;
        for (int i = 2; i < sentence.size(); i++) {
            if (sentence[i] == "#") {
                break;
            }
            sent2 = sent2 + sentence[i] + " ";
        }
        //for split between the psikim un sent2;
        vector<string> sent2bypsik = split(sent2, ",");


        vector<string> sofi;
        for (int i = 0; i < sent2bypsik.size(); i++) {
            string tocompute = sent2bypsik[i];
            vector<string> temp = split(tocompute, " ");
            for (int c = 0; c < temp.size(); c++) {
                sofi.push_back(temp[c]);
            }
        }
        vector<string> sofiii;
        for (int y = 0; y < sofi.size() - 1; y++) {
            sofiii.push_back(sofi[y]);
        }
        if (order == "open") {
            Trainer *trainer = getTrainer(stoi(sentence[1]));
            for (int i = 0; i < sofiii.size() - 1; i = i + 2) {
                if (sofiii[i + 1] == "swt") {
                    auto *swt = new SweatyCustomer(sofiii[i], idcustomer);
                    trainer->addCustomer(swt);
                    idcustomer++;
                }
                if (sofiii[i + 1] == "chp") {
                    auto *chp = new CheapCustomer(sofiii[i], idcustomer);
                    trainer->addCustomer(chp);
                    idcustomer++;
                }
                if (sofiii[i + 1] == "mcl") {
                    auto *mcl = new HeavyMuscleCustomer(sofiii[i], idcustomer);
                    trainer->addCustomer(mcl);
                    idcustomer++;
                }
                if (sofiii[i + 1] == "fbd") {
                    auto *fbd = new FullBodyCustomer(sofiii[i], idcustomer);
                    trainer->addCustomer(fbd);
                    idcustomer++;
                }
            }
            vector<Customer *> customerlist = getTrainer(stoi(sentence[1]))->getCustomers();
            BaseAction *open1 = new OpenTrainer(stoi(sentence[1]), customerlist);
            actionsLog.push_back(open1);
            open1->act(*this);
        }
//Order
        else if (order == "order")
        {
            BaseAction *order1 = new Order(stoi(sentence[1]));
            actionsLog.push_back(order1);
            order1->act(*this);

        }
//Move Customer
        else if (order == "move") {
            int from = stoi(sentence[1]);
            int to = stoi(sentence[2]);
            int id = stoi(sentence[3]);
            BaseAction *move = new MoveCustomer(from, to, id);
            move->act(*this);
            actionsLog.push_back(move);

        }
//close trainer
        else if (order == "close") {
            BaseAction *close = new Close(stoi(sentence[1]));
            close->act(*this);
            actionsLog.push_back(close);
        }
            // close all trainers
        else if (order == "closeAll") {
            BaseAction *cloaeAll = new CloseAll();
            cloaeAll->act(*this);
            actionsLog.push_back(cloaeAll);

        }
            //print trainer status
        else if (order == "status") {
            BaseAction *status = new PrintTrainerStatus(stoi(sentence[1]));
            status->act(*this);
            actionsLog.push_back(status);
        }
            //print workout option
        else if (order == "workout_options") {
            BaseAction *workoptions = new PrintWorkoutOptions();
            workoptions->act(*this);
            actionsLog.push_back(workoptions);
        }
            //print actions log
        else if (order == "log") {
            BaseAction *actionslog = new PrintActionsLog();
            actionslog->act(*this);
        }
            //backup studio
        else if (order == "backup") {
            BaseAction *backup = new BackupStudio();
            backup->act(*this);
            actionsLog.push_back(backup);
        }
            //restore studio
        else if (order == "restore") {
            BaseAction *restore = new RestoreStudio();
            restore->act(*this);
            actionsLog.push_back(restore);
        }

    }
    //std::cout<<action<<std::endl;
}

Trainer *Studio::getTrainer(int tid) {
    if (tid >= trainers.size()) {
        return nullptr;
    }
    return trainers[tid];
}

int Studio::getNumOfTrainers() const {
    return trainers.size();
}

const std::vector<BaseAction *> &Studio::getActionsLog() const {
    return actionsLog;
}

std::vector<Workout> &Studio::getWorkoutOptions() {
    return workout_options;
}

std::vector<Trainer *> &Studio::getTrainers() {
    return trainers;
}
std::vector<std::string> Studio::split(std::string data, const std::string& delimiter)
{
std::vector<std::string> newData;
size_t pos = 0;
std::string token;
while ((pos = data.find(delimiter)) != std::string::npos) {
token = data.substr(0, pos);
    newData.push_back(token);
data.erase(0, pos + delimiter.length());
}
newData.push_back(data);
return newData;
}


Studio::~Studio() {
open= static_cast<bool>(nullptr);;
for(Trainer *trainer:trainers){
    delete trainer;
}
for(BaseAction *action:actionsLog){
    delete action;
}
workout_options.clear();
trainers.clear();
actionsLog.clear();
}


Studio& Studio::operator=(const Studio &other) {
    open=other.open;
    trainers= vector<Trainer*>();
    for(Trainer *trainer:other.trainers){
        auto* trainer1=new Trainer(*trainer);
        trainers.push_back(trainer1);
        delete trainer;
    }
    workout_options=other.workout_options;
    actionsLog=vector<BaseAction*>();
    for(BaseAction *action:other.actionsLog){
        actionsLog.push_back(action->clone());
        delete action;
    }
    return *this;
}
