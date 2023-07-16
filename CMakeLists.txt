cmake_minimum_required(VERSION 3.20)
project(untitled)

set(CMAKE_CXX_STANDARD 14)

add_executable(untitled src/main.cpp src/Action.cpp src/Studio.cpp src/Trainer.cpp src/Customer.cpp src/Workout.cpp src/OpenTrainer.cpp include/OpenTrainer.h src/Order.cpp include/Order.h src/MoveCustomer.cpp include/MoveCustomer.h src/Close.cpp include/Close.h src/CloseAll.cpp include/CloseAll.h src/PrintWorkoutOptions.cpp include/PrintWorkoutOptions.h src/PrintTrainerStatus.cpp include/PrintTrainerStatus.h src/PrintActionsLog.cpp include/PrintActionsLog.h src/BackupStudio.cpp include/BackupStudio.h src/RestoreStudio.cpp include/RestoreStudio.h)
