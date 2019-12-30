#include <iostream>
#include <vector>
#include <iomanip>
#include <algorithm>

#include "edit.h"

using namespace std;

void editConfig(vector<Config> &configs)
{
  cout << "Edit config\n\n";

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
      system("pause");
    }
    else
    {
      int choice;
      do
      {

        cout << setw(41) << setfill('-') << "" << endl;
        cout << "| To continue, please select an option: |\n";
        cout << setw(41) << setfill('-') << "" << endl;
        cout << setw(40) << setfill(' ') << left << "| 1. Edit the serial number."
             << "|\n";
        cout << setw(40) << setfill(' ') << left << "| 2. Edit the brand."
             << "|\n";
        cout << setw(40) << setfill(' ') << left << "| 3. Edit the model."
             << "|\n";
        cout << setw(40) << setfill(' ') << left << "| 4. Edit the proccessor manufacturer."
             << "|\n";
        cout << setw(40) << setfill(' ') << left << "| 5. Edit the proccessor model."
             << "|\n";
        cout << setw(40) << setfill(' ') << left << "| 6. Edit the proccessor frequency."
             << "|\n";
        cout << setw(40) << setfill(' ') << left << "| 7. Edit the number of cores."
             << "|\n";
        cout << setw(40) << setfill(' ') << left << "| 8. Edit the RAM(in GB)."
             << "|\n";
        cout << setw(40) << setfill(' ') << left << "| 9. Back."
             << "|\n";
        cout << setw(41) << setfill('-') << "" << endl;

        cin >> choice;

        switch (choice)
        {
        case 1:

          int serialNumber;
          bool found;

          do
          {
            cout << "Input the new serial number: ";
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

          config.serial_number = serialNumber;

          break;
        case 2:
          cout << "Input the new brand: ";
          cin >> config.brand;

          break;
        case 3:
          cout << "Input the new model: ";
          cin >> config.model;

          break;
        case 4:
          cout << "Input the new proccessor manufacturer: ";
          cin >> config.processor.manufacturer;

          break;
        case 5:
          cout << "Input the new proccessor model: ";
          cin >> config.processor.model;

          break;
        case 6:
          cout << "Input the new proccessor frequency: ";
          cin >> config.processor.frequency;

          break;
        case 7:
          cout << "Input the new number of cores: ";
          cin >> config.processor.core_count;

          break;
        case 8:
          cout << "Input the new RAM(in GB): ";
          cin >> config.ram;

          break;
        }
      } while (choice >= 1 && choice <= 8);
      configs[index] = config;

      replace(configs.begin(), configs.end(), configs[index], config);
    }
  }
  else
  {
    cout << "No config found with that serial number.\n\n";
  }
}
