/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fduzant <fduzant@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/25 18:37:52 by fduzant           #+#    #+#             */
/*   Updated: 2024/01/24 17:08:35 by fduzant          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONTACT_HPP
# define CONTACT_HPP
# include "lib.hpp"

class Contact{

public:
	Contact(void);
	~Contact(void);

	std::string get_first_name(void);
	std::string get_last_name(void);
	std::string get_nick_name(void);
	std::string get_phone_number(void);
	std::string get_darkest_secret(void);

	void set_first_name(std::string first_name);
	void set_last_name(std::string last_name);
	void set_nick_name(std::string nick_name);
	void set_phone_number(std::string phone_number);	
	void set_darkest_secret(std::string darkest_secret);
private:
	std::string _first_name;
	std::string _last_name;
	std::string _nick_name;
	std::string _phone_number;
	std::string _darkest_secret;
};

#endif