/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   OfficeBlock.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsidler <fsidler@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/08 13:00:36 by fsidler           #+#    #+#             */
/*   Updated: 2017/01/21 19:10:17 by fsidler          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef OFFICE_BLOCK_HPP
# define OFFICE_BLOCK_HPP

# include "Bureaucrat.hpp"
# include "Intern.hpp"
# include "Form.hpp"

class OfficeBlock {

    private:

        Intern          *_intern;
        Bureaucrat      *_signer;
        Bureaucrat      *_executor;

        OfficeBlock(OfficeBlock const &src);
        
    public:
        class NoInternException : public std::exception {
            public:
                NoInternException();
                NoInternException(NoInternException const &src);
                virtual ~NoInternException() throw();

                NoInternException   &operator=(NoInternException const &rhs);

                char const          *what(void) const throw();

        };

        class NoSignerException : public std::exception {
            public:
                NoSignerException();
                NoSignerException(NoSignerException const &src);
                virtual ~NoSignerException() throw();

                NoSignerException   &operator=(NoSignerException const &rhs);

                char const          *what(void) const throw();

        };

        class NoExecutorException : public std::exception {
            public:
                NoExecutorException();
                NoExecutorException(NoExecutorException const &src);
                virtual ~NoExecutorException() throw();

                NoExecutorException   &operator=(NoExecutorException const &rhs);

                char const          *what(void) const throw();

        };

        class BureaucracyFailedException : public std::exception {
            public:
                BureaucracyFailedException();
                BureaucracyFailedException(BureaucracyFailedException const &src);
                virtual ~BureaucracyFailedException() throw();

                BureaucracyFailedException   &operator=(BureaucracyFailedException const &rhs);

                char const          *what(void) const throw();

        };

        OfficeBlock();
        OfficeBlock(Intern *intern, Bureaucrat *signer, Bureaucrat *executor);
        ~OfficeBlock();
        
        OfficeBlock     &operator=(OfficeBlock const &rhs);

        void            setIntern(Intern &ntrn);
        void            setSigner(Bureaucrat &sgnr);
        void            setExecutor(Bureaucrat &xctr);

        void            doBureaucracy(std::string const formName, std::string const target) const;

};

#endif