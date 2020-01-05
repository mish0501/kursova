#include <iostream>
#include <iomanip>

#include "add.h"

using namespace std;

void addConfigMenu(vector<Config> &configs)
{

  int choice;

  do
  {
    system("clear");
    system("cls");

    cout << setw(41) << setfill('-') << "" << endl;
    cout << "| To continue, please select an option: |\n";
    cout << setw(41) << setfill('-') << "" << endl;
    cout << setw(40) << setfill(' ') << left << "| 1. Add one new config."
         << "|\n";
    cout << setw(40) << setfill(' ') << left << "| 2. Add list of new configs."
         << "|\n";
    cout << setw(40) << setfill(' ') << left << "| 3. Back."
         << "|\n";
    cout << setw(41) << setfill('-') << "" << endl;
    cout << "Please, choose an option: ";

    cin >> choice;

    switch (choice)
    {
    case 1:
      addConfig(configs, false);
      break;
    case 2:
      addConfig(configs, true);
      break;
    case 3:
      break;
    }

  } while (choice >= 1 && choice <= 2);
}

void addConfig(vector<Config> &configs, bool many)
{

  system("clear");
  system("cls");

  cout << "Adding a config(s)\n";

  int len = configs.size();

  if (len != 0)
  {
    cout << "There is/are " << len << " config(s).\n";
  }

  if (len == configsCount)
  {
    cout << "You can't add more than 100 configs";
  }
  else
  {
    if (many)
    {

      int num;
      cout << "Input the number of configs you are going to add: ";
      cin >> num;

      do
      {
        char choice;
        add(configs);
        num--;
        cout << "\nSuccessfully added a config.\n";

        if (num > 0)
        {
          cout << "Do you want to continue?(y/n) ";
          cin >> choice;

          if (choice == 'n')
            break;
        }

      } while (num > 0);
    }
    else
    {
      add(configs);
      cout << "\nSuccessfully added a config.\n\n";
    }
  }
  system("pause");
}

void add(vector<Config> &configs)
{
  Config newConfig;
  int serialNumber;
  bool found;

  do
  {
    cout << "Input the serial number: ";
    cin >> serialNumber;

    found = false;

    for (int i = 0; i < configs.size(); i++)
    {
      if (configs[i].serial_number == serialNumber)
      {
        found = true;
        break;
      }
    }

    if (found)
      cout << "There is a config with that serial number. Try again.";
  } while (found);

  newConfig.serial_number = serialNumber;

  cin.ignore(1);

  cout << "Input the brand: ";
  getline(cin, newConfig.brand);

  cout << "Input the model: ";
  getline(cin, newConfig.model);

  cout << "Input the proccessor manufacturer: ";
  getline(cin, newConfig.processor.manufacturer);

  cout << "Input the proccessor model: ";
  getline(cin, newConfig.processor.model);

  cout << "Input the proccessor frequency: ";
  cin >> newConfig.processor.frequency;

  cout << "Input the number of cores: ";
  cin >> newConfig.processor.core_count;

  cout << "Input the RAM(in GB): ";
  cin >> newConfig.ram;

  cout << "Input the price: ";
  cin >> newConfig.price;

  newConfig.status = Config::Status::selling;

  configs.push_back(newConfig);
}
