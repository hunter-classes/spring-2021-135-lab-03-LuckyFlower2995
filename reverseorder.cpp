#include <fstream>
#include <cstdlib>
#include <climits>
#include <iostream>
#include "reverseorder.h"

using namespace std;

void reverse_order(std::string date1, std::string date2) {
   string date;
   string datenum1 = date1;
   string datenum2 = date2;
   int days = 0;
   int index = 0;
   string date_amount[365];
   
   string eastSt;
   string eastEl;
   string westSt;
   string westEl;
   
   ifstream fin("Current_Reservoir_Levels.tsv");
   if(fin.fail()) {
      cerr << "File cannot be opened for reading." << endl;
      exit(1);
   }
   
   string junk;
   getline(fin, junk);
   
   while (fin >> date >> eastSt >> eastEl >> westSt >> westEl) {
      fin.ignore(INT_MAX, '\n');
      if (date == datenum1 or index == 1) {
         date_amount[days] = {date + "  " + westEl};
         days = days + 1;
         index = 1;
      }
      if (date == datenum2) {
         index = 0;
      }
      if (index == 0) {
         days = days + 0;
      }
     
   }
   
   days = days - 1;
   cout << "First date: " << datenum1 << endl;
   cout << "Last date: " << datenum2 << endl << endl;
   
   while (days != -1) {
      cout << date_amount[days] << " ft" << endl;
      days = days - 1;
   }
   fin.close();
}

