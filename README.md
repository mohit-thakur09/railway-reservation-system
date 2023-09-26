# Railway Enquiry & reservation System (CUI)

The **Railway Enquiry & Management System** is a three-tier architecture Command Line Interface (CUI) project developed in C programming language. This project demonstrates advanced concepts such as file handling, structures, header files, and functions to divide complex tasks into smaller sub-tasks, achieving modularity. It offers various features for checking train details, booking train tickets (generating PNR), canceling tickets, searching ticket details using PNR, and managing contact information.

## Three-Tier Architecture

The Railway Enquiry & Management System follows a three-tier architecture, which includes:

1. **Presentation Tier (User Interface)**:
   - The user interacts with the system through a command-line interface.
   - Options are presented to the user to perform various actions.

2. **Application Tier (Business Logic)**:
   - The core logic of the system resides in this tier.
   - It handles operations like booking tickets, canceling tickets, and searching for ticket details.
   - The application tier uses functions, structures, and file handling for data storage and retrieval.

3. **Data Tier (Data Storage)**:
   - The data tier stores information about trains, tickets, and contact details.
   - Data is stored in files (e.g., train information, ticket data, contact information).
   - File handling is employed to read and write data.

## Features

The Railway Enquiry & Management System offers the following features:

- **Check Train Details**:
  - Users can inquire about train schedules, routes, and availability.

- **Book Train Tickets**:
  - Users can book train tickets by providing necessary details.
  - A unique PNR (Passenger Name Record) is generated for each booking.

- **Cancel Tickets**:
  - Users can cancel their booked tickets by providing the PNR.

- **Search Ticket Details**:
  - Users can search for ticket details using the PNR.
  - Information about the booked ticket is displayed.

- **Manage Contact Details**:
  - Users can store and manage their contact information for future bookings.

## Getting Started

Follow these steps to run the Railway Enquiry & Management System:

1. Clone or download this repository to your local machine.

2. Compile the project using a C compiler (e.g., GCC):

   ```bash
   gcc railway.c -o railway
   ```

3. Run the compiled executable:

   ```bash
   ./railway
   ```

4. Follow the on-screen instructions to navigate and use the system.

## Usage

1. **Main Menu**:
   - Use numeric keys to select various options from the main menu.
   - Options include checking train details, booking tickets, canceling tickets, searching ticket details, and managing contact information.

2. **Booking Tickets**:
   - Provide necessary details such as name, age, contact, and preferred train.
   - A PNR will be generated upon successful booking.

3. **Canceling Tickets**:
   - Enter the PNR of the ticket to be canceled.
   - The system will confirm the cancellation.

4. **Searching Ticket Details**:
   - Enter the PNR of the ticket to retrieve its details.

5. **Managing Contact Details**:
   - Add, view, or modify contact information for future bookings.

## Contributing

Contributions to this project are welcome. You can contribute by opening issues, providing feedback, or submitting pull requests.

## License

This project is licensed under the MIT License - see the [LICENSE](LICENSE) file for details.

Enjoy using the Railway Enquiry & Management System!
