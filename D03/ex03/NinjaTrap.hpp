#ifndef NINJATRAP_HPP
# define NINJATRAP_HPP

# include "ClapTrap.hpp"

class   NinjaTrap : public ClapTrap{

public:
    NinjaTrap(std::string const name);
    NinjaTrap(NinjaTrap const &src);
    ~NinjaTrap(void);

    NinjaTrap &operator=(NinjaTrap const &rhs);

    void    ninjaShoebox(std::string const &target);

private:
    NinjaTrap(void);

};

#endif