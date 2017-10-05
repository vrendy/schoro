/*
 * JobShop.hpp
 *
 *  Created on: Sep 22, 2017
 *      Author: Vrendy
 */

#ifndef JOBSHOP_H_
#define JOBSHOP_H_

#include <map>

#include "Job.h"
#include "Task.h"

class JobShop{
public:

	JobShop();
	JobShop(unsigned short aAantalMachines, unsigned short aNumberOfJobs = 0);

	void addJob(Job &aJob);
	Job& getJob(const unsigned short id);

	void printRuntimes();
	void run();

private:
	std::vector<Job>jobList;
	std::map<unsigned short, std::pair<short, short>>machineList; //machineList <machineID, <JobID, TaskID>>

	unsigned short aantalMachines;
	unsigned short overalRuntime;
	unsigned short numberOfJobs;


	//Private functions, only used by this same class
	void calculateES(unsigned short currentStart);
	void calculateLS(unsigned short currentEnd);
	unsigned short getLongestPath();
	void planTaken();
	unsigned short getShortestTask();
	void runTasks(unsigned short aShortestTask);

};



#endif /* JOBSHOP_H_ */
