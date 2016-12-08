/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   CentralBureaucracy.hpp                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsidler <fsidler@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/08 16:42:31 by fsidler           #+#    #+#             */
/*   Updated: 2016/12/08 18:17:34 by fsidler          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CENTRAL_BUREAUCRACY_HPP
# define CENTRAL_BUREAUCRACY_HPP

# include "OfficeBlock.hpp"

typedef struct              s_targetQueue
{
    std::string             target;
    struct s_targetQueue    *next;
}                           t_targetQueue;

class CentralBureaucracy {

    private:
        OfficeBlock         _blocks[20];
        t_targetQueue       *_queue;

        void                _freeQueue();

        unsigned int        _blockCount;
        unsigned int        _bureaucratCount;

    public:
        CentralBureaucracy();
        CentralBureaucracy(CentralBureaucracy const &src);
        ~CentralBureaucracy();

        CentralBureaucracy  &operator=(CentralBureaucracy const &rhs);

        void                feed(Bureaucrat &bureaucrat);
        void                doBureaucracy() const;
        void                queueUp(std::string target);
        t_targetQueue       *pushTarget(std::string target);

};

#endif