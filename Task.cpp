/*
 * Task.cpp
 *
 *  Created on: Sep 22, 2017
 *      Author: Vrendy
 */

#include "Task.h"
#include <iostream>


Task::Task() : ES(0), LS(0), id(0), runtime(0), neededMachine(0), running(false){}
Task::Task(const unsigned short aRuntime, const unsigned short aNeededMachine) : ES(0), LS(0), id(0), runtime(aRuntime), neededMachine(aNeededMachine), running(false){}

Task::Task(const Task& aTask): ES(aTask.ES), LS(aTask.LS), id(aTask.id), runtime(aTask.runtime), neededMachine(aTask.neededMachine), running(aTask.running){
}


Task& Task::operator=(Task& aTask){

	if (this != &aTask) {
		ES = aTask.ES;
		LS = aTask.LS;
		neededMachine = aTask.neededMachine;
		running = aTask.running;
		runtime = aTask.runtime;
		id = aTask.id;
	}
	return *this;
}


short Task::getES()const{
	return ES;
}

void Task::setES(const short aES){
	//if(id == 0)
		//std::cout << aES << std::endl;
	ES = aES;
}

short Task::getLS()const{
	return LS;
}

void Task::setLS(const short aLS){
	LS = aLS;
}

unsigned short Task::getRuntime()const{
	return runtime;
}

void Task::setRuntime(const unsigned short aRuntime){
	runtime = aRuntime;
}

unsigned short Task::getNeededMachine()const{
	return neededMachine;
}

void Task::setNeededMachine(const unsigned short aNeededMachine){
	neededMachine = aNeededMachine;
}

bool Task::isRunning()const{
	return running;
}

void Task::setRunning(const bool aRunning){
	running = aRunning;
}


unsigned short Task::getId()const{
	return id;
}

void Task::setId(unsigned short anId){
	id = anId;
}
