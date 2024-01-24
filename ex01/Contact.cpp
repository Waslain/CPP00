/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fduzant <fduzant@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/25 18:36:27 by fduzant           #+#    #+#             */
/*   Updated: 2024/01/24 17:10:21 by fduzant          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.hpp"

//Contact
Contact::Contact(void)
{
	// std::cout << "Contact constructor called" << std::endl;
	return ;
}

Contact::~Contact(void)
{
	// std::cout << "Contact destructor called" << std::endl;
	return ;
}

std::string Contact::get_first_name(void)
{
	return (_first_name);
}

std::string Contact::get_last_name(void)
{
	return (_last_name);
}

std::string Contact::get_nick_name(void)
{
	return (_nick_name);
}

std::string Contact::get_phone_number(void)
{
	return (_phone_number);
}

std::string Contact::get_darkest_secret(void)
{
	return (_darkest_secret);
}

void Contact::set_first_name(std::string first_name)
{
	_first_name = first_name;
}

void Contact::set_last_name(std::string last_name)
{
	_last_name = last_name;
}

void Contact::set_nick_name(std::string nick_name)
{
	_nick_name = nick_name;
}

void Contact::set_phone_number(std::string phone_number)
{
	_phone_number = phone_number;
}

void Contact::set_darkest_secret(std::string darkest_secret)
{
	_darkest_secret = darkest_secret;
}