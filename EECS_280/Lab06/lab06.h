
#include <string>

using namespace std;

/* EmployeeRecord: Employee represented as a struct */

struct EmployeeRecord 
{
	string name;
	string gender;
	int age;
	int rank;
};

// MODIFIES: EmployeeRecord rec
// EFFECTS: Sets all fields in EmplyeeRecord rec
void EmployeeRecord_init( EmployeeRecord *rec, string name, string gender, int age, int rank );

// MODIFIES: rank in EmployeeRecord rec
// EFFECTS: Increases rank by one
void EmployeeRecord_promote( EmployeeRecord *rec );

// MODIFIES: rank in EmployeeRecord rec
// EFFECTS: Decreases rank by one
void EmployeeRecord_demote( EmployeeRecord *rec );

// EFFECTS: Prints Name, Gender, Age and Rank of employee
void EmployeeRecord_printInfo( const EmployeeRecord *rec );

/* Employee: Employee represented as a Class */

class Employee 
{
	// OVERVIEW: A representation of an employee, 
	//			 as well as actions we can take on them

	private:
		string name;
		string gender;
		int age;
		int rank;

	public:
		// Constructor
		// EFFECTS: Sets employee with name, gender, age and rank information
		Employee( string in_name, string in_gender, int in_age, int in_rank );

		// MODIFIES: rank
		// EFFECTS: Increases rank by one
		void promote();

		// MODIFIES: rank
		// EFFECTS: Decreases rank by one
		void demote();

		// EFFECTS: Prints out info
		void printInfo();
};