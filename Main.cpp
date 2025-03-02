#include"Header.h"
using namespace std;


int main()
{
    int userChoice = 0, atcChoice = 0, arrivalChoice = 0, departureChoice = 0;
    
    ATC atcSystem;
    CBT cbtSystem;
   
    
    
    do
    {
        system("cls");  // CLEAR SCREEN

        // Main Menu
        cout << "\033[33m--------------------------- MENU --------------------------------\033[0m" << endl;
        cout << "\033[32m ENTER YOUR CHOICE: \033[0m" << endl;
        cout << "\033[33m1. Air Traffic Controller (ATC)\033[0m" << endl;
        cout << "\033[33m2. Book a Ticket\033[0m" << endl;
        cout << "\033[33m3. Exit\033[0m" << endl;
        cout << "\033[32m-----------------------------------------------------------------\033[0m" << endl;
        cout << "\033[32mChoice: \033[0m";
        cin >> userChoice;
        if (cin.fail()) ///////////// error handeling
        {
            cout << RED << " Invalid input! You must enter a number.\n" << RESET;
            cin.clear();  // Clear the error flag
            cin.ignore(1000, '\n');  // Ignore invalid input
            continue;
        }
        load();
        system("cls"); // CLEAR SCREEN

        switch (userChoice)
        {
        case 1:  // Air Traffic Control
            if (passwordCheck("atc"))
            {
                do
                {


                    cout << "\n\033[32m          AIR TRAFFIC CONTROLLER (ATC)   \033[0m" << endl;
                    cout << "\033[33m1. Arrival Management\033[0m" << endl;
                    cout << "\033[33m2. Departure Management\033[0m" << endl;
                    cout << "\033[33m3. Back to Main Menu\033[0m" << endl;
                    cout << "\033[32mChoice: \033[0m";
                    cin >> atcChoice;
                    if (cin.fail()) ///////////// error handeling
                    {
                        cout << RED << " Invalid input! You must enter a number.\n" << RESET;
                        cin.clear();  // Clear the error flag
                        cin.ignore(1000, '\n');  // Ignore invalid input
                        continue;
                    }
                    load();
                    system("cls"); // CLEAR SCREEN

                    switch (atcChoice)
                    {
                    case 1: // Arrival Management
                        do
                        {
                            cout << RED << "\n----- ARRIVAL MANAGEMENT -----" << endl << RESET;
                            cout << "1. Add Arrival" << endl;
                            cout << "2. Update Arrival" << endl;
                            cout << "3. Delete Arrival" << endl;
                            cout << "4. View Arrivals" << endl;
                            cout << "5. Last record Arrivals from txt file" << endl;
                            cout << "6. Back to ATC Menu" << endl;
                            cout << RED << "-----------------------------------" << endl << RESET;
                            cout << GREEN << "Choice: " << RESET;
                            cin >> arrivalChoice;
                            if (cin.fail()) ///////////// error handeling
                            {
                                cout << RED << " Invalid input! You must enter a number.\n" << RESET;
                                cin.clear();  // Clear the error flag
                                cin.ignore(1000, '\n');  // Ignore invalid input
                                continue;
                            }
                            
                            system("cls"); // CLEAR SCREEN

                            if (arrivalChoice == 1)
                            {
                                atcSystem.addArrival();
                                atcSystem.saveArrivalsToFile();
                            }

                            else if (arrivalChoice == 2)
                            {
                                headerbarFMS();
                                atcSystem.viewArrivals();
                                atcSystem.updateArrival();
                            }
                            else if (arrivalChoice == 3)
                            {
                                headerbarFMS();
                                atcSystem.viewArrivals();
                                atcSystem.deleteArrival();
                            }

                            else if (arrivalChoice == 4)
                            {
                                headerbarFMS(); 
                                atcSystem.viewArrivals();
                            }

                            else if (arrivalChoice == 5)
                            {
                                atcSystem.loadArrivalsFromFile();
                            }
                           
                            else if (arrivalChoice == 6)
                            {
                                break; // Back option
                            }

                            else if (arrivalChoice < 1 || arrivalChoice > 6)
                            {
                                cout << RED << "Invalid choice! Try again.\n" << RESET;
                                
                            }
                               
                            else
                            {
                                cout << RED << "Feature not implemented yet!\n" << RESET; // Placeholder

                            }

                        } while (cin.fail() || arrivalChoice != 6);
                        load();
                        break;

                    case 2: // Departure Management
                        do
                        {
                            cout << RED << "\n----- DEPARTURE MANAGEMENT -----" << endl << RESET;
                            cout << "1. Add Departure" << endl;
                            cout << "2. Update Departure" << endl;
                            cout << "3. Delete Departure" << endl;
                            cout << "4. View Departures" << endl;
                            cout << "5. Last record Departures from txt file" << endl;
                            cout << "6. Back to ATC Menu" << endl;
                            cout << RED << "-----------------------------------" << endl << RESET;
                            cout << GREEN << "Choice: " << RESET;
                            cin >> departureChoice;
                            if (cin.fail()) ///////////// error handeling
                            {
                                cout << RED << " Invalid input! You must enter a number.\n" << RESET;
                                cin.clear();  // Clear the error flag
                                cin.ignore(1000, '\n');  // Ignore invalid input
                                continue;
                            }
                            system("cls"); // CLEAR SCREEN

                            if (departureChoice == 1)
                            {
                                atcSystem.addDeparture();
                                atcSystem.saveDeparturesToFile();
                            }
                            else if (departureChoice == 2)
                            {
                                headerbarFMS();
                                atcSystem.viewDepartures();
                                atcSystem.updateDeparture();
                            }
                            else if (departureChoice == 3)
                            {
                                headerbarFMS();
                                atcSystem.viewDepartures();
                                atcSystem.deleteDeparture();
                            }
                            else if (departureChoice == 4)
                            {
                                headerbarFMS();
                                atcSystem.viewDepartures();
                            }
                            
                            else if (departureChoice == 5)
                            {
                                atcSystem.loadDeparturesFromFile();
                            }
                            else if (departureChoice == 6)
                            {
                                break; // Back option
                            }
                            else if (departureChoice < 1 || departureChoice > 6)
                            {
                                cout << RED << "Invalid choice! Try again.\n" << RESET;

                            }
                            else
                            {
                                cout << RED << "Feature not implemented yet!\n" << RESET; // Placeholde

                            }
                        } while (cin.fail()  || departureChoice != 6);
                        load();
                        break;
                       
                    case 3:
                        cout << YELLOW << "Returning to Main Menu...\n" << RESET;
                        load();
                        break;

                    default:
                        cout << RED << "Invalid choice! Please enter a valid option.\n" << RESET;
                    }
                } while (cin.fail() || atcChoice != 3);
                

            }             
            break;
        case 2:  // Book a Ticket
            int ticketChoice;
            do
            {
                cout << RED << "\n        AIR TICKET BOOKING   " << endl << RESET;
                cout << "1. Book a New Ticket" << endl;
                cout << "2. View Ticket Details" << endl;
                cout << "3. Cancel a Ticket" << endl;
                cout << "4. Show last Bookings " << endl;
                cout << "5. Exit " << endl;
                cout << GREEN << "Choice: " << RESET;
                cin >> ticketChoice;
                load();
                if (cin.fail()) ///////////// error handeling
                {
                    cout << RED << " Invalid input! You must enter a number.\n" << RESET;
                    cin.clear();  // Clear the error flag
                    cin.ignore(1000, '\n');  // Ignore invalid input
                    continue;
                }
                
                system("cls"); // CLEAR SCREEN

                if (ticketChoice == 1)
                {
                    atcSystem.loadDeparturesFromFile();
                    system("cls");
                    headerbarFMS();
                    atcSystem.viewDepartures();
                    cout << RED << "------------------------------------------------------------------------------------------------------" << endl << RESET;
                    cbtSystem.addBooking();
                    cbtSystem.saveBookingsToFile();
                                     
                   
                }

                else if (ticketChoice == 2)
                {
                    cbtSystem.viewBookings();
                }

                else if (ticketChoice == 3)
                {
                    cbtSystem.viewBookings();
                    cbtSystem.cancelBooking();
                }

              
                else if (ticketChoice == 4)
                {
                    load();
                    cbtSystem.loadBookingsFromFile();
                    cbtSystem.viewBookings();
                }

                else if (ticketChoice == 5)
                {
                    break; // Back option
                }
                
                else if (ticketChoice < 1 || ticketChoice > 5)
                {
                    cout << RED << "Invalid choice! Try again.\n" << RESET;
                }
                    
                else
                {
                    cout << RED << "Feature not implemented yet!\n" << RESET; // Placeholder

                }

            } while (cin.fail() || ticketChoice != 5);
            load();
            break; 
           

        case 3:  // Exit
            cout <<RED<< "   CLOSING THE PROGRAM " << endl << RESET;
            load();
           system("cls");
           cout << "\n\n\n\n\n\n\n";
            cout << "                                     \033[33mSOLUTIONS BY ASAD ULLAH\033[0m             " << endl;
            cout << "\n\n\n\n\n\n\n";
            break;

        default:
            cout << RED << "Invalid choice! Please enter a valid option.\n" << RESET;  
            system("pause");
            cin.ignore();
            cout << "PRESS ENTER : " << endl;
        }
       
    } while (cin.fail() ||userChoice != 3);

   
    return 0;
}
