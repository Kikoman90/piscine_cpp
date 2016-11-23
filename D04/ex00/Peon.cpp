#include "Peon.hpp"

Peon::Peon(std::string const name) : Victim(name)
{
    std::cout << "Zog zog." << std::endl;
}

Peon::Peon(Peon const &src) : Victim(src)
{
    *this = src;
}

Peon::~Peon(void)
{
    std::cout << "Bleuark..." << std::endl;
}

void        Peon::getPolymorphed(void) const
{
    std::cout << this->getName() << " has been turned into a pink pony !" << std::endl;
}

Peon        &Peon::operator=(Peon const &rhs)
{
    if (this != &rhs)
        this->setName(rhs.getName());
    return (*this);
}