# Movie-Ticket-Booking
The provided code is a console-based C program for an online movie ticket booking system. It allows users to log in, view currently showing movies, book tickets, see upcoming movie premieres, and request movies for re-screening or premiering.
Description:
The program starts by prompting the user to log in with a username and password. Upon successful login, the user can navigate through a menu to view currently showing movies, book tickets, see upcoming movie premieres, and request movies. The ticket booking process includes selecting a movie, choosing the dimension (IMAX, 3D, or 2D), selecting the show time, entering personal information, and making a payment. The program stores the booking details in a text file and confirms the booking.

Key Concepts:
File Handling: The program uses file handling to store booking information and movie requests. It uses fopen, fprintf, and fclose functions to write to files.

Structures: The program defines a structure booker_information to store the user's personal information, including name, phone number, email, and address.

Global Variables: Movie names, show times, and dimensions are stored as global variables for easy access and modification.

Control Structures:

Loops: goto statements are used for navigating between different parts of the program.
Conditional Statements: if, else, and switch statements are used to control the flow of the program based on user input.
User Input and Output: The program interacts with the user through printf for output and scanf for input, allowing users to provide necessary information and make selections.

String Handling: The program uses functions from the string.h library to handle strings, such as user names, movie names, and requests.

Delay Function: The program uses Sleep function from windows.h to introduce delays for a better user experience, such as showing messages for a brief period before clearing the screen.

Basic Authentication: A simple authentication mechanism is implemented where the user has to enter a predefined password to log in.

Example Flow:
User logs in with a username and password.
User chooses to view currently showing movies.
User decides to book a ticket:
Selects a movie from the list.
Chooses the dimension (IMAX, 3D, 2D).
Selects a show time.
Enters personal information.
Makes a payment through a simulated banking process.
Booking details are saved and displayed to the user.
User can also view upcoming movies and request movies for re-screening or premiering.
This program provides a basic yet functional movie ticket booking system using fundamental C programming concepts and demonstrates how to handle user input, file operations, and simple navigation within a console application.
