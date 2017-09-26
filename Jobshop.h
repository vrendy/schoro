/*
 * Jobshop.h
 *
 *  Created on: Sep 22, 2017
 *      Author: vrendy
 */

#ifndef JOBSHOP_H_
#define JOBSHOP_H_

#include <vector>

#include "Job.h"

class Jobshop {
public:
	Jobshop(unsigned char anJobs, unsigned char anMachines);
	virtual ~Jobshop();
	void addJob(const Job& aJob);

	void dispatch(); //temp

private:
	/* getLongestJobTime resolves the Job with the longest remaining time from jobList
	 * @returns unsigned short longestTime
	 */
	unsigned short getLongestJobTime() const;

	/* getMachineId resolves the machineId of the next Task for the given Job
	 * @param Job to get the machineId of the next task from
	 * @returns unsigned char machineId
	 */
	unsigned char getMachineId(const Job& aJob) const;

//	void dispatch();


	unsigned char nJobs;			// Number of Jobs in the Jobshop
	unsigned char nMachines;		// Number of Machines in the Jobshop
	std::vector<Job> jobList;
};

#endif /* JOBSHOP_H_ */
