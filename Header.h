
#ifndef HEADER_H
#define HEADER_H
#include<iostream>
#include<string>
#include<fstream>
#include<iomanip>
#include<windows.h>
#include <algorithm>  
#include <sstream>


#define RED    "\033[1;31m"
#define GREEN  "\033[1;32m"
#define YELLOW "\033[1;33m"
#define BLUE   "\033[1;34m"
#define RESET  "\033[0m"


using namespace std;

///////////////////// GLOBAL FUNCTIONS /////////////////////

void headerbarFMS();
void load();
bool passwordCheck(string correctPassword);
bool timeCheck(int& hrs, int& mins, string& meridian);
bool dateCheck(int& date, int& month, int& year);
//========================================================

///////////////// BASE CLASS FLIGHT MANAGEMENT SYSTEM ////////////////

class FlightManagemengt
{
protected:
	string airlineName;
	string from;
	string to;
	string status;
	int flightID;

public:

	FlightManagemengt();

	FlightManagemengt(string name, string f, string t, string s, int id);

	// GETTER 

	int getFlightID() const;
	string getAirlineName() const;
	string getFrom() const;
	string getTo() const;
	string getStatus() const;

	virtual void display() const;

	virtual~FlightManagemengt();
	
};


////////////////////// DERIVED CLASS ARRIVAL /////////////////////

class Arrival : public FlightManagemengt
{
protected:
	int arrivalHours;
	int arrivalMinuts;
	string arrivalMeridiam;
	string arrivalDay;
	int arrivalDate;
	int arrivalMonth;
	int arrivalYear;
	
	

public:

	Arrival();

	Arrival(string name, string f, string t, string s, int id, int ahrs, int aMins, string aMeridiam, string aDay, int aDate, int aMonth, int aYear);

	// GETTER FUNCTIONS 

	int getArrivalHours()const;
	int getArrivalMinuts()const;
	string getArrivalMeridiam()const;
	string getArrivalDay()const;
	int getArrivalDate()const;
	int getArrivalMonth()const;
	int getArrivalYear()const;


	void display()const override;

	virtual~Arrival();

};



////////////////////// DERIVED CLASS DEPARTURE /////////////////////

class Departure : public FlightManagemengt
{
protected:
	int departureHours;
	int departureMinuts;
	string departureMeridiam;
	string departureDay;
	int departureDate;
	int departureMonth;
	int departureYear;

public:

	Departure();

	Departure(string name, string f, string t, string s, int id, int dhrs, int dMins, string dMeridiam, string dDay, int dDate, int dMonth, int dYear);

	// GETTER FUNCTIONS 

	int getDepartureHours()const;
	int getDepartureMinuts()const;
	string getDepartureMeridiam()const;
	string getDepartureDay()const;
	int getDepartureDate()const;
	int getDepartureMonth()const;
	int getDepartureYear()const;

	void display()const override;

	virtual~Departure();
};

//////////////////////////////// CLASS ATC /////////////////////////////////////
class ATC
{
protected:
	Arrival* arrivals[20];
	Departure* departures[20];
	int arrivalCount;
	int departureCount;


public:
	 
	ATC();

	ATC(Arrival* arr, Departure* dep);

	bool isUniqueID(int id);

	void addArrival();
	void viewArrivals() const;
	void addDeparture();
	void viewDepartures() const;

	

	////////////// FILE HANDELING //////////////
	void saveArrivalsToFile();  //  Save to file
	void saveDeparturesToFile();  // Save to file
	void loadArrivalsFromFile();  //  Load from file
	void loadDeparturesFromFile();  //  Load from file


	///////////////////////////////////////////

	void updateArrival();
	void updateDeparture();
	void deleteArrival();
	void deleteDeparture();

	virtual~ATC();
};


//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

class Booking
{
protected:
	int bookID; //
	string name; //
	int age; // 
	long long mobileNumber; //
	string address; //
	string pasportNumber; //
	string airline; //
	int seats;//
	int category; //
	string destination; //
	string day; //
	int date; //
	int month; //
	int year; //
	int bookingHour; //
	int bookingMinutes; //
	string bookingMeridian; //
	double price; //
public:

	Booking();

	Booking(int id, string n, int a, long long mN, string adrs,string pasport, string airL, int sts, int cat, string des, string dy, int dt, int mnth, int yr, int bHrs, int bMins, string bMeridian, double p);

	int getBookID() const;
	string getBookName() const;
	int getBookAge() const;
	long long getBookMobileNumber() const;
	string getBookAddress() const;
	string getBookPassportNumber() const;
	string getBookAirline() const;
	int getBookSeats() const;
	int getBookCategory() const;
	string getBookDestination() const;
	string getBookDay() const;
	int getBookDate() const;
	int getBookMonth() const;
	int getBookYear() const;
	int getBookHour()const;
	int getBookMinuts()const;
	string getBookMeridian()const;
	double getBookPrice() const;


	virtual~Booking();

	
};
////////////////////////////// class  for  set booking /////////////////////////////////////


//\033[31\033[0m

class CBT
{
private:
	Booking* bookings[20];
	int bookingCount;

public:
	CBT();
	bool isUniqueBookingID(int id);
	bool isValidDestinationAndAirline(const string& destination, const string& airline, string& day, int& date, int& month, int& year, int& hours, int& minutes, string& meridian);
	void addBooking();
	void cancelBooking();
	void saveBookingsToFile();
	void loadBookingsFromFile();
	void viewBookings() const;
	~CBT();
};

#endif  

///////////////////


