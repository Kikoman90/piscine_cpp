#ifndef SCAVTRAP_HPP
# define SCAVTRAP_HPP

# include "ClapTrap.hpp"

class   ScavTrap : public ClapTrap{

public:
    ScavTrap(std::string const name);
    ScavTrap(ScavTrap const &src);
    ~ScavTrap(void);

    ScavTrap &operator=(ScavTrap const &rhs);

    void    challengeNewcomer(std::string const &target);

private:
    ScavTrap(void);

};

#endif