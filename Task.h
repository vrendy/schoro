/*
 * Task.hpp
 *
 *  Created on: Sep 22, 2017
 *      Author: Vrendy
 */

#ifndef TASK_H_
#define TASK_H_

class Task{
public:

	Task();
	Task(const unsigned short aRuntime, const unsigned short aNeededMachine);
	Task(const Task& aTask);

	Task& operator=(Task& aTask);

	unsigned short getId()const;
	void setId(const unsigned short anId);

	short getES()const;
	void setES(const short aES);

	short getLS()const;
	void setLS(const short aLS);

	unsigned short getRuntime()const;
	void setRuntime(const unsigned short runtime);

	unsigned short getNeededMachine()const;
	void setNeededMachine(const unsigned short aNeededMachine);


	bool isRunning()const;
	void setRunning(const bool aRunning);

private:
	short ES;
	short LS;

	unsigned short id;
	unsigned short runtime;
	unsigned short neededMachine;
	bool running;

};



#endif /* TASK_H_ */
