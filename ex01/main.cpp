/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgayout <mgayout@student.42nice.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/10 14:37:06 by mgayout           #+#    #+#             */
/*   Updated: 2024/09/10 14:37:06 by mgayout          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Serializer.hpp"

int	main(void)
{
	Data		input;
	Data		*copy;
	uintptr_t	output;

	input.name = "Patrick";
	output = Serializer::serialize(&input);
	std::cout << output << std::endl;
	copy = Serializer::deserialize(output);
	std::cout << input.name << " et " << copy->name << std::endl;
	return 0;
}