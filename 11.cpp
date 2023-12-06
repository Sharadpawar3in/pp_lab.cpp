#include <iostream>
using namespace std;
class WeatherReport {
private:
    int day_of_month;
    int hightemp;
    int lowtemp;
    double amount_rain;
    double amount_snow;

public:
    WeatherReport() {
        day_of_month = 99;
        hightemp = 999;
        lowtemp = -999;
        amount_rain = 0.0;
        amount_snow = 0.0;
    }

    void enterData() {
        cout << "Enter day of month: ";
        cin >> day_of_month;

        cout << "Enter high temperature: ";
        cin >> hightemp;

        cout << "Enter low temperature: ";
        cin >> lowtemp;

        cout << "Enter amount of rain: ";
        cin >> amount_rain;

        cout << "Enter amount of snow: ";
        cin >> amount_snow;
    }

    void displayReport() {
        cout << "Monthly Weather Report" << endl;
        cout << "------------------------" << endl;

        cout << "Day of Month\tHigh Temp\tLow Temp\tRain (mm)\tSnow (cm)" << endl;
        cout << "-------------\t---------\t---------\t---------\t---------\n";

        for (int day = 1; day <= 31; day++) {
            if (day == day_of_month) {
                cout << day << "\t\t" << hightemp << "\t\t" << lowtemp << "\t\t" << amount_rain << "\t\t" << amount_snow << endl;
            } else {
                cout << day << "\t\t" << "-" << "\t\t" << "-" << "\t\t" << "-" << "\t\t" << "-" << endl;
            }
        }
    }
};

int main() {
    WeatherReport weatherReport;

    int choice;
    do {
        cout << "\nWeather Report Menu" << endl;
        cout << "-------------------" << endl;
        cout << "1. Enter Data" << endl;
        cout << "2. Display Report" << endl;
        cout << "0. Exit" << endl;
        cout << "\nEnter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                weatherReport.enterData();
                break;
            case 2:
                weatherReport.displayReport();
                break;
            case 0:
                cout << "Exiting..." << endl;
                break;
            default:
                cout << "Invalid choice. Please enter a valid option." << endl;
        }
    } while (choice != 0);

    return 0;
}
