#include "Sorcerer.hpp"
#include "Victim.hpp"
#include "Peon.hpp"

int main()
{
    Sorcerer    Sorc("Robert", "the Magnificent");
    
    Victim      Vict("Pierre-Baptiste");
    Peon        Pe("Jerem");

    std::cout << Sorc << Vict << Pe;

    Sorc.polymorph(Vict);
    Sorc.polymorph(Pe);

    return 0;
}