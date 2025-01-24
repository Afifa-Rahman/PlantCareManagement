
#include <iostream>
#include <vector>
#include <string>
#include <iomanip>

using namespace std;

// Structure to hold plant details
struct Plant {
    string name;
    string type;
    string sunlightNeeds;
    int wateringFrequency; // in days
    string lastWatered;
    string lastFertilized;
};

// Global vector to store all plants
vector<Plant> plantDatabase;

// Function to add a new plant
void addPlant() {
    Plant plant;
    cout << "Enter plant name: ";
    cin.ignore();
    getline(cin, plant.name);
    cout << "Enter plant type (e.g., flower, vegetable, herb): ";
    getline(cin, plant.type);
    cout << "Enter sunlight needs (e.g., full sun, partial shade): ";
    getline(cin, plant.sunlightNeeds);
    cout << "Enter watering frequency (in days): ";
    cin >> plant.wateringFrequency;
    cin.ignore();
    cout << "Enter last watering date (YYYY-MM-DD): ";
    getline(cin, plant.lastWatered);
    cout << "Enter last fertilizing date (YYYY-MM-DD): ";
    getline(cin, plant.lastFertilized);

    plantDatabase.push_back(plant);
    cout << "Plant added successfully!\n";
}

// Function to view all plant details
void viewPlants() {
    if (plantDatabase.empty()) {
        cout << "No plants in the database yet.\n";
        return;
    }

    cout << left << setw(15) << "Name"
         << setw(15) << "Type"
         << setw(20) << "Sunlight Needs"
         << setw(20) << "Watering Freq (days)"
         << setw(15) << "Last Watered"
         << setw(15) << "Last Fertilized" << endl;
    cout << string(100, '-') << endl;

    for (const auto& plant : plantDatabase) {
        cout << left << setw(15) << plant.name
             << setw(15) << plant.type
             << setw(20) << plant.sunlightNeeds
             << setw(20) << plant.wateringFrequency
             << setw(15) << plant.lastWatered
             << setw(15) << plant.lastFertilized << endl;
    }
}

// Function to log maintenance activities
void logMaintenance() {
    string name, date;
    cout << "Enter the plant name: ";
    cin.ignore();
    getline(cin, name);

    bool found = false;
    for (auto& plant : plantDatabase) {
        if (plant.name == name) {
            found = true;
            cout << "Enter new last watering date (YYYY-MM-DD): ";
            getline(cin, date);
            plant.lastWatered = date;
            cout << "Enter new last fertilizing date (YYYY-MM-DD): ";
            getline(cin, date);
            plant.lastFertilized = date;
            cout << "Maintenance log updated successfully!\n";
            break;
        }
    }

    if (!found) {
        cout << "Plant not found!\n";
    }
}

// Function to generate daily task summary
void generateTaskSummary() {
    if (plantDatabase.empty()) {
        cout << "No plants in the database to generate tasks.\n";
        return;
    }

    cout << "Daily Task Summary:\n";
    cout << "-------------------\n";
    for (const auto& plant : plantDatabase) {
        cout << "Plant Name: " << plant.name << endl;
        cout << "Watering Frequency: Every " << plant.wateringFrequency << " days" << endl;
        cout << "Last Watered: " << plant.lastWatered << endl;
        cout << "Last Fertilized: " << plant.lastFertilized << endl;
        cout << string(20, '-') << endl;
    }
}

// Function to display the menu
void displayMenu() {
    cout << "\nPlant Care Application\n";
    cout << "-----------------------\n";
    cout << "1. Add Plant\n";
    cout << "2. View All Plants\n";
    cout << "3. Log Maintenance\n";
    cout << "4. Generate Task Summary\n";
    cout << "5. Exit\n";
    cout << "Enter your choice: ";
}

int main() {
    int choice;

    do {
        displayMenu();
        cin >> choice;

        switch (choice) {
            case 1:
                addPlant();
                break;
            case 2:
                viewPlants();
                break;
            case 3:
                logMaintenance();
                break;
            case 4:
                generateTaskSummary();
                break;
            case 5:
                cout << "Exiting the application. Goodbye!\n";
                break;
            default:
                cout << "Invalid choice! Please try again.\n";
        }
    } while (choice != 5);

    return 0;
}
