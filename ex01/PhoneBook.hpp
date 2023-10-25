/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fduzant <fduzant@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/25 16:21:18 by fduzant           #+#    #+#             */
/*   Updated: 2023/10/25 21:46:31 by fduzant          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHONEBOOK_HPP
# define PHONEBOOK_HPP
# include "Contact.hpp"

class PhoneBook{

public:
	void	search(void);
	void	add_contact(void);

	PhoneBook(void);
	~PhoneBook(void);
private:
	bool	_is_numeric(const char* str) const;
	void	_showcontact(int i);
	Contact _contacts[8];
	int _num_contacts;
	int _oldest_contact_num;
};

#endif