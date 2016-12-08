/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsidler <fsidler@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/03 17:23:23 by fsidler           #+#    #+#             */
/*   Updated: 2016/12/08 18:49:10 by fsidler          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "CentralBureaucracy.hpp"
#include "OfficeBlock.hpp"
#include "Bureaucrat.hpp"
#include "Form.hpp"
#include "Intern.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

int     main(void)
{
	std::cout << "_creating the Central Bureaucracy and 20 bureaucrats_" << std::endl;
	CentralBureaucracy	centralBur;

    Bureaucrat  bur1 = Bureaucrat("Hermes Conrad", 7);
    Bureaucrat  bur2 = Bureaucrat("Bobby Bobson", 80);
	Bureaucrat	bur3 = Bureaucrat("Jimmy Neutron", 20);
	Bureaucrat	bur4 = Bureaucrat("Tom", 24);
	Bureaucrat	bur5 = Bureaucrat("Alfredo", 1);
	Bureaucrat	bur6 = Bureaucrat("Gabi", 2);
	Bureaucrat	bur7 = Bureaucrat("Hugo", 150);
	Bureaucrat	bur8 = Bureaucrat("Steinman", 130);
	Bureaucrat	bur9 = Bureaucrat("Bsouchet", 100);
	Bureaucrat	bur10 = Bureaucrat("Artouuuur", 15);
	Bureaucrat	bur11 = Bureaucrat("BEATA", 3);
	Bureaucrat	bur12 = Bureaucrat("miss White", 60);
	Bureaucrat	bur13 = Bureaucrat("jesse", 50);
	Bureaucrat	bur14 = Bureaucrat("Rick", 45);
	Bureaucrat	bur15 = Bureaucrat("Andre", 48);
	Bureaucrat	bur16 = Bureaucrat("Lola", 111);
	Bureaucrat	bur17 = Bureaucrat("Florentin", 26);
	Bureaucrat	bur18 = Bureaucrat("Jean-victime", 149);
	Bureaucrat	bur19 = Bureaucrat("GingerFgt", 14);
	Bureaucrat	bur20 = Bureaucrat("Pere Noel", 69);
	
	std::cout << "_assigning bureaucrats to the offices_" << std::endl;
	centralBur.feed(bur1);
	centralBur.feed(bur2);
	centralBur.feed(bur3);
	centralBur.feed(bur4);
	centralBur.feed(bur5);
	centralBur.feed(bur6);
	centralBur.feed(bur7);
	centralBur.feed(bur8);
	centralBur.feed(bur9);
	centralBur.feed(bur10);
	centralBur.feed(bur11);
	centralBur.feed(bur12);
	centralBur.feed(bur13);
	centralBur.feed(bur14);
	centralBur.feed(bur15);
	centralBur.feed(bur16);
	centralBur.feed(bur17);
	centralBur.feed(bur18);
	centralBur.feed(bur19);
	centralBur.feed(bur20);

	std::cout << "_creating and queuing up targets_" << std::endl;
	centralBur.queueUp("le frere jumean de Valentin");
	centralBur.queueUp("PHILIPPE");
	centralBur.queueUp("Le rat des champs");
	centralBur.queueUp("Carlos");
	centralBur.queueUp("Omar le Homard");
	centralBur.queueUp("Xavier Niel");
	centralBur.queueUp("frederic le poto");
	centralBur.queueUp("geekos2000");
	centralBur.queueUp("bsouchette");
	centralBur.queueUp("France!");
	centralBur.queueUp("Pachenko");
	centralBur.queueUp("Putin");
	centralBur.queueUp("Dimitriv");
	centralBur.queueUp("Petrova");
	centralBur.queueUp("a fake girl");
	centralBur.queueUp("justin");
	centralBur.queueUp("Anthony");
	centralBur.queueUp("un chat mignon");
	
	std::cout << std::endl << "_let the magic begin_" << std::endl;
	centralBur.doBureaucracy();
	return (0);
}