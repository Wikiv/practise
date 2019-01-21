#include<iostream>
#include <map>
#include <string>
using namespace std; 
class User
{
	string m_id;
	string m_name;
public:
	User(string name, std::string id) :
			m_id(id), m_name(name)
	{
	}
/*	const std::string& getId() const
	{
		return m_id;
	}
	const std::string& getName() const
	{
		return m_name;
	}
	bool operator<(const User& userObj) const
	{
		if (userObj.m_id < this->m_id)
			return true;
	}*/
};
 
void example_1()
{
	std::map<User, int> m_UserInfoMap;
 
	m_UserInfoMap.insert(std::make_pair<User, int>(User("Mr.X", "3"), 100));
	m_UserInfoMap.insert(std::make_pair<User, int>(User("Mr.X", "1"), 120));
	m_UserInfoMap.insert(std::make_pair<User, int>(User("Mr.Z", "2"), 300));
 
	std::map<User, int>::iterator it = m_UserInfoMap.begin();
	for (; it != m_UserInfoMap.end(); it++)
	{
		std::cout << it->first << " :: " << it->second << std::endl;
	}
}
/*struct UserNameComparator
{
	bool operator()(const User &left, const User &right) const
	{
		return (left.getName() > right.getName());
	}
};
 
void example_2()
{
	std::map<User, int, UserNameComparator> m_UserInfoMap;
 
	m_UserInfoMap.insert(std::make_pair<User, int>(User("Mr.X", "3"), 100));
	m_UserInfoMap.insert(std::make_pair<User, int>(User("Mr.X", "1"), 120));
	m_UserInfoMap.insert(std::make_pair<User, int>(User("Mr.Z", "2"), 300));
 
	std::map<User, int, UserNameComparator>::iterator it =
			m_UserInfoMap.begin();
	for (; it != m_UserInfoMap.end(); it++)
	{
		std::cout << it->first.getName() << " :: " << it->second << std::endl;
	}
}*/
int main()
{
	std::cout << "EXAMPLE 1 :: Comparing by ID" << std::endl;
	example_1();
//	std::cout << "EXAMPLE 1 :: Comparing by NAME" << std::endl;
//	example_2();
	return 0;
}
