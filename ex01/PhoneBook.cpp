/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fduzant <fduzant@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/25 15:52:35 by fduzant           #+#    #+#             */
/*   Updated: 2023/10/26 09:22:20 by fduzant          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.hpp"

//Phonebook
PhoneBook::PhoneBook(void)
{
	_num_contacts = 0;
	_oldest_contact_num = 0;
	std::cout << "PhoneBook constructor called" << std::endl;
	return ;
}

PhoneBook::~PhoneBook(void)
{
	std::cout << "PhoneBook destructor called" << std::endl;
	return ;
}

bool	PhoneBook::_is_numeric(const char* str) const
{
	int len = std::strlen(str);
	for (int i = 0; i < len; i++) {
		if (!std::isdigit(str[i])) {
			return false;
		}
	}
	return true;
}

void	PhoneBook::_showcontact(int i) const
{
	std::cout << "Ton contact numéro " << i << " :"<< std::endl;
	Contact contact = _contacts[i];

	std::cout << contact.first_name << std::endl;
	std::cout << contact.last_name << std::endl;
	std::cout << contact.nick_name << std::endl;
	std::cout << contact.phone_number << std::endl;
	std::cout << contact.darkest_secret << std::endl;
}

void	PhoneBook::search(void) const
{
	std::string	u_input;
	int	i = 0;
	int	len;
	
	std::cout << "Looking for contact..." << std::endl;
	std::cout << "     index|    prenom|       nom| telephone" << std::endl;
	std::cout << std::setfill('-') << std::setw(44) << "\n" << std::setfill(' ');
	// std::cout << "-------------------------------------------" << std::endl;

	while (i < _num_contacts)
	{
		Contact contact = _contacts[i];
		std::cout << std::setw(9) << "" << i;
		std::cout << "|";
		if (contact.first_name.length() > 10)
			std::cout << contact.first_name.substr(0, 9) << ".";
		else
		{
			len = 10 - contact.first_name.length();
			std::cout << std::setw(len) << "" << contact.first_name;
		}
		std::cout << "|";
		if (contact.last_name.length() > 10)
			std::cout << contact.last_name.substr(0, 9) << ".";
		else
		{
			len = 10 - contact.last_name.length();
			std::cout << std::setw(len) << "" << contact.last_name;
		}
		std::cout << "|";
		if (contact.nick_name.length() > 10)
			std::cout << contact.nick_name.substr(0, 9) << ".";
		else
		{
			len = 10 - contact.nick_name.length();
			std::cout << std::setw(len) << "" << contact.nick_name;
		}
		std::cout << std::endl;
		i++;
	}
	while (1)
	{
		std::cout << "Quel contacte souhaite tu afficher ?" << std::endl;
		std::getline(std::cin, u_input);
		if (_is_numeric(u_input.c_str()) == false)
			std::cout << "Veuillez entrer un chiffre" << std::endl;
		else if (std::atoi(u_input.c_str()) < 0 || std::atoi(u_input.c_str()) >= _num_contacts)
			std::cout << "Veuillez entrer un numéro de contact présent dans le répertoire" << std::endl;
		else
		{
			_showcontact(std::atoi(u_input.c_str()));
			return ;
		}
	}
	return ;
}

void PhoneBook::add_contact(void)
{
	std::string	u_input;
	
	if (_num_contacts < 8)
	{
		Contact new_contact;
		
		std::cout << "Ajout du contact..." << std::endl;
		while (1)
		{
			std::cout << "Entrez le prénom du contact" << std::endl;
			std::getline(std::cin, u_input);
			if (u_input.empty())
				std::cout << "Vous n'avez rien entré. ";
			else
			{
				new_contact.first_name = u_input;
				break ;
			}
		}
		while (1)
		{
			std::cout << "Entrez le nom de famille du contact" << std::endl;
			std::getline(std::cin, u_input);
			if (u_input.empty())
				std::cout << "Vous n'avez rien entré. ";
			else
			{
				new_contact.last_name = u_input;
				break ;
			}
		}
		while (1)
		{
			std::cout << "Entrez le surnom du contact" << std::endl;
			std::getline(std::cin, u_input);
			if (u_input.empty())
				std::cout << "Vous n'avez rien entré. ";
			else
			{
				new_contact.nick_name = u_input;
				break ;
			}
		}
		while (1)
		{
			std::cout << "Entrez le numé de téléphone du contact" << std::endl;
			std::getline(std::cin, u_input);
			if (u_input.empty())
					std::cout << "Vous n'avez rien entré. ";
				else
				{
					new_contact.phone_number = u_input;
					break ;
				}
		}
		while (1)
		{
			std::cout << "Entrez le plus gros secret du contact" << std::endl;
			std::getline(std::cin, u_input);
			if (u_input.empty())
					std::cout << "Vous n'avez rien entré. ";
				else
				{
					new_contact.darkest_secret = u_input;
					break ;
				}
		}
		_contacts[_num_contacts] = new_contact;
		_num_contacts++;
	}
	else
	{
		std::cout << "Liste de contacte pleine, effacement du plus vieux contact..." << std::endl;
		
		Contact new_contact;
		
		while (1)
		{
			std::cout << "Entrez le prénom du contact" << std::endl;
			std::getline(std::cin, u_input);
			if (u_input.empty())
				std::cout << "Vous n'avez rien entré. ";
			else
			{
				new_contact.first_name = u_input;
				break ;
			}
		}
		while (1)
		{
			std::cout << "Entrez le nom de famille du contact" << std::endl;
			std::getline(std::cin, u_input);
			if (u_input.empty())
				std::cout << "Vous n'avez rien entré. ";
			else
			{
				new_contact.last_name = u_input;
				break ;
			}
		}
		while (1)
		{
			std::cout << "Entrez le surnom du contact" << std::endl;
			std::getline(std::cin, u_input);
			if (u_input.empty())
				std::cout << "Vous n'avez rien entré. ";
			else
			{
				new_contact.nick_name = u_input;
				break ;
			}
		}
		while (1)
		{
			std::cout << "Entrez le numé de téléphone du contact" << std::endl;
			std::getline(std::cin, u_input);
			if (u_input.empty())
					std::cout << "Vous n'avez rien entré. ";
				else
				{
					new_contact.phone_number = u_input;
					break ;
				}
		}
		while (1)
		{
			std::cout << "Entrez le plus gros secret du contact" << std::endl;
			std::getline(std::cin, u_input);
			if (u_input.empty())
					std::cout << "Vous n'avez rien entré. ";
				else
				{
					new_contact.darkest_secret = u_input;
					break ;
				}
		}
		_contacts[_oldest_contact_num] = new_contact;
		_oldest_contact_num++;
		if (_oldest_contact_num == 8)
			_oldest_contact_num = 0;
	}
	return ;
}
