# ✈️ Airport Management System

## 📌 Overview
The **Airport Management System** is a C++-based console application that manages air traffic control and flight bookings. It provides functionalities to handle flight arrivals, departures, and passenger ticket bookings.

## 🚀 Features
### 1️⃣ Air Traffic Controller (ATC)
   - 🛬 **Manage Flight Arrivals**: Add, update, delete, and view arriving flights.
   - 🛫 **Manage Flight Departures**: Add, update, delete, and view departing flights.
   - 📂 **File Handling**: Arrivals and departures are stored in `arrival.txt` and `departure.txt`.

### 2️⃣ Booking System
   - 🎫 **Book a Ticket**: Passengers can book flights by selecting destinations and airline options.
   - ❌ **Cancel a Ticket**: Cancel an existing flight booking.
   - 👀 **View Bookings**: Check all booked tickets.
   - 📝 **File Handling**: Bookings are stored in `booking.txt`.

## 🏗️ Classes & Structure
- **✈️ FlightManagement** (Base class)
  - Stores flight details like airline name, flight ID, from/to destinations, and status.
- **🛬 Arrival** (Derived from FlightManagement)
  - Stores additional details like arrival time, date, and status.
- **🛫 Departure** (Derived from FlightManagement)
  - Stores additional details like departure time, date, and status.
- **🕹️ ATC** (Manages Arrivals and Departures)
  - Controls the list of arrivals and departures, allowing updates and file storage.
- **👤 Booking**
  - Stores passenger details like name, passport number, flight details, and ticket price.
- **📅 CBT** (Manages Bookings)
  - Controls ticket booking, cancellation, and retrieval.

## ⚙️ Installation & Compilation
### ✅ Prerequisites
- 🖥️ C++ compiler (g++ or MSVC)
- 🏢 Windows OS (for `windows.h` dependency) or modify code for cross-platform compatibility

## 📝 Usage
- Run the program and select options from the **Main Menu**.
- Enter valid flight or booking details as prompted.
- 🔑 To access the ATC system, the correct password must be entered.
- 🗂️ All data is stored and retrieved from text files for persistence.

## 🔮 Future Improvements
- 🖥️ Implement a graphical user interface (GUI).
- 🗄️ Add a database for better data management.
- 🛠️ Improve error handling and input validation.



