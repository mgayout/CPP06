/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgayout <mgayout@student.42nice.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/05 15:40:51 by mgayout           #+#    #+#             */
/*   Updated: 2024/09/05 15:40:51 by mgayout          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCALARCONVERTER_HPP
# define SCALARCONVERTER_HPP

#include <iostream>
#include <string>
#include <limits>
#include <iomanip>
#include <cstdlib>

class ScalarConverter
{
	public:
			static void	convert(const std::string&	param);

	private:
			ScalarConverter();
			ScalarConverter(const ScalarConverter& other);
			ScalarConverter& operator=(const ScalarConverter& other);
			~ScalarConverter();
			static int	isChar(const std::string& param);
			static int	isInt(const std::string& param);
			static int	isFloat(const std::string& param);
			static int	isDouble(const std::string& param);
			static int	isOther(const std::string& param);
			static void	toChar(const std::string& param);
			static void	toInt(const std::string& param);
			static void	toFloat(const std::string& param);
			static void	toDouble(const std::string& param);
			static void	toOther(const std::string& param);
};


#endif