#ifndef VICTIM_HPP
# define VICTIM_HPP

# include <iostream>

class Victim {

    public:
        Victim(std::string const name);
        Victim(Victim const &src);
        ~Victim(void);

        Victim          &operator=(Victim const &rhs);

        virtual void    getPolymorphed(void) const;

        std::string     getName(void) const;
        void            setName(std::string const name);

    private:
        std::string     _name;
        Victim(void);

};

std::ostream        &operator<<(std::ostream &o, Victim const &rhs);

#endif