#include "FragTrap.hpp"
#include "ScavTrap.hpp"

int main(void)
{
    FragTrap    FragTrap("FragTrap");
    ScavTrap    ScavTrap("ScavTrap");

    FragTrap.beRepaired(20);
    FragTrap.meleeAttack("Bullymong");
    FragTrap.rangedAttack("Bullymong");
    FragTrap.takeDamage(30);
    FragTrap.vaulthunter_dot_exe("Bullymong");
    FragTrap.vaulthunter_dot_exe("Bullymong");
    FragTrap.vaulthunter_dot_exe("Bullymong");
    FragTrap.vaulthunter_dot_exe("Bullymong");
    FragTrap.beRepaired(20);

    ScavTrap.beRepaired(20);
    ScavTrap.meleeAttack("Bullymong");
    ScavTrap.rangedAttack("Bullymong");
    ScavTrap.takeDamage(30);
    ScavTrap.challengeNewcomer("Bullymong");
    ScavTrap.challengeNewcomer("Bullymong");
    ScavTrap.challengeNewcomer("Bullymong");
    ScavTrap.beRepaired(20);
}
