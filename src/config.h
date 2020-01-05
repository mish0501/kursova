#ifndef Config_H
#define Config_H
#include <string>

#define configsCount 100

struct Processor
{
  std::string manufacturer, model;
  float frequency;
  int core_count;
};

struct Config
{
  int serial_number, ram;
  std::string model, brand;
  float price;
  Processor processor;
  enum Status
  {
    sold,
    selling
  } status;

  bool operator==(const Config &right)
  {
    return serial_number == right.serial_number &&
           brand == right.brand &&
           model == right.model &&
           price == right.price &&
           ram == right.ram &&
           status == right.status &&
           processor.model == right.processor.model &&
           processor.manufacturer == right.processor.manufacturer &&
           processor.frequency == right.processor.frequency &&
           processor.core_count == right.processor.core_count;
  }
};
#endif
