#include <iostream>
#include <string>
#include <fstream>
#include <bitset>

#include "Utility.h"
std::string Parmition ( int mid , std::string str , bool& maxOrMin)
{
	std::fstream fout (str,std::ios_base::in);
	Util::tmpFileName[1]++;
	std::fstream fin1 (Util::tmpFileName , std::ios_base::out);
	Util::tmpFileName[1]++;
	std::fstream fin2 (Util::tmpFileName , std::ios_base::out);
	if ( !fout.is_open() && !fin1.is_open() && !fin2.is_open() )
	{
		std::cout<< "Tuft error" << std::endl;
		std::abort();
	}
	std::string s;
	size_t tmp {};
	size_t count1 {};
	size_t count2 {};
	while (!fout.eof())
	{
		fout >> s;
		if (s == "") { continue; }
		tmp = std::stoll(s);
		if (tmp > mid)
		{
			fin1 << tmp << "  ";
			count1++;
		} else {
			fin2 << tmp << "  ";
			count2++;
		}
	}
	if (count1 < count2)
	{
		Util::tmpFileName[1]--;
		maxOrMin = false ;
		return Util::tmpFileName ;
	}
		maxOrMin = true ;
		return Util::tmpFileName ;
}
std::string findMinReang (size_t& st , size_t& end , std::string str)
{
	if (st + Util::reng < end )
	{
		int mid = ( st + end )/ 2 ;
		bool maxOrMin = false ;
		std::string s = Parmition(mid,str,maxOrMin) ;
		if (maxOrMin)
		{
			end = mid;
			auto i = findMinReang(st,end,s);
			return i ;
		} else {
			st = mid;
			auto i = findMinReang(st,end,s);
			return i ;
		}
	}
	return str ;
}

int main()
{
	size_t st = 0 ;
	size_t end = Util::maxElemSize ; 
	std::string str = findMinReang(st , end , Util::fileName) ;
	std::cout<< st << "  " << end << std::endl;
	std::fstream fin (str);
	std::bitset<Util::reng> bit;
	if (!fin.is_open()) {std::cout << "Tufta Error" << std::endl;return 0 ;}
	std::string tmp;
	while ( !fin.eof() )
	{
		tmp = "";
		fin >> tmp;
		if (tmp == "") { continue; }
		bit[(std::stoll(tmp)-st)] = true;
	}
	for(int i = 0 ; i < bit.size() ; ++i)
	{
		if(!bit[i]) { std::cout<< i+st << std::endl; break; }
	
	}

	return 0 ;
}
