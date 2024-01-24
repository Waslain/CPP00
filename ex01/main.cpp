/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fduzant <fduzant@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/25 16:28:17 by fduzant           #+#    #+#             */
/*   Updated: 2024/01/24 17:09:21 by fduzant          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.hpp"

//Main de notre phone book qui attends que l'utilisateur entre une commande pour l'executer

int	main()
{
	std::string	u_input;
	PhoneBook	Phone;
	
	while (1)
	{
		std::cout << "Enter a command (ADD, SEARCH or EXIT): " << std::endl;
		std::cin >> u_input;
		std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
		if (u_input.compare("EXIT") == 0)
			break ;
		else if (u_input.compare("ADD") == 0)
			Phone.add_contact();
		else if (u_input.compare("SEARCH") == 0)
			Phone.search();
	}
	return (0);
}
