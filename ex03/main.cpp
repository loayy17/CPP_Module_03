#include "DiamondTrap.hpp"
#include <iostream>

int main()
{
	std::cout << "=== DiamondTrap Tests ===" << std::endl;
	// Test 1: Basic functionality
	std::cout << "\n--- Test 1: Basic functionality ---" << std::endl;
	DiamondTrap diamond1("Guardian1");
	diamond1.attack("Enemy1");
	diamond1.takeDamage(20);
	diamond1.beRepaired(10);
	diamond1.whoAmI();
	// Test 2: Energy depletion
	std::cout << "\n--- Test 2: Energy depletion ---" << std::endl;
	DiamondTrap diamond2("Guardian2");
	for (int i = 0; i < 51; i++) // Should run out of energy after 50 attacks
	{
		std::cout << "Attack " << (i + 1) << ": ";
		diamond2.attack("Target");
	}
	// Test 3: Hit points depletion
	std::cout << "\n--- Test 3: Hit points depletion ---" << std::endl;
	DiamondTrap diamond3("Guardian3");
	diamond3.takeDamage(120); // More damage than hit points
	diamond3.attack("Enemy"); // Should not be able to attack
	diamond3.beRepaired(10);  // Should not be able to repair
	diamond3.highFivesGuys(); // Should still be able to toggle gate mode
	// Test 4: Copy constructor and assignment
	std::cout << "\n--- Test 4: Copy constructor and assignment ---"
	          << std::endl;
	DiamondTrap diamond4("Original");
	DiamondTrap diamond5(diamond4); // Copy constructor
	DiamondTrap diamond6("Temp");
	diamond6 = diamond4; // Assignment operator

	std::cout << "\n=== Tests Complete ===" << std::endl;
	return 0;
}