#include <fstream>
#include <vector>

#include "files.h"

using namespace std;

void saveInFile(vector<Config> &configs)
{
  fstream file;
  int size = configs.size();
  file.open("configs.bin", ios::out | ios::binary);

  file.write((char *)&size, sizeof(int));

  for (int i = 0; i < size; i++)
  {
    int len;
    file.write((char *)&configs[i].serial_number, sizeof(int));
    file.write((char *)&configs[i].ram, sizeof(int));

    len = configs[i].model.size();
    file.write((char *)&len, sizeof(int));
    file.write((char *)&configs[i].model[0], len);

    len = configs[i].brand.size();
    file.write((char *)&len, sizeof(int));
    file.write((char *)&configs[i].brand[0], len);

    file.write((char *)&configs[i].price, sizeof(float));

    len = configs[i].processor.manufacturer.size();
    file.write((char *)&len, sizeof(int));
    file.write((char *)&configs[i].processor.manufacturer[0], len);

    len = configs[i].processor.model.size();
    file.write((char *)&len, sizeof(int));
    file.write((char *)&configs[i].processor.model[0], len);

    file.write((char *)&configs[i].processor.frequency, sizeof(float));
    file.write((char *)&configs[i].processor.core_count, sizeof(int));
    file.write((char *)&configs[i].status, sizeof(Config::Status));
  }

  file.close();
}

void getFromFile(vector<Config> &configs)
{
  fstream file;
  int size = configs.size();

  file.open("configs.bin", ios::in | ios::binary);

  file.read((char *)&size, sizeof(int));

  for (int i = 0; i < size; i++)
  {
    int len;

    Config config;

    file.read((char *)&config.serial_number, sizeof(int));
    file.read((char *)&config.ram, sizeof(int));

    file.read((char *)&len, sizeof(int));
    config.model.resize(len);
    file.read((char *)&config.model[0], len);

    file.read((char *)&len, sizeof(int));
    config.brand.resize(len);
    file.read((char *)&config.brand[0], len);

    file.read((char *)&config.price, sizeof(float));

    file.read((char *)&len, sizeof(int));
    config.processor.manufacturer.resize(len);
    file.read((char *)&config.processor.manufacturer[0], len);

    file.read((char *)&len, sizeof(int));
    config.processor.model.resize(len);
    file.read((char *)&config.processor.model[0], len);

    file.read((char *)&config.processor.frequency, sizeof(float));
    file.read((char *)&config.processor.core_count, sizeof(int));
    file.read((char *)&config.status, sizeof(Config::Status));

    configs.push_back(config);
  }

  file.close();
}
