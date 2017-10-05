/*
 * Job.h
 *
 *  Created on: Sep 22, 2017
 *      Author: Vrendy
 */

#ifndef JOB_H_
#define JOB_H_

#include <vector>
#include "Task.h"


class Job {
public:
	Job();
	Job(const unsigned short aJobID);

	void calculateES(const unsigned short currentStart);
	void calculateLS(const unsigned short currentEnd);
	void addTask(Task& aTask);

	Task& getCurrentTask();

	unsigned short getStartTime()const;
	unsigned short getFinishTime()const;
	unsigned short getEndTime()const;
	void setEndTime(const unsigned short aEndTime);

	short getCurrentTaskID()const;

	void setId(const unsigned short anId);
	unsigned short getId()const;
	Task& getTask(short getTask);

	void incrementCurrentTask();


private:
	std::vector<Task>taskList;
	unsigned short currentTask;
	unsigned short endTime;
	unsigned short id;
	unsigned short numberOfTasks;
};



#endif /* JOB_H_ */
