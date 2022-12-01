/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tandroma <tandroma@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/26 17:45:00 by tandroma          #+#    #+#             */
/*   Updated: 2022/10/27 22:15:44 by tandroma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"

ScavTrap::ScavTrap()
{
	std::cout << "Default constructor called. ScavTrap " << this->_name << " create" << std::endl;
}

ScavTrap::ScavTrap(std::string const name): ClapTrap(name)
{
	std::cout << "Constructor with parametrs called. ScavTrap " << this->_name << " create" << std::endl;
}

ScavTrap::~ScavTrap()
{
	std::cout << "Destructor called. ScavTrap " << this->_name << " destroy" << std::endl;
}

ScavTrap::ScavTrap(ScavTrap const &copy): ClapTrap(copy)
{
	std::cout << "ScavTrap " << this->_name << " copy" << std::endl;
}

ScavTrap	&ScavTrap::operator=(ScavTrap const &copy)
{
	std::cout << "Copy assignment operator for ScavTrap" << std::endl;
	ClapTrap::operator=(copy);
	return (*this);
}

void ScavTrap::attack(const std::string& target)
{
    if (this->_energyPoints > 0 && this->_hitPoints > 0)
	{
		this->_attackDamage++;
		std::cout << "ScavTrap " << this->_name << " attacks " << target << ", causing " << this->_attackDamage << " points of damage!" << std::endl;
		this->_energyPoints--;
	}
	if (this->_hitPoints <= 0)
		std::cout << "ScavTrap " << this->_name << " dead" << std::endl;
	else if (!this->_energyPoints)
		std::cout << "ScavTrap " << this->_name << " hasn't energy points" << std::endl;
}

void	ScavTrap::guardGate()
{
	if (this->_hitPoints <= 0)
		std::cout << "Can't be gate-keeper mode, because: ClapTrap " << this->_name << " die" << std::endl;
	else
		std::cout << "ScavTrap " << this->_name << " says his mode: \"Guard Gate\"." << std::endl;
}
