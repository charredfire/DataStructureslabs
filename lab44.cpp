//Charles Dunlap
// CS 2315
//lab44

#include <iostream>
#include <cstdlib>
#include <cctype>
#include <string>
#include <deque>
#include <algorithm>

using namespace std;

bool isPalindrome(string str)
{
	deque <char> r,t;
	
	
	// turns string into all uppercase
	transform(str.begin(), str.end(),str.begin() , static_cast<int (*)(int)>(toupper));
	
	//puts the string into loops r & s
	for(uint i = 0; i < str.size(); i++)
	{
		r.emplace_back(str[i]);
		t.emplace_back(str[i]);
	}
	
	
	while(!r.empty() && !t.empty())
	{
		if(r.front() != t.back())
		{
			return false;
		}
		r.pop_front();
		t.pop_back();
	}
			
		
	return true;	
}