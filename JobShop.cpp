/*
 * JobShop.cpp
 *
 *  Created on: Sep 22, 2017
 *      Author: Vrendy
 */

#include "JobShop.h"

#include <algorithm>
#include <utility>
#include <iostream>

JobShop::JobShop() : aantalMachines(0), overalRuntime(0), numberOfJobs(0){}
JobShop::JobShop(unsigned short aAantalMachines, unsigned short aNumberOfJobs) : aantalMachines(aAantalMachines),
												overalRuntime(0), numberOfJobs(aNumberOfJobs){
	//Build the list of machines
	std::pair<short, short>emptyPair = std::make_pair(-1, -1);
	for(unsigned short i = 0; i < aAantalMachines; i++){
		machineList[i] = emptyPair;
	}
}



/*
 * Voeg een job toe aan de job list, en verander zijn jobID
 */
void JobShop::addJob(Job &aJob){
	aJob.setId(numberOfJobs);
	jobList.push_back(aJob);
	numberOfJobs++;
}

Job& JobShop::getJob(const unsigned short id){
	return jobList.at(id);
}

void JobShop::run(){
	calculateES(0);
	calculateLS(getLongestPath());


	//Loop tot alle taken klaar zijn
	bool doneRunning = false;
	while(!doneRunning){
		doneRunning = true;
		for(Job& aJob : jobList){
			if(aJob.getEndTime() == 0){
				doneRunning = false;
				break;
			}
		}

		planTaken();
		runTasks(getShortestTask());

		calculateES(overalRuntime);
		calculateLS(getLongestPath());

	}
}


/*
 * Plan alle taken op de beschikbare machines
 */

void JobShop::planTaken(){
	for(Job& huidigeJob : jobList){
		//Check of de huidige job nog taken heeft.
		if(huidigeJob.getCurrentTaskID() == -1){
			//check of de job al een eindtijd heeft anders set hem hier
			if(huidigeJob.getEndTime() == 0)
				huidigeJob.setEndTime(overalRuntime);
			//Deze job heeft geen taken meer skip naar de volgende
			continue;
		}
		Task &currentTaskInJob = huidigeJob.getCurrentTask();

		std::pair<short, short> jobTaskPair = machineList.at(currentTaskInJob.getNeededMachine());
		if(jobTaskPair.first != -1 && jobTaskPair.second != -1){
			//Er is al een taak gepland op deze machine
			//Get de taak die gepland is en
			Task &plannedTask = (jobList.at(jobTaskPair.first)).getTask(jobTaskPair.second);
			if(plannedTask.isRunning())
				continue; //Taak is running, laat hem staan en skip naar de volgende job

			//Taak is niet running, check of onze slack kleiner is dan die van de geplande taak
			if((currentTaskInJob.getLS() - currentTaskInJob.getES()) < (plannedTask.getLS() - plannedTask.getES())){
				//Slack van de huidige job is kleiner dan slack van geplande job, zet de huidige job op de machine.
				std::pair<short, short>insertPair = std::make_pair(huidigeJob.getId(), currentTaskInJob.getId());
				machineList[currentTaskInJob.getNeededMachine()] = insertPair;
				continue;
			}
		} else {
			//Plan de taak op deze machine
			std::pair<short, short>insertPair = std::make_pair(huidigeJob.getId(), currentTaskInJob.getId());
			machineList[currentTaskInJob.getNeededMachine()] = insertPair;
			continue;
		}

	}
}


/*
 * Return de kortste runtime van de ingeplande taken
 */
unsigned short JobShop::getShortestTask(){
	unsigned short huidigeKortsteTijd = 0XFF;
	for(unsigned short i = 0; i < machineList.size(); i++){
		//Loop door de hele machinelijst heen
		std::pair<short, short>jobTaskPair = machineList.at(i);
		if(jobTaskPair.first != -1 && jobTaskPair.second != -1){
			Task currentTask = (jobList.at(jobTaskPair.first)).getTask(jobTaskPair.second);
			if(currentTask.getRuntime() < huidigeKortsteTijd){
				huidigeKortsteTijd = currentTask.getRuntime();
			}
		}

	}


	return huidigeKortsteTijd;
}


void JobShop::runTasks(unsigned short aShortestTask){
	overalRuntime += aShortestTask;

	for(unsigned short i = 0; i < machineList.size(); i++){
		std::pair<short, short> jobTaskPair = machineList.at(i);
		if(jobTaskPair.first != -1 && jobTaskPair.second != -1){ //Check of er een job is gepland op deze machine
			Task &currentTask = (jobList.at(jobTaskPair.first).getTask(jobTaskPair.second));
			//Check if de taak is afgerond
			if((currentTask.getES() + currentTask.getRuntime()) == overalRuntime){
				(jobList.at(jobTaskPair.first)).incrementCurrentTask();
				//Zet machine pair op -1
				machineList[i] = std::make_pair(-1, -1);
			} else {
				currentTask.setRunning(true);
				unsigned short newRuntime = (currentTask.getRuntime() - aShortestTask);
				currentTask.setRuntime(newRuntime);
			}
		}
	}

}



/*
 * Bereken voor alle taken in de jobs de ES waardes
 */
void JobShop::calculateES(unsigned short currentStart){
	std::for_each(jobList.begin(), jobList.end(), [currentStart](Job& aJob)->void{
		aJob.calculateES(currentStart);
	});
}

/*
 * Bereken voor alle taken in de jobs de LS waardes
 */
void JobShop::calculateLS(unsigned short currentEnd){
	std::for_each(jobList.begin(), jobList.end(), [currentEnd](Job &aJob)->void{
		aJob.calculateLS(currentEnd);
	});
}

unsigned short JobShop::getLongestPath(){
	unsigned short longestTime = 0;
	std::for_each(jobList.begin(), jobList.end(), [&longestTime](Job &aJob)->void{
		if(aJob.getFinishTime() > longestTime){
			longestTime = aJob.getFinishTime();
		}
	});

	return longestTime;
}


void JobShop::printRuntimes(){
	for(Job& aJob : jobList){
		std::cout << aJob.getId() << "\t" << aJob.getStartTime() << "\t" << aJob.getFinishTime() << std::endl;
	}
}
