// CS 302 Winter 2024
// Keaton Spiller
// Prog 1 Header file

// holding a race for different winter sports using a
// LLL, CLL, STL strings, char*, STL vectors & 5 classes

// Requires three public methods for each class in addition to constructors, destructors, setters, and display functions.

/*             Snow_Race
           /      |      \
      Ski      Sleddog      SnowMobile
      |           |              |
    Ski_Node  Sleddog_Node  SnowMobile_Node
      |           |              |
    Ski_LLL   Sleddog_CLL   SnowMobile_Vector
*/

# include <iostream>
# include <vector>
# include <string>
# include <list>
# include <cstring>
# include <cstdlib>
# include <stdexcept>

using std::string, std::cin, std::cout, std::endl, std::list, std::vector,
std::stoi, std::stof, std::invalid_argument;

//base case*************************************************************************
// This will handle the generic attributes that all the snow sports have
// every sport will have a racer_name and a distance
class Snow_Race
{
	public:
		Snow_Race();  // constructor
		~Snow_Race(); // deconstructor
		Snow_Race(const char * src_name,        // Parameterized Constructor
                  const int src_distance);      
        Snow_Race(const Snow_Race & to_copy);   // Copy Constructor
        // obj1 = obj2
        Snow_Race & operator=(const Snow_Race & to_copy); // Assignment operator

        int update_distance(const int increment);
        int compare_distance(const Snow_Race to_cmp);
        int check_winner(const int finish_line);
        int display(void);

	protected:
        // data members
        char * racing_name;
        int distance;
        // methods
        int str_copy(char *& dest, const char * src);
        int deep_copy(const Snow_Race & to_copy);
};

//child ski*************************************************************************
// The Ski Racers are a child class of the Snow Race 
// This will be the base class of Node
// This will be the one derived class using the dynamic char *
class Ski: public Snow_Race
{
	public:
		Ski();  // constructor
		~Ski(); // deconstructor
		Ski(const char * src_name,        // Paramaterized Constructor
            const int src_distance,
            const char * src_ski_type, 
            const int src_ski_length);
        Ski(const Ski & to_copy);         // copy constructor
        Ski & operator=(const Ski & src); // assignment operator
        // methods
		int display(); // instead of a getters, displaying the data

	protected:
        // data members
        char * ski_type;
		int ski_length;
        // methods
        int deep_copy(const Ski & to_copy);
};

//**************************************************************************
// child Ski Node
// This will be incorporated using a LLL
class Ski_Node: public Ski
{
	public:
		Ski_Node();  // constructor
		~Ski_Node(); // deconstructor
        Ski_Node(const char * src_name,             // Parameterized Constructor
                 const int src_distance,
                 const char * src_ski_type, 
                 const int src_ski_length);
        Ski_Node(const Ski_Node & to_copy);         // CC To Carry Dynamic above
		// Node Settings
		Ski_Node *& get_next();                     // curr = curr->get_next()
		int set_next(Ski_Node *& next_node);        // head->next
		bool has_next();                            // if(head->next)?
        int set_next_null();                        // head->next = nullptr

	protected:
		Ski_Node * next;
};

class LLL_Ski
{
	public:
		LLL_Ski();  // Default Constructor
		~LLL_Ski(); // Deconstructor
        LLL_Ski(const LLL_Ski & to_copy);         // copy constructor
        LLL_Ski & operator=(LLL_Ski & src); // assignment operator
        int deep_copy(Ski_Node *& dest, Ski_Node * src); // traverse/connect
		int insert(const char * src_name, const int src_distance,
                   const char * src_ski_type, const int src_ski_length);
        int remove_all(); // Traverse and deallocate memory
		int display();
        // Race all competitors to See Who crosses the finish line first
        // cout the states of the race individuals, and cout the winner
        int start_race(const int finish_line); 

	protected:
		Ski_Node * head;
        int remove_all(Ski_Node *& head);
        int display(Ski_Node * head);
        bool update_race_state(Ski_Node *& head, const int finish_line);
        int random_increment(const int max);
        int determine_winner(Ski_Node * head, Ski_Node * winning_racer); 
};


//Sleddog***********************************************************************
// The Sleddog are a child class of the Snow Race 
// This will be the base class of Sleddog_Node
class Sleddog: public Snow_Race
{
	public:
		Sleddog();  // constructor
		~Sleddog(); // deconstructor
		Sleddog(const char * src_name,        // Paramaterized Constructor
            const int src_distance,
            const string src_dog_breed, 
            const int src_bobsled_dogs);
        Sleddog(const Sleddog & to_copy);         // copy constructor
		int display(); // instead of a getters, displaying the data
	protected:
        // data members
        string dog_breed;
		int dogs;
};

//**************************************************************************
// child Sleddog Node
// This will be incorporated using a CLL
class Sleddog_Node: public Sleddog
{
	public:
		Sleddog_Node();  // constructor
		~Sleddog_Node(); // deconstructor
        Sleddog_Node(const Sleddog_Node & to_copy); // CC to cary up dynamic memory
        Sleddog_Node(const char * src_name,         // Parameterized Constructor
                     const int src_distance,
                     const string src_dog_breed, 
                     const int src_dogs);
		// Node Settings
		Sleddog_Node *& get_next();                 // curr = curr->get_next()
		int set_next(Sleddog_Node *& next_node);    // head->next = next_node 
        int set_next_null();                        // head->next = nullptr
		bool has_next();                            // if(head->next)?

	protected:
		Sleddog_Node * next;
};

//Sleddog_CLL***********************************************************************
// CLL of Sleddog_Nodes
class CLL_Sleddog
{
	public:
		CLL_Sleddog();  // Default Constructor
		~CLL_Sleddog(); // Deconstructor

        CLL_Sleddog(const CLL_Sleddog & to_copy);         // copy constructor
        CLL_Sleddog & operator=(const CLL_Sleddog & src);       // assignment operator
        int deep_copy(Sleddog_Node *& dest, 
                      Sleddog_Node * src, 
                      const Sleddog_Node * end); // traverse/connect

		int insert(const char * src_name, const int src_distance,
                   const string src_dog_breed, const int src_dogs);
        int remove_all(); // Traverse and deallocate memory
		int display();
        // Race all competitors to See Who crosses the finish line first
        // cout the states of the race individuals, and cout the winner
        int start_race(const int finish_line); 

	protected:
		Sleddog_Node * rear;
        int remove_all(Sleddog_Node *& rear);
        int display(Sleddog_Node * rear);
        bool update_race_state(Sleddog_Node *& rear, const int finish_line);
        int random_increment(const int max);
        int determine_winner(Sleddog_Node * head, Sleddog_Node * winning_racer); 
};


//SnowMobile***********************************************************************
// The Snowmobile child class of Snow_race base class
class SnowMobile: public Snow_Race
{
	public:
		SnowMobile();  // constructor
		~SnowMobile(); // deconstructor
		SnowMobile(const char * src_name,        // Paramaterized Constructor
                   const int    src_distance,
                   const int    src_mph, 
                   const float  src_gas);
		int display(); // instead of a getters, displaying the data
	protected:
        // data members
        int mph; 
		float gas;
};


// SnowMobile Vector****************************************************************
// Vector of Snowmobile's'
class Vector_SnowMobile
{
	public:
		Vector_SnowMobile();  // Default Constructor
		~Vector_SnowMobile(); // Deconstructor
		int insert(const char * src_name, 
                   const int    src_distance,
                   const int    src_mph, 
                   const float  src_gas);
		int display();
        // Race all competitors to See Who crosses the finish line first
        // cout the states of the race individuals, and cout the winner
        int start_race(const int finish_line); 

	protected:
		vector<SnowMobile> snow_mobile_vector;
        bool update_race_state(const int finish_line);
        int random_increment(const int max);
        int determine_winner(SnowMobile winning_racer); 
};
