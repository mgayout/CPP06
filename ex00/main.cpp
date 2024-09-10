/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgayout <mgayout@student.42nice.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/05 15:48:43 by mgayout           #+#    #+#             */
/*   Updated: 2024/09/05 15:48:43 by mgayout          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"

int	main(int argc, char **argv)
{
	if (argc != 2)
	{
		std::cout << "Needs only 1 parameter." << std::endl;
		return 1;
	}
	ScalarConverter::convert(argv[1]);
	return 0;
}

/*int main(void)
{
	float	a = 4.1f;

	std::cout << a << std::endl;
}*/