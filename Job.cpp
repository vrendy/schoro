/*
 * Job.cpp
 *
 *  Created on: Sep 22, 2017
 *      Author: vrendy
 */

#include "Job.h"

Job::Job(unsigned char anId) : id(anId)
{
	// TODO Auto-generated constructor stub

}

Job::~Job() {
	// TODO Auto-generated destructor stub
}

void Job::addTask(const Task& aTask)
{
	taskList.push_back(aTask);
}

unsigned short Job::getRemainingJobTime() const // Wat ik aan het doen ben: Tel de tijd van alle taken bij elkaar op, en return deze
											// vervolgens kan de langste tijd in jobshop bekeken worden van de langste job
											// vervolgens kan dit meegegeven worden en kan er uitgerekend worden welke taak er uitgevoerd moet worden
{
	unsigned short time = 0;

	for(const auto& t : taskList)
		time += t.getDuration();

	return time;
}

char Job::getMachineId() const // Keuze, haal je task uit de job vector, of zet je task op completed, redenen voor?
{
	char machineId = -1;

	for(const auto& t : taskList)
	{
		if(!t.isCompleted())
			machineId = t.getMachineId();
		if(machineId != -1)
			break;
	}

	return machineId;
}

unsigned char Job::getId() const
{
	return id;
}
