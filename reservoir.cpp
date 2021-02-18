#include <fstream>
#include <cstdlib>
#include <climits>
#include <iostream>
#include "reservoir.h"

using namespace std;

double get_east_storage(std::string date) { 
   string date2 = date;
   string eastSt;
   
   ifstream fin("Current_Reservoir_Levels.tsv");
   
   if(fin.fail()) {
      cerr << "File cannot be opened for reading." << endl;
      exit(1);
   }
   string junk;
   getline(fin, junk);
   
   while(fin >> date >> eastSt) {
      fin.ignore(INT_MAX, '\n');
      if (date == date2) {
         cout << date << ": " << eastSt << " billion gallons." << endl;
      }
   }  
   fin.close();
   return 0;
}

//////////////////////////////////////////////////////////////

double get_min_east() { 
   double eastSt;
   string date;
   double min = 100;
   
   
   ifstream fin("Current_Reservoir_Levels.tsv");
   
   if(fin.fail()) {
      cerr << "File cannot be opened for reading." << endl;
      exit(1);
   }
   string junk;
   getline(fin, junk);
   
   while(fin >> date >> eastSt) {
      fin.ignore(INT_MAX, '\n');
      if (eastSt < min) {
         min = eastSt;
      }
  
   }  
   cout << "Minimum storage in East Basin: " << min
        << " billion gallons.\n";
   fin.close();
   return 0;
}

////////////////////////////////////////////////////////////////

double get_max_east() { 
   double eastSt;
   string date;
   double max = 0;
   
   
   ifstream fin("Current_Reservoir_Levels.tsv");
   
   if(fin.fail()) {
      cerr << "File cannot be opened for reading." << endl;
      exit(1);
   }
   string junk;
   getline(fin, junk);
   
   while(fin >> date >> eastSt) {
      fin.ignore(INT_MAX, '\n');
      if (eastSt > max) {
         max = eastSt;
      }
  
   }  
   cout << "Maximum storage in East Basin: " << max
        << " billion gallons.\n";
   fin.close();
   return 0;
}

///////////////////////////////////////////////////////////

string compare_basins(std::string date) { 
   string date2 = date;
   double eastSt;
   double eastEl;
   double westSt;
   double westEl;
   
   ifstream fin("Current_Reservoir_Levels.tsv");
   
   if(fin.fail()) {
      cerr << "File cannot be opened for reading." << endl;
      exit(1);
   }
   string junk;
   getline(fin, junk);
   
   while(fin >> date >> eastSt >> eastEl >> westSt >> westEl) {
      fin.ignore(INT_MAX, '\n');
      if (date == date2) {
         if (eastEl > westEl) {
            cout << "East\n";
         } else if (eastEl < westEl) {
            cout << "West\n";
         } else {
            cout << "Equal\n";
         }
      }
   }  
   fin.close();
   return(" ");
}
