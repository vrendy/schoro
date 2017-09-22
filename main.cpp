#include <fstream>
#include <iostream>

int main ( int argc, char *argv[] )
{
  if (argc != 2) // If program is called differently than with 2 arguments
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
      while(the_file.get(x)) // returns false at the end of file or when error occurs
        std::cout<< x;
    }
    the_file.close();
  }
}
