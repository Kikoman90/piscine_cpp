#ifndef ClapTrap_HPP
# define ClapTrap_HPP

# include <string>

class   ClapTrap{

public:
    ClapTrap(std::string const name);
    ClapTrap(ClapTrap const &src);
    ~ClapTrap(void);

    ClapTrap &operator=(ClapTrap const &rhs);

    void    rangedAttack(std::string const & target);
    void    meleeAttack(std::string const & target);
    void    takeDamage(unsigned int amount);
    void    beRepaired(unsigned int amount);

    std::string const   name;

protected:
    ClapTrap(void);

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