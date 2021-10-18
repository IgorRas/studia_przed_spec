#include <iostream>

void digitize(std::string &s)	{
	auto target=s.begin();
	for (auto source = s.begin(); source<s.end(); source++)	{
		if (std::isdigit(*source))	{
			*target = *source;
			target++;
		}
	}
	s.erase(target, s.end());
}

int main()	{
	std::string s = "123 - 45 67-89";
	digitize(s);
	std::cout<<s<<std::endl;
}
