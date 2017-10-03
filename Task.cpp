/*
 * Task.cpp
 *
 *  Created on: Sep 22, 2017
 *      Author: vrendy
 */

#include "Task.h"
#include <iostream>

Task::Task(unsigned char anId, unsigned char aMachineId, unsigned char aDuration) : id(anId), machineId(aMachineId), duration(aDuration), completed(0)
{
	std::cout << __PRETTY_FUNCTION__ << std::endl;
}

Task::~Task()
{
	std::cout << __PRETTY_FUNCTION__ << std::endl;
}

Task::Task(const Task& aTask) : id(aTask.id), machineId(aTask.machineId), duration(aTask.duration), completed(aTask.completed)
{
	std::cout << __PRETTY_FUNCTION__ << std::endl;
}

bool Task::isCompleted() const
{
	return completed;
}

unsigned char Task::getDuration() const
{
	if(completed)
		return 0;
	else
		return duration;
}

unsigned char Task::getMachineId() const
{
	return machineId;
}
