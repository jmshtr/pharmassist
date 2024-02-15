#include <iostream>
#include <vector>
#include <string>

using namespace std;

// Prescription structure
struct Prescription {
    string patientName;
    string doctorName;
    string medication;
    string instructions;
};

// Prescription Management System class
class PrescriptionManager {
private:
    vector<Prescription> prescriptions;

public:
    // Function to add a new prescription
    void addPrescription(const Prescription& prescription) {
        prescriptions.push_back(prescription);
        cout << "Prescription added successfully.\n";
    }

    // Function to display all prescriptions
    void displayPrescriptions() {
        if (prescriptions.empty()) {
            cout << "No prescriptions available.\n";
            return;
        }

        cout << "Prescriptions:\n";
        for (const auto& prescription : prescriptions) {
            cout << "Patient Name: " << prescription.patientName << endl;
            cout << "Doctor Name: " << prescription.doctorName << endl;
            cout << "Medication: " << prescription.medication << endl;
            cout << "Instructions: " << prescription.instructions << endl;
            cout << "---------------------\n";
        }
    }
};

int main() {
    PrescriptionManager manager;

    // Sample prescriptions
    Prescription prescription1 = {"John Doe", "Dr. Smith", "Aspirin", "Take with water after meals."};
    Prescription prescription2 = {"Jane Smith", "Dr. Johnson", "Paracetamol", "Take 2 tablets every 6 hours."};

    // Adding prescriptions
    manager.addPrescription(prescription1);
    manager.addPrescription(prescription2);

    // Displaying prescriptions
    manager.displayPrescriptions();

    return 0;
}
