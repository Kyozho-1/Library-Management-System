%:include <iostream>
%:include <string>
%:include <ostream>
%:include <sstream>

%:ifndef BOOK_H
%:define BOOK_H

class Book <%
	private:
		std::string name;
		std::string author;
		std::string publication_year;
		std::string publisher;
		std::string ISBN;
		std::string format;

		unsigned page_count;

	public:
		bool borrowed = false;

		/// <summary>
		/// Creates a Book object.
		/// <summary>
		/// <param name = "name">The name of the book.</param>
		/// <param name = "author">TThe name of the author.</param>
		/// <param name = "publication_year">The publication year of the book.</param>
		/// <param name = "publisher">The publisher of the book.</param>
		/// <param name = "ISBN">The ISBN of the book.</param>
		/// <param name = "page_count">The page count of the book.</param>
		Book(std::string name,
			 std::string author,
			 std::string publication_year,
			 std::string publisher,
			 std::string ISBN,
			 unsigned page_count);

		/// <returns>Gets the name of the book.</returns>
		std::string get_name() const;

		///<returns>Gets the author of the book.</returns>
		std::string get_author() const;

		///<returns>Gets the publication year of the book.</returns>
		std::string get_publication_year() const;

		///<returns>Gets the publisher of the book.</returns>
		std::string get_publisher() const;
		
		///<returns>Gets the ISBN of the book.</returns>
		std::string get_ISBN() const;

		///<returns>Gets the page count of the book.</returns>
		unsigned get_page_count() const;

		/// <summary>
		/// Sets the name of the book.
		/// </summary>
		/// <param name = "name">The name of the book.</param>
		void set_name(std::string name);

		/// <summary>
		/// Sets the name of the author.
		/// </summary>
		/// <param name = "author">The name of the author.</param>
		void set_author(std::string author);

		/// <summary>
		/// Sets the publication year of the book.
		/// </summary>
		/// <param name = "publication_year">Sets the publication year of the book.</param>
		void set_publication_year(std::string publication_year);

		/// <summary>
		/// Sets the publisher of the book.
		/// </summary>
		/// <param name = "publisher">The publisher of the book.</param>
		void set_publisher(std::string publisher);

		/// <summary>
		/// Sets the ISBN of the book.
		/// </summary>
		/// <param name = "ISBN">The ISBN of the book.</param>
		void set_ISBN(std::string ISBN);

		/// <summary>
		/// Sets the format of the book.
		/// </summary>
		/// <param name = "format">The desired book format.</param>
		void set_format(std::string format);

		/// <summary>
		/// Sets the page count of the book.
		/// </summary>
		/// <param name = "page_count">The page count of the book.</param>
		void set_page_count(unsigned page_count);

		/// <summary>
		/// Shows information about the book.
		/// </summary>
		/// <param name = "os">The ostream.</param>
		/// <param name = "book">The book object.</param>
		/// <returns>Information about the book.</returns>
		friend std::ostream& operator << (std::ostream& os, const Book& book);

		/// <summary>
		/// Converts an ostream operator (<<) function to a string.
		/// </summary>
		/// <returns>A book's information.</returns>
		std::string to_string() const;
%>;

%:endif