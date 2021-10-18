#include <iostream>

void trim(std::string &s)	{
	auto i=s.begin();
	for(;i<s.end()&&std::isspace(*i);i++);
	s.erase(s.begin(),i);
	i=s.end();
	while (std::isspace(*--i)&&s.begin()<i);
	if(i<s.end())	{
		s.erase(i+1,s.end());
	}
}

int main()	{
	std::string s=" ala ma kota \t\n";
	trim(s);
	std::cout<<s<<"| "<<std::endl;
}
