/**
* Developer: Chase Parlett
* Date: 7 July 2026
* Version: 1.0.0
*/

%:include "user.hpp"

%:ifndef LIBRARY_H
%:define LIBRARY_H

class Library <%
	private:
		std::vector<Book> books;
		std::vector<User> users;
	public:
		/// <summary>
		/// Runs the program.
		/// </summary>
		void run();

		/// <summary>
		/// Adds a user to the library.
		/// </summary>
		/// <param name = "user">The User object.</param>
		void add_user(const User& user);

		/// <summary>
		/// Removes a user from the library.
		/// </summary>
		/// <param name = "user">The User object.</param>
		/// <param name = "index">The index of where the user object is the users vector.</param>
		void remove_user(const User& user, unsigned short& index);

		/// <summary>
		/// Removes a book from the library.
		/// </summary>
		/// <param name = "book">The Book object.</param>
		/// <param name = "index">The index of where the book object is in the books vector.</param>
		void remove_book(const Book& book, unsigned short& index);

		/// <summary>
		/// Allows the user to borrow a book from the library.
		/// </summary>
		/// <param name = "user">The user object.</param>
		/// <param name = "book">The Book object.</param>
		void borrow_book(User& user, Book& book);

		/// <summary>
		/// Allows the user to return a book.
		/// </summary>
		/// <param name = "user">The User object.</param>
		/// <param name = "book">The Book object.</param>
		void return_book(User& user, Book& book);

		/// <summary>
		/// Shows all the users in the library system.
		/// </summary>
		void view_users();

		/// <summary>
		/// Shows all the books in the library system.
		/// </summary>
		void view_books();
%>;

%:endif