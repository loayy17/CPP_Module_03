#include "FragTrap.hpp"
#include <iostream>

int main()
{
	std::cout << "=== FragTrap Tests ===" << std::endl;
	// Test 1: Basic functionality
	std::cout << "\n--- Test 1: Basic functionality ---" << std::endl;
	FragTrap frag1("Guardian1");
	frag1.attack("Enemy1");
	frag1.takeDamage(20);
	frag1.beRepaired(10);
	frag1.highFivesGuys();
	// Test 2: Energy depletion
	std::cout << "\n--- Test 2: Energy depletion ---" << std::endl;
	FragTrap frag2("Guardian2");
	for (int i = 0; i < 51; i++) // Should run out of energy after 50 attacks
	{
		std::cout << "Attack " << (i + 1) << ": ";
		frag2.attack("Target");
	}
	// Test 3: Hit points depletion
	std::cout << "\n--- Test 3: Hit points depletion ---" << std::endl;
	FragTrap frag3("Guardian3");
	frag3.takeDamage(120); // More damage than hit points
	frag3.attack("Enemy"); // Should not be able to attack
	frag3.beRepaired(10);  // Should not be able to repair
	frag3.highFivesGuys(); // Should still be able to toggle gate mode
	// Test 4: Copy constructor and assignment
	std::cout << "\n--- Test 4: Copy constructor and assignment ---"
	          << std::endl;
	FragTrap frag4("Original");
	FragTrap frag5(frag4); // Copy constructor
	FragTrap frag6("Temp");
	frag6 = frag4; // Assignment operator

	std::cout << "\n=== Tests Complete ===" << std::endl;
	return 0;
}