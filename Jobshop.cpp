/*
 * Jobshop.cpp
 *
 *  Created on: Sep 22, 2017
 *      Author: vrendy
 */

#include "Jobshop.h"

#include <iostream> //temp

#include <map>
#include <utility>

Jobshop::Jobshop(unsigned char anJobs, unsigned char anMachines) : nJobs(anJobs), nMachines(anMachines)
{
	// TODO Auto-generated constructor stub

}

Jobshop::~Jobshop() {
	// TODO Auto-generated destructor stub
}


void Jobshop::addJob(const Job& aJob)
{
	jobList.push_back(aJob);
}

unsigned short Jobshop::getLongestJobTime() const
{
	unsigned short longestTime = 0;
	unsigned short jobTime = 0;

	for(const auto& job : jobList)
	{
		jobTime = job.getRemainingJobTime();
		if(jobTime > longestTime)
			longestTime = jobTime;
	}

	return longestTime;
}

unsigned char Jobshop::getMachineId(const Job& aJob) const //TODO REFACTOR
{
	char machineId = aJob.getMachineId();
//	std::cout << "Machine ID: " << machineId << std::endl;
	//if(machineId == -1)
		// TODO throw exception no Machines left

	return (unsigned char)machineId;
}

void Jobshop::dispatch()
{
	std::map<unsigned char, unsigned char> jobMachineMap;
	unsigned char taskAssignedMachineList[nMachines] = {}; // Counts number of tasks assigned to the machine(id)

	for(const auto& job : jobList)
	{
		taskAssignedMachineList[getMachineId(job)] += 1;
		jobMachineMap.emplace(std::make_pair(job.getId(), getMachineId(job)));
	}

	for(unsigned char i = 0; i < nMachines; ++i)
	{
		std::cout << "Machine[" << (int)i << "]: " << (int)taskAssignedMachineList[i] << std::endl;
	}

	for(const auto& it : jobMachineMap)
	{
		std::cout << "Job: " << (int)it.first << " Machine: " << (int)it.second << std::endl;
	}
	// get jobs with tasks on same machine (map met job id, machine id vullen)
	// calculate least slack time
}
