#include "DiamondTrap.hpp"
#include <iostream>
DiamondTrap::DiamondTrap(std::string n)
    : ClapTrap(n + "_clap_name"), ScavTrap(n), FragTrap(n), name(n) {
  hitPoints = 100;
  energyPoints = 50;
  attackDamage = 30; 
  std::cout << "DiamondTrap " << name << " created!" << std::endl;
}

DiamondTrap::~DiamondTrap() {
  std::cout << "DiamondTrap " << name << " destroyed!" << std::endl;
}

DiamondTrap::DiamondTrap(const DiamondTrap &other)
    : ClapTrap(other), ScavTrap(other), FragTrap(other), name(other.name) {
  std::cout << "DiamondTrap " << other.name << " copied!" << std::endl;
}
DiamondTrap &DiamondTrap::operator=(const DiamondTrap &other) {
  if (this != &other) {
    ClapTrap::operator=(other);
    ScavTrap::operator=(other);
    FragTrap::operator=(other);
    this->name = other.name;
  }
  std::cout << "DiamondTrap " << name << " assigned!" << std::endl;
  return *this;
}
void DiamondTrap::whoAmI() {
  std::cout << "DiamondTrap name: " << name
            << ", ClapTrap name: " << ClapTrap::name << std::endl;
}

void DiamondTrap::attack(const std::string &target) {
  ScavTrap::attack(target);
}