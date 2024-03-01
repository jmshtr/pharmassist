#include <iostream>
#include <fstream>
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
    vector<Prescription> prescriptions; // Vector to store prescriptions
    string filename; // File to store prescriptions

public:
    // Constructor to initialize the PrescriptionManager with a filename
    PrescriptionManager(const string& filename) : filename(filename) {}

    // Function to load prescriptions from a file
    void loadPrescriptions() {
        prescriptions.clear(); // Clear existing prescriptions
        ifstream file(filename); // Open file for reading
        if (file.is_open()) {
            Prescription prescription;
            // Read prescription details line by line
            while (getline(file, prescription.patientName)) {
                getline(file, prescription.doctorName);
                getline(file, prescription.medication);
                getline(file, prescription.instructions);
                prescriptions.push_back(prescription); // Add prescription to vector
            }
            file.close(); // Close file
        }
    }

    // Function to save prescriptions to a file
    void savePrescriptions() {
        ofstream file(filename); // Open file for writing
        if (file.is_open()) {
            // Write each prescription detail to file
            for (const auto& prescription : prescriptions) {
                file << prescription.patientName << endl;
                file << prescription.doctorName << endl;
                file << prescription.medication << endl;
                file << prescription.instructions << endl;
            }
            file.close(); // Close file
        }
    }

    // Function to add a new prescription
    // Parameters:
    // - prescription: Prescription to be added
    void addPrescription(const Prescription& prescription) {
        prescriptions.push_back(prescription); // Add prescription to vector
        savePrescriptions(); // Save after adding
        cout << "Prescription added successfully.\n";
    }

    // Function to display all prescriptions
    void displayPrescriptions() {
        if (prescriptions.empty()) {
            cout << "No prescriptions available.\n";
            return;
        }

        cout << "Prescriptions:\n";
        // Display each prescription detail
        for (const auto& prescription : prescriptions) {
            cout << "Patient Name: " << prescription.patientName << endl;
            cout << "Doctor Name: " << prescription.doctorName << endl;
            cout << "Medication: " << prescription.medication << endl;
            cout << "Instructions: " << prescription.instructions << endl;
            cout << "---------------------\n";
        }
    }

    // Function to update a prescription
    // Parameters:
    // - index: Index of the prescription to be updated in the prescriptions vector
    // - newPrescription: Updated prescription details
    void updatePrescription(int index, const Prescription& newPrescription) {
        if (index >= 0 && index < prescriptions.size()) {
            prescriptions[index] = newPrescription; // Update prescription
            savePrescriptions(); // Save after updating
            cout << "Prescription updated successfully.\n";
        } else {
            cout << "Invalid prescription index.\n";
        }
    }

    // Function to delete a prescription
    // Parameters:
    // - index: Index of the prescription to be deleted in the prescriptions vector
    void deletePrescription(int index) {
        if (index >= 0 && index < prescriptions.size()) {
            prescriptions.erase(prescriptions.begin() + index); // Delete prescription
            savePrescriptions(); // Save after deleting
            cout << "Prescription deleted successfully.\n";
        } else {
            cout << "Invalid prescription index.\n";
        }
    }
};

int main() {
    PrescriptionManager manager("prescriptions.txt"); // Create PrescriptionManager object with filename

    // Load existing prescriptions from the file
    manager.loadPrescriptions();

    // Displaying prescriptions
    manager.displayPrescriptions();

    // Sample prescriptions
    Prescription prescription1 = {"John Doe", "Dr. Smith", "Aspirin", "Take with water after meals."};
    Prescription prescription2 = {"Jane Smith", "Dr. Johnson", "Paracetamol", "Take 2 tablets every 6 hours."};

    // Adding prescriptions
    manager.addPrescription(prescription1);
    manager.addPrescription(prescription2);

    // Displaying prescriptions after adding
    manager.displayPrescriptions();

    // Updating prescription
    Prescription newPrescription = {"John Doe", "Dr. White", "Ibuprofen", "Take with food."};
    manager.updatePrescription(0, newPrescription);
    manager.displayPrescriptions();

    // Deleting prescription
    manager.deletePrescription(1);
    manager.displayPrescriptions();

    return 0;
}
