#include <iostream>
#include <iomanip>
#include <vector>
#include <algorithm>

#include "sale.h"
#include "show.h"

using namespace std;

void saleConfigMenu(vector<Config> &configs)
{
  int choice;

  do
  {
    cout << setw(41) << setfill('-') << "" << endl;
    cout << "| To continue, please select an option: |\n";
    cout << setw(41) << setfill('-') << "" << endl;
    cout << setw(40) << setfill(' ') << left << "| 1. Sale config by serial number."
         << "|\n";
    cout << setw(40) << setfill(' ') << left << "| 2. Sale config by characteristics."
         << "|\n";
    cout << setw(40) << setfill(' ') << left << "| 3. Exit."
         << "|\n";
    cout << setw(41) << setfill('-') << "" << endl;
    cout << "Please, choose an option: ";

    cin >> choice;

    switch (choice)
    {
    case 1:
      cout << "Sale config by serial number\n\n";

      saleConfigBySerialNum(configs);
      break;
    case 2:
      cout << "Sale config by processor frequency and cores and RAM.\n\n";

      saleConfigByCharacteristics(configs);
      break;
    case 3:
      break;
    }

  } while (choice >= 1 && choice <= 2);
}

void saleConfigBySerialNum(vector<Config> &configs)
{
  int serialNum, index(-1);

  cout << "Input the serial number of the config: ";
  cin >> serialNum;

  for (int i = 0; i < configs.size(); i++)
  {
    if (configs[i].serial_number == serialNum)
    {
      index = i;
      break;
    }
  }

  if (index != -1)
  {
    Config config = configs[index];

    if (!config.status)
    {
      cout << "The config is sold.\n";
    }
    else
    {
      config.status = Config::Status::sold;

      replace(configs.begin(), configs.end(), configs[index], config);

      cout << "The config was sold successfuly.\n";
    }
  }
}

void saleConfigByCharacteristics(vector<Config> &configs)
{
  int cores, ram, index(-1), serialNum;
  float frequency;
  vector<Config> sortedConfigs;

  cout << "Input the processor frequency: ";
  cin >> frequency;

  cout << "Input the processor number of cores: ";
  cin >> cores;

  cout << "Input the RAM(in GB): ";
  cin >> ram;

  for (int i = 0; i < configs.size(); i++)
  {
    if (configs[i].processor.frequency == frequency && configs[i].processor.core_count == cores && configs[i].ram == ram)
    {
      sortedConfigs.push_back(configs[i]);
    }
  }

  showConfigs(sortedConfigs);

  saleConfigBySerialNum(configs);
}
