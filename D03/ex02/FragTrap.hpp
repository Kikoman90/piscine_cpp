#ifndef FRAGTRAP_HPP
# define FRAGTRAP_HPP

# include "ClapTrap.hpp"

class   FragTrap : public ClapTrap{

public:
    FragTrap(std::string const name);
    FragTrap(FragTrap const &src);
    ~FragTrap(void);

    FragTrap &operator=(FragTrap const &rhs);


    void    makeJoke(std::string const  &target);
    void    makeSpin(std::string const &target);
    void    makeOffensiveGesture(std::string const &target);
    void    vaulthunter_dot_exe(std::string const & target);

private:
    FragTrap(void);

};

#endif