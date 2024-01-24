/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fduzant <fduzant@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/25 15:52:35 by fduzant           #+#    #+#             */
/*   Updated: 2024/01/24 17:27:20 by fduzant          ###   ########.fr       */
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
	std::cout << "Your contact number " << i << " :"<< std::endl;
	Contact contact = _contacts[i];

	std::cout << "First name: " << contact.get_first_name() << std::endl;
	std::cout << "Last name: " << contact.get_last_name() << std::endl;
	std::cout << "Nickname: " << contact.get_nick_name() << std::endl;
	std::cout << "Phone number: " << contact.get_phone_number() << std::endl;
	std::cout << "Darkest secret: " << contact.get_darkest_secret() << std::endl;
}

void	PhoneBook::search(void) const
{
	if (_num_contacts > 0)
	{
		std::string	u_input;
		int	i = 0;
		int	len;
		
		std::cout << "Looking for contact..." << std::endl;
		std::cout << "     index|      name| last name|     phone" << std::endl;
		std::cout << std::setfill('-') << std::setw(44) << "\n" << std::setfill(' ');
		// std::cout << "-------------------------------------------" << std::endl;

		while (i < _num_contacts)
		{
			Contact contact = _contacts[i];
			std::cout << std::setw(9) << "" << i;
			std::cout << "|";
			if (contact.get_first_name().length() > 10)
				std::cout << contact.get_first_name().substr(0, 9) << ".";
			else
			{
				len = 10 - contact.get_first_name().length();
				std::cout << std::setw(len) << "" << contact.get_first_name();
			}
			std::cout << "|";
			if (contact.get_last_name().length() > 10)
				std::cout << contact.get_last_name().substr(0, 9) << ".";
			else
			{
				len = 10 - contact.get_last_name().length();
				std::cout << std::setw(len) << "" << contact.get_last_name();
			}
			std::cout << "|";
			if (contact.get_nick_name().length() > 10)
				std::cout << contact.get_nick_name().substr(0, 9) << ".";
			else
			{
				len = 10 - contact.get_nick_name().length();
				std::cout << std::setw(len) << "" << contact.get_nick_name();
			}
			std::cout << std::endl;
			i++;
		}
		while (1)
		{
			std::cout << "Which contact do you want to display" << std::endl;
			std::getline(std::cin, u_input);
			if (u_input.empty())
				std::cout << "Please enter a number" << std::endl;
			else if (_is_numeric(u_input.c_str()) == false)
				std::cout << "Please enter a number" << std::endl;
			else if (std::atoi(u_input.c_str()) < 0 || std::atoi(u_input.c_str()) >= _num_contacts)
				std::cout << "Please enter a contact number in the directory" << std::endl;
			else
			{
				_showcontact(std::atoi(u_input.c_str()));
				return ;
			}
		}
		return ;
	}
	else
		std::cout << "Please add a contact first" << std::endl;
}

void PhoneBook::add_contact(void)
{
	std::string	u_input;
	
	if (_num_contacts < 8)
	{
		Contact new_contact;
		
		std::cout << "Adding the contact..." << std::endl;
		while (1)
		{
			std::cout << "Enter your contact name" << std::endl;
			std::getline(std::cin, u_input);
			if (u_input.empty())
				std::cout << "You didn't enter anything. ";
			else
			{
				new_contact.set_first_name(u_input);
				break ;
			}
		}
		while (1)
		{
			std::cout << "Enter your contact last name" << std::endl;
			std::getline(std::cin, u_input);
			if (u_input.empty())
				std::cout << "You didn't enter anything. ";
			else
			{
				new_contact.set_last_name(u_input);
				break ;
			}
		}
		while (1)
		{
			std::cout << "Enter your contact nickname" << std::endl;
			std::getline(std::cin, u_input);
			if (u_input.empty())
				std::cout << "You didn't enter anything. ";
			else
			{
				new_contact.set_nick_name(u_input);
				break ;
			}
		}
		while (1)
		{
			std::cout << "Enter your contact phone number." << std::endl;
			std::getline(std::cin, u_input);
			if (u_input.empty())
					std::cout << "You didn't enter anything. ";
				else
				{
					new_contact.set_phone_number(u_input);
					break ;
				}
		}
		while (1)
		{
			std::cout << "Enter your contact biggest secret" << std::endl;
			std::getline(std::cin, u_input);
			if (u_input.empty())
					std::cout << "You didn't enter anything. ";
				else
				{
					new_contact.set_darkest_secret(u_input);
					break ;
				}
		}
		_contacts[_num_contacts] = new_contact;
		_num_contacts++;
	}
	else
	{
		std::cout << "Contact list full, erasing oldest contact..." << std::endl;
		
		Contact new_contact;
		
		while (1)
		{
			std::cout << "Enter your contact name" << std::endl;
			std::getline(std::cin, u_input);
			if (u_input.empty())
				std::cout << "You didn't enter anything. ";
			else
			{
				new_contact.set_first_name(u_input);
				break ;
			}
		}
		while (1)
		{
			std::cout << "Enter your contact last name" << std::endl;
			std::getline(std::cin, u_input);
			if (u_input.empty())
				std::cout << "You didn't enter anything. ";
			else
			{
				new_contact.set_last_name(u_input);
				break ;
			}
		}
		while (1)
		{
			std::cout << "Enter your contact nickname" << std::endl;
			std::getline(std::cin, u_input);
			if (u_input.empty())
				std::cout << "You didn't enter anything. ";
			else
			{
				new_contact.set_nick_name(u_input);
				break ;
			}
		}
		while (1)
		{
			std::cout << "Enter your contact phone number" << std::endl;
			std::getline(std::cin, u_input);
			if (u_input.empty())
					std::cout << "You didn't enter anything. ";
				else
				{
					new_contact.set_phone_number(u_input);
					break ;
				}
		}
		while (1)
		{
			std::cout << "Enter your contact biggest secret" << std::endl;
			std::getline(std::cin, u_input);
			if (u_input.empty())
					std::cout << "You didn't enter anything. ";
				else
				{
					new_contact.set_darkest_secret(u_input);
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
