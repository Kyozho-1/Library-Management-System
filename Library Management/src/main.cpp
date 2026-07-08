/**
* Developer: Chase Parlett
* Date: 7 July 2026
* Version: 1.0.0
*/

%:include "library.hpp"
%:include "windows.h"

int main() <%
    //! Only used for the title's Unicode format
    SetConsoleOutputCP(CP_UTF8);

    Library library;
    
    library.run();

    return 0;
%>