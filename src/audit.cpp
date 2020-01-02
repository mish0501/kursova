#include <iostream>
#include <iomanip>

#include "audit.h"

using namespace std;

void auditMenu(vector<Config> &configs)
{
  int choice;

  do
  {
    system("clear");
    system("cls");

    cout << setw(58) << setfill('-') << "" << endl;
    cout << "|         To continue, please select an option:          |\n";
    cout << setw(58) << setfill('-') << "" << endl;
    cout << setw(57) << setfill(' ') << left << "| 1. Sort all curently selling configs by serial number."
         << "|\n";
    cout << setw(57) << setfill(' ') << left << "| 2. Sort all configs by proccessor model and RAM."
         << "|\n";
    cout << setw(57) << setfill(' ') << left << "| 3. Sort all sold configs by proccessor model."
         << "|\n";
    cout << setw(57) << setfill(' ') << left << "| 4. Back."
         << "|\n";
    cout << setw(58) << setfill('-') << "" << endl;
    cout << "Please, choose an option: ";

    cin >> choice;

    switch (choice)
    {
    case 1:
      allSelling(configs);
      break;
    case 2:
      allByProccessorAndRam(configs);
      break;
    case 3:
      allSold(configs);
      break;
    case 4:
      break;
    }

  } while (choice >= 1 && choice <= 3);
}

void allSelling(vector<Config> &configs)
{
  vector<Config> sellingConfigs;

  for (int i = 0; i < configs.size(); i++)
  {
    if (configs[i].status)
    {
      sellingConfigs.push_back(configs[i]);
    }
  }

  Config temp;
  bool swapped;

  for (int i = 0; i < sellingConfigs.size(); i++)
  {
    swapped = false;
    for (int j = 0; j < sellingConfigs.size() - 1; j++)
    {
      if (sellingConfigs[j].serial_number > sellingConfigs[j + 1].serial_number)
      {
        temp = sellingConfigs[j];
        sellingConfigs[j] = sellingConfigs[j + 1];
        sellingConfigs[j + 1] = temp;

        swapped = true;
      }
    }

    if (!swapped)
      break;
  }

  showConfigs(sellingConfigs);
}

void allByProccessorAndRam(vector<Config> &configs)
{
  vector<Config> configsToSort;

  string model;
  int ram;

  cout << "Input the proccessor model: ";
  cin >> model;

  cout << "Input the RAM: ";
  cin >> ram;

  for (int i = 0; i < configs.size(); i++)
  {
    if (configs[i].processor.model == model && configs[i].ram == ram)
    {
      configsToSort.push_back(configs[i]);
    }
  }

  Config temp;
  bool swapped;

  for (int i = 0; i < configsToSort.size(); i++)
  {
    swapped = false;
    for (int j = 0; j < configsToSort.size() - 1; j++)
    {
      if (configsToSort[j].price < configsToSort[j + 1].price)
      {
        temp = configsToSort[j];
        configsToSort[j] = configsToSort[j + 1];
        configsToSort[j + 1] = temp;

        swapped = true;
      }
    }

    if (!swapped)
      break;
  }

  showConfigs(configsToSort);
}

void allSold(vector<Config> &configs)
{

  vector<Config> soldConfigs;

  for (int i = 0; i < configs.size(); i++)
  {
    if (!configs[i].status)
    {
      soldConfigs.push_back(configs[i]);
    }
  }

  Config temp;
  bool swapped;

  for (int i = 0; i < soldConfigs.size(); i++)
  {
    swapped = false;
    for (int j = 0; j < soldConfigs.size() - 1; j++)
    {
      if (soldConfigs[j].processor.model.compare(soldConfigs[j + 1].processor.model) > 0)
      {
        temp = soldConfigs[j];
        soldConfigs[j] = soldConfigs[j + 1];
        soldConfigs[j + 1] = temp;

        swapped = true;
      }
    }

    if (!swapped)
      break;
  }

  showConfigs(soldConfigs);
}
