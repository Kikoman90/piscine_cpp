/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Logger.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsidler <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/09 16:34:37 by fsidler           #+#    #+#             */
/*   Updated: 2016/11/09 18:10:41 by fsidler          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Logger.hpp"

Logger::Logger(std::string filename) : _filename(filename)
{
	return ;
}

Logger::~Logger(void)
{
	return ;
}

std::string			Logger::makeLogEntry(std::string const & message)
{
	time_t				cur_time = time(NULL);
	struct tm			*local_t = localtime(&cur_time);
	std::ostringstream	sdest;
  	
	sdest << "[" << (local_t->tm_year + 1900) << '-' << (local_t->tm_mon + 1)
		<< '-' <<  local_t->tm_mday << "] " << message;
	return (sdest.str());
}

void				Logger::logToConsole(std::string const & message)
{
	std::cout << message << std::endl;
}

void				Logger::logToFile(std::string const & message)
{
	std::ofstream	file(this->_filename);

	file << message << std::endl;
	file.close();
}

void				Logger::log(std::string const & dest, std::string const & message)
{
	int	i = 0;
	const std::string	arrName[2] = {"console", "file"};
	void				(Logger::*arrPtr[2])(std::string const & message) =
		{&Logger::logToConsole, &Logger::logToFile};
	std::string			log_msg;

	log_msg = Logger::makeLogEntry(message);
	while (i < 2)
	{
		if (dest.compare(arrName[i]) == 0)
			(this->*arrPtr[i])(log_msg);
		i++;
	}
}
