#include "ClapTrap.hpp"
#include <iostream>

ClapTrap::ClapTrap(std::string n)
    : name(n), hitPoints(10), energyPoints(10), attackDamage(0)
{
	std::cout << "ClapTrap " << name << " created!" << std::endl;
}

ClapTrap::~ClapTrap()
{
	std::cout << "ClapTrap " << name << " destroyed!" << std::endl;
}

ClapTrap::ClapTrap(const ClapTrap& other)
    : name(other.name),
      hitPoints(other.hitPoints),
      energyPoints(other.energyPoints),
      attackDamage(other.attackDamage)
{
	std::cout << "ClapTrap " << name << " copied!" << std::endl;
}

ClapTrap& ClapTrap::operator=(const ClapTrap& other)
{
	if (this != &other)
	{
		this->name = other.name;
		this->hitPoints = other.hitPoints;
		this->energyPoints = other.energyPoints;
		this->attackDamage = other.attackDamage;
	}
	std::cout << "ClapTrap " << name << " assigned!" << std::endl;
	return *this;
}

void ClapTrap::attack(const std::string& target)
{
	if (!canDoAction())
		return;
	std::cout << "ClapTrap " << name << " attacks " << target << ", causing "
	          << attackDamage << " points of damage!" << std::endl;
	energyPoints--;
}

void ClapTrap::takeDamage(unsigned int amount)
{
	std::cout << "ClapTrap " << name << " takes " << amount
	          << " points of damage!" << std::endl;

	if (amount >= hitPoints)
		hitPoints = 0;
	else
		hitPoints -= amount;
}

void ClapTrap::beRepaired(unsigned int amount)
{
	if (!canDoAction())
		return;

	hitPoints += amount;
	std::cout << "ClapTrap " << name << " is repaired for " << amount
	          << " points!" << std::endl;
	energyPoints--;
}

bool ClapTrap::canDoAction()
{
	if (hitPoints <= 0)
	{
		std::cout << "ClapTrap " << name << " is out of hit points!"
		          << std::endl;
		return false;
	}
	if (energyPoints <= 0)
	{
		std::cout << "ClapTrap " << name << " is out of energy points!"
		          << std::endl;
		return false;
	}
	return true;
}