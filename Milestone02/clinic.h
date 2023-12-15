/*/////////////////////////////////////////////////////////////////////////
                                                  Workshop - #A1 (MS02)

                                                  DISCLAIMER

This Work is only for educational purpose, any student who comes across this
work is not permitted to copy this work. AGAIN Any student who comes across these
documents is warned NOT TO USE these as their homework as it is plagiarism and
a clear violation of Seneca's Academic Integrity!

/////////////////////////////////////////////////////////////////////////*/

// SAFE-GUARD:
// It is good practice to apply safe-guards to header files
// Safe-guard's ensures only 1 copy of the header file is used in the project
// build The macro name should be mirroring the file name with _ for spaces,
// dots, etc.
#ifndef CLINIC_H
#define CLINIC_H

//////////////////////////////////////
// Module macro's (usable by any file that includes this header)
//////////////////////////////////////

// Display formatting options (Provided to student)
// !!! DO NOT MODIFY THESE MACRO'S !!!
#define FMT_FORM 1
#define FMT_TABLE 2

// C Strings: array sizes
#define NAME_LEN 15
#define PHONE_DESC_LEN 4
#define PHONE_LEN 10

//////////////////////////////////////
// Structures
//////////////////////////////////////

// Data type: Phone
// ToDo:
struct Phone {
  char description[PHONE_DESC_LEN + 1];
  char number[PHONE_LEN + 1];
};

// Data type: Patient
// ToDo:
struct Patient {
  int patientNumber;
  char name[NAME_LEN];
  struct Phone phone;
};

// ClinicData type: Provided to student
// !!! DO NOT MODIFY THIS DATA TYPE !!!
struct ClinicData {
  struct Patient *patients;
  int maxPatient;
};

//////////////////////////////////////
// DISPLAY FUNCTIONS
//////////////////////////////////////

// Display's the patient table header (table format)
void displayPatientTableHeader(void);

// Displays a single patient record in FMT_FORM | FMT_TABLE format
void displayPatientData(const struct Patient *patient, int fmt);

//////////////////////////////////////
// MENU & ITEM SELECTION FUNCTIONS
//////////////////////////////////////

// Menu: Main
void menuMain(struct ClinicData *data);

// Menu: Patient Management
void menuPatient(struct Patient patient[], int max);

// Menu: Patient edit
void menuPatientEdit(struct Patient *patient);

// !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
// !!! ALL the below functions need defining       !!!
// !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!

// !!! DO NOT MODIFY THE BELOW PROTOTYPES !!!

// Display's all patient data in the FMT_FORM | FMT_TABLE format
void displayAllPatients(const struct Patient patient[], int max, int fmt);

// Search for a patient record based on patient number or phone number
void searchPatientData(const struct Patient patient[], int max);

// Add a new patient record to the patient array
void addPatient(struct Patient patient[], int max);

// Edit a patient record from the patient array
void editPatient(struct Patient patient[], int max);

// Remove a patient record from the patient array
void removePatient(struct Patient patient[], int max);

//////////////////////////////////////
// UTILITY FUNCTIONS
//////////////////////////////////////

// Search and display patient record by patient number (form)
void searchPatientByPatientNumber(const struct Patient patient[], int max);

// Search and display patient records by phone number (tabular)
void searchPatientByPhoneNumber(const struct Patient patient[], int max);

// Get the next highest patient number
int nextPatientNumber(const struct Patient patient[], int max);

// Find the patient array index by patient number (returns -1 if not found)
int findPatientIndexByPatientNum(int patientNumber,
                                 const struct Patient patient[], int max);

//////////////////////////////////////
// USER INPUT FUNCTIONS
//////////////////////////////////////

// Get user input for a new patient record
void inputPatient(struct Patient *patient);

// Get user input for phone contact information
void inputPhoneData(struct Phone *phone);

#endif // !CLINIC_H