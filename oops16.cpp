#include <iostream>
#include <string>
using namespace std;

class ServiceRecord
{
private:
  string serviceName;
  float serviceCost;

public:
  void read()
  {
    cout << "Enter Service Name: ";
    cin >> serviceName;

    cout << "Enter Service Cost: ";
    cin >> serviceCost;
  }

  void display()
  {
    cout << "Service: " << serviceName
         << " | Cost: Rs. " << serviceCost << endl;
  }

  float getCost()
  {
    return serviceCost;
  }
};

class Vehicle
{
private:
  string vehicleNumber;
  string ownerName;
  int serviceCount;
  ServiceRecord *services;

public:
  // Constructor
  Vehicle(int count)
  {
    serviceCount = count;

    // Dynamically allocate ServiceRecord array
    services = new ServiceRecord[serviceCount];
  }

  void read()
  {
    cout << "Enter Vehicle Number: ";
    cin >> vehicleNumber;

    cout << "Enter Owner Name: ";
    cin >> ownerName;

    cout << "\nEnter Service Details:\n";

    for (int i = 0; i < serviceCount; i++)
    {
      cout << "\nService " << i + 1 << ":\n";
      services[i].read();
    }
  }

  void display()
  {
    cout << "\n--- Vehicle Details ---\n";
    cout << "Vehicle Number: " << vehicleNumber << endl;
    cout << "Owner Name: " << ownerName << endl;

    cout << "\n--- Service Records ---\n";

    float totalBill = 0;

    for (int i = 0; i < serviceCount; i++)
    {
      services[i].display();
      totalBill += services[i].getCost();
    }

    cout << "\nTotal Service Bill: Rs. " << totalBill << endl;
  }

  ~Vehicle()
  {
    delete[] services;
  }
};

int main()
{
  int count;

  cout << "Enter number of services: ";
  cin >> count;

  // Dynamically create Vehicle object
  Vehicle *vehicle = new Vehicle(count);

  vehicle->read();

  vehicle->display();

  delete vehicle;

  return 0;
}