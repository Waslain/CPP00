/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fduzant <fduzant@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/25 18:37:52 by fduzant           #+#    #+#             */
/*   Updated: 2023/10/25 21:53:52 by fduzant          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONTACT_HPP
# define CONTACT_HPP
# include "lib.hpp"

class Contact{

public:
	std::string first_name;
    std::string last_name;
    std::string nick_name;
    std::string phone_number;
	std::string darkest_secret;
	
	Contact(void);
	~Contact(void);
};

#endif