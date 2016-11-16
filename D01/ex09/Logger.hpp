/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Logger.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsidler <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/09 15:45:44 by fsidler           #+#    #+#             */
/*   Updated: 2016/11/09 17:39:17 by fsidler          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LOGGER_HPP
# define LOGGER_HPP

# include <iostream>
# include <sstream>
# include <fstream>

class Logger
{
	public:

		Logger(std::string filename);
		~Logger(void);

		void				log(std::string const & dest, std::string const & message);

	private:

		std::string			_filename;
		std::string 		makeLogEntry(std::string const & message);
		void				logToFile(std::string const & message);
		void				logToConsole(std::string const & message);
};

#endif
