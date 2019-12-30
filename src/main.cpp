#include <iostream>
#include <vector>
#include <iomanip>
#include <fstream>

#include "main.h"

using namespace std;

int main()
{
  int choice;
  vector<Config> configs;

  getFromFile(configs);

  system("mode con: cols=132 lines=24 && color 0a");
  system("printf '\e[8;24;132t' && stty rows 24 && stty cols 132");

  do
  {
    system("clear");
    system("cls");

    cout << setw(41) << setfill('-') << "" << endl;
    cout << "| To continue, please select an option: |\n";
    cout << setw(41) << setfill('-') << "" << endl;
    cout << setw(40) << setfill(' ') << left << "| 1. Add new config."
         << "|\n";
    cout << setw(40) << setfill(' ') << left << "| 2. Show all configs."
         << "|\n";
    cout << setw(40) << setfill(' ') << left << "| 3. Edit a config."
         << "|\n";
    cout << setw(40) << setfill(' ') << left << "| 4. Sale a config."
         << "|\n";
    cout << setw(40) << setfill(' ') << left << "| 5. Sort all configs."
         << "|\n";
    cout << setw(40) << setfill(' ') << left << "| 6. Exit."
         << "|\n";
    cout << setw(41) << setfill('-') << "" << endl;

    cin >> choice;

    switch (choice)
    {
    case 1:
      addConfigMenu(configs);
      break;
    case 2:
      showAllConfigs(configs);
      break;
    case 3:
      editConfig(configs);
      break;
    case 4:
      saleConfigMenu(configs);
      break;
    case 5:
      auditMenu(configs);
      break;
    case 6:
      break;
    }

  } while (choice >= 1 && choice <= 5);

  saveInFile(configs);
}
