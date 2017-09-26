/*
 * Task.cpp
 *
 *  Created on: Sep 22, 2017
 *      Author: vrendy
 */

#include "Task.h"

Task::Task(unsigned char anId, unsigned char aMachineId, unsigned char aDuration) : id(anId), machineId(aMachineId), duration(aDuration), completed(0)
{
	// TODO Auto-generated constructor stub

}

Task::~Task()
{
	// TODO Auto-generated destructor stub
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
