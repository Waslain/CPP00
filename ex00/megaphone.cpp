/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   megaphone.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fduzant <fduzant@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/25 13:39:35 by fduzant           #+#    #+#             */
/*   Updated: 2023/10/25 15:49:54 by fduzant          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

//Megaphone qui transforme argv[i] > 1 en majuscule et l'affiche

int main(int argc, char **argv)
{
	int	i;
	int	y;

	if (argc == 1)
	{
		std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *" << std::endl;
		return (1);
	}
	i = 1;
	while (argv[i])
	{
		y = 0;
		while (argv[i][y])
		{
			std::cout << (char)toupper(argv[i][y]);
			y++;
		}
		std::cout << " ";
		i++;
	}
	std::cout << std::endl;
	return (0);
}
