
#include "lab06.h"
#include <iostream>
#include <cstdlib>
#include <vector>

using namespace std;

/* EmployeeRecord */

void EmployeeRecord_init( EmployeeRecord *rec, string in_name, string in_gender, int in_age, int in_rank )
{
  // TASK 1: Implement setRecord
  rec->name = in_name;
  rec->gender = in_gender;
  rec->age = in_age;
  rec->rank = in_rank;
  
}

void EmployeeRecord_promote( EmployeeRecord *rec )
{
	// TASK 1: Implement promote
  ++rec->rank;
}

void EmployeeRecord_demote( EmployeeRecord *rec )
{
	// TASK 1: Implement demote
  --rec->rank;
}

void EmployeeRecord_printInfo( const EmployeeRecord *rec )
{
	cout << "Name: " << rec->name << " Gender: " << rec->gender << " Age: " << rec->age << " Rank: " << rec->rank << endl;
}

/* Employee */


Employee::Employee( string in_name, string in_gender, int in_age, int in_rank )
: name(in_name) , gender(in_gender), age(in_age), rank(in_rank)
{
	// TASK 2: Implement Constructor
}

void Employee::promote()
{
	// TASK 2: Implement promote
  ++this->rank;
}

void Employee::demote()
{
	// TASK 2: Implement demote
  --this->rank;
}

void Employee::printInfo()
{
	cout << "Name: " << name << " Gender: " << gender << " Age: " << age << " Rank: " << rank << endl;
}

int main()
{
  vector<EmployeeRecord> eecsSoft;

  // TASK 3: Create two employees with EmployeeRecord and add to eecsSoft
  
  EmployeeRecord bmunday;
  EmployeeRecord Kl_T;
  
  EmployeeRecord_init(&bmunday, "Baldeep Munday", "Male", 22, 9);
  EmployeeRecord_init(&Kl_T, "Kl Tur", "Female", 19, 2);
  
  eecsSoft.push_back(bmunday);
  eecsSoft.push_back(Kl_T);
  
  vector<Employee> umichWorks;

  // TASK 3: Create two employees with Employee and add to umichWorks
  
  Employee Vmunday("Vicky Munday", "Male", 22, 9);
  Employee Mehak("Mehak Aeri", "Female", 22, 2);
  
  umichWorks.push_back(Vmunday);
  umichWorks.push_back(Mehak);

  int eecsSoftSize = eecsSoft.size();
	
  cout << "Welcome to eecsSoft! Here are our loyal employees: " << endl;
  for( int index = 0; index < eecsSoftSize; ++index )
  {
      EmployeeRecord_printInfo( &eecsSoft[index] );
  }
  
  // TASK 3: Promote one employee and demote the other at eecsSoft
  EmployeeRecord_promote(&eecsSoft[0]);
  EmployeeRecord_demote(&eecsSoft[1]);
  
  cout << "Here is the new info for the employees of eecsSoft: " << endl;
  for( int index = 0; index < eecsSoftSize; ++index )
  {
    EmployeeRecord_printInfo( &eecsSoft[index] );
  }
	
  int umichWorksSize = umichWorks.size();

  cout << endl << "Welcome to umichWorks! Here are our loyal employees: " << endl;
  for( int index = 0; index < umichWorksSize; ++index )
  {
      umichWorks[index].printInfo();
  }

  // TASK 3: Promote one employee and demote the other at umichWorks
  umichWorks[0].promote();
 umichWorks[1].demote();
  
  cout << "Here is the new info for the employees of umichWorks: " << endl;
  for( int index = 0; index < umichWorksSize; ++index )
  {
      umichWorks[index].printInfo();
  }

  return 0;
}