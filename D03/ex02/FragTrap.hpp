#ifndef FRAGTRAP_HPP
# define FRAGTRAP_HPP

# include <string>

class   FragTrap{

public:
    FragTrap(std::string const name);
    FragTrap(FragTrap const &src);
    ~FragTrap(void);

    FragTrap &operator=(FragTrap const &rhs);

    void    rangedAttack(std::string const & target);
    void    meleeAttack(std::string const & target);
    void    takeDamage(unsigned int amount);
    void    beRepaired(unsigned int amount);

    void    makeJoke(std::string const  &target);
    void    makeSpin(std::string const &target);
    void    makeOffensiveGesture(std::string const &target);
    void    vaulthunter_dot_exe(std::string const & target);

    std::string const   name;

private:
    FragTrap(void);

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