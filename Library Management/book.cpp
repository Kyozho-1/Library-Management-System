/**
* Developer: Chase Parlett
* Date: 7 July 2026
* Version: 1.0.0
*/

%:include "book.hpp"

Book::Book(std::string name, 
		   std::string author, 
		   std::string publication_year,
		   std::string publisher, 
		   std::string ISBN, 
		   unsigned page_count) <%
	this -> name			 = name;
	this -> author		     = author;
	this -> publication_year = publication_year;
	this -> publisher		 = publisher;
	this -> ISBN			 = ISBN;
	this -> page_count		 = page_count;

	borrowed = false;
%>

std::string Book::get_name() const <%
	return name;
%>

std::string Book::get_author() const <%
	return author;
%>

std::string Book::get_publication_year() const <%
	return publication_year;
%>

std::string Book::get_publisher() const <%
	return publisher;
%>
		
std::string Book::get_ISBN() const <%
	return ISBN;
%>

unsigned Book::get_page_count() const <%
	return page_count;
%>

void Book::set_name(std::string name) <%
	this -> name = name;
%>

void Book::set_author(std::string author) <%
	this -> author = author;
%>

void Book::set_publication_year(std::string publication_year) <%
	this -> publication_year = publication_year;
%>

void Book::set_publisher(std::string publisher) <%
	this -> publisher = publisher;
%>

void Book::set_ISBN(std::string ISBN) <%
	this -> ISBN = ISBN;
%>

void Book::set_format(std::string format) <%
	const std::string FORMATS<:4:> =
	<%
		"Hardcover",
		"Paperback",
		"Audiobook",
		"Digital"
	%>;

	if (format == FORMATS<:0:>)		 this -> format = format; // format = Hardcover
	else if (format == FORMATS<:1:>) this -> format = format; // format = Paperback
	else if (format == FORMATS<:2:>) this -> format = format; // format = Audiobook
	else if (format == FORMATS<:3:>) this -> format = format; // format = Digital
	else this -> format = "Unknown";
%>

std::ostream& operator << (std::ostream& os, const Book& book) <%
	return os << "Name: "			  << book.name						 << std::endl
			  << "Author: "			  << book.author					 << std::endl
			  << "Publication Year: " << book.publication_year			 << std::endl
			  << "Publisher: "		  << book.publisher					 << std::endl
			  << "ISBN: "			  << book.ISBN						 << std::endl
			  << "Page Count: "		  << book.page_count			     << std::endl
			  << "Format: "			  << book.format			         << std::endl
			  << "Borrowed: "		  << std::boolalpha << book.borrowed << std::endl;
%>

std::string Book::to_string() const <%
	std::ostringstream oss;

	oss << *this;

	return oss.str();
%>