
#include <iostream>
#include <string>

using namespace std;

class Person {
public:
    // Constructor to initialize data
    Person(string name, string dob, string bloodGroup, float height, float weight, string insurancePolicyNumber, string contactAddress, string telephoneNumber, string drivingLicenseNumber) {
        this->name = name;
        this->dob = dob;
        this->bloodGroup = bloodGroup;
        this->height = height;
        this->weight = weight;
        this->insurancePolicyNumber = insurancePolicyNumber;
        this->contactAddress = contactAddress;
        this->telephoneNumber = telephoneNumber;
        this->drivingLicenseNumber = drivingLicenseNumber;
    }

    // Default constructor
    Person() = default;

    // Copy constructor
    Person(const Person& person) {
        this->name = person.name;
        this->dob = person.dob;
        this->bloodGroup = person.bloodGroup;
        this->height = person.height;
        this->weight = person.weight;
        this->insurancePolicyNumber = person.insurancePolicyNumber;
        this->contactAddress = person.contactAddress;
        this->telephoneNumber = person.telephoneNumber;
        this->drivingLicenseNumber = person.drivingLicenseNumber;
    }

    // Destructor to release memory
    ~Person() {
        // Release any dynamically allocated memory here
    }

    // Static member function to get the current year
    static int getCurrentYear() {
        time_t now = time(0);
        tm* ltm = localtime(&now);
        return ltm->tm_year + 1900;
    }

    // Friend function to calculate age
    friend int calculateAge(const Person& person) {
        int currentYear = getCurrentYear();
        int yearOfBirth = stoi(person.dob.substr(0, 4));
        return currentYear - yearOfBirth;
    }

    // Inline function to check if blood group is valid
    inline bool isValidBloodGroup() const {
        string validBloodGroups[] = {"A+", "A-", "B+", "B-", "AB+", "AB-", "O+", "O-"};
        for (const string& bloodGroup : validBloodGroups) {
            if (bloodGroup == this->bloodGroup) {
                return true;
            }
        }
        return false;
    }

    // Display person's details
    void displayDetails() {
        cout << "Name: " << name << endl;
        cout << "Date of Birth: " << dob << endl;
        cout << "Blood Group: " << bloodGroup << endl;
        cout << "Height: " << height << " cm" << endl;
        cout << "Weight: " << weight << " kg" << endl;
        cout << "Insurance Policy Number: " << insurancePolicyNumber << endl;
        cout << "Contact Address: " << contactAddress << endl;
        cout << "Telephone Number: " << telephoneNumber << endl;
        cout << "Driving License Number: " << drivingLicenseNumber << endl;
    }

private:
    string name;
    string dob;
    string bloodGroup;
    float height;
    float weight;
    string insurancePolicyNumber;
    string contactAddress;
    string telephoneNumber;
    string drivingLicenseNumber;
};

int main() {
    // Create a person object using constructor
    Person person1("John Doe", "1990-01-01", "A+", 175.0, 70.0, "123456789", "123 Main Street", "123-456-7890", "AB12345");

    // Display person's details
    person1.displayDetails();

    // Calculate age using friend function
    int age = calculateAge(person1);
    cout << "Age: " << age << endl;

    // Check if blood group is valid using inline function
    if (person1.isValidBloodGroup()) {
        cout << "Blood group is valid" << endl;
    } else {
        cout << "Blood group is not valid" << endl;
    }

    return 0;
}
