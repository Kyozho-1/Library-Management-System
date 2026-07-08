/**
* Developer: Chase Parlett
* Date: 7 July 2026
* Version: 1.0.0
*/

%:include <random>
%:include <vector>

%:include "book.hpp"

%:ifndef USER_H
%:define USER_H

class User <%
	private:
		std::string name;
		std::string id;
		std::vector<Book> books;

		/// <summary>
		/// Creates an ID for the user.
		/// </summary>
		static std::string create_id();
	public:
		/// <summary>
		/// Creates a user object.
		/// </summary>
		/// <param name = "name">The name of the user.</param>
		User(const std::string& name);

		/// <returns>The name of the user.</returns>
		std::string get_name() const;

		/// <returns>The id of the user.</returns>
		std::string get_id() const;

		/// <returns>The latest book a user has.</returns>
		const Book* get_latest_book() const;

		/// <summary>
		/// Sets the name of the user.
		/// </summary>
		void set_name(const std::string& name);

		/// <summary>
		/// All the books the user currently has.
		/// </summary>
		void display_books() const;

		/// <summary>
		/// Adds a book to the user's book vector.
		/// Used in borrow_book(...) method in library.cpp.
		/// </summary>
		/// <param name = "book">The Book object.</param>
		void add_book(Book& book);

		/// <summary>
		/// Removes a book from the user's book vector.
		/// Used in return_book(...) method in library.cpp.
		/// </summary>
		/// <param name="book"></param>
		void remove_book(Book& book);

		friend std::ostream& operator << (std::ostream& os, const User& user);

		/// <summary>
		/// Converts the ostream operator (<<) function to a string.
		/// </summary>
		/// <returns>The user's information.</returns>
		std::string to_string() const;
%>;

%:endif