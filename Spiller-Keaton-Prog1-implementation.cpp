// CS 302 Winter 2024
// Keaton Spiller
// Prog 1 implementation file

// holding a race for different winter sports using a
// LLL, CLL, STL strings, char*, STL vectors & 5 classes

# include "Spiller-Keaton-Prog1-helper.h"

// Base Class Snow Race*************************************************************
// protected data members: 
// char* racing_name, int distance


// Default constructor
Snow_Race::Snow_Race():  
	racing_name(nullptr), distance(0) {}


// Deconstructor 
// deallocate char * racing_name
Snow_Race::~Snow_Race()
{
    if(racing_name)
    {
        delete [] racing_name;
        racing_name = nullptr;
    }
}


// Paramaterized Constructor
// Initialize distance & deep copy racing_name
Snow_Race::Snow_Race(const char * src_name, 
                     const int src_distance):
    racing_name(nullptr), distance(src_distance)
{
    str_copy(racing_name, src_name);
}


// Copy Constructor
Snow_Race::Snow_Race(const Snow_Race & to_copy): 
    racing_name(nullptr), distance(0)
{
    deep_copy(to_copy);
}


// Assignment Overloader
// obj1 = obj2
// if obj1 is not empty
Snow_Race & Snow_Race::operator=(const Snow_Race & to_copy) //Assign over
{
    if(this == & to_copy) return *this;
    if(racing_name) 
    {
        delete [] racing_name;
        racing_name = nullptr;
    }
    distance = to_copy.distance;
    deep_copy(to_copy);
    return *this;
}


int Snow_Race::compare_distance(const Snow_Race to_cmp)
{
    if(distance >= to_cmp.distance) return 1;
    else return 0;
}

// Deep Copy Method
int Snow_Race::deep_copy(const Snow_Race & to_copy) // Handle the deep copy
{
    if(!to_copy.racing_name) return 0;
    distance = to_copy.distance;
    str_copy(racing_name, to_copy.racing_name);
    return 1;
}


// Str Copy Method
int Snow_Race::str_copy(char *& dest, const char * src)
{
    if (!src) return 0;
    dest = new char[strlen(src)+1];
    strcpy(dest, src); // (Desination, Source)
    return 1;
}


// display racing_name & distance(0)
int Snow_Race::display()
{
    if(!racing_name){
        cout << "*****************************************\n";
        cout << "No Racers to display: \n";
        cout << "****************************************\n";
        return 0;
    }
    cout << "Racing Name: " << racing_name << endl;
    cout << "Distance: " << distance << endl;
    return 1;
}


// update with distance moved
int Snow_Race::update_distance(const int increment)
{
    if(!increment) return 0;
    distance += increment;
    return 1;
}


// return 1 if winner is found
int Snow_Race::check_winner(const int finish_line)
{
    return distance >= finish_line;
}


// Ski: public Snow_Race*************************************************
// protected data members:
// char * ski_type, int ski_length


// Default constructor
Ski::Ski():
    ski_type(nullptr), ski_length(0) {}


// Deconstructor
Ski::~Ski()
{
    if(ski_type)
    {
        delete [] ski_type;
        ski_type = nullptr;
    }
}


// Parametric Constructor
Ski::Ski(const char * src_name,
         const int src_distance,
         const char * src_ski_type, 
         const int src_ski_length):
    Snow_Race(src_name, src_distance), ski_type(nullptr), ski_length(src_ski_length)
{
    str_copy(ski_type, src_ski_type);
}


// Copy Constructor
Ski::Ski(const Ski & to_copy):
    Snow_Race(to_copy), ski_type(nullptr), ski_length(to_copy.ski_length)
{
    deep_copy(to_copy);
}


// display Method
// Base Class data members, ski_type, and ski_length
int Ski::display()
{
    Snow_Race::display();

    if(!ski_type){
        cout << "*****************************************\n";
        cout << "No Ski Type to display: \n";
        if(distance) cout << "Distance: " << distance << endl;
        cout << "****************************************\n";
        return 0;
    }
    cout << "Ski Type: " << ski_type << endl;
    cout << "Ski Length: " << ski_length << endl;
    return 1;
}


// Deep Copy Method
int Ski::deep_copy(const Ski & to_copy)
{
    if(!to_copy.ski_type) return 0;
    str_copy(ski_type, to_copy.ski_type);
    return 1;
}


// Assignment Overloader
// obj1 = obj2
// if obj1 is not empty
Ski & Ski::operator=(const Ski & src)
{
    if(this == & src) return *this;
    if(ski_type){
        delete [] ski_type;
        ski_type = nullptr;
    }
    str_copy(ski_type, src.ski_type);

    return *this;
}


// Ski_Node: public Ski*******************************************************
// protected data members:
// Ski_Node * next 


// Default Constructor
Ski_Node::Ski_Node():
    next(nullptr) {}


// Deconstructor
Ski_Node::~Ski_Node()
{
    next = nullptr;
}


// Parametric Constructor
Ski_Node::Ski_Node(const char * src_name,
                   const int src_distance,
                   const char * src_ski_type, 
                   const int src_ski_length):
    Ski(src_name, src_distance, src_ski_type, src_ski_length), next(nullptr) {}


// Copy Constructor
Ski_Node::Ski_Node(const Ski_Node & to_copy):
    Ski(to_copy), next(nullptr) {}


// Node Settings
// head->set_next(next_node)
int Ski_Node::set_next(Ski_Node *& next_node) 
{
    if(!next_node) return 0;
    next = next_node;
    return 1;
}

// head->set_next() = nullptr
int Ski_Node::set_next_null() 
{
    next = nullptr;
    return 1;
}


// Node Settings
// curr = curr->get_next()
Ski_Node *& Ski_Node::get_next()               
{
    return next;
}


// Node Settings
// if(head->has_next())?
bool Ski_Node::has_next()                     
{
    return next;
}


// LLL_Ski**************************************************************************
// protected data members:
// Ski_Node * head


// Default Constructor
LLL_Ski::LLL_Ski():
    head(nullptr) {}


// Deconstructor
LLL_Ski::~LLL_Ski()
{
    if(head)
    {
        int removal_count = remove_all();
        cout << "Successfully Deallocated " << removal_count <<  " Nodes" << endl;
    }
}


// dest(src)
LLL_Ski::LLL_Ski(const LLL_Ski & to_copy):         // copy constructor
    head(nullptr)
{
    int copy_success = deep_copy(head, to_copy.head);
    if (!copy_success) cout << "Copy Failure\n";
}


int LLL_Ski::deep_copy(Ski_Node *& dest, Ski_Node * src)
{
    if(!src)
    {
        dest = nullptr;
        return 0;
    }
    dest = new Ski_Node(*src);

    return 1 + deep_copy(dest->get_next(), src->get_next());
}


// Set obj1 = obj2
LLL_Ski & LLL_Ski::operator=(LLL_Ski & src) // assignment operator
{
    if(this == &src) return *this;

    if(head) remove_all(head);

    int copy = deep_copy(this->head, src.head);
   
    if(!copy) cout << "LLL Copy Error\n";

    return *this;
}


// Wrapper for the LLL Sending head into recursive function
int LLL_Ski::remove_all() // Traverse and deallocate memory
{
    if(!head) return 0;
    cout << "Order Of Deallocation\n";
    return remove_all(head);
}

// Removing with Head Recursion Traversing from back to front
int LLL_Ski::remove_all(Ski_Node *& head)
{
    if(!head) return 0;
    int removal_success = 1 + remove_all(head->get_next());
    // individually remove nodes?
    //Ski_Node::remove();
    head->display();
    delete head;
    head = nullptr;
    return removal_success;
}


// 1. Hold previous head
// 2. Create A New Node with parametric constructor
// 3. Re-connect head to hold
int LLL_Ski::insert(const char * src_name, 
                    const int src_distance,
                    const char * src_ski_type, 
                    const int src_ski_length)
{
    if(!src_name) return 0;
    Ski_Node * hold = head;
    head = new Ski_Node(src_name, src_distance, src_ski_type, src_ski_length);
    head->set_next(hold);
    return 1;
}


// wrapper to recursively print all skiers
int LLL_Ski::display()
{
    if(!head)
    {
        cout << "*****************************************\n";
        cout << "No Skiers to Display\n";
        cout << "*****************************************\n";

        return 0;
    }
    return display(head);
}


// Recursively Display the Nested Display Functions within each Node
// Ski.display() Snow_Race.display()
int LLL_Ski::display(Ski_Node * head)
{
    if(!head) return 0;

    cout << "*****************************************\n";
    head->display();
    cout << "*****************************************\n";

    display(head->get_next());

    return 1;
}


// returns a random number from 0 to max
int LLL_Ski::random_increment(const int max)
{
    if(!max) return 0;
    return (rand() % max) + 1;
}


// while !winner (update_race_state -> check_winner)
// return winner
bool LLL_Ski::update_race_state(Ski_Node *& head, const int finish_line)
{
    if(! head) return 0;
    // generate random integar from 0 to finsh_line
    // dive the increments to move by 4 to create a longer race
    int increment = random_increment(finish_line) / 4;

    // move the racer forward
    int update_distance = head->update_distance(increment);
    if(!update_distance) return 0;
   
    // displaying racer progression
    cout << endl;
    head->display();
    cout << endl;
    
    // if someone crossed the finish_line
    int winner_found = head->check_winner(finish_line);

    return winner_found + update_race_state(head->get_next(), finish_line);
}


// Finds Largest distance and returns Sum of Win/tie found
// used Results enumeration of (loss, win, tie) == (0, 1, 2)
int LLL_Ski::determine_winner(Ski_Node * head, Ski_Node * winning_racer)
{
    if(!head)
    {
        cout << "~~~~ Winning Racer ~~~~\n";
        winning_racer->display();
        return 1;
    }
    
    // racer1 distance > racer2 distance
    int cmp = head->compare_distance(*winning_racer);
    if(cmp)
    {
        return determine_winner(head->get_next(), head);
    }
    else
    {
        return determine_winner(head->get_next(), winning_racer);
    }
}

// 1. start_race
// 2. while No winner: (update_race_state -> check_winner)
// 3. Loop Through Racers & determine_winner
// Race The Skiers from distance to finishline
int LLL_Ski::start_race(const int finish_line)
{
    if(!head) return 0;
    srand((unsigned) time(NULL)); // Change the seed for random times this race
    bool winner = false;
    int round = 0;
    while(!winner)
    {
        ++ round;
        cout << "Round: " << round << endl;
        winner = update_race_state(head, finish_line);
    }
    cout << "Final Positions\n";
    display();
    // cycle through all racers to find the winner / tie
    return determine_winner(head, head); 
}
// End LLL Ski

// Sleddog: public Snow_Race*************************************************
// protected data members:
// string dog_breed, int weight


// Default constructor
Sleddog::Sleddog():
    dog_breed(nullptr), dogs(0) {}

// Deconstructor
Sleddog::~Sleddog() {}


// Copy Constructor to Cary the dynamic memory up to the base
Sleddog::Sleddog(const Sleddog & to_copy):
    Snow_Race(to_copy), dog_breed(nullptr), dogs(0) {}


// Parametric Constructor
Sleddog::Sleddog(const char * src_name,
                 const int src_distance,
                 const string src_dog_breed, 
                 const int src_dogs):
    Snow_Race(src_name, src_distance), dog_breed(src_dog_breed),
    dogs(src_dogs) {}


// display Method
// Base Class data members, ski_type, and ski_length
int Sleddog::display()
{
    Snow_Race::display();

    if(dog_breed.empty()){
        cout << "*****************************************\n";
        cout << "No Sled dog Breeds to display: \n";
        cout << "****************************************\n";
        return 0;
    }
    cout << "Sleddog breed: " << dog_breed << endl;
    cout << "Number of Dogs on the Sled: " << dogs << endl;
    return 1;
}


// Sleddog_Node: public Sleddog*****************************************************
// protected data members:
// Sleddog_Node * next 


// Default Constructor
Sleddog_Node::Sleddog_Node():
    next(nullptr) {}


// Deconstructor
Sleddog_Node::~Sleddog_Node()
{
    next = nullptr;
}


// Copy Constructor
Sleddog_Node::Sleddog_Node(const Sleddog_Node & to_copy):
    Sleddog(to_copy), next(nullptr) {}


// Parametric Constructor
Sleddog_Node::Sleddog_Node(const char * src_name,
                           const int src_distance,
                           const string src_dog_breed, 
                           const int src_dogs):
    Sleddog(src_name, src_distance, src_dog_breed, src_dogs), next(nullptr) {}


// Node Settings
// head->set_next(next_node)
int Sleddog_Node::set_next(Sleddog_Node *& next_node) 
{
    if(!next_node) return 0;
    next = next_node;
    return 1;
}

// set to null
int Sleddog_Node::set_next_null() 
{
    if(!next) return 0;
    next = nullptr;
    return 1;
}


// Node Settings
// curr = curr->get_next()
Sleddog_Node *& Sleddog_Node::get_next()               
{
    return next;
}


// Node Settings
// if(head->has_next())?
bool Sleddog_Node::has_next()                     
{
    return next;
}


// CLL_Sleddog**********************************************************************
// protected data members:
// Sleddog_Node * rear

// Default Constructor
CLL_Sleddog::CLL_Sleddog():
    rear(nullptr) {}


// Deconstructor
CLL_Sleddog::~CLL_Sleddog()
{
    if(rear)
    {
        int removal_count = remove_all();
        cout << "Successfully Deallocated " << removal_count <<  " Nodes" << endl;
    }
}


// Copy contents of object 1 into object 2 
// obj1(ob2)
CLL_Sleddog::CLL_Sleddog(const CLL_Sleddog & to_copy):   // copy constructor
    rear(nullptr) 
{
    if(!to_copy.rear) return;
    
    deep_copy(rear, to_copy.rear->get_next(), to_copy.rear);
    return;
}

// Copy Contents of obj1 = obj2
// 1. returning if they are the same
// 2. Deallocating memory if not empty
// 3. Using deep copy to copy from destination to source
CLL_Sleddog & CLL_Sleddog::operator=(const CLL_Sleddog & src) // assignment operator
{
    if(this == & src) return *this;
    remove_all(rear);
    deep_copy(rear, src.rear->get_next(), src.rear);
    return *this;
}

// Copy Source to Destination (D,S)
// Starting CLL at Front and copying until reaches End 
int CLL_Sleddog::deep_copy(Sleddog_Node *& dest, Sleddog_Node * src, const Sleddog_Node * end) // traverse/connect
{
    // 1. if no source
    if(!src) 
    {
        dest = nullptr;
        return 0;
    }

    Sleddog_Node * temp = new Sleddog_Node(*src);
    // 2. if first node
    if(!dest)
    {
        temp->set_next(temp);
        dest = temp;
    }
    else
    {   // 4. set [] -> [] multiple Nodes
        temp->set_next(dest->get_next());
        dest = temp;
    }
    
    // 5. if we reached the end 
    if(src == end)
    {
        rear = dest;
        return 1;
    }
    // Tail Recursion Front to Back
    return 1 + deep_copy(dest->get_next(), src->get_next(), end);
}


// Wrapper to send in the Front of the CLL if not empty
int CLL_Sleddog::remove_all() // Traverse and deallocate memory
{
    if(!rear) return 0;

    // send in front
    return remove_all(rear->get_next());
}


// removing from the front without disconnecting
// 1. No Nodes
// 2. One Node
// 3  Multiple Nodes
int CLL_Sleddog::remove_all(Sleddog_Node *& rear)
{
    // 1. No Nodes
    if(!rear) return 0;

    // 2. One Node
    if(this->rear == this->rear->get_next())
    {
        delete this->rear;
        this->rear = nullptr;
        return 1;
    }

    // 3. Multiple Nodes
    // i. hold
    Sleddog_Node * hold = rear->get_next();
    // ii. delete
    delete rear;
    // iii. reconnect
    rear = hold;

    // Tail recursive traverse front to back
    return 1 + remove_all(rear);
}


// 1. Hold previous head
// 2. Create A New Node with parametric constructor
// 3. Re-connect head to hold
int CLL_Sleddog::insert(const char * src_name, 
                        const int src_distance,
                        const string src_dog_breed, 
                        const int src_dogs)
{
    // there is no string
    if(!src_name) return 0;

    // 1. There is no rear
    if(!rear)
    {
        // Create First Rear
        rear = new Sleddog_Node(src_name, src_distance, src_dog_breed,
        src_dogs);
        // Link Self Loop
        rear->set_next(rear);
        return 1;
    }
    // i. Hold Rear's Link To previous Front
    Sleddog_Node * previous_front = rear->get_next();
    // ii. Create New Node
    Sleddog_Node * front = new Sleddog_Node(src_name, src_distance, src_dog_breed,
    src_dogs);
    // iii. Set new Nodes Next to previous Front
    front->set_next(previous_front);
    // iv. Set Rears Next to New Front
    rear->set_next(front);
    return 1;
}


// wrapper to recursively print all bobsleds
// Starting the display at the Front
int CLL_Sleddog::display()
{
    if(!rear)
    {
        cout << "*****************************************\n";
        cout << "No Sleddogs to Display\n";
        cout << "*****************************************\n";

        return 0;
    }
    return display(rear->get_next());
}


// Recursively Display the Nested Display Functions within each Node
// Sleddog.display() Snow_Race.display()
// First Displaying Then Checking If we've Reached the End Node
// Front to End
int CLL_Sleddog::display(Sleddog_Node * rear)
{
    cout << "*****************************************\n";
    rear->display();
    cout << "*****************************************\n";

    // if rear is at the end
    if(rear == this->rear) return 0;

    // else traverse
    display(rear->get_next());

    return 1;
}


// returns a random number from 0 to max
int CLL_Sleddog::random_increment(const int max)
{
    if(!max) return 0;
    return (rand() % max) + 1;
}


// while !winner (update_race_state -> check_winner)
// return winner
bool CLL_Sleddog::update_race_state(Sleddog_Node *& rear, const int finish_line)
{
    // generate random integar from 0 to finsh_line
    // dive the increments to move by 4 to create a longer race
    int increment = random_increment(finish_line) / 4;

    // move the racer forward
    int update_distance = rear->update_distance(increment);
    if(!update_distance) return 0;
   
    // displaying racer progression
    cout << endl;
    rear->display();
    cout << endl;
    
    // if someone crossed the finish_line
    int winner_found = rear->check_winner(finish_line);

    if( rear == this->rear ) return winner_found;

    return winner_found + update_race_state(rear->get_next(), finish_line);
}


// Finds Largest distance and returns Sum of Win/tie found
// used Results enumeration of (loss, win, tie) == (0, 1, 2)
int CLL_Sleddog::determine_winner(Sleddog_Node * rear, Sleddog_Node * winning_racer)
{
    // if completed the loop and pointing to front
    if(rear == this->rear->get_next() && winning_racer)
    {
        cout << "~~~~ Winning Racer ~~~~\n";
        winning_racer->display();
        return 1;
    }
    // if first time checking
    if(!winning_racer)
    {
        winning_racer = rear;
    }
    // racer1 distance > racer2 distance
    if(rear->compare_distance(*winning_racer))
    {
        return determine_winner(rear->get_next(), rear);
    }
    else
    {
        return determine_winner(rear->get_next(), winning_racer);
    }
}

// 1. start_race
// 2. while No winner: (update_race_state -> check_winner)
// 3. Loop Through Racers & determine_winner
// Race The Skiers from distance to finish line
int CLL_Sleddog::start_race(const int finish_line)
{
    if(!rear) return 0;
    srand((unsigned) time(NULL)); // Change the seed for random times this race
    bool winner = false;
    int round = 0;
    while(!winner)
    {
        ++ round;
        cout << "Round: " << round << endl;
        // start the update at the front
        winner = update_race_state(rear->get_next(), finish_line);
    }
    cout << "Final Positions\n";
    // After A Winning Competitor has been found
    display();
    if(rear->get_next() != rear)
    {
        // cycle through all racers to find the winner / tie
        return determine_winner(rear->get_next(), nullptr); 
    }
    else
    {
        cout << "~~~~ Winning Racer ~~~~\n";
        rear->display();
        return 1;
    }
}
// End CLL Sleddog


// SnowMobile: public Snow_Race*************************************************
// protected data members:
// int mph, float gas


// Default constructor
SnowMobile::SnowMobile():
    mph(0), gas(0.0) {}


// Deconstructor
SnowMobile::~SnowMobile() {}


// Parametric Constructor
SnowMobile::SnowMobile(const char * src_name,
                       const int    src_distance,
                       const int    src_mph,
                       const float  src_gas):
    Snow_Race(src_name, src_distance), mph(src_mph), gas(src_gas) {}


// display Method
// Base Class data members, ski_type, and ski_length
int SnowMobile::display()
{
    Snow_Race::display();

    if(! gas || ! mph){
        cout << "*****************************************\n";
        cout << "No gas or mph listed\n";
        cout << "****************************************\n";
        return 0;
    }
    cout << "gas: " << gas << endl;
    cout << "mph: " << mph << endl;
    return 1;
}


// Vector_SnowMobile***************************************************************
// protected data members:
// vector<SnowMobile> snow_mobile_vector;

// Default Constructor
Vector_SnowMobile::Vector_SnowMobile()
{
    // vector<SnowMobile> snow_mobile_vector; // empty initialization in header
}


// Deconstructor
Vector_SnowMobile::~Vector_SnowMobile()
{
    // Vector Handles it's own memory (base class deconstructors removed on exit)
}


// 1. Hold previous head
// 2. Create A New Node with parametric constructor
// 3. Re-connect head to hold
int Vector_SnowMobile::insert(const char * src_name, 
                              const int    src_distance,
                              const int    src_mph, 
                              const float  src_gas)
{
    snow_mobile_vector.push_back(SnowMobile(src_name, 
                                            src_distance, 
                                            src_mph,
                                            src_gas));
    return 1;
}


// wrapper to recursively print all skiers
int Vector_SnowMobile::display()
{
    if(snow_mobile_vector.empty())
    {
        cout << "*****************************************\n";
        cout << "No Snow Mobiles In The Competition\n";
        cout << "*****************************************\n";

        return 0;
    }

    // display nested SnowMobile::display() && Snow_Race::display()
    for (SnowMobile racer : snow_mobile_vector)
    {
        racer.display();
    }
    return 1;
}


// returns a random number from 0 to max
int Vector_SnowMobile::random_increment(const int max)
{
    if(!max) return 0;
    return (rand() % max) + 1;
}


// while !winner (update_race_state -> check_winner)
// return winner True/False
bool Vector_SnowMobile::update_race_state(const int finish_line)
{
    if(snow_mobile_vector.empty()) return 0;

    int winner_found = 0;

    for(SnowMobile & racer: snow_mobile_vector)
    {
        // generate random integar from 0 to finsh_line
        // dive the increments to move by 4 to create a longer race
        int increment = random_increment(finish_line) / 4;

        // move the racer forward
        int update_distance = racer.update_distance(increment);
        if(!update_distance) return 0;
       
        // displaying racer progression
        cout << endl;
        racer.display();
        cout << endl;
        
        // if someone crossed the finish_line
        winner_found += racer.check_winner(finish_line);
    }
    return winner_found;
}


// Finds Largest distance and prints out the winning racer
int Vector_SnowMobile::determine_winner(SnowMobile winning_racer)
{
    if(snow_mobile_vector.empty())
    {
        cout << "No Racers To Determine Winner\n";
        return 0;
    }
   
    // traverse through racers to see who crossed the finish line
    for(SnowMobile racer: snow_mobile_vector)
    {
        // racer1 distance > racer2 distance
        int cmp = racer.compare_distance(winning_racer);
        if(cmp)
        {
            winning_racer = racer;
        }
    }

    cout << "~~~~ Winning Racer ~~~~\n";
    winning_racer.display();
    return 1;
}

// 1. start_race
// 2. while No winner: (update_race_state -> check_winner)
// 3. Loop Through Racers & determine_winner
// Race The Skiers from distance to finishline
int Vector_SnowMobile::start_race(const int finish_line)
{
    if(snow_mobile_vector.empty()) return 0;
    srand((unsigned) time(NULL)); // Change the seed for random times this race
    bool winner = false;
    int round = 0;
    while(!winner)
    {
        ++ round;
        cout << "Round: " << round << endl;
        winner = update_race_state(finish_line);
    }
    cout << "Final Positions\n";
    display();
    // cycle through all racers to find the winner / tie
    return determine_winner(snow_mobile_vector[0]); 
}
// End Vector Snow Mobile

