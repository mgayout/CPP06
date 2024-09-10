/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Serializer.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgayout <mgayout@student.42nice.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/10 14:37:27 by mgayout           #+#    #+#             */
/*   Updated: 2024/09/10 14:37:27 by mgayout          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SERIALIZER_HPP
# define SERIALIZER_HPP

# include "Data.hpp"

class	Serializer
{
	public:
			static uintptr_t	serialize(Data* ptr);
			static Data*		deserialize(uintptr_t raw);

	private:
			Serializer();
			Serializer(const Serializer& other);
			Serializer& operator=(const Serializer& other);
			~Serializer();

};

#endif