/*
 * Job.h
 *
 *  Created on: Sep 22, 2017
 *      Author: vrendy
 */

#ifndef JOB_H_
#define JOB_H_

#include "Task.h"

#include <vector>

class Job {
public:
	Job(unsigned char anId);
	virtual ~Job();
	Job(const Job& aJob);

	void addTask(const Task& aTask);
	unsigned short getRemainingJobTime() const;
	/* getMachineId resolves the machineId from the first Task from taskList that is not completed
	 * returns char machineId if found, -1 if all Tasks are completed
	 */
	char getMachineId() const;

	/* getId resolves the id of Job
	 * returns unsigned char id
	 */
	unsigned char getId() const;

private:
	unsigned char id;
	std::vector<Task> taskList;
};

#endif /* JOB_H_ */
