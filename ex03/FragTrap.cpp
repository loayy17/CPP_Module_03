#include "FragTrap.hpp"
#include <iostream>

FragTrap::FragTrap(std::string n) : ClapTrap(n)
{
	hitPoints = 100;
	energyPoints = 100;
	attackDamage = 30;
	std::cout << "FragTrap " << name << " created!" << std::endl;
}
FragTrap::~FragTrap()
{
	std::cout << "FragTrap " << name << " destroyed!" << std::endl;
}
FragTrap::FragTrap(const FragTrap& other) : ClapTrap(other)
{
	std::cout << "FragTrap " << other.name << " copied!" << std::endl;
}
FragTrap& FragTrap::operator=(const FragTrap& other)
{
	if (this != &other)
	{
		ClapTrap::operator=(other);
	}
	std::cout << "FragTrap assigned!" << std::endl;
	return *this;
}
void FragTrap::highFivesGuys(void)
{
	if (hitPoints == 0)
	{
		std::cout << "FragTrap " << name
		          << " cannot high five, it is destroyed!" << std::endl;
		return;
	}
	std::cout << "FragTrap " << name << " requests a high five! ✋"
	          << std::endl;
}