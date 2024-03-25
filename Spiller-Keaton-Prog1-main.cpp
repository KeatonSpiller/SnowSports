// CS 302 Winter 2024
// Keaton Spiller
// Prog 1 main 

// holding a race for different winter sports using a
// LLL, CLL, STL strings, char*, STL vectors & 5 classes

# include "Spiller-Keaton-Prog1-helper.h"

int main()
{

    // menu system
    char input_buffer[256];
    string user_input;    // Sub options of particular Snow Sport
    string race_choice;   // Which Race to Create
    string user_continue; // Continue Asking For Racing Teams?

    do{
        cout << "Which Race Would You Like to Create?\n";
        cout << "*****************************************\n";
        cout << "1 Ski | 2 Sleddog | 3 Snow Mobile\n";
        cout << "0 to quit\n";
        cout << "*****************************************\n";

        // Get user Input
        cin.get(input_buffer, 256);
        cin.ignore(256, '\n');
        race_choice = input_buffer;

        switch(stoi(race_choice))
        {
            case 1:
            {
                // Create object
                LLL_Ski race;

                cout << "*** Ski Race!!! ***\n";
                do{
                    // Present Options
                    cout << "What Would You Like to Do?\n";
                    cout << "*****************************************\n";
                    cout << "1 Insert A Competitor | 2 Display Competitors\n";
                    cout << "3 Start The Race!!!   |\n";
                    cout << "0 to quit\n";
                    cout << "*****************************************\n";
                    
                    // Allocate memory for Choice
                    cin.get(input_buffer, 256);
                    cin.ignore(256, '\n');
                    user_input = input_buffer;

                    switch(stoi(user_input))
                    {
                        case 0:
                        {
                            cout << "Thank you for Running The Program!\n";

                            break;
                        }// ending prompt

                        case 1:
                        {
                            int insert_success = 0;
                            while(!insert_success)
                            {
                                cout << "Let's Insert A Skiier into the race\n";

                                int starting_position = 0;
                                int src_ski_length = 0;
                                
                                cout << "What is Your Racing Name?\n";
                                cin.get(input_buffer, 256);
                                cin.ignore(256, '\n');
                                char * src_racing_name = new char[strlen(input_buffer) +1];
                                strcpy(src_racing_name, input_buffer);

                                cout << "What is Your Ski Type?\n";
                                cin.get(input_buffer, 256);
                                cin.ignore(256, '\n');
                                char * src_ski_type = new char[strlen(input_buffer)+1];
                                strcpy(src_ski_type, input_buffer);
                                
                                while(!src_ski_length)
                                {
                                    cout << "What is Your Ski Length?\n";
                                    cin.get(input_buffer, 256);
                                    cin.ignore(256, '\n');
                                    try 
                                    {
                                        src_ski_length = stoi(input_buffer);
                                    }
                                    catch(invalid_argument & err)
                                    {
                                        cout << "Invalid Integar, Please Enter again\n";
                                    }
                                }
                                // All Variables Ready to insert
                                insert_success = race.insert(src_racing_name, 
                                                             starting_position, 
                                                             src_ski_type,
                                                             src_ski_length);
                                // clean up User Entry Dynamic Memory
                                delete [] src_racing_name;
                                src_racing_name = nullptr;
                                delete [] src_ski_type;
                                src_ski_type = nullptr;
                            }
                            break;

                        }// end insert

                        case 2:
                        {
                            cout << "Display the Racers in the competition\n";
                            race.display();

                            break;
                        }// end display

                        case 3:
                        {
                            int race_distance = 0;
                            while(!race_distance)
                            {
                                cout << "What Is The Race Distance in feet?\n";
                                cin.get(input_buffer, 256);
                                cin.ignore(256, '\n');
                                try 
                                {
                                    race_distance = stoi(input_buffer);
                                }
                                catch(invalid_argument & err)
                                {
                                    cout << "Invalid Integar, Please Enter again\n";
                                }
                            }
                            cout << "Let the Race Begin!!!\n";
                            race.start_race(race_distance);

                            break;
                        }// end race

                        default:
                        {
                            cout << "Please Enter A Number 0-10\n";
                        }// end default
                    break;
                    }// end switch
                }
                while(stoi(user_input) != 0); // End Of Race Options
                // break from ski race case
                break;
            }// End Ski Case

            // Begin Sleddog Case        
            case 2:
            {
                // Create object
                CLL_Sleddog race;

                cout << "*** Sleddog Race!!! ***\n";
                do{
                    // Present Options
                    cout << "What Would You Like to Do?\n";
                    cout << "*****************************************\n";
                    cout << "1 Insert A Competitor | 2 Display Competitors\n";
                    cout << "3 Start The Race!!!   |\n";
                    cout << "0 To End Race\n";
                    cout << "*****************************************\n";

                    // Allocate memory for Choice
                    cin.get(input_buffer, 256);
                    cin.ignore(256, '\n');
                    user_input = input_buffer;

                    switch(stoi(user_input))
                    {
                        case 0:
                        {
                            cout << "Thank you for Running The Program!\n";

                            break;
                        }// ending prompt

                        case 1:
                        {
                            int insert_success = 0;
                            while(!insert_success)
                            {
                                cout << "Let's Add A Sled dog Competitor into the race\n";

                                int starting_position = 0;
                                int src_dogs = 0;
                                
                                cout << "What is Your Racing Name?\n";
                                cin.get(input_buffer, 256);
                                cin.ignore(256, '\n');
                                char * src_racing_name = new char[strlen(input_buffer)+1];
                                strcpy(src_racing_name, input_buffer);

                                cout << "What Are Your Breeds of Sled Dogs?\n";
                                cin.get(input_buffer, 256);
                                cin.ignore(256, '\n');
                                string src_dog_breed = input_buffer;
                                
                                while(!src_dogs)
                                {
                                    cout << "How Many Dogs For Your Sled?\n";
                                    cin.get(input_buffer, 256);
                                    cin.ignore(256, '\n');
                                    try 
                                    {
                                        src_dogs = stoi(input_buffer);
                                    }
                                    catch(invalid_argument & err)
                                    {
                                        cout << "Invalid Integar, Please Enter again\n";
                                    }
                                }
                                // All Variables Ready to insert
                                insert_success = race.insert(src_racing_name, 
                                                             starting_position, 
                                                             src_dog_breed,
                                                             src_dogs);
                                // clean up User Entry Dynamic Memory
                                delete [] src_racing_name;
                                src_racing_name = nullptr;
                            }

                            break;
                        }// end insert

                        case 2:
                        {
                            cout << "Display the Racers in the competition\n";
                            race.display();

                            break;
                        }// end display

                        case 3:
                        {
                            int race_distance = 0;
                            while(!race_distance)
                            {
                                cout << "What Is The Race Distance in feet?\n";
                                cin.get(input_buffer, 256);
                                cin.ignore(256, '\n');
                                try 
                                {
                                    race_distance = stoi(input_buffer);
                                }
                                catch(invalid_argument & err)
                                {
                                    cout << "Invalid Integar, Please Enter again\n";
                                }
                            }
                            cout << "Let the Race Begin!!!\n";
                            race.start_race(race_distance);

                            break;
                        }// end race

                        default:
                        {
                            cout << "Please Enter A Number 0-10\n";
                        }// end default
                    }// end switch

                } // End bobsled While
                while(stoi(user_input) != 0); // End Of Sleddog Race

                // break from bobsled Race
                break;
            }// End Sleddog Case

            // Begin SnowMobile Case
            case 3:
            {
                // Create object
                Vector_SnowMobile race;

                cout << "*** Snow Mobile Race!!! ***\n";
                do{
                    // Present Options
                    cout << "What Would You Like to Do?\n";
                    cout << "*****************************************\n";
                    cout << "1 Insert A Competitor | 2 Display Competitors\n";
                    cout << "3 Start The Race!!!   |\n";
                    cout << "0 To End Race\n";
                    cout << "*****************************************\n";

                    // Allocate memory for Choice
                    cin.get(input_buffer, 256);
                    cin.ignore(256, '\n');
                    user_input = input_buffer;

                    switch(stoi(user_input))
                    {
                        case 0:
                        {
                            cout << "Thank you for Running The Program!\n";

                            break;
                        }// ending prompt

                        case 1:
                        {
                            int insert_success = 0;
                            while(!insert_success)
                            {
                                cout << "Let's Add A Snow Mobile!!!\n";

                                int starting_position = 0;
                                int src_mph = 0;
                                float src_gas = 0.0;
                                
                                cout << "What is Your Racing Name?\n";
                                cin.get(input_buffer, 256);
                                cin.ignore(256, '\n');
                                char * src_racing_name = new char[strlen(input_buffer)+1];
                                strcpy(src_racing_name, input_buffer);

                                cout << "How Fast Can Your Vehicle Drive (mph)?\n";
                                cin.get(input_buffer, 256);
                                cin.ignore(256, '\n');
                                src_mph = stoi(input_buffer);
                                
                                cout << "How Much Gas (0.0 - 1.0) Empty - Full?\n";
                                cin.get(input_buffer, 256);
                                cin.ignore(256, '\n');
                                src_gas = stof(input_buffer);
                                // All Variables Ready to insert
                                insert_success = race.insert(src_racing_name, 
                                                             starting_position, 
                                                             src_mph,
                                                             src_gas);
                                // clean up User Entry Dynamic Memory
                                delete [] src_racing_name;
                                src_racing_name = nullptr;
                            }// end While ! insert success

                            break;
                        }// end insert

                        case 2:
                        {
                            cout << "Display the Racers in the competition\n";
                            race.display();

                            break;
                        }// end display

                        case 3:
                        {
                            int race_distance = 0;
                            while(!race_distance)
                            {
                                cout << "What Is The Race Distance in feet?\n";
                                cin.get(input_buffer, 256);
                                cin.ignore(256, '\n');
                                try 
                                {
                                    race_distance = stoi(input_buffer);
                                }
                                catch(invalid_argument & err)
                                {
                                    cout << "Invalid Integar, Please Enter again\n";
                                }
                            }
                            cout << "Let the Race Begin!!!\n";
                            race.start_race(race_distance);

                            break;
                        }// end race
                    
                        default:
                        {
                            cout << "Please Enter A Number 0-10\n";
                        }// end default
                    }// end switch

                } // End Snow Mobile While
                while(stoi(user_input) != 0); // End Of SnowMobile Race

                break; 
            }// End SnowMobile Case

            case 0:
            {
                // If We Don't to Race
                user_continue = "n";
                break;
            }// End of Case

        }// End All Race Types Switch Statements
    
        if(stoi(race_choice) != 0)
        {
            cout << "Would You Like to Race Again? 'y' or 'n'?\n";
            cin.get(input_buffer, 256);
            cin.ignore(256, '\n');
            user_continue = input_buffer;
        }
    }
    while(user_continue == "y" || user_continue == "Y"); 
    // Continue Asking For Racing Teams?
    
    // Outro
    cout << "Have A Wonderful Day!\n";

	return 0;
}
