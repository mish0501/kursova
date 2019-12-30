#include <iostream>
#include <vector>
#include <iomanip>

#include "show.h"

using namespace std;

ostream &operator<<(ostream &out, const Config::Status &x)
{
  switch (x)
  {
  case Config::Status::selling:
    out << "selling";
    break;
  case Config::Status::sold:
    out << "sold";
    break;
  default:
    throw out_of_range("Invalid value for type Config::Status");
  }
  return out;
}

void showAllConfigs(vector<Config> configs)
{
  int len = configs.size();

  cout << setw(131) << setfill('-') << "" << endl; // Line 1

  cout << "|" << setw(15) << setfill(' ') << ""
       << "|"
       << setw(10) << setfill(' ') << ""
       << "|"
       << setw(10) << setfill(' ') << ""
       << "|"
       << setw(23) << setfill(' ') << ""
       << "Proccessor" << setw(22) << setfill(' ') << ""
       << "|" << setw(13) << setfill(' ') << ""
       << "|"
       << setw(10) << setfill(' ') << ""
       << "|"
       << setw(10) << setfill(' ') << ""
       << "|" << endl; // Line 2

  cout << setw(16) << setfill(' ') << "| Serial number"
       << "|"
       << setw(10) << setfill(' ') << " Brand"
       << "|"
       << setw(10) << setfill(' ') << " Model"
       << "|"
       << setw(55) << setfill('-') << "" << setw(14) << setfill(' ') << "| RAM (in GB)"
       << "|"
       << setw(10) << setfill(' ') << " Price"
       << "|"
       << setw(10) << setfill(' ') << " Status"
       << "|" << endl; //Line 3

  cout << "|" << setw(15) << setfill(' ') << ""
       << "|"
       << setw(10) << setfill(' ') << ""
       << "|"
       << setw(10) << setfill(' ') << ""
       << "|"
       << setw(15) << setfill(' ') << " Manufacturer"
       << "|"
       << setw(10) << setfill(' ') << " Model"
       << "|"
       << setw(20) << setfill(' ') << " Frequency (in GHz)"
       << "|"
       << setw(7) << setfill(' ') << " Cores"
       << "|" << setw(13) << setfill(' ') << ""
       << "|"
       << setw(10) << setfill(' ') << ""
       << "|"
       << setw(10) << setfill(' ') << ""
       << "|" << endl; // Line 4

  if (len == 0)
  {
    cout << setw(131) << setfill('-') << "" << endl;
    cout << "|" << setw(51) << setfill(' ') << ""
         << "There are no configs added." << setw(51) << setfill(' ') << ""
         << "|" << endl;
  }
  else
  {
    for (int i = 0; i < len; i++)
    {
      cout << setw(131) << setfill('-') << "" << endl;
      cout << "| " << setw(13) << setfill(' ') << left << configs[i].serial_number;
      cout << " | " << setw(8) << setfill(' ') << left << configs[i].brand;
      cout << " | " << setw(8) << setfill(' ') << left << configs[i].model;
      cout << " | " << setw(13) << setfill(' ') << left << configs[i].processor.manufacturer;
      cout << " | " << setw(8) << setfill(' ') << left << configs[i].processor.model;
      cout << " | " << setw(18) << setfill(' ') << left << setprecision(1) << fixed << configs[i].processor.frequency;
      cout << " | " << setw(5) << setfill(' ') << left << configs[i].processor.core_count;
      cout << " | " << setw(11) << setfill(' ') << left << configs[i].ram;
      cout << " | " << setw(8) << setfill(' ') << left << setprecision(2) << fixed << configs[i].price;
      cout << " | " << setw(8) << setfill(' ') << left << configs[i].status << " |\n";
    }
  }

  cout << setw(131) << setfill('-') << "" << endl;

  system("pause");
}
