/*
 * main.cpp
 *
 *  Created on: Sep 22, 2017
 *      Author: Vrendy
 */

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <map>
#include <fstream>
#include <regex>

#include "Job.h"
#include "JobShop.h"
#include "Task.h"

int main(int argc, char *argv[])
{
	if(argc < 2){
		std::cout << "No input file!" << std::endl;
		return -1;
	}

	short nJobs = 0;
	std::map<short, std::vector<std::pair<short, short> > > jobList;
	std::pair<short, short> task;
	short nMachines = 0;
	std::regex reg("[0-9]+"); // 1..* numbers in a row will count as a string
	std::string line;
	std::ifstream myfile(argv[1]);

	if (!myfile.is_open())
	{
		std::cout << "Cannot open input file!" << std::endl;
		return -1;
	}

	getline(myfile, line);
	std::sregex_iterator it(line.begin(), line.end(), reg);
	std::sregex_iterator it_end;

	std::smatch match = *it;
	nJobs = stoi(match.str());
	++it;
	std::smatch match1 = *it;
	nMachines = stoi(match1.str());

	// Store all data in jobList
	short jobID = 0;
	while (getline(myfile, line) && jobID < nJobs)
	{
		std::sregex_iterator it(line.begin(), line.end(), reg);
		std::sregex_iterator it_end;
		while (it != it_end)
		{
			 std::smatch match = *it;
			 task.first = stoi(match.str());
			 ++it;
			 //Tweede
			 match = *it;
			 task.second = stoi(match.str());
			 ++it;
			 jobList[jobID].push_back(task);
		}
		++jobID;
	}
	myfile.close();
	JobShop scheduler(nMachines);
	for (auto& entry : jobList)
	{
		Job j;
		for (auto it = entry.second.begin(); it != entry.second.end(); ++it)
		{
			//int index = distance(entry.second.begin(), it);
			Task task(it->second, it->first);
			j.addTask(task);
		}
		scheduler.addJob(j);
	}
	scheduler.run();
	scheduler.printRuntimes();
	std::regex_replace(std::string(""), std::regex("[a-z]"), std::string(""));

	return 0;
}













/*
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <map>

#include "Job.hpp"
#include "Task.hpp"
#include "JobShop.hpp"

int main(int argc, char *argv[]){
	//Lees de jobs in ...
	Task taak1(30, 0);
	Task taak2(30, 1);
	Task taak3(10, 2);

	Task taak11(60, 0);
	Task taak22(15, 1);
	Task taak33(10, 2);

	JobShop sheduler(3);

	Job j1;
	Job j2;

	j1.addTask(taak1);
	j1.addTask(taak2);
	j1.addTask(taak3);

	j2.addTask(taak11);
	j2.addTask(taak22);
	j2.addTask(taak33);


	sheduler.addJob(j1);
	sheduler.addJob(j2);

	sheduler.run();
	sheduler.printRuntimes();




	return 0;
} */
