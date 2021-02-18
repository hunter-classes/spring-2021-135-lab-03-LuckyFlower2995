#include <iostream>
#include "reservoir.h"
#include "reverseorder.h"

using namespace std;

int main()
{
   string date = "01/01/2018";
   string date1 = "05/29/2018";
   string date2 = "06/02/2018";
   
   get_east_storage(date);
   cout << endl;
   
   get_min_east();
   get_max_east();
   cout << endl;
   
   compare_basins(date);
   cout << endl;
   
   reverse_order(date1, date2);
  return 0;
}
