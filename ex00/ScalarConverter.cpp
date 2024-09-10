/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgayout <mgayout@student.42nice.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/05 15:54:51 by mgayout           #+#    #+#             */
/*   Updated: 2024/09/05 15:54:51 by mgayout          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"

ScalarConverter::ScalarConverter()
{

}

ScalarConverter::ScalarConverter(const ScalarConverter& other)
{
	(void)other;
}

ScalarConverter& ScalarConverter::operator=(const ScalarConverter& other)
{
	(void)other;
	return *this;
}

ScalarConverter::~ScalarConverter()
{

}

void	ScalarConverter::convert(const std::string&	param)
{
	if (isChar(param))
		toChar(param);
	else if (isInt(param))
		toInt(param);
	else if (isFloat(param))
		toFloat(param);
	else if (isDouble(param))
		toDouble(param);
	else if (isOther(param))
		toOther(param);
	else
		std::cout << "Invalid param. Enter a char, int, float or double value." << std::endl;
}

int	ScalarConverter::isChar(const std::string& param)
{
	if (param.size() == 3 && (param[0] == '\'' && param[2] == '\''))
		return 1;
	else if (param.size() == 1 && !std::isdigit(param[0]))
		return 1;
	return 0;
}

int	ScalarConverter::isInt(const std::string& param)
{
	size_t	i = 0;

	while (i != param.size() && std::isspace(param[i]))
		i++;
	if (i == param.size())
		return 0;
	if (param[i] == '+' || param[i] == '-')
		i++;
	if (i == param.size())
		return 0;
	while (i < param.size() && std::isdigit(param[i]))
		i++;
	if (i == param.size())
		return 1;
	return 0;
}

int	ScalarConverter::isFloat(const std::string& param)
{
	bool	before = false;
	bool	point = false;
	bool	after = false;
	size_t	i = 0;

	while (i != param.size() && std::isspace(param[i]))
		i++;
	if (i == param.size())
		return 0;
	if (param[i] == '+' || param[i] == '-')
		i++;
	if (i == param.size())
		return 0;
	for (; i < param.size() && std::isdigit(param[i]); i++)
		before = true;
	if (param[i] == '.')
	{
		point = true;
		i++;
	}
	for (; i < param.size() && std::isdigit(param[i]); i++)
		after = true;
	if (i == param.size() - 1 && (param[i] == 'f' || param[i] == 'F') && (before && point && after))
		return 1;
	return 0;
}

int	ScalarConverter::isDouble(const std::string& param)
{
	bool	before = false;
	bool	point = false;
	bool	after = false;
	size_t	i = 0;

	while (i != param.size() && std::isspace(param[i]))
		i++;
	if (i == param.size())
		return 0;
	if (param[i] == '+' || param[i] == '-')
		i++;
	if (i == param.size())
		return 0;
	for (; i < param.size() && std::isdigit(param[i]); i++)
		before = true;
	if (param[i] == '.')
	{
		point = true;
		i++;
	}
	for (; i < param.size() && std::isdigit(param[i]); i++)
		after = true;
	if (i == param.size() && (before && point && after))
		return 1;
	return 0;
}

int	ScalarConverter::isOther(const std::string& param)
{
	if (param == "-inff" || param == "inff" || param == "nanf" || param == "-inf" || param == "inf" || param == "nan")
		return 1;
	return 0;
}

void	ScalarConverter::toChar(const std::string& param)
{
	char	c;
	int		i;
	float	f;
	double	d;

	if (param.size() == 1)
		c = param[0];
	else
		c = param[1];
	i = static_cast<int>(c);
	f = static_cast<float>(c);
	d = static_cast<double>(c);
	if (isprint(c))
		std::cout << "char: " << c << std::endl;
	else
		std::cout << "char: impossible" << std::endl;
	std::cout << "int: " << i << std::endl;
	std::cout << "float: " << std::fixed << std::setprecision(1) << f << "f" << std::endl;
	std::cout << "double: " << d << std::endl;
}

void	ScalarConverter::toInt(const std::string& param)
{
	int		i = std::atoi(param.c_str());
	char	c = static_cast<char>(i);
	float	f = static_cast<float>(i);
	double	d = static_cast<double>(i);

	if (isprint(c))
		std::cout << "char: " << c << std::endl;
	else
		std::cout << "char: impossible" << std::endl;
	std::cout << "int: " << i << std::endl;
	std::cout << "float: " << std::fixed << std::setprecision(1) << f << "f" << std::endl;
	std::cout << "double: " << d << std::endl;
}

void	ScalarConverter::toFloat(const std::string& param)
{
	float	f = atof(param.c_str());
	char	c = static_cast<char>(f);
	int		i = static_cast<int>(f);
	double	d = static_cast<double>(f);

	if (isprint(c))
		std::cout << "char: " << c << std::endl;
	else
		std::cout << "char: impossible" << std::endl;
	std::cout << "int: " << i << std::endl;
	std::cout << "float: " << std::fixed << std::setprecision(1) << f << "f" << std::endl;
	std::cout << "double: " << d << std::endl;
}

void	ScalarConverter::toDouble(const std::string& param)
{
	double	d = std::atof(param.c_str());
	char	c = static_cast<char>(d);
	int		i = static_cast<int>(d);
	float	f = static_cast<float>(d);

	if (isprint(c))
		std::cout << "char: " << c << std::endl;
	else
		std::cout << "char: impossible" << std::endl;
	std::cout << "int: " << i << std::endl;
	std::cout << "float: " << std::fixed << std::setprecision(1) << f << "f" << std::endl;
	std::cout << "double: " << d << std::endl;
}

void	ScalarConverter::toOther(const std::string& param)
{
	std::string	tmp;

	std::cout << "char: impossible" << std::endl;
	std::cout << "int: impossible" << std::endl;

	if (param == "-inff" || param == "inff" || param == "nanf")
	{
		std::cout << "float: " << param << std::endl;
		tmp = param;
		tmp.resize(tmp.size() - 1);
		std::cout << "double: " << tmp << std::endl;
	}
	else
	{
		std::cout << "float: " << param << "f" << std::endl;
		std::cout << "double: " << param << std::endl;
	}
}