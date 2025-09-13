#include "ScavTrap.hpp"
#include <iostream>
ScavTrap::ScavTrap(std::string n) : ClapTrap(n), inGateKeeperMode(false)
{
	hitPoints = 100;
	energyPoints = 50;
	attackDamage = 20;
	std::cout << "ScavTrap " << name << " created!" << std::endl;
}
ScavTrap::~ScavTrap()
{
	std::cout << "ScavTrap " << name << " destroyed!" << std::endl;
}
ScavTrap::ScavTrap(const ScavTrap& other)
    : ClapTrap(other), inGateKeeperMode(other.inGateKeeperMode)
{
	std::cout << "ScavTrap " << other.name << " copied!" << std::endl;
}
ScavTrap& ScavTrap::operator=(const ScavTrap& other)
{
	if (this != &other)
	{
		ClapTrap::operator=(other);
		this->inGateKeeperMode = other.inGateKeeperMode;
	}
	std::cout << "ScavTrap assigned!" << std::endl;
	return *this;
}
void ScavTrap::attack(const std::string& target)
{
	if (!canDoAction("ScavTrap"))
		return;
	std::cout << "ScavTrap " << name << " attacks " << target << ", causing "
	          << attackDamage << " points of damage!" << std::endl;
	energyPoints--;
}
void ScavTrap::guardGate()
{
	if (!inGateKeeperMode)
	{
		inGateKeeperMode = true;
		std::cout << "ScavTrap: " << name << " is now in Gate Keeper mode."
		          << std::endl;
	}
	else
	{
		inGateKeeperMode = false;
		std::cout << "ScavTrap: " << name << " has exited Gate Keeper mode."
		          << std::endl;
	}
}