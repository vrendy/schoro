#include "Jobshop.h"
#include "Job.h"
#include "Task.h"

#include <fstream>
#include <iostream>

#define WHITESPACE 32
#define NEWLINE 10

int main ( int argc, char *argv[] )
{
	Task t1(0, 0, 30);
	Task t2(1, 1, 30);
	Task t3(2, 2, 10);

	Task t4(0, 0, 60);
	Task t5(1, 1, 15);
	Task t6(2, 2, 10);

	Job j1(0);
	Job j2(1);

	j1.addTask(Task(0, 0, 30));
	j1.addTask(t2);
	j1.addTask(t3);

	j2.addTask(t4);
	j2.addTask(t5);
	j2.addTask(t6);

	Jobshop shop(2, 3);

	shop.addJob(j1);
	shop.addJob(j2);
	std::cout << j1.getRemainingJobTime() << std::endl;
	std::cout << j2.getRemainingJobTime() << std::endl;
//	std::cout << shop.getLongestJobTime() << std::endl; // maak weer private
//	std::cout << (int)shop.getMachineId(j1) << std::endl;
//	std::cout << (int)shop.getMachineId(j2) << std::endl;
	shop.dispatch();
	// kijk van alle jobs wat de machine van de uit te voeren task is
	// bepaal welke taak/job eerst mag, als de zelfde machine gebruikt moet worden
}



	// Jobshop.addJob(j1);
	// Jobshop.addJob(j2);


 /* if (argc != 2) // If program is called differently than with 2 arguments
    std::cout << "Invalid argument, usage: './SchedulingJobShop <filename.txt>" << std::endl;
  else
  {
    // argv[1] is the filename to open
    std::ifstream the_file(argv[1]);
    if(!the_file.is_open())
      std::cout << "Could not open file" << std::endl;
    else
    {
      char x;
      char lineCounter = 0;
      char taskCounter = 0;
      char nJobs = 0;
      char nMachines = 0;
      while(the_file.get(x)) // returns false at the end of file or when error occurs
      {
    	  std::cout << "x: " << x << std::endl;
    	  if(the_file.peek() != WHITESPACE && the_file.peek() != NEWLINE) // Next char will be another number
    	  {
    		  std::cout << "x: " << x << std::endl;
    		  x = (x * 10) + the_file.peek(); // Make actual number
    		  //std::cout << "(x * 10): " << (x * 10) << std::endl;
    		  the_file.get();				  // Skip next, because we accessed it with peek()
    		  //std::cout << "test x: " << (int)x << std::endl;
    	  }
		  if( x == '\n')
			  ++lineCounter;
		  if( x != ' ') // if x is not newline or whitespace, it must be another number
		  {
			  if(lineCounter == 0)
			  {
				  int test;
				  test = the_file.peek();
//				  std::cout << "x: " << x << std::endl;
//				  std::cout << "Peek: " << test << std::endl;
			  }
		  }
			  // x + the_file.peek

//		  char a = 1;
//		  char b = 2;
//		  unsigned short c = 0;
//		  c |= (a * 10) + b;
//		  std::cout << c << std::endl;


		  switch(lineCounter)
		  {
		  case 0:
			  if(taskCounter == 0)
				  nJobs = x;
			  if(taskCounter == 1)
				  nMachines = x;
			  if(x != ' ')
			  {
				  ++taskCounter;
			  }
			  break;
		  }
      }
      std::cout << "\nNumber of jobs:\t\t" << nJobs << std::endl;
      std::cout << "Number of machines:\t" << nMachines << std::endl;
    }
    the_file.close();
  }
}*/
