/*
 * Task.h
 *
 *  Created on: Sep 22, 2017
 *      Author: vrendy
 */

#ifndef TASK_H_
#define TASK_H_

class Task {
public:
	Task(unsigned char anId, unsigned char aMachineId, unsigned char aDuration);
	virtual ~Task();

	bool isCompleted() const;

	unsigned char getDuration() const;

	unsigned char getMachineId() const;

private:
	unsigned char id;
	unsigned char machineId;
	unsigned char duration;

	bool completed;
};

#endif /* TASK_H_ */
