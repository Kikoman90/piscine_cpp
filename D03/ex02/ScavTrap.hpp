#ifndef SCAVTRAP_HPP
# define SCAVTRAP_HPP

# include <string>

class   ScavTrap{

public:
    ScavTrap(std::string const name);
    ScavTrap(ScavTrap const &src);
    ~ScavTrap(void);

    ScavTrap &operator=(ScavTrap const &rhs);

    void    rangedAttack(std::string const & target);
    void    meleeAttack(std::string const & target);
    void    takeDamage(unsigned int amount);
    void    beRepaired(unsigned int amount);

    void    challengeNewcomer(std::string const &target);

    std::string const   name;

private:
    ScavTrap(void);

    void    log() const;

    unsigned int        hitPoints;
    unsigned int        maxHitPoints;
    unsigned int        energyPoints;
    unsigned int        maxEnergyPoints;
    unsigned int        level;
    unsigned int        meleeAttackDamage;
    unsigned int        rangedAttackDamage;
    unsigned int        armorDamageReduction;
};

#endif