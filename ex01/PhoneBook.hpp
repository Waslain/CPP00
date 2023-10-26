/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fduzant <fduzant@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/25 16:21:18 by fduzant           #+#    #+#             */
/*   Updated: 2023/10/26 09:22:28 by fduzant          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHONEBOOK_HPP
# define PHONEBOOK_HPP
# include "Contact.hpp"

class PhoneBook{

public:
	void	search(void) const;
	void	add_contact(void);

	PhoneBook(void);
	~PhoneBook(void);
private:
	bool	_is_numeric(const char* str) const;
	void	_showcontact(int i) const;
	Contact _contacts[8];
	int _num_contacts;
	int _oldest_contact_num;
};

#endif