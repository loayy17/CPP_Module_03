#include "ClapTrap.hpp"
#include <iostream>

int main()
{
	std::cout << "=== ClapTrap Tests ===" << std::endl;

	// Test 1: Basic functionality
	std::cout << "\n--- Test 1: Basic functionality ---" << std::endl;
	ClapTrap clap1("Robot1");
	clap1.attack("Enemy1");
	clap1.takeDamage(5);
	clap1.beRepaired(3);

	// Test 2: Energy depletion
	std::cout << "\n--- Test 2: Energy depletion ---" << std::endl;
	ClapTrap clap2("Robot2");
	for (int i = 0; i < 11; i++) // Should run out of energy after 10 attacks
	{
		std::cout << "Attack " << (i + 1) << ": ";
		clap2.attack("Target");
	}

	// Test 3: Hit points depletion
	std::cout << "\n--- Test 3: Hit points depletion ---" << std::endl;
	ClapTrap clap3("Robot3");
	clap3.takeDamage(15);  // More damage than hit points
	clap3.attack("Enemy"); // Should not be able to attack
	clap3.beRepaired(5);   // Should not be able to repair
	return 0;
}