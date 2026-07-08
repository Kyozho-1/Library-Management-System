/**
* Developer: Chase Parlett
* Date: 7 July 2026
* Version: 1.0.0
*/

%:include "user.hpp"

User::User(const std::string& name) <%
	this -> name = name;

	id = create_id();
%>

std::string User::get_name() const <%
	return name;
%>

std::string User::get_id() const <%
	return id;
%>

const Book* User::get_latest_book() const <%
	if (books.empty()) return nullptr;

	return &books.back();
%>

void User::display_books() const <%
	for (const Book& book : books) std::cout << book << std::endl << std::endl;
%>

void User::set_name(const std::string& name) <%
	this -> name = name;
%>

void User::add_book(Book& book) <%
	if (book.borrowed) <%
		std::cout << "The book (" << book.get_name() << ") is being borrowed at the moment. "
				  << "Please try again when the book has been returned.";
	%> else <%
		books.push_back(book);

		book.borrowed = true;
	%>
%>

void User::remove_book(Book& book) <%
	unsigned short index = 0;

	if (not book.borrowed) <%
		std::cout << "The book (" << book.get_name() << ") is not being borrowed at the moment. "
				  << "Please try again when the book has been borrowed.";
	%> else <%
		for (Book& var_book : books) <%
			if (var_book.get_ISBN() == book.get_ISBN()) <%
				break;
			%> else <%
				index++;
			%>
		%>

		books.erase(books.begin() + index);

		book.borrowed = false;
	%>
%>

std::string User::create_id() <%
	std::random_device rd;
	std::mt19937 gen(rd());
	std::uniform_int_distribution<> dist(0, 9);

	std::string id;

	id.reserve(8);

	for (short i = 0; i < 8; i++) id += std::to_string(dist(gen));

	return id;
%>

std::ostream& operator << (std::ostream& os, const User& user) <%
	return os << "User's name: "				 << user.name << std::endl
			  << "User ID: "					 << user.id   << std::endl
			  << "Number of checked out books: " << user.books.size();
%>

std::string User::to_string() const <%
	std::ostringstream oss;

	oss << *this;

	return oss.str();
%>