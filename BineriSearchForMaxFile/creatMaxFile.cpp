#include <iostream>
#include <string>
#include <fstream>
#include <bitset>
#include <ctime>

#include "Utility.h"

int main()
{
	std::string str = Util::path ;
	str += Util::fileName ;

	std::fstream fout (str,std::ios::out);

	if ( !fout.is_open() ) {std::cout<< "ERROR" << std::endl; return -1 ;}
	std::srand(std::time(0));

	for ( int i = 0 ; i < Util::maxCount ; ++i )
	{
		fout << std::rand() % Util::maxElemSize << "\n";
	}

}
