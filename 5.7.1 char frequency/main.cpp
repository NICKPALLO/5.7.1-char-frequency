#include<iostream>
#include<map>



std::multimap<int, char> invert(std::map<char, int> m1)
{
	std::multimap<int, char> m2;
	auto it = m2.begin();

	for (auto& i : m1)
	{
		m2.insert(std::pair<int, char>(i.second, i.first));
	}
	return m2;
}


int main()
{
	std::map<char, int> m1;

	std::string str = "Hello world!!";


	for (int i = 0; i < str.size(); ++i)
	{
		if (m1.find(str[i]) != m1.end())
		{
			++m1[str[i]];
		}
		else
		{
			m1[str[i]] = 1;
		}
	}

	std::multimap<int, char> m2 = invert(m1);

	auto it = m2.rbegin();

	while (it != m2.rend())
	{
		std::cout << it->second << ": " << it->first<<std::endl;
		++it;
	}
	return 0;
}