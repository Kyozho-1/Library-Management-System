/**
* Developer: Chase Parlett
* Date: 7 July 2026
* Version: 1.0.0
*/

%:include "library.hpp"

%:include <map>
%:include <limits>

void clear_input_buffer();

void Library::run() <%
	const std::map<short, std::string> OPTIONS = 
	<%
		<%1, "Add user"%>,		//! Finished!
		<%2, "Remove user"%>,   //! Finished!
		<%3, "View users"%>,    //! Finished!
		<%4, "Add book"%>,      //! Finished!
		<%5, "Remove book"%>,   //! Finished!
		<%6, "Borrow book"%>,	//! Finished!
		<%7, "Search book"%>,   //! Finished!
		<%8, "Return book"%>,   //! Finished!
		<%9, "View Books"%>,    //! Finished!
		<%10, "Quit"%>          //! Finished!
	%>;

	const std::string TITLE = "┌──────────────────────────────────────┐\n"
							  "│Chase's Library Management Application│\n"
							  "└──────────────────────────────────────┘\n";

	unsigned short user_input = 0;

	const auto QUIT = prev(OPTIONS.end());

	do <%
		std::cout << TITLE;

		for (auto& option : OPTIONS) <%
			std::cout << '[' << option.first << "] " << option.second << std::endl;
		%>

		std::cout << std::endl; // Only used for adding newline after printing the options.

		std::cout << "Enter choice > ";

		std::cin >> user_input;

		if (std::cin.fail()) <%
			std::cout << std::endl << "Error! Please enter a number!" << std::endl << std::endl
								   << "Press [Enter] to continue.";

			// Used for clearing input buffer and ignoring newline.
			std::cin.clear();
			std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

			std::cin.get();

			system("cls");

			continue;
		%>

		// Used for clearing input buffer and ignoring newline.
		std::cin.clear();
		std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

		switch (user_input) <%
			//! Option: Add User
			case 1: <%
				std::string name;
				
				system("cls");

				std::cout << "Enter name as (Last, First)" << std::endl
						  << "Enter name: ";

				std::getline(std::cin, name);

				User user(name);

				add_user(user);

				std::cout << std::endl << "User: (" << name << ") has been successfully added to the system!";

				std::cout << std::endl << "User's ID: " << user.get_id();

				std::cout << std::endl << std::endl << "Press [Enter] to continue.";

				std::cin.get();

				system("cls");

				break;
			%>
			//! Option: Remove User
			case 2: <%
				std::string name;
				std::string id;
				unsigned short index = 0;

				bool user_found = false;

				system("cls");

				if (not users.empty()) <%
					std::cout << "Enter user's name as (Last, First)" << std::endl
							  << "Enter name here: ";

				std::getline(std::cin, name);

				std::cout << std::endl << "Enter user's ID: ";

				std::cin >> id;

				clear_input_buffer();

				for (User& user : users) <%
					if (user.get_name() == name and user.get_id() == id) <%
						remove_user(users<:index:>, index);

						user_found = true;
					%> else <%
						index++;
					%>
				%>

					if (user_found) <%
						std::cout << "User (" << name << ") has been removed from the library system.";
					%> else <%
						std::cout << "Error! User was not able to be found. "
								  << "Please check the spelling and format of their name or the ID entered.";
					%>
				%> else <%
					std::cout << "Error! There are no users in the library system. "
							  << "Please add users to the system.";
				%>
				

				std::cout << std::endl << std::endl << "Press [Enter] to continue.";

				std::cin.get();

				system("cls");

				break;
			%>
			//! Option: View Users
			case 3: <%
				system("cls");

				if (users.empty()) std::cout << "There are no users in the system." << std::endl << std::endl;
				else view_users();
				
				std::cout << "Press [Enter] to continue.";

				std::cin.get();

				system("cls");

				break;
			%>
			//! Option: Add Book
			case 4: <%
				std::string name;
				std::string author;
				std::string publication_year;
				std::string publisher;
				std::string ISBN;
				std::string format;

				unsigned short page_count;

				const unsigned short ISBN_DIGIT_COUNT = 13;

				bool format_selected = false;
				bool ISBN_DIGIT_PASS = false;

				system("cls");

				std::cout << "Enter the title of the book: ";

				std::getline(std::cin, name);

				std::cout << std::endl << "Enter the author of (" << name << ") (Last, First): ";

				std::getline(std::cin, author);

				std::cout << std::endl << "Enter the publication year: ";

				std::cin >> publication_year;

				clear_input_buffer();

				std::cout << std::endl << "Enter the publisher: ";

				std::getline(std::cin, publisher);

				std::cout << std::endl; // Only used to add newline.

				do <%
					std::cout << "Enter the ISBN: ";

					std::cin >> ISBN; //- IMPLEMENT A FEATURE THAT OVERRIDES A BOOK THAT HAS THE SAME ISBN!!!
					
					clear_input_buffer();

					if (ISBN.length() != ISBN_DIGIT_COUNT) <%
						std::cout << std::endl << "Error! ISBN must contain 13 digits." << std::endl << std::endl;

						std::cout << "Press [Enter] to continue.";

						std::cin.get();

						system("cls");

						continue;
					%>
				%> while (ISBN.length() != ISBN_DIGIT_COUNT);

				std::cout << std::endl << "Enter the page count: ";

				std::cin >> page_count;

				clear_input_buffer();

				if (std::cin.fail()) <%
					std::cout << std::endl << "Error! Please enter the page count as an integer (Ex: 104)";

					std::cout << std::endl << std::endl << "Press [Enter] to continue.";

					std::cin.get();

					system("cls");

					continue;
				%>

				Book book(name, author, publication_year, publisher, ISBN, page_count);

				while (not format_selected) <%
					std::cout << std::endl << "Add a format for the book." << std::endl;

					const std::string FORMATS<:5:> =
					<%
						"Hardcover",
						"Paperback",
						"Audiobook",
						"Digital",
						"Quit"
					%>;

					unsigned short format_input;

					std::cout << std::endl; // This is only here to add a newline under the text printed above.

					for (size_t i = 0; i < size(FORMATS); i++) <%
						std::cout << '[' << (i + 1) << "] " << FORMATS<:i:> << std::endl;
					%>

					std::cout << std::endl << "Enter choice > ";

					std::cin >> format_input;

					clear_input_buffer();

					if (format_input >= 1 and format_input <= (size(FORMATS) - 1)) <%
						format = FORMATS[format_input - 1];

						book.set_format(format);

						books.push_back(book);
				
						std::cout << std::endl << "The book: " << name << " has been successfully added to the library.";

						format_selected = true;
					%> else if (format_input == 5) <%
						std::cout << "Exited adding book process.";

						break;
					%> else <%
						std::cout << "Invalid input! Please enter a valid option from the following option above.";

						std::cout << std::endl << std::endl << "Press [Enter] to continue.";

						std::cin.get();

						system("cls");
					%>
				%>
				std::cout << std::endl << std::endl << "Press [Enter] to continue.";

				std::cin.get();

				system("cls");

				break;
			%>
			//! Option: Remove Book
			case 5: <%
				std::string name;
				std::string ISBN;

				unsigned short index = 0;

				bool book_found = false;

				system("cls");

				if (not books.empty() and not users.empty()) <%
					std::cout << "Enter the book's title: ";

					std::getline(std::cin, name);

					std::cout << std::endl << std::endl << "Enter the ISBN of the book: ";

					std::cin >> ISBN;

					clear_input_buffer();

					for (Book& book : books) <%
						if (book.get_name() == name and book.get_ISBN() == ISBN) <%
							remove_book(books<:index:>, index);
						
							book_found = true;
						%> else <%
							index++;
						%>
					%>
				
					if (book_found) <%
						std::cout << "The book: (" << name << ") has been removed from the library's system.";
					%> else <%
						std::cout << "Error! Book could not be removed from the library's system. "
								  << "Please check the spelling of the book's title or the ISBN entered.";
					%>
				%> else if (users.empty()) <%
					std::cout << "Error! There are no users in the system. Please add users to the system.";
				%> else <%
					std::cout << "Error! There are no books in the system. Please add books to the system.";
				%>
				
				std::cout << std::endl << std::endl << "Press [Enter] to continue.";

				std::cin.get();

				system("cls");

				break;
			%>
			//! Option: Borrow Book
			case 6: <%
				system("cls");
				
				std::string id;
				std::string ISBN;

				User* ptr_user = nullptr;
				Book* ptr_book = nullptr;

				if (not users.empty() and not books.empty()) <%
					std::cout << "Enter the user's ID: ";

					std::cin >> id;

					clear_input_buffer();

					std::cout << std::endl << "Enter the book's ISBN: ";

					std::cin >> ISBN;

					clear_input_buffer();

					for (User& user : users) <%
						if (user.get_id() == id) <%
							ptr_user = &user;

							break;
						%>
					%>

					for (Book& book : books) <%
						if (book.get_ISBN() == ISBN) <%
							ptr_book = &book;

							break;
						%>
					%>

					if (ptr_user != nullptr and ptr_book != nullptr) <%
						borrow_book(*ptr_user, *ptr_book);
					%> else if (ptr_user != nullptr) <%
						std::cout << "Error! User could not be found. Please check the ID.";
					%> else <%
						std::cout << "Error! Book could not be found. Please check the ISBN.";
					%>

					std::cout << std::endl << "The transaction was successful!";
				%> else if (users.empty())<%
					std::cout << "Error! There are no users in the system. Please add users to the system.";
				%> else <%
					std::cout << "Error! There are no books in the system. Please add books to the system.";
				%>
				
				std::cout << std::endl << std::endl << "Press [Enter] to continue.";

				std::cin.get();

				system("cls");

				break;
			%>
			//! Option: Search Book
			case 7: <%
				std::string ISBN_or_name;

				system("cls");

				std::cout << "Enter the book's ISBN or enter the title of the book: ";

				std::getline(std::cin, ISBN_or_name);

				for (Book& book : books) <%
					if (book.get_name() == ISBN_or_name or book.get_ISBN() == ISBN_or_name) <%
						std::cout << book;
					%> else <%
						std::cout << "Error! That book couldn't be found. Please check the ISBN or the spelling.";
					%>
				%>

				std::cout << std::endl << std::endl << "Press [Enter] to continue.";

				std::cin.get();

				system("cls");

				break;
			%>
			//! Option: Return Book
			case 8: <%
				system("cls");
				
				std::string id;
				std::string ISBN;

				User* ptr_user = nullptr;
				Book* ptr_book = nullptr;

				if (not users.empty() and not books.empty()) <%
					std::cout << "Enter the user's ID: ";

					std::cin >> id;

					clear_input_buffer();

					std::cout << std::endl << "Enter the book's ISBN: ";

					std::cin >> ISBN;

					clear_input_buffer();

					for (User& user : users) <%
						if (user.get_id() == id) <%
							ptr_user = &user;

							break;
						%>
					%>

					for (Book& book : books) <%
						if (book.get_ISBN() == ISBN) <%
							ptr_book = &book;

							break;
						%>
					%>

					if (ptr_user != nullptr and ptr_book != nullptr) <%
						return_book(*ptr_user, *ptr_book);
					%> else if (ptr_user != nullptr) <%
						std::cout << "Error! User could not be found. Please check the ID.";
					%> else <%
						std::cout << "Error! Book could not be found. Please check the ISBN.";
					%>

					std::cout << std::endl << "The transaction was successful!";
				%> else if (users.empty()) <%
					std::cout << "Error! There are no users in the system. Please add users to the system.";
				%> else <%
					std::cout << "Error! There are no books in the system. Please add books to the system.";
				%>
				
				std::cout << std::endl << std::endl << "Press [Enter] to continue.";

				std::cin.get();

				system("cls");

				break;
			%>
			//! Option: View Books
			case 9: <%
				system("cls");

				if (books.empty()) std::cout << "There are no books in the system." << std::endl << std::endl;
				else view_books();
				
				std::cout << "Press [Enter] to continue.";

				std::cin.get();

				system("cls");

				break;
			%>
			//! Option: Quit
			case 10: break;

			default:
				std::cout << std::endl 
					      << "Please select a valid option from the options above." << std::endl << std::endl
						  << "Press [Enter] to continue.";

				std::cin.get();

				system("cls");

				continue;

				break;
		%>
	%> while (user_input != QUIT -> first);

	std::cout << std::endl << "You have exited out of the program." << std::endl;
%>

void Library::add_user(const User& user) <%
	users.push_back(user);
%>

void Library::remove_user(const User& user, unsigned short& index) <%
	users.erase(users.begin() + index);
%>

void Library::view_users() <%
	for (User& user : users) std::cout << user << std::endl << std::endl;
%>

void Library::remove_book(const Book & book, unsigned short& index) <%
	books.erase(books.begin() + index);
%>

void Library::view_books() <%
	for (Book& book : books) std::cout << book << std::endl;
%>

void Library::borrow_book(User& user, Book& book) <%
	user.add_book(book);
%>

void Library::return_book(User& user, Book& book) <%
	user.remove_book(book);
%>

/// <summary>
/// Clears the input buffer of '\n'.
/// </summary>
void clear_input_buffer() <%
	std::cin.clear();
	std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
%>