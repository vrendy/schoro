/*
 * Job.cpp
 *
 *  Created on: Sep 22, 2017
 *      Author: Vrendy
 */

#include "Job.h"

#include <iostream>

Job::Job() : currentTask(0), endTime(0), jobID(0), numberOfTasks(0){

}

Job::Job(const unsigned short aJobID) : currentTask(0), endTime(0), jobID(aJobID), numberOfTasks(0){}


/*
 * DESC: Voeg een taak toe aan de takenlijst
 */
void Job::addTask(Task& aTask){
	aTask.setTaskID(numberOfTasks);
	taskList.push_back(aTask);

	numberOfTasks++;
}


/*
 * DESC: Bereken de ES value voor alle taken vanaf de currentTask !
 * PARAM: currentStart, de waarde van de huidige eerst volgende starttijd,
 */
void Job::calculateES(const unsigned short currentStart){
	for(unsigned short i = currentTask; i < taskList.size(); i++){
		if(i == currentTask) { //Als het de eerste taak in de reeks is, hanteer de huidige earliest start time
			taskList.at(i).setES(currentStart);
			continue;
		}
		taskList.at(i).setES(taskList.at(i - 1).getES() + taskList.at(i - 1).getRuntime()); //vorigeTaak.es + vorigeTaak.runtime, is es van huidige taak
	}
}



/*
 * DESC: Bereken de LS value voor alle taken van eind tot currentTask
 * PARAM: currentEnd, de waarde van de eindtijd van het kritieke / langste pad
 */
void Job::calculateLS(const unsigned short currentEnd){
	unsigned short tmpLS = currentEnd;
	short i = taskList.size() - 1;
	while(i >= currentTask){
		taskList.at(i).setLS((tmpLS -= taskList.at(i).getRuntime())); //Huidige eindtijd - runtime van huidige taak is LS tijd voor huidige taak
		i--;
	}
}

/*
 * Haal de eerst volgende taak op, of return -1 als de current task buiten de array wijst
 */

short Job::getCurrentTaskID()const{
	if(currentTask >= taskList.size())
		return -1;

	return currentTask;
}

Task& Job::getCurrentTask(){
	return taskList.at(currentTask);
}

Task& Job::getTask(short getTask){
	return taskList.at(getTask);
}

unsigned short Job::getStartTime()const{
	Task firstTaskInJob = taskList.at(0);
	return firstTaskInJob.getES();
}

unsigned short Job::getFinishTime()const{
	Task lastTaskInJob = taskList.at(taskList.size() - 1);
	return lastTaskInJob.getES() + lastTaskInJob.getRuntime();
}


unsigned short Job::getJobID()const{
	return jobID;
}


void Job::incrementCurrentTask(){
	currentTask++;
}


unsigned short Job::getEndTime()const{
	return endTime;
}

void Job::setEndTime(const unsigned short aEndTime){
	endTime = aEndTime;
}

void Job::setJobID(const unsigned short aJobID){
	jobID = aJobID;
}
