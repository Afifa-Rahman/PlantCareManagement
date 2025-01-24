
#include <iostream>
#include <vector>
#include <string>
using namespace std;

// Structure to store plant details
struct Plant {
    string name;
    string type;
    string sunlightNeeds;
    string wateringFrequency;
};

// Function to add a plant
void addPlant(vector<Plant>& plants) {
    Plant newPlant;
    cout << "\nEnter Plant Name: ";
    cin.ignore();
    getline(cin, newPlant.name);
    cout << "Enter Plant Type: ";
    getline(cin, newPlant.type);
    cout << "Enter Sunlight Needs: ";
    getline(cin, newPlant.sunlightNeeds);
    cout << "Enter Watering Frequency: ";
    getline(cin, newPlant.wateringFrequency);
    plants.push_back(newPlant);
    cout << "Plant added successfully!\n";
}

// Function to view plant details
void viewPlants(const vector<Plant>& plants) {
    if (plants.empty()) {
        cout << "\nNo plants added yet!\n";
        return;
    }
    cout << "\nPlant Details:\n";
    for (size_t i = 0; i < plants.size(); i++) {
        cout << "Plant " << i + 1 << ":\n";
        cout << "Name: " << plants[i].name << "\n";
        cout << "Type: " << plants[i].type << "\n";
        cout << "Sunlight Needs: " << plants[i].sunlightNeeds << "\n";
        cout << "Watering Frequency: " << plants[i].wateringFrequency << "\n\n";
    }
}

// Function to manage watering schedules
void manageWateringSchedule(const vector<Plant>& plants) {
    if (plants.empty()) {
        cout << "\nNo plants added yet!\n";
        return;
    }
    cout << "\nWatering Schedules:\n";
    for (size_t i = 0; i < plants.size(); i++) {
        cout << plants[i].name << " needs watering every " << plants[i].wateringFrequency << ".\n";
    }
}

int main() {
    vector<Plant> plants;
    int choice;

    do {
        // Menu for the Plant Care System
        cout << "\nPlant Care System - Menu\n";
        cout << "1. Add a Plant\n";
        cout << "2. View Plant Details\n";
        cout << "3. Manage Watering Schedule\n";
        cout << "4. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                addPlant(plants);
                break;
            case 2:
                viewPlants(plants);
                break;
            case 3:
                manageWateringSchedule(plants);
                break;
            case 4:
                cout << "Exiting Plant Care System. Goodbye!\n";
                break;
            default:
                cout << "Invalid choice! Please try again.\n";
        }
    } while (choice != 4);

    return 0;
}
