#include "Header.h"
#include<iostream>
using namespace std;

///////////////////// GLOBAL FUNCTIONS /////////////////////
void headerbarFMS()
{
    cout << left;  // Left-align all columns
    cout << setw(5) << "ID"
        << setw(15) << "AIRLINE"
        << setw(12) << "FROM"
        << setw(12) << "TO"
        << setw(10) << "STATUS"
        << setw(10) << "DAY"
        << setw(15) << "TIME"
        << setw(15) << "DATE" << endl
        << "\033[32m-----------------------------------------------------------------------------------------------------\033[0m" << endl;
}

void load()
{
    cout << "\033[33m  LOADING \033[0m";
    for (int i = 0; i < 10; i++)
    {
        Sleep(100);
        cout << "\033[33m.\033[0m" << flush;
    }
    cout << endl;
}

// Function to check password with 3 attempts
bool passwordCheck(string correctPassword)
{
    string passkey;
    int attempts = 0;

    while (attempts < 3) 
    {
        cout << "\033[32m Enter Password: \033[0m";
        cin >> passkey;

        if (passkey == correctPassword)
        {
            cout << "\033[32mAccess Granted!\033[0m" << endl;
            load();
            return true;
        }
        else
        {
            cout << "\033[33mIncorrect Password! Attempts left: \033[0m" << (2 - attempts) << endl;
        }

        attempts++;
        
    }

    cout << "\033[31mToo many failed attempts! Access Denied.\033[0m" << endl;
    load();
    return false;
}

// Function to check time Format
bool timeCheck(int& hrs, int& mins, string& meridian)
{
    do
    {
        cout << "Enter the Hours (1-12): ";
        cin >> hrs;

        if (hrs < 1 || hrs > 12)
        {
            cout << RED << "Invalid Hours! Please enter a value between 1 and 12.\n" << RESET;
        }

    } while (hrs < 1 || hrs > 12); // Keep asking until valid input

    do
    {
        cout << "Enter the Minutes (0-59): ";
        cin >> mins;

        if (mins < 0 || mins > 59)
        {
            cout << RED << "Invalid Minutes! Please enter a value between 0 and 59.\n" << RESET;
        }

    } while (mins < 0 || mins > 59); // Keep asking until valid input

    do
    {
        cout << "Enter Meridian (AM/PM): ";
        cin >> meridian;

        // Convert to uppercase for case insensitivity
        for (char& c : meridian)
        {
            c = toupper(c);
        }

        if (meridian != "AM" && meridian != "PM")
        {
            cout << RED << "Invalid Meridian! Please enter 'AM' or 'PM'.\n" << RESET;
        }

    } while (meridian != "AM" && meridian != "PM"); // Keep asking until valid input

    return true;
}

// Function to check date format;
bool dateCheck(int& date, int& month, int& year)
{
    do
    {
        cout << "Enter the date (1-31): ";
        cin >> date;

        if (date < 1 || date > 31)
        {
            cout <<RED<< "Invalid date! Please enter a value between 1 and 31.\n" << RESET;
        }

    } while (date < 1 || date > 31); // Keep asking until valid input

    do
    {
        cout << "Enter the Month(1-12): ";
        cin >> month;

        if (month < 1 || month > 12)
        {
            cout << RED<<"Invalid Month! Please enter a value between 1 and 12.\n" << RESET;
        }

    } while (month < 1 || month > 12); // Keep asking until valid input

    
        cout << "Enter the year: ";
        cin >> year;

        return true;

}
//========================================================
// 


///////////////// BASE CLASS FLIGHT MANAGEMENT SYSTEM ////////////////

FlightManagemengt::FlightManagemengt() :airlineName(nullptr), from(nullptr), to(nullptr), status(nullptr), flightID(0) {}

FlightManagemengt::FlightManagemengt(string name, string f, string t, string s, int id)
    : airlineName(name), from(f), to(t), status(s), flightID(id) {}

int FlightManagemengt::getFlightID() const { return flightID; }  // Getter for ID
string FlightManagemengt::getAirlineName() const { return airlineName; }
string FlightManagemengt::getFrom() const { return from; }
string FlightManagemengt::getTo() const { return to; }
string FlightManagemengt::getStatus() const { return status; }


void FlightManagemengt::display() const
{
    cout << left;  // Ensure left alignment
    cout << setw(5) << flightID
        << setw(15) << airlineName
        << setw(12) << from
        << setw(12) << to
        << setw(10) << status;
}

FlightManagemengt::~FlightManagemengt() {}

////////////////////// DERIVED CLASS ARRIVAL /////////////////////

Arrival::Arrival() :FlightManagemengt(), arrivalHours(0), arrivalMinuts(0), arrivalMeridiam(nullptr), arrivalDay(nullptr), arrivalDate(0), arrivalMonth(0), arrivalYear(0) {}

Arrival::Arrival(string name, string f, string t, string s, int id, int ahrs, int aMins, string aMeridiam, string aDay, int aDate, int aMonth, int aYear)
    : FlightManagemengt(name, f, t, s, id), arrivalHours(ahrs), arrivalMinuts(aMins), arrivalMeridiam(aMeridiam), arrivalDay(aDay), arrivalDate(aDate), arrivalMonth(aMonth), arrivalYear(aYear) {}




// GETTER FUNCTIONS 

int Arrival::getArrivalHours()const { return arrivalHours; }
int Arrival::getArrivalMinuts()const { return arrivalMinuts; }
string Arrival::getArrivalMeridiam()const { return arrivalMeridiam; }
string Arrival::getArrivalDay()const { return arrivalDay; }
int Arrival::getArrivalDate()const { return arrivalDate; }
int Arrival::getArrivalMonth()const { return arrivalMonth; }
int Arrival::getArrivalYear()const { return arrivalYear; }


void Arrival::display() const
{
    
    FlightManagemengt::display();  // Display base class details
    if (status == "cancel" || status == "Cancel" || status == "canceled" || status == "Canceled")
    {
        cout << setw(10) << arrivalDay
            << setw(15) << "\033[33mcanceled\033[0m"
            << setw(15) << (to_string(arrivalDate) + "/" + to_string(arrivalMonth) + "/" + to_string(arrivalYear)) << endl;
    }
    else
    {
        cout << setw(10) << arrivalDay
            << setw(15) << (to_string(arrivalHours) + ":" + (arrivalMinuts < 10 ? "0" + to_string(arrivalMinuts) : to_string(arrivalMinuts)) + " " + arrivalMeridiam)
            << setw(15) << (to_string(arrivalDate) + "/" + to_string(arrivalMonth) + "/" + to_string(arrivalYear)) << endl;
    }
   
}

Arrival::~Arrival() {}


////////////////////// DERIVED CLASS DEPARTURE /////////////////////

 Departure::Departure():FlightManagemengt(), departureHours(0), departureMinuts(0), departureMeridiam(nullptr), departureDay(nullptr), departureDate(0), departureMonth(0), departureYear(0) {}


Departure::Departure(string name, string f, string t, string s, int id, int dhrs, int dMins, string dMeridiam, string dDay, int dDate, int dMonth, int dYear)
    : FlightManagemengt(name, f, t, s, id), departureHours(dhrs), departureMinuts(dMins), departureMeridiam(dMeridiam), departureDay(dDay), departureDate(dDate), departureMonth(dMonth), departureYear(dYear) {}


// GETTER FUNCTIONS 

int Departure::getDepartureHours()const { return departureHours; }
int Departure::getDepartureMinuts()const { return departureMinuts; }
string Departure::getDepartureMeridiam()const { return departureMeridiam; }
string Departure::getDepartureDay()const { return departureDay; }
int Departure::getDepartureDate()const { return departureDate; }
int Departure::getDepartureMonth()const { return departureMonth; }
int Departure::getDepartureYear()const { return departureYear; }


void Departure::display() const
{
    FlightManagemengt::display();  // Display base class details

    if (status == "cancel" || status == "Cancel" || status == "canceled" || status == "Canceled")
    {
        cout << setw(10) << departureDay
            << setw(15) <<"\033[33mcanceled\033[0m"
            << setw(15) << (to_string(departureDate) + "/" + to_string(departureMonth) + "/" + to_string(departureYear)) << endl;
    }
    else
    {
        cout << setw(10) << departureDay
            << setw(15) << (to_string(departureHours) + ":" + (departureMinuts < 10 ? "0" + to_string(departureMinuts) : to_string(departureMinuts)) + " " + departureMeridiam)
            << setw(15) << (to_string(departureDate) + "/" + to_string(departureMonth) + "/" + to_string(departureYear)) << endl;
    }
    
}

Departure::~Departure() {}



//////////////////////////////// CLASS ATC /////////////////////////////////////

ATC::ATC() :arrivalCount(0), departureCount(0)
{
    for (int i = 0; i < 20; i++)
    {
        arrivals[i] = nullptr;
        departures[i] = nullptr;

    }
}



bool ATC::isUniqueID(int id)
{
    // Check Arrivals
    for (int i = 0; i < arrivalCount; i++)
    {
        if (arrivals[i]->getFlightID() == id)
        {
            return false;  // ID already exists in Arrivals
        }
    }

    // Check Departures
    for (int i = 0; i < departureCount; i++)
    {
        if (departures[i]->getFlightID() == id)
        {
            return false;  // ID already exists in Departures
        }
    }

    return true;  // ID is unique
}



void ATC::addArrival()
{
    if (arrivalCount >= 20)
    {
        cout <<RED<< " Cannot add more arrivals. MAX LIMIT REACHED!\n" << RESET;
        return;
    }
    
    //====== USER DATA ENTERING VARIABLES =========

    string userAirlineName, from, to, status, meridian, day;
    int id{}, hrs{}, mins{}, date{}, month{}, year{};
    do
    {



        cout << "Enter Flight ID: ";
        cin >> id;
        // Check if input is not a valid number
        if (cin.fail()) 
        {
            cout << "\033[31mInvalid input! You must enter a number.\033[0m\n";
            cin.clear();  // Clear the error flag
            cin.ignore(1000, '\n');  // Ignore invalid input
            continue;
        }
        else
        {
            if (!isUniqueID(id))
            {
                cout << "\033[31mERROR: FLIGHT ID ALREADY EXISTS! TRY AGAIN.\033[0m\n";
            }
        }
        
    } while (cin.fail() || !isUniqueID(id));  // Keep asking until ID is unique

    cin.ignore();

    cout << "Enter Airline name: ";
    getline(cin, userAirlineName);
    cout << "Enter the \"FROM\" location: ";
    getline(cin, from);
    cout << "Enter the \"TO\" location: ";
    getline(cin, to);
    cout << "Enter the status of flight: (delayed / confirmed / canceled): ";
    getline(cin, status);

    if (status == "cancel" || status == "Cancel" || status == "canceled" || status == "Canceled" || status == "CANCEL" || status == "CANCELED")
    {
        cout << "Enter date\n";
        dateCheck(date, month, year);
        cin.ignore();
        cout << "Enter the day: ";
        getline(cin, day);
        // Store arrival in shared vector
        arrivals[arrivalCount] = new Arrival(userAirlineName, from, to, status, id, hrs, mins, meridian, day, date, month, year);
        arrivalCount++;
        cout << GREEN << "\n Arrival Added Successfully!\n" << RESET;
    }

    else  if (status != "cancel" || status != "Cancel" || status != "canceled" || status != "Canceled")
    {
        cout << "Enter time\n";
        timeCheck(hrs, mins, meridian);

        cout << "Enter date\n";
        dateCheck(date, month, year);
        cin.ignore();
        cout << "Enter the day: ";
        getline(cin, day);

        // Store arrival in shared vector
        arrivals[arrivalCount] = new Arrival(userAirlineName, from, to, status, id, hrs, mins, meridian, day, date, month, year);
        arrivalCount++;
        cout << GREEN << "\n Arrival Added Successfully!\n" << RESET;
    }
   
   
} 

       
    // View Arrivals
    void ATC::viewArrivals() const
    {
        if (arrivalCount == 0)
        {
            cout << "\033[31mNo Arrivals Available.\033[0m\n";
            return;
        }

        
        for (int i = 0; i < arrivalCount; i++)
        {
            arrivals[i]->display();
        }

       
    }
    void ATC::addDeparture()
    {
        
            if (departureCount >= 20)
            {
                cout << RED << " Cannot add more departure. MAX LIMIT REACHED!\n" << RESET;
                return;
            }

            //====== USER DATA ENTERING VARIABLES =========

            string userAirlineName, from, to, status, meridian, day;
            int id{}, hrs{}, mins{}, date{}, month{}, year{};
            do
            {



                cout << "Enter Flight ID: ";
                cin >> id;
                if (!isUniqueID(id))
                {
                    cout << "\033[31mERROR: FLIGHT ID ALREADY EXISTS! TRY AGAIN.\033[0m\n";
                }
            } while (!isUniqueID(id));  // Keep asking until ID is unique

            cin.ignore();

            cout << "Enter Airline name: ";
            getline(cin, userAirlineName);
            cout << "Enter the \"FROM\" location: ";
            getline(cin, from);
            cout << "Enter the \"TO\" location: ";
            getline(cin, to);
            cout << "Enter the status of flight: (delayed / confirmed / canceled): ";
            getline(cin, status);

            if (status == "cancel" || status == "Cancel" || status == "canceled" || status == "Canceled" || status == "CANCEL" || status == "CANCELED")
            {
                cout << "Entering dateCheck()...\n";  // Debugging
                dateCheck(date, month, year);
                cin.ignore();
                cout << "Enter the day: ";
                getline(cin, day);

                // Store arrival in shared vector
                departures[departureCount] = new Departure(userAirlineName, from, to, status, id, hrs, mins, meridian, day, date, month, year);
                departureCount++;
                cout << GREEN << "\n Departure Added Successfully!\n" << RESET;
            }
            
            else  if (status != "cancel" || status != "Cancel" || status != "canceled" || status != "Canceled")
            {
                cout << "Entering timeCheck()...\n";  // Debugging
                timeCheck(hrs, mins, meridian);

                cout << "Entering dateCheck()...\n";  // Debugging
                dateCheck(date, month, year);
                cin.ignore();
                cout << "Enter the day: ";
                getline(cin, day);

                // Store arrival in shared vector
                departures[departureCount] = new Departure(userAirlineName, from, to, status, id, hrs, mins, meridian, day, date, month, year);
                departureCount++;
                cout << GREEN << "\n Departure Added Successfully!\n" << RESET;
            }
           
        


    }
    

    void ATC::viewDepartures() const
    {
        if (departureCount == 0)
        {
            cout << "\033[31mNo Departure Available.\033[0m\n";
            return;
        }

       
        for (int i = 0; i < departureCount; i++)
        {
            departures[i]->display();
        }
    }

    //****************************************************************************************************************
    ////////////// FILE HANDELING //////////////
    void ATC::saveArrivalsToFile() //  Save to file
    {
        ofstream fout("arrival.txt");
        if (!fout)
        {
            cout << "\033[31m ERROR: Cannot open arrival.txt!\033[0m\n";
            return;
        }
        

        for (int i = 0; i < arrivalCount; i++)
        {
            fout << arrivals[i]->getFlightID() << " "
                << arrivals[i]->getAirlineName() << " "   //  Use getter function
                << arrivals[i]->getFrom() << " "
                << arrivals[i]->getTo() << " "
                << arrivals[i]->getStatus() << " "
                << arrivals[i]->getArrivalHours() << " "
                << arrivals[i]->getArrivalMinuts() << " "
                << arrivals[i]->getArrivalMeridiam() << " "
                << arrivals[i]->getArrivalDay() << " "
                << arrivals[i]->getArrivalDate() << " "
                << arrivals[i]->getArrivalMonth() << " "
                << arrivals[i]->getArrivalYear() << endl;
        }

        fout.close();
        cout << "\033[32m Arrivals saved to arrival.txt!\033[0m\n";

    }

    void ATC::saveDeparturesToFile()  // Save to file
    {
        ofstream fout("departure.txt");
        if (!fout)
        {
            cout << "\033[31 ERROR: Cannot open departure.txt!\033[0m\n";
            return;
        }

        for (int i = 0; i < departureCount; i++)
        {
            fout << departures[i]->getFlightID() << " "
                << departures[i]->getAirlineName() << " "   //  Use getter function
                << departures[i]->getFrom() << " "
                << departures[i]->getTo() << " "
                << departures[i]->getStatus() << " "
                << departures[i]->getDepartureHours() << " "
                << departures[i]->getDepartureMinuts() << " "
                << departures[i]->getDepartureMeridiam() << " "
                << departures[i]->getDepartureDay() << " "
                << departures[i]->getDepartureDate() << " "
                << departures[i]->getDepartureMonth() << " "
                << departures[i]->getDepartureYear() << endl;
        }


        fout.close();
        cout << "\033[32m Departures saved to departure.txt!\033[0m\n";
    }

    void ATC::loadArrivalsFromFile()  //  Load from file
    {

        ifstream fin("arrival.txt");  // Open file for reading
        if (!fin)
        {
            cout << "\033[31 ERROR: Cannot open arrival.txt! Starting fresh.\033[0m\n";
            return;
        }

        arrivalCount = 0;  // Reset count before loading
        int id, hrs, mins, date, month, year;
        string airline, from, to, status, meridian, day;

        while (fin >> id >> airline >> from >> to >> status
            >> hrs >> mins >> meridian >> day >> date >> month >> year)
        {
            if (arrivalCount >= 20) break;  // Prevent exceeding array size

            arrivals[arrivalCount] = new Arrival(airline, from, to, status, id, hrs, mins, meridian, day, date, month, year);
            arrivalCount++;
        }

        fin.close();
        cout << "\033[32mArrivals loaded from arrival.txt!\033[0m\n";

        //  Display All Loaded Arrivals in a Separate View Box
        if (arrivalCount > 0)
        {
            cout << RED << "\n======================================================================================================" << endl << RESET;
            cout << GREEN << "                                  LAST ARRIVALS LOADED FROM FILE   " << endl << RESET;
            cout << RED << "======================================================================================================" << endl << RESET;
            cout << left << setw(5) << "ID"
                << setw(15) << "Airline"
                << setw(12) << "From"
                << setw(12) << "To"
                << setw(10) << "Status"
                << setw(10) << "Day"
                << setw(15) << "Time"
                << setw(15) << "Date" << endl;
            cout << RED << "------------------------------------------------------------------------------------------------------" << endl << RESET;

            for (int i = 0; i < arrivalCount; i++)
            {
                cout << left
                    << setw(5) << arrivals[i]->getFlightID()
                    << setw(15) << arrivals[i]->getAirlineName()
                    << setw(12) << arrivals[i]->getFrom()
                    << setw(12) << arrivals[i]->getTo()
                    << setw(12) << arrivals[i]->getStatus()
                    << setw(10) << arrivals[i]->getArrivalDay()
                    << setw(6) << (arrivals[i]->getArrivalHours() < 10 ? "0" : "") << arrivals[i]->getArrivalHours() << ":"
                    << (arrivals[i]->getArrivalMinuts() < 10 ? "0" : "") << arrivals[i]->getArrivalMinuts()
                    << setw(5) << arrivals[i]->getArrivalMeridiam()
                    << setw(4) << (arrivals[i]->getArrivalDate() < 10 ? "0" : "") << arrivals[i]->getArrivalDate() << "/"
                    << setw(4) << (arrivals[i]->getArrivalMonth() < 10 ? "0" : "") << arrivals[i]->getArrivalMonth() << "/"
                    << setw(6) << arrivals[i]->getArrivalYear()
                    << endl;
            }
            cout << RED << "======================================================================================================" << endl << RESET;
        }
    }

    void ATC::loadDeparturesFromFile()  //  Load from file

    {
        ifstream fin("departure.txt", ios::in);  // Open file for reading
        if (!fin.is_open())
        {
            cout << "\033[31 ERROR: Cannot open departure.txt! Starting fresh.\033[0m\n";
            return;
        }

        departureCount = 0;  // Reset count before loading
        int id, hrs, mins, date, month, year;
        string airline, from, to, status, meridian, day;

        while (fin >> id >> airline >> from >> to >> status
            >> hrs >> mins >> meridian >> day >> date >> month >> year)
        {
            if (departureCount >= 20) break;  // Prevent exceeding array size

            departures[departureCount] = new Departure(airline, from, to, status, id, hrs, mins, meridian, day, date, month, year);
            departureCount++;
        }

        fin.close();
        cout << "\033[32mDeparture loaded from departure.txt!\033[0m\n";

        //  Display All Loaded Arrivals in a Separate View Box
        if (departureCount > 0)
        {
            cout << RED << "\n======================================================================================================" << endl << RESET;
            cout << GREEN << "                                  LAST Departures LOADED FROM FILE   " << endl << RESET;
            cout << RED << "======================================================================================================" << endl << RESET;
            cout << left << setw(5) << "ID"
                << setw(15) << "Airline"
                << setw(12) << "From"
                << setw(12) << "To"
                << setw(10) << "Status"
                << setw(10) << "Day"
                << setw(15) << "Time"
                << setw(15) << "Date" << endl;
            cout << RED << "------------------------------------------------------------------------------------------------------" << endl << RESET;

            for (int i = 0; i < departureCount; i++)
            {
                cout << left
                    << setw(5) << departures[i]->getFlightID()
                    << setw(15) << departures[i]->getAirlineName()
                    << setw(12) << departures[i]->getFrom()
                    << setw(12) << departures[i]->getTo()
                    << setw(12) << departures[i]->getStatus()
                    << setw(10) << departures[i]->getDepartureDay()
                    << setw(6) << (departures[i]->getDepartureHours() < 10 ? "0" : "") << departures[i]->getDepartureHours() << ":"
                    << (departures[i]->getDepartureMinuts() < 10 ? "0" : "") << departures[i]->getDepartureMinuts()
                    << setw(5) << departures[i]->getDepartureMeridiam()
                    << setw(4) << (departures[i]->getDepartureDate() < 10 ? "0" : "") << departures[i]->getDepartureDate() << "/"
                    << setw(4) << (departures[i]->getDepartureMonth() < 10 ? "0" : "") << departures[i]->getDepartureMonth() << "/"
                    << setw(6) << departures[i]->getDepartureYear()
                    << endl;
            }
            cout <<RED<< "======================================================================================================" << endl << RESET;
        }
    }
    

    ///////////////////////////////////////////

    void ATC::updateArrival()
    {
        int tempID{};
        cout << "Enter the Flight ID you want to update: ";
        cin >> tempID;

        if (arrivalCount == 0)
        {
            cout << "\033[31m No Arrivals Available.\033[0m\n";
            return;
        }

        bool found = false;

        for (int i = 0; i < arrivalCount; i++)
        {
            if (tempID == arrivals[i]->getFlightID())
            {
                found = true;
                string userAirlineName = arrivals[i]->getAirlineName();
                string from = arrivals[i]->getFrom();
                string to = arrivals[i]->getTo();
                string status = arrivals[i]->getStatus();
                string meridian = arrivals[i]->getArrivalMeridiam();
                string day = arrivals[i]->getArrivalDay();
                int hrs = arrivals[i]->getArrivalHours();
                int mins = arrivals[i]->getArrivalMinuts();
                int date = arrivals[i]->getArrivalDate();
                int month = arrivals[i]->getArrivalMonth();
                int year = arrivals[i]->getArrivalYear();

                int choice{};
                cout << " ENTER THE FIELD YOU WANT TO UPDATE: "
                    "\n1. Airline Name"
                    "\n2. From Destination"
                    "\n3. To Destination"
                    "\n4. Status"
                    "\n5. Date"
                    "\n6. Time"
                    "\n7. Day"
                    "\n8. ALL"
                    "\n9. BACK\n";
                cout <<GREEN<< "CHOICE = " << RESET;
                cin >> choice;
                cin.ignore();  //  Fix for getline() issue

                switch (choice)
                {
                case 1:
                    cout << "Enter Airline Name: ";
                    getline(cin, userAirlineName);
                    break;
                case 2:
                    cout << "Enter \"FROM\" Location: ";
                    getline(cin, from);
                    break;
                case 3:
                    cout << "Enter \"TO\" Location: ";
                    getline(cin, to);
                    break;
                case 4:
                    cout << "Enter Status (delayed / confirmed / canceled): ";
                    getline(cin, status);
                    break;
                case 5:
                    cout << "Enter Date:\n";
                    dateCheck(date, month, year);
                    break;
                case 6:
                    cout << "Enter Time:\n";
                    timeCheck(hrs, mins, meridian);
                    break;
                case 7:
                    cout << "Enter Day: ";
                    getline(cin, day);
                    break;
                case 8:
                    //  Delete the old Arrival before full replacement
                    delete arrivals[i];

                    cout << "Enter Airline Name: ";
                    getline(cin, userAirlineName);
                    cout << "Enter \"FROM\" Location: ";
                    getline(cin, from);
                    cout << "Enter \"TO\" Location: ";
                    getline(cin, to);
                    cout << "Enter Status (delayed / confirmed / canceled): ";
                    getline(cin, status);
                    cout << "Enter Time:\n";
                    timeCheck(hrs, mins, meridian);
                    cout << "Enter Date:\n";
                    dateCheck(date, month, year);
                    cout << "Enter Day: ";
                    getline(cin, day);
                    break;
                case 9:
                    cout << YELLOW << " RETURNING " << RESET;
                    load();
                    return;  //  Exit function
                default:
                    cout << "\033[31m Invalid choice! Try again.\033[0m\n";
                    return;
                }

                //  Update the existing object instead of recreating it
                delete arrivals[i];
                arrivals[i] = new Arrival(userAirlineName, from, to, status, tempID, hrs, mins, meridian, day, date, month, year);

                cout << "\n\033[32mArrival Updated Successfully!\033[0m\n";

                //  Save the updated data to the file
                saveArrivalsToFile();

                return;  //  Exit after updating
            }
        }

        if (!found)
        {
            cout << RED << " No Arrival found with Flight ID " << RESET << tempID << ".\n";
        }
    }

    void ATC::updateDeparture()
    {
        int tempID{};
        cout << "Enter the Flight ID you want to update: ";
        cin >> tempID;

        if (departureCount == 0)
        {
            cout << RED << " No Departure Available.\n" << RESET;
            return;
        }

        bool found = false;

        for (int i = 0; i < departureCount; i++)
        {
            if (tempID == departures[i]->getFlightID())
            {
                found = true;
                string userAirlineName = departures[i]->getAirlineName();
                string from = departures[i]->getFrom();
                string to = departures[i]->getTo();
                string status = departures[i]->getStatus();
                string meridian = departures[i]->getDepartureMeridiam();
                string day = departures[i]->getDepartureDay();
                int hrs = departures[i]->getDepartureHours();
                int mins = departures[i]->getDepartureMinuts();
                int date = departures[i]->getDepartureDate();
                int month = departures[i]->getDepartureMonth();
                int year = departures[i]->getDepartureYear();

                int choice{};
                cout << " ENTER THE FIELD YOU WANT TO UPDATE: "
                    "\n1. Airline Name"
                    "\n2. From Destination"
                    "\n3. To Destination"
                    "\n4. Status"
                    "\n5. Date"
                    "\n6. Time"
                    "\n7. Day"
                    "\n8. ALL"
                    "\n9. BACK\n";
                cout << GREEN << "CHOICE = " << RESET;
                cin >> choice;
                cin.ignore();  // Fix for getline() issue

                switch (choice)
                {
                case 1:
                    cout << "Enter Airline Name: ";
                    getline(cin, userAirlineName);
                    break;
                case 2:
                    cout << "Enter \"FROM\" Location: ";
                    getline(cin, from);
                    break;
                case 3:
                    cout << "Enter \"TO\" Location: ";
                    getline(cin, to);
                    break;
                case 4:
                    cout << "Enter Status (delayed / confirmed / canceled): ";
                    getline(cin, status);
                    break;
                case 5:
                    cout << "Enter Date:\n";
                    dateCheck(date, month, year);
                    break;
                case 6:
                    cout << "Enter Time:\n";
                    timeCheck(hrs, mins, meridian);
                    break;
                case 7:
                    cout << "Enter Day: ";
                    getline(cin, day);
                    break;
                case 8:
                    //  Delete the old Departure before full replacement
                    delete arrivals[i];

                    cout << "Enter Airline Name: ";
                    getline(cin, userAirlineName);
                    cout << "Enter \"FROM\" Location: ";
                    getline(cin, from);
                    cout << "Enter \"TO\" Location: ";
                    getline(cin, to);
                    cout << "Enter Status (delayed / confirmed / canceled): ";
                    getline(cin, status);
                    cout << "Enter Time:\n";
                    timeCheck(hrs, mins, meridian);
                    cout << "Enter Date:\n";
                    dateCheck(date, month, year);
                    cout << "Enter Day: ";
                    getline(cin, day);
                    break;
                case 9:
                    cout << YELLOW << " RETURNING " << RESET;
                    load();
                    return;  //  Exit function
                default:
                    cout << RED << " Invalid choice! Try again.\n" << RESET;
                    return;
                }

                //  Update the existing object instead of recreating it
                delete departures[i];
                departures[i] = new Departure(userAirlineName, from, to, status, tempID, hrs, mins, meridian, day, date, month, year);

                cout << GREEN << "\n Departure Updated Successfully!\n" << RESET;

                // Save the updated data to the file
                saveDeparturesToFile();

                return;  // Exit after updating
            }
        }

        if (!found)
        {
            cout << RED << " No Departure found with Flight ID " << RESET << tempID << ".\n";
        }
    }

    void ATC::deleteArrival()
    {
        int tempID{};
        cout << "Enter the Flight ID you want to delete: ";
        cin >> tempID;

        if (arrivalCount == 0)
        {
            cout << RED << " No Arrival Available.\n" << RESET;
            return;
        }

        bool found = false;

        for (int i = 0; i < arrivalCount; i++)
        {
            if (tempID == arrivals[i]->getFlightID())
            {
                found = true;


                delete arrivals[i];


                for (int j = i; j < arrivalCount - 1; j++)
                {
                    arrivals[j] = arrivals[j + 1];
                }

                arrivals[arrivalCount - 1] = nullptr;  //  Prevent dangling pointer
                arrivalCount--;  //  Reduce count

                cout << "\n Arrival Deleted Successfully!\n";

                //  Step 3: Save updated arrivals to file
                saveArrivalsToFile();

                return;  //  Exit after deletion
            }
        }

        if (!found)
        {
            cout << RED << " No Arrival found with Flight ID " << RESET << tempID << ".\n";
        }
    }
    void ATC::deleteDeparture()
    {
        int tempID{};
        cout << "Enter the Flight ID you want to delete: ";
        cin >> tempID;

        if (departureCount == 0)
        {
            cout << RED << " No Departure Available.\n" << RESET;
            return;
        }

        bool found = false;

        for (int i = 0; i < departureCount; i++)
        {
            if (tempID == departures[i]->getFlightID())
            {
                found = true;

                
                delete departures[i];

               
                for (int j = i; j < departureCount - 1; j++)
                {
                    departures[j] = departures[j + 1];
                }

                departures[departureCount - 1] = nullptr;  //  Prevent dangling pointer
                departureCount--;  //  Reduce count

                cout << GREEN << "\n Departure Deleted Successfully!\n" << RESET;

                //  Step 3: Save updated departures to file
                saveDeparturesToFile();

                return;  //  Exit after deletion
            }
        }

        if (!found)
        {
            cout << RED << " No Departure found with Flight ID " << RESET << tempID << ".\n";
        }
    }


    ATC::~ATC() 
    {
        for (int i = 0; i < arrivalCount; i++)
            delete arrivals[i];

        for (int i = 0; i < departureCount; i++)
            delete departures[i];
    }

    //////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    //////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////// BOOKING CLASS /////////////////////////////////////////////////////////////


    Booking::Booking():bookID(0), name(""), age(0), mobileNumber(0), address(""),pasportNumber(0), airline(""),
        seats(0), category(0), destination(""), day(""), date(0), month(0), year(0),bookingHour(0),bookingMinutes(0),bookingMeridian(""), price(0) {}

    Booking::Booking(int id, string n, int a, long long mN, string adrs, string pasport, string airL,
        int sts, int cat, string des, string dy, int dt, int mnth, int yr,
        int bHrs, int bMins, string bMeridian, double p)
        : bookID(id),  
        name(n), age(a), mobileNumber(mN), address(adrs),
        pasportNumber(pasport), airline(airL), seats(sts), category(cat),
        destination(des), day(dy), date(dt), month(mnth), year(yr),
        bookingHour(bHrs), bookingMinutes(bMins), bookingMeridian(bMeridian),
        price(p) {}


    int      Booking::getBookID()               const { return bookID; }
    string   Booking::getBookName()             const { return name; }
    int      Booking::getBookAge()              const { return age; }
long long      Booking::getBookMobileNumber()   const { return mobileNumber; }
    string   Booking::getBookAddress()          const { return address; }
    string   Booking::getBookPassportNumber()   const { return pasportNumber; }
    string   Booking::getBookAirline()          const { return airline; }
    int      Booking::getBookSeats()            const { return seats; }
    int      Booking::getBookCategory()         const { return category; }
    string   Booking::getBookDestination()      const { return destination; }
    string   Booking::getBookDay()              const { return day; }
    int      Booking::getBookDate()             const { return date; }
    int      Booking::getBookMonth()            const { return month; }
    int      Booking::getBookYear()             const { return year; }
    int      Booking::getBookHour()             const { return bookingHour; }
    int      Booking::getBookMinuts()           const { return bookingMinutes; }
    string   Booking::getBookMeridian()         const { return bookingMeridian; }
    double   Booking::getBookPrice()            const { return price; }

   

    Booking::~Booking() {}



    
    
   ////////////////////////////// CBT class  for  set booking /////////////////////////////////////
    

    CBT::CBT() : bookingCount(0) 
    {
        for (int i = 0; i < 20; i++)
        {
            bookings[i] = nullptr;
        }
    }

    bool CBT::isUniqueBookingID(int id) 
    {
        for (int i = 0; i < bookingCount; i++) 
        {
            if (bookings[i]->getBookID() == id) 
            {
                return false;
            }
        }
        return true;
    }

   
    bool CBT::isValidDestinationAndAirline(const string& destination, const string& airline, string& day, int& date, int& month, int& year, int& hours, int& minutes, string& meridian) 
    {
        ifstream fin("departure.txt");
        if (!fin) 
        {
            cout << RED << "Error: Unable to open departure.txt!" << endl << RESET;
            return false;
        }

        string line, fileDest, fileAirline;
        while (getline(fin, line)) 
        {
            istringstream iss(line);
            int id;
            string from, status;
            iss >> id >> fileAirline >> from >> fileDest >> status >> hours >> minutes >> meridian >> day >> date >> month >> year;

            if (fileDest == destination && fileAirline == airline)
            {
                fin.close();
                return true;
            }
        }
        fin.close();
        cout << RED << "Error: Destination and Airline not found!" << endl << RESET;
        return false;
    }

    void CBT::saveBookingsToFile()
    {
        ofstream fout("booking.txt");
        if (!fout)
        {
            cout << RED << "Error: Unable to open booking.txt for writing!" << endl << RESET;
            return;
        }

        for (int i = 0; i < bookingCount; i++)
        {
            fout << bookings[i]->getBookID() << " "
                << bookings[i]->getBookName() << " "
                << bookings[i]->getBookAge() << " "
                << bookings[i]->getBookMobileNumber() << " "
                << bookings[i]->getBookAddress() << " "
                << bookings[i]->getBookPassportNumber() << " "
                << bookings[i]->getBookAirline() << " "
                << bookings[i]->getBookSeats() << " "
                << bookings[i]->getBookCategory() << " "
                << bookings[i]->getBookDestination() << " "
                << bookings[i]->getBookPrice() << endl;
        }
        fout.close();
        cout << GREEN << "Bookings saved to booking.txt successfully!" << endl << RESET;
    }

    void CBT::addBooking()
    {
        if (bookingCount >= 20) 
        {
            cout << RED << "Booking limit reached! Cannot add more bookings." << endl << RESET;
            return;
        }

        int id, age, seats, category, date, month, year, hours, minutes;
        long long mobileNumber;
        string name, address, passport, airline, destination, day, meridian;
        double price;

        do 
        {
            cout << "Enter Booking ID: ";
            cin >> id;
            if (!isUniqueBookingID(id)) cout << RED << "Booking ID must be unique! Try again." << endl << RESET;
        } while (!isUniqueBookingID(id));

        
       
         cout << "Enter Passport Number: ";
         cin >> passport;
           
       

        cin.ignore();
        cout << "Enter Name: ";
        getline(cin, name);
        cout << "Enter Age: ";
        cin >> age;
        cout << "Enter Mobile Number: ";
        cin >> mobileNumber;
        cin.ignore();
        cout << "Enter Address: ";
        getline(cin, address);

        while (true) 
        {
            cout << "Enter Destination: ";
            getline(cin, destination);
            cout << "Enter Airline Name: ";
            getline(cin, airline);

            if (isValidDestinationAndAirline(destination, airline, day, date, month, year, hours, minutes, meridian)) 
            {
                break;
            }

            char choice;
            cout << YELLOW << "Do you want to try again? (y/n): " << RESET;
            cin >> choice;
            cin.ignore();
            if (choice == 'n' || choice == 'N') 
            {
                cout << YELLOW << "Booking cancelled! Returning to main menu." << endl << RESET;
                return;
            }
        }

        cout << "Choose Category:\n1. Economy ($100)\n2. Business ($300)\n3. Executive ($350)\nChoice: ";
        do 
        {
            cin >> category;
            if (category < 1 || category > 3) cout << RED << "Invalid category! Try again: " << RESET;
        } while (category < 1 || category > 3);

        cout << "Enter Number of Seats: ";
        do 
        {
            cin >> seats;
            if (seats <= 0) cout << RED << "Seats must be greater than 0! Try again: " << RESET;
        } while (seats <= 0);

        price = seats * (category == 1 ? 100 : category == 2 ? 300 : 350);

        bookings[bookingCount++] = new Booking(id, name, age, mobileNumber, address, passport, airline, seats, category, destination, day, date, month, year, hours, minutes, meridian, price);
        cout << GREEN << "Booking Added Successfully!" << endl << RESET;
    }


    void CBT::cancelBooking() 
    {
        if (bookingCount == 0)
        {
            cout << RED << "No bookings available to cancel!" << endl << RESET;
            return;
        }

        int id;
        cout << "Enter Booking ID to cancel: ";
        cin >> id;

        for (int i = 0; i < bookingCount; i++)
        {
            if (bookings[i]->getBookID() == id) 
            {
                delete bookings[i];
                for (int j = i; j < bookingCount - 1; j++) 
                {
                    bookings[j] = bookings[j + 1];
                }
                bookings[--bookingCount] = nullptr;
                cout << GREEN << "Booking cancelled successfully!" << endl << RESET;

                // Update the file to reflect the deletion
                ofstream fout("booking.txt");
                if (!fout) {
                    cout << RED << "Error: Unable to update booking.txt!" << endl << RESET;
                    return;
                }
                for (int k = 0; k < bookingCount; k++) {
                    fout << bookings[k]->getBookID() << " "
                        << bookings[k]->getBookName() << " "
                        << bookings[k]->getBookAge() << " "
                        << bookings[k]->getBookMobileNumber() << " "
                        << bookings[k]->getBookAddress() << " "
                        << bookings[k]->getBookPassportNumber() << " "
                        << bookings[k]->getBookAirline() << " "
                        << bookings[k]->getBookSeats() << " "
                        << bookings[k]->getBookCategory() << " "
                        << bookings[k]->getBookDestination() << " "
                        << bookings[k]->getBookPrice() << endl;
                }
                fout.close();
                return;
            }
        }
        cout << RED << "Booking ID not found!" << endl << RESET;
    }

    void CBT::viewBookings() const 
    {
        if (bookingCount == 0) 
        {
            cout << RED << "No bookings available!" << endl << RESET;
            return;
        }
        cout << RED << "\n--- Booking List ---" << endl << RESET;
        for (int i = 0; i < bookingCount; i++) {
            cout << "Booking ID:        " << bookings[i]->getBookID() << endl;
            cout << "Name:              " << bookings[i]->getBookName() << endl;
            cout << "Age:               " << bookings[i]->getBookAge() << endl;
            cout << "Mobile:            " << bookings[i]->getBookMobileNumber() << endl;
            cout << "Passport:          " << bookings[i]->getBookPassportNumber() << endl;
            cout << "Airline:           " << bookings[i]->getBookAirline() << endl;
            cout << "Destination:       " << bookings[i]->getBookDestination() << endl;
            cout << "Seats:             " << bookings[i]->getBookSeats() << endl;
            if (bookings[i]->getBookCategory() == 1)
            {
                cout << "Category:          " << BLUE << "ECONOMY " << RESET << endl;
            }
            else if (bookings[i]->getBookCategory() == 2)
            {
                cout << "Category:          " << YELLOW << "BUSINESS " << RESET << endl;
            }
            else if (bookings[i]->getBookCategory() == 3)
            {
                cout << "Category:          " << GREEN << "EXECUTIVE " << RESET << endl;
            }
            cout << "Total Price: $     " << bookings[i]->getBookPrice() << endl;
            cout << RED << "----------------------------" << endl << RESET;
        }
    }

    void CBT::loadBookingsFromFile()
    {
        ifstream fin("booking.txt");
        if (!fin)
        {
            cout << RED << "No previous bookings found!" << endl << RESET;
            return;
        }

        bookingCount = 0;
        cout << RED << "\n--- Last Bookings Loaded ---" << endl << RESET;
        while (fin && bookingCount < 20)
        {
            int id, age, seats, category;
            long long mobileNumber;
            string name, address, passport, airline, destination;
            double price;

            fin >> id >> name >> age >> mobileNumber >> address >> passport >> airline >> seats >> category >> destination >> price;

            if (fin) 
            {
                bookings[bookingCount++] = new Booking(id, name, age, mobileNumber, address, passport, airline, seats, category, destination, "", 0, 0, 0, 0, 0, "", price);
                
            }
        }

        fin.close();
        cout << RED << "------------------------------" << endl << RESET;
        cout << GREEN << "Bookings loaded successfully!" << endl << RESET;
    }



    CBT::~CBT() 
    {
        for (int i = 0; i < bookingCount; i++) 
        {
            delete bookings[i];
        }
    }
