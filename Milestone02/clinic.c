/*/////////////////////////////////////////////////////////////////////////
                                                  Workshop - #A1 (MS02)

                                                  DISCLAIMER

This Work is only for educational purpose, any student who comes across this
work is not permitted to copy this work. AGAIN Any student who comes across these
documents is warned NOT TO USE these as their homework as it is plagiarism and
a clear violation of Seneca's Academic Integrity!

/////////////////////////////////////////////////////////////////////////*/

#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <string.h>
// include the user library "core" so we can use those functions
#include "core.h"
// include the user library "clinic" where the function prototypes are declared
#include "clinic.h"

//////////////////////////////////////
// DISPLAY FUNCTIONS
//////////////////////////////////////

// !!! DO NOT MODIFY THIS FUNCTION DEFINITION !!!
// Display's the patient table header (table format)
void displayPatientTableHeader(void) {
  printf("Pat.# Name            Phone#\n"
         "----- --------------- --------------------\n");
}

// !!! DO NOT MODIFY THIS FUNCTION DEFINITION !!!
// Displays a single patient record in FMT_FORM | FMT_TABLE format
void displayPatientData(const struct Patient *patient, int fmt) {
  if (fmt == FMT_FORM) {
    printf("Name  : %s\n"
           "Number: %05d\n"
           "Phone : ",
           patient->name, patient->patientNumber);
    displayFormattedPhone(patient->phone.number);
    printf(" (%s)\n", patient->phone.description);
  } else {
    printf("%05d %-15s ", patient->patientNumber, patient->name);
    displayFormattedPhone(patient->phone.number);
    printf(" (%s)\n", patient->phone.description);
  }
}

//////////////////////////////////////
// MENU & ITEM SELECTION FUNCTIONS
//////////////////////////////////////

// !!! DO NOT MODIFY THIS FUNCTION DEFINITION !!!
// main menu
void menuMain(struct ClinicData *data) {
  int selection;

  do {
    printf("Veterinary Clinic System\n"
           "=========================\n"
           "1) PATIENT     Management\n"
           "2) APPOINTMENT Management\n"
           "-------------------------\n"
           "0) Exit System\n"
           "-------------------------\n"
           "Selection: ");
    selection = inputIntRange(0, 2);
    putchar('\n');
    switch (selection) {
    case 0:
      printf("Are you sure you want to exit? (y|n): ");
      selection = !(inputCharOption("yn") == 'y');
      putchar('\n');
      if (!selection) {
        printf("Exiting system... Goodbye.\n\n");
      }
      break;
    case 1:
      menuPatient(data->patients, data->maxPatient);
      break;
    case 2:
      printf("<<< Feature not yet available >>>\n\n");
      break;
    }
  } while (selection);
}

// !!! DO NOT MODIFY THIS FUNCTION DEFINITION !!!
// Menu: Patient Management
void menuPatient(struct Patient patient[], int max) {
  int selection;

  do {
    printf("Patient Management\n"
           "=========================\n"
           "1) VIEW   Patient Data\n"
           "2) SEARCH Patients\n"
           "3) ADD    Patient\n"
           "4) EDIT   Patient\n"
           "5) REMOVE Patient\n"
           "-------------------------\n"
           "0) Previous menu\n"
           "-------------------------\n"
           "Selection: ");
    selection = inputIntRange(0, 5);
    putchar('\n');
    switch (selection) {
    case 1:
      displayAllPatients(patient, max, FMT_TABLE);
      suspend();
      break;
    case 2:
      searchPatientData(patient, max);
      break;
    case 3:
      addPatient(patient, max);
      suspend();
      break;
    case 4:
      editPatient(patient, max);
      break;
    case 5:
      removePatient(patient, max);
      suspend();
      break;
    }
  } while (selection);
}

// !!! DO NOT MODIFY THIS FUNCTION DEFINITION !!!
// Menu: Patient edit
void menuPatientEdit(struct Patient *patient) {
  int selection;

  do {
    //printing menu
    printf("Edit Patient (%05d)\n"
           "=========================\n"
           "1) NAME : %s\n"
           "2) PHONE: ",
           patient->patientNumber, patient->name);
    //calling function to print phone number
    displayFormattedPhone(patient->phone.number);

    printf("\n"
           "-------------------------\n"
           "0) Previous menu\n"
           "-------------------------\n"
           "Selection: ");
    //getting input either 0 or 1 or 2
    selection = inputIntRange(0, 2);
    putchar('\n');

    if (selection == 1) {
      printf("Name  : ");
      //getiing string as input with length between 1 and NAME_LEN
      inputCString(patient->name, 1, NAME_LEN);
      putchar('\n');
      printf("Patient record updated!\n\n");
    } else if (selection == 2) {
      //calling function to input phone number
      inputPhoneData(&patient->phone);
      printf("Patient record updated!\n\n");
    }

  } while (selection);
}

// ---------------------------------------------------------------------------
// !!! Put all the remaining function definitions below !!!
// Note: Maintain the same order/sequence as it is listed in the header file
// ---------------------------------------------------------------------------

// Display's all patient data in the FMT_FORM | FMT_TABLE format
// (ToDo: PUT THE FUNCTION DEFINITION BELOW)
void displayAllPatients(const struct Patient patient[], int max, int fmt) {
  int i, flag = 0;
  displayPatientTableHeader();
  for (i = 0; i < max; i++) {
    if (patient[i].patientNumber != 0) {
      // displaying patient data
      displayPatientData(&patient[i], fmt);
      flag = 1;
    }
  }
  if (!flag) {
    printf("*** No records found ***\n");
  }
  putchar('\n');
}

// Search for a patient record based on patient number or phone number
// (ToDo: PUT THE FUNCTION DEFINITION BELOW)
void searchPatientData(const struct Patient patient[], int max) {
  int selection;
  do {
    printf("Search Options\n"
           "==========================\n"
           "1) By patient number\n"
           "2) By phone number\n"
           "..........................\n"
           "0) Previous menu\n"
           "..........................\n");
    printf("Selection: ");
    selection = inputIntRange(0, 2);
    printf("\n");
    // if selection is 1 then search by patient number
    if (selection == 1) {
      searchPatientByPatientNumber(patient, max);
    } else if (selection == 2) {
      // if selection is 2 then search by phone number
      searchPatientByPhoneNumber(patient, max);
    }
  } while (selection);
}

// Add a new patient record to the patient array
// (ToDo: PUT THE FUNCTION DEFINITION BELOW)
void addPatient(struct Patient patient[], int max) {
  int i, index = -1;
  for (i = max - 1; i >= 0; i--) {
    if (patient[i].patientNumber == 0) {
      index = i;
    }
  }

  if (index >= 0) {
  //getting patient number for next patient
    patient[index].patientNumber = nextPatientNumber(patient, max);
    inputPatient(&patient[index]);
    printf("*** New patient record added ***\n");
  } else {
    printf("ERROR: Patient listing is FULL!\n");
  }
  putchar('\n');
}

// Edit a patient record from the patient array
// (ToDo: PUT THE FUNCTION DEFINITION BELOW)
void editPatient(struct Patient patient[], int max) {
  int patientID, index;
  printf("Enter the patient number: ");
  patientID = inputIntPositive();
  // searching for patient record
  index = findPatientIndexByPatientNum(patientID, patient, max);
  putchar('\n');
  if (index < 0) {
    printf("\nERROR: Patient record not found!\n");
  } else {
    menuPatientEdit(&patient[index]);
  }
}

// Remove a patient record from the patient array
// (ToDo: PUT THE FUNCTION DEFINITION BELOW)
void removePatient(struct Patient patient[], int max) {
  int patientID, index;
  char choice;
  printf("Enter the patient number: ");
  // getting patient id as input
  patientID = inputIntPositive();
  index = findPatientIndexByPatientNum(patientID, patient, max);
  if (index < 0) {
    printf("\nERROR: Patient record not found!\n\n");
  } else {
    putchar('\n');
    //displaying patient data
    displayPatientData(&patient[index], FMT_FORM);
    putchar('\n');
    printf("Are you sure you want to remove this patient record? (y/n): ");
    choice = !(inputCharOption("yn") == 'n');
    if (choice) {
      //reseting patient data
      patient[index].patientNumber = 0;
      strcpy(patient[index].name, "\0");
      strcpy(patient[index].phone.number, "\0");
      strcpy(patient[index].phone.description, "\0");
      printf("Patient record has been removed!");
    } else if (!choice) {
      printf("Operation aborted.");
    }
    putchar('\n');
    putchar('\n');
  }
}

//////////////////////////////////////
// UTILITY FUNCTIONS
//////////////////////////////////////

// Search and display patient record by patient number (form)
// (ToDo: PUT THE FUNCTION DEFINITION BELOW)
void searchPatientByPatientNumber(const struct Patient patient[], int max) {
  int patientID, index;
  printf("Search by patient number: ");
  //getting patientID as positive integer using a function
  patientID = inputIntPositive();
  putchar('\n');
  index = findPatientIndexByPatientNum(patientID, patient, max);
  if (index >= 0) {
    //if index is greater than 0 displaying patient data
    displayPatientData(&patient[index], FMT_FORM);
  } else {
    printf("*** No records found ***\n");
  }
  putchar('\n');
  printf("<ENTER> to continue...");
  getchar();
  putchar('\n');
}

// Search and display patient records by phone number (tabular)
// (ToDo: PUT THE FUNCTION DEFINITION BELOW)
void searchPatientByPhoneNumber(const struct Patient patient[], int max) {
  int i, found = 0;
  char phoneNumber[PHONE_LEN] = {'\0'};
  printf("Search by phone number: ");
  inputCString(phoneNumber, 10, 10);
  putchar('\n');
  displayPatientTableHeader();
  for (i = 0; i < max; i++) {
    
    if (strcmp(patient[i].phone.number, phoneNumber) == 0) {
      displayPatientData(&patient[i], FMT_TABLE);
      //using found flag to determine if the patient data is found or not
      found = 1;
    }
  }
  if (!found) {
    printf("\n*** No records found ***\n");
  }
  putchar('\n');
  printf("<ENTER> to continue...");
  getchar();
  putchar('\n');
}

// Get the next highest patient number
// (ToDo: PUT THE FUNCTION DEFINITION BELOW)
int nextPatientNumber(const struct Patient patient[], int max) {
  int largestNumber, i;
  largestNumber = patient[0].patientNumber;
  for (i = 0; i < max; i++) {
    if (patient[i].patientNumber > largestNumber) {
      largestNumber = patient[i].patientNumber;
    }
  }
  //returning largest number + 1 value
  return largestNumber + 1;
}

// Find the patient array index by patient number (returns -1 if not found)
// (ToDo: PUT THE FUNCTION DEFINITION BELOW)
int findPatientIndexByPatientNum(int patientNumber,
                                 const struct Patient patient[], int max) {
  int i;
  for (i = 0; i < max; i++) {
    if (patientNumber == patient[i].patientNumber) {
      return i;
    }
  }
  return -1;
}

//////////////////////////////////////
// USER INPUT FUNCTIONS
//////////////////////////////////////

// Get user input for a new patient record
// (ToDo: PUT THE FUNCTION DEFINITION BELOW)
void inputPatient(struct Patient *patient) {
  printf("Patient Data Input\n"
         "------------------\n");
  printf("Number: %05d\n"
         "Name  : ",
         patient->patientNumber);
  inputCString(patient->name, 0, NAME_LEN);
  putchar('\n');
  inputPhoneData(&patient->phone);
}

// Get user input for phone contact information
// (ToDo: PUT THE FUNCTION DEFINITION BELOW)
void inputPhoneData(struct Phone *phone) {
  int choice;
  printf("Phone Information\n"
         "-----------------\n"
         "How will the patient like to be contacted?\n"
         "1. Cell\n"
         "2. Home\n"
         "3. Work\n"
         "4. TBD\n"
         "Selection: ");
  choice = inputIntRange(1, 4);
  //using swtich case to select the phone type
  switch (choice) {
  case 1:
    strcpy(phone->description, "CELL");
    break;
  case 2:
    strcpy(phone->description, "HOME");
    break;
  case 3:
    strcpy(phone->description, "WORK");
    break;
  case 4:
    strcpy(phone->description, "TBD");
    break;
  default:
    break;
  }
  
  if (choice >= 1 && choice <= 3) {
    printf("\nContact: %s\n"
           "Number : ",
           phone->description);
    //using inputCString to get the phone number
    inputCString(phone->number, 10, 10);
  }
  putchar('\n');
}