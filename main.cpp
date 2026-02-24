#include <iostream>
#include <string>
using namespace std;

class Appliance {
    private:
    string name;
    double power;
    double hours;

    public:
    void setAppliance() {
        cout << "Enter appliance name: ";
        cin.ignore();
        getline(cin, name);

        while (name.empty()) {
            cout << " Name cannot be empty. Enter again: ";
            getline(cin, name);
        }

        cout << "Enter power rating (watts): ";
        cin >> power;
        while (power <= 0) {
            cout << "Power must be greater than zero. Enter again: ";
            cin>> power;
        }

            cout << "Enter daily usage hours(0 - 24): ";
            cin >> hours;
            while (hours< 0|| hours >24) {
                cout << "Invalid hours. Enter between 0 and 24: ";
                cin >> hours;
            }
    }
    double calculateEnergy() const {
        return (power * hours) / 1000.0;
    }
   void displayAppliance(double tariff) const {
    cout << "Appliance Name: " << name << endl;
    cout << "Power Rating: " << power << " W" << endl;
    cout << "Daily Usage: " << hours << " hours" << endl;
    cout << "Daily Energy: " << calculateEnergy() << " kWh" << endl;
    cout << "Monthly Energy: " << calculateMonthlyEnergy() << " kWh" << endl;
    cout << "Monthly Cost: " 
         << calculateMonthlyCost(tariff) << endl;
    cout << "--------------------------------------" << endl;
}
 double calculateMonthlyEnergy() const {
    return calculateEnergy() * 30;
}

double calculateMonthlyCost(double tariff) const {
    return calculateMonthlyEnergy() * tariff;
}
};
        
int main() {
    const int MAX = 10;
    Appliance appliances[MAX];
    int count = 0;
    int choice;

    double tariff = 1.5;

cout << "Enter electricity tariff rate per kWh: ";
cin >> tariff;

while (tariff <= 0) {
    cout << "Tariff must be greater than 0. Enter again: ";
    cin >> tariff;
}
    do {
        cout << "\n=== Electrical Load Monitoring System ===\n";
        cout << "1. Register Appliance\n";
        cout << "2. View All Appliances\n";
        cout << "3. View Total Monthly Bill\n";
        cout << "4. System Status\n";
        cout << "0. Exit\n";
        cout << "Enter choice: ";
        cin >> choice;
        
        switch (choice) {
            case 1:
                if (count < MAX) {
                    appliances[count].setAppliance();
                    count++;
                    cout << "Appliance registered successfully!\n";
                } else {
                    cout << "Appliance list is full!\n";
                }
                break;

            case 2:
                if (count == 0) {
                    cout << "No appliances registered yet.\n";
                } else {
                    for (int i = 0; i < count; i++) {
                        appliances[i].displayAppliance(tariff);
                    }
                }
                break;

            case 3:
                if (count == 0) {
                    cout << "No appliances registered yet.\n";
                } else {
                    double totalMonthlyEnergy = 0;
                    double totalBill = 0;

                    for (int i = 0; i < count; i++) {
                        totalMonthlyEnergy += appliances[i].calculateMonthlyEnergy();
                        totalBill += appliances[i].calculateMonthlyCost(tariff);
                    }

                    cout << "Total Monthly Energy: "
                         << totalMonthlyEnergy << " kWh\n";

                    cout << "Estimated Monthly Electricity Bill: "
                         << totalBill << endl;
                }
                break;

            case 4:
                if (count == 0) {
                    cout << "System Status: No appliances registered.\n";
                } else {
                    cout << "System Status: "
                         << count << " appliance(s) registered.\n";
                }
                break;

            case 0:
                cout << "Exiting program...\n";
                break;

            default:
                cout << "Invalid choice! Try again.\n";
        }
    } while (choice != 0);
    
    return 0;
}