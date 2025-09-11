#include "ScavTrap.hpp"
#include <iostream>

int main()
{
	std::cout << "=== ScavTrap Tests ===" << std::endl;
	// Test 1: Basic functionality
	std::cout << "\n--- Test 1: Basic functionality ---" << std::endl;
	ScavTrap scav1("Guardian1");
	scav1.attack("Enemy1");
	scav1.takeDamage(20);
	scav1.beRepaired(10);
	scav1.guardGate();
	// Test 2: Energy depletion
	std::cout << "\n--- Test 2: Energy depletion ---" << std::endl;
	ScavTrap scav2("Guardian2");
	for (int i = 0; i < 51; i++) // Should run out of energy after 50 attacks
	{
		std::cout << "Attack " << (i + 1) << ": ";
		scav2.attack("Target");
	}
	// Test 3: Hit points depletion
	std::cout << "\n--- Test 3: Hit points depletion ---" << std::endl;
	ScavTrap scav3("Guardian3");
	scav3.takeDamage(120);  // More damage than hit points
	scav3.attack("Enemy"); // Should not be able to attack
	scav3.beRepaired(10);   // Should not be able to repair
	scav3.guardGate();      // Should still be able to toggle gate mode
	// Test 4: Copy constructor and assignment
	std::cout << "\n--- Test 4: Copy constructor and assignment ---"<< std::endl;
	ScavTrap scav4("Original");
	ScavTrap scav5(scav4); // Copy constructor
	ScavTrap scav6("Temp");
	scav6 = scav4; // Assignment operator

	std::cout << "\n=== Tests Complete ===" << std::endl;
	return 0;
}