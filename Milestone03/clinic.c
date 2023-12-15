/*/////////////////////////////////////////////////////////////////////////
                                                  Workshop - #A1 (MS03)

                                                  DISCLAIMER

This Work is only for educational purpose, any student who comes across this
work is not permitted to copy this work. AGAIN Any student who comes across these
documents is warned NOT TO USE these as their homework as it is plagiarism and
a clear violation of Seneca's Academic Integrity!

/////////////////////////////////////////////////////////////////////////*/

#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>

// include the user library "core" so we can use those functions
#include "core.h"
// include the user library "clinic" where the function prototypes are declared
#include "clinic.h"

//////////////////////////////////////
// DISPLAY FUNCTIONS
//////////////////////////////////////

// !!! DO NOT MODIFY THIS FUNCTION DEFINITION !!!
// Display's the patient table header (table format)
void displayPatientTableHeader(void)
{
    printf("Pat.# Name            Phone#\n"
           "----- --------------- --------------------\n");
}

// !!! DO NOT MODIFY THIS FUNCTION DEFINITION !!!
// Displays a single patient record in FMT_FORM | FMT_TABLE format
void displayPatientData(const struct Patient *patient, int fmt)
{
    if (fmt == FMT_FORM)
    {
        printf("Name  : %s\n"
               "Number: %05d\n"
               "Phone : ",
               patient->name, patient->patientNumber);
        displayFormattedPhone(patient->phone.number);
        printf(" (%s)\n", patient->phone.description);
    }
    else
    {
        printf("%05d %-15s ", patient->patientNumber,
               patient->name);
        displayFormattedPhone(patient->phone.number);
        printf(" (%s)\n", patient->phone.description);
    }
}

// !!! DO NOT MODIFY THIS FUNCTION DEFINITION !!!
// Display's appointment schedule headers (date-specific or all records)
void displayScheduleTableHeader(const struct Date *date, int isAllRecords)
{
    printf("Clinic Appointments for the Date: ");

    if (isAllRecords)
    {
        printf("<ALL>\n\n");
        printf("Date       Time  Pat.# Name            Phone#\n"
               "---------- ----- ----- --------------- --------------------\n");
    }
    else
    {
        printf("%04d-%02d-%02d\n\n", date->year, date->month, date->day);
        printf("Time  Pat.# Name            Phone#\n"
               "----- ----- --------------- --------------------\n");
    }
}

// !!! DO NOT MODIFY THIS FUNCTION DEFINITION !!!
// Display a single appointment record with patient info. in tabular format
void displayScheduleData(const struct Patient *patient,
                         const struct Appointment *appoint,
                         int includeDateField)
{
    if (includeDateField)
    {
        printf("%04d-%02d-%02d ", appoint->date.year, appoint->date.month,
               appoint->date.day);
    }
    printf("%02d:%02d %05d %-15s ", appoint->time.hour, appoint->time.min,
           patient->patientNumber, patient->name);

    displayFormattedPhone(patient->phone.number);

    printf(" (%s)\n", patient->phone.description);
}

//////////////////////////////////////
// MENU & ITEM SELECTION FUNCTIONS
//////////////////////////////////////

// !!! DO NOT MODIFY THIS FUNCTION DEFINITION !!!
// main menu
void menuMain(struct ClinicData *data)
{
    int selection;

    do
    {
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
        switch (selection)
        {
        case 0:
            printf("Are you sure you want to exit? (y|n): ");
            selection = !(inputCharOption("yn") == 'y');
            putchar('\n');
            if (!selection)
            {
                printf("Exiting system... Goodbye.\n\n");
            }
            break;
        case 1:
            menuPatient(data->patients, data->maxPatient);
            break;
        case 2:
            menuAppointment(data);
            break;
        }
    } while (selection);
}

// !!! DO NOT MODIFY THIS FUNCTION DEFINITION !!!
// Menu: Patient Management
void menuPatient(struct Patient patient[], int max)
{
    int selection;

    do
    {
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
        switch (selection)
        {
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
void menuPatientEdit(struct Patient *patient)
{
    int selection;

    do
    {
        printf("Edit Patient (%05d)\n"
               "=========================\n"
               "1) NAME : %s\n"
               "2) PHONE: ",
               patient->patientNumber, patient->name);

        displayFormattedPhone(patient->phone.number);

        printf("\n"
               "-------------------------\n"
               "0) Previous menu\n"
               "-------------------------\n"
               "Selection: ");
        selection = inputIntRange(0, 2);
        putchar('\n');

        if (selection == 1)
        {
            printf("Name  : ");
            inputCString(patient->name, 1, NAME_LEN);
            putchar('\n');
            printf("Patient record updated!\n\n");
        }
        else if (selection == 2)
        {
            inputPhoneData(&patient->phone);
            printf("Patient record updated!\n\n");
        }

    } while (selection);
}

// !!! DO NOT MODIFY THIS FUNCTION DEFINITION !!!
// Menu: Appointment Management
void menuAppointment(struct ClinicData *data)
{
    int selection;

    do
    {
        printf("Appointment Management\n"
               "==============================\n"
               "1) VIEW   ALL Appointments\n"
               "2) VIEW   Appointments by DATE\n"
               "3) ADD    Appointment\n"
               "4) REMOVE Appointment\n"
               "------------------------------\n"
               "0) Previous menu\n"
               "------------------------------\n"
               "Selection: ");
        selection = inputIntRange(0, 4);
        putchar('\n');
        switch (selection)
        {
        case 1:
            viewAllAppointments(data); // ToDo: You will need to create this function!
            suspend();
            break;
        case 2:
            viewAppointmentSchedule(data); // ToDo: You will need to create this function!
            suspend();
            break;
        case 3:
            addAppointment(data->appointments, data->maxAppointments,
                           data->patients, data->maxPatient); // ToDo: You will need to create this function!
            suspend();
            break;
        case 4:
            removeAppointment(data->appointments, data->maxAppointments,
                              data->patients, data->maxPatient); // ToDo: You will need to create this function!
            suspend();
            break;
        }
    } while (selection);
}

// ---------------------------------------------------------------------------
// !!! INSERT/COPY YOUR MS#2 FUNCTION DEFINITIONS BELOW... !!!
// Note: Maintain the same order/sequence as it is listed in the header file
//       Properly organize/categorize any new functions accordingly
// ---------------------------------------------------------------------------

// Display's all patient data in the FMT_FORM | FMT_TABLE format
// (Copy your code from MS#2)
void displayAllPatients(const struct Patient patient[], int max, int fmt)
{
    int i, flag = 0;
    displayPatientTableHeader();
    for (i = 0; i < max; i++)
    {
        if (patient[i].patientNumber != 0)
        {
            // displaying patient data
            displayPatientData(&patient[i], fmt);
            flag = 1;
        }
    }
    if (!flag)
    {
        printf("*** No records found ***\n");
    }
    putchar('\n');
}

// Search for a patient record based on patient number or phone number
// (Copy your code from MS#2)
void searchPatientData(const struct Patient patient[], int max)
{
    int selection;
    do
    {
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
        if (selection == 1)
        {
            searchPatientByPatientNumber(patient, max);
        }
        else if (selection == 2)
        {
            // if selection is 2 then search by phone number
            searchPatientByPhoneNumber(patient, max);
        }
    } while (selection);
}

// Add a new patient record to the patient array
// (Copy your code from MS#2)
void addPatient(struct Patient patient[], int max)
{
    int i, index = -1;
    for (i = max - 1; i >= 0; i--)
    {
        if (patient[i].patientNumber == 0)
        {
            index = i;
        }
    }

    if (index >= 0)
    {
        // getting patient number for next patient
        patient[index].patientNumber = nextPatientNumber(patient, max);
        inputPatient(&patient[index]);
        printf("*** New patient record added ***\n");
    }
    else
    {
        printf("ERROR: Patient listing is FULL!\n");
    }
    putchar('\n');
}

// Edit a patient record from the patient array
// (Copy your code from MS#2)
void editPatient(struct Patient patient[], int max)
{
    int patientID, index;
    printf("Enter the patient number: ");
    patientID = inputIntPositive();
    // searching for patient record
    index = findPatientIndexByPatientNum(patientID, patient, max);
    putchar('\n');
    if (index < 0)
    {
        printf("\nERROR: Patient record not found!\n");
    }
    else
    {
        menuPatientEdit(&patient[index]);
    }
}

// Remove a patient record from the patient array
// (Copy your code from MS#2)
void removePatient(struct Patient patient[], int max)
{
    int patientID, index;
    char choice;
    printf("Enter the patient number: ");
    // getting patient id as input
    patientID = inputIntPositive();
    index = findPatientIndexByPatientNum(patientID, patient, max);
    if (index < 0)
    {
        printf("\nERROR: Patient record not found!\n\n");
    }
    else
    {
        putchar('\n');
        // displaying patient data
        displayPatientData(&patient[index], FMT_FORM);
        putchar('\n');
        printf("Are you sure you want to remove this patient record? (y/n): ");
        choice = !(inputCharOption("yn") == 'n');
        if (choice)
        {
            // reseting patient data
            patient[index].patientNumber = 0;
            strcpy(patient[index].name, "\0");
            strcpy(patient[index].phone.number, "\0");
            strcpy(patient[index].phone.description, "\0");
            printf("Patient record has been removed!");
        }
        else if (!choice)
        {
            printf("Operation aborted.");
        }
        putchar('\n');
        putchar('\n');
    }
}

// !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
// Milestone #3 mandatory functions...
// !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
// sort
void sort(struct Appointment appoints[], int max)
{
    int i, j;
    struct Appointment temp;
    for (i = 0; i < max; i++)
    {
        //converting year, month, day, hours, minutes to minutes
        appoints[i].time.min = (appoints[i].date.year * 12 * 30 * 24 * 60) + (appoints[i].date.month * 30 * 24 * 60) + (appoints[i].date.day * 24 * 60) + (appoints[i].time.hour * 60) + appoints[i].time.min;
    }

    // comparing and swaping
    for (i = max - 1; i > 0; i--)
    {
        for (j = 0; j < i; j++)
        {
            if (appoints[j].time.min > appoints[j + 1].time.min)
            {
                temp = appoints[j];
                appoints[j] = appoints[j + 1];
                appoints[j + 1] = temp;
            }
        }
    }

    // Converting back to year, month, day, hours, minutes
    for (i = 0; i < max; i++)
    {
        appoints[i].time.min = appoints[i].time.min - (appoints[i].date.year * 12 * 30 * 24 * 60) - (appoints[i].date.month * 30 * 24 * 60) - (appoints[i].date.day * 24 * 60) - (appoints[i].time.hour * 60);
    }
}

// View ALL scheduled appointments
// Todo:
void viewAllAppointments(struct ClinicData *data)
{
    int i, j;
    sort(data->appointments, data->maxAppointments);
    displayScheduleTableHeader(NULL, ALL_REC);
    for (i = 0; i < data->maxAppointments; i++)
    {
        for (j = 0; j < data->maxPatient; j++)
        {
            //matching patient with appointment by comparing patientNumber of both patient and appointment
            if (data->appointments[i].patientNumber == data->patients[j].patientNumber)
            {
                displayScheduleData(&data->patients[j], &data->appointments[i], 1);
            }
        }
    }
    putchar('\n');
}

// View appointment schedule for the user input date
// Todo:
void viewAppointmentSchedule(struct ClinicData *data)
{
    struct Date date;
    int last, i, j;
    printf("Year        : ");
    date.year = inputIntPositive();
    printf("Month (1-12): ");
    date.month = inputIntRange(1, 12);
    //getting last day of the month
    last = getLastDay(date.year, date.month);
    printf("Day (%d-%d)  : ", 1, last);

 
    date.day = inputIntRange(1, last);
    printf("\n");
    //sorting appointment data by date
    sort(data->appointments, data->maxAppointments);
    displayScheduleTableHeader(&date, 0);
    for (i = 0; i < data->maxAppointments; i++)
    {
        for (j = 0; j < data->maxPatient; j++)
        {
            if (data->appointments[i].patientNumber == data->patients[j].patientNumber)
            {
                if (data->appointments[i].date.year == date.year && data->appointments[i].date.month == date.month && data->appointments[i].date.day == date.day)
                {
                    displayScheduleData(&data->patients[j], &data->appointments[i], 0);
                }
            }
        }
    }
    putchar('\n');
}


// Add an appointment record to the appointment array
// Todo:
void addAppointment(struct Appointment *appoints, int maxAppointments, struct Patient *patient, int maxPatients)
{
    struct Date date;
    struct Time time;
    int patientNum, index, lastDate, i, flag = 1;
    printf("Patient Number: ");
    patientNum = inputIntPositive();
    index = findPatientIndexByPatientNum(patientNum, patient, maxPatients);
    if (index > 0)
    {
        do
        {
            flag = 1;
            printf("Year        : ");
            date.year = inputIntPositive();
            printf("Month (%d-%d): ", 1, 12);
            date.month = inputIntRange(1, 12);
            //getting last day of the month
            lastDate = getLastDay(date.year, date.month);
            printf("Day (%d-%d)  : ", 1, lastDate);
            date.day = inputIntRange(1, lastDate);

            //checks and gets valid time as input 
            time = getAppointmentTime(date);

            for (i = 0; i < maxAppointments; i++)
            {
                if ((date.year == appoints[i].date.year && date.month == appoints[i].date.month && date.day == appoints[i].date.day && time.hour == appoints[i].time.hour && time.min == appoints[i].time.min))
                {
                    flag = 0;
                }
            }
            if (flag == 0)
            {
                printf("\nERROR: Appointment timeslot is not available!\n\n");
            }
        } while (flag == 0);
        // Assigning the values to the next available slot
        index = nextSlotAvailable(appoints, maxAppointments);
        appoints[index].date = date;
        appoints[index].time = time;
        appoints[index].patientNumber = patientNum;
        printf("\n*** Appointment scheduled! ***\n");
    }
    else {
        printf("\nERROR: Patient record not found!\n\n");
    }
    putchar('\n');
}
// Remove an appointment record from the appointment array
// Todo:
void removeAppointment(struct Appointment *appoints, int maxAppointments, struct Patient *patient, int maxPatients)
{
    struct Date date;
    int patientNum, index, lastDate, i, appointIndex = 0;
    printf("Patient Number: ");
    patientNum = inputIntPositive();

    //finds and gets index of the patient by patient num
    index = findPatientIndexByPatientNum(patientNum, patient, maxPatients);
    if (index >= 0)
    {
        printf("Year        : ");
        date.year = inputIntPositive();
        printf("Month (%d-%d): ", 1, 12);
        date.month = inputIntRange(1, 12);

        //getting last day of the month
        lastDate = getLastDay(date.year, date.month);
        printf("Day (%d-%d)  : ", 1, lastDate);
        date.day = inputIntRange(1, lastDate);
        for (i = 0; i < maxAppointments; i++)
        {
            if ((appoints[i].patientNumber == patientNum) && (appoints[i].date.day == date.day) && (appoints[i].date.month == date.month) && (appoints[i].date.year == date.year))
            {
                appointIndex = i;
            }
        }
        putchar('\n');
        if (appointIndex >= 0)
        {

            displayPatientData(&patient[index], FMT_FORM);
            printf("Are you sure you want to remove this appointment (y,n): ");
            if (inputCharOption("yn") == 'y')
            {
                //deleting recored by changeing patientNumber to zero
                appoints[appointIndex].patientNumber = 0;
                printf("\nAppointment record has been removed!\n\n");
            }

            else
            {
                printf("ERROR: No appointment for this date!\n\n");
            }
        }
    }
    else
    {
        printf("ERROR: Patient record not found!\n\n");
    }
}
//Gets next appointment slot
int nextSlotAvailable(struct Appointment* app, int maxAppointments) {
    int i = 0, available = 0;
    while (available == 0 && i < maxAppointments) {
        if (app[i].patientNumber < 1) {
            available = 1;
        }
        i++;
    }
    return i;
}
// Get appointment time
struct Time getAppointmentTime(struct Date date)
{
    struct Time time;
    int flag = 1;
    do
    {
        printf("Hour (%d-%d)  : ", 0, 23);
        time.hour = inputIntRange(0, 23);
        printf("Minute (%d-%d): ", 0, 59);
        time.min = inputIntRange(0, 59);
        if ((time.hour < APPOINT_START || time.hour > APPOINT_END) || (time.hour == APPOINT_END && time.min > 0) || (time.min % INTERVAL != 0))
        {
            printf("ERROR: Time must be between %02d:00 and %02d:00 in %02d minute intervals.\n\n", APPOINT_START, APPOINT_END, INTERVAL);
            flag = 0;
        }
        else
        {
            flag = 1;
        }
    } while (flag == 0);
    return time;
}
//////////////////////////////////////
// UTILITY FUNCTIONS
//////////////////////////////////////

// Search and display patient record by patient number (form)
// (Copy your code from MS#2)
void searchPatientByPatientNumber(const struct Patient patient[], int max)
{
    int patientID, index;
    printf("Search by patient number: ");
    // getting patientID as positive integer using a function
    patientID = inputIntPositive();
    putchar('\n');
    index = findPatientIndexByPatientNum(patientID, patient, max);
    if (index >= 0)
    {
        // if index is greater than 0 displaying patient data
        displayPatientData(&patient[index], FMT_FORM);
    }
    else
    {
        printf("*** No records found ***\n");
    }
    putchar('\n');
    printf("<ENTER> to continue...");
    getchar();
    putchar('\n');
}

// Search and display patient records by phone number (tabular)
// (Copy your code from MS#2)
void searchPatientByPhoneNumber(const struct Patient patient[], int max)
{
    int i, found = 0;
    char phoneNumber[PHONE_LEN] = {'\0'};
    printf("Search by phone number: ");
    inputCString(phoneNumber, 10, 10);
    putchar('\n');
    displayPatientTableHeader();
    for (i = 0; i < max; i++)
    {

        if (strcmp(patient[i].phone.number, phoneNumber) == 0)
        {
            displayPatientData(&patient[i], FMT_TABLE);
            // using found flag to determine if the patient data is found or not
            found = 1;
        }
    }
    if (!found)
    {
        printf("\n*** No records found ***\n");
    }
    putchar('\n');
    printf("<ENTER> to continue...");
    getchar();
    putchar('\n');
}

// Get the next highest patient number
// (Copy your code from MS#2)
int nextPatientNumber(const struct Patient patient[], int max)
{
    int largestNumber, i;
    largestNumber = patient[0].patientNumber;
    for (i = 0; i < max; i++)
    {
        if (patient[i].patientNumber > largestNumber)
        {
            largestNumber = patient[i].patientNumber;
        }
    }
    // returning largest number + 1 value
    return largestNumber + 1;
}

// Find the patient array index by patient number (returns -1 if not found)
// (Copy your code from MS#2)
int findPatientIndexByPatientNum(int patientNumber,
                                 const struct Patient patient[], int max)
{
    int i;
    for (i = 0; i < max; i++)
    {
        if (patientNumber == patient[i].patientNumber)
        {
            return i;
        }
    }
    return -1;
}

//////////////////////////////////////
// USER INPUT FUNCTIONS
//////////////////////////////////////

// Get user input for a new patient record
// (Copy your code from MS#2)
void inputPatient(struct Patient *patient)
{
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
// (Copy your code from MS#2)
void inputPhoneData(struct Phone *phone)
{
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
    // using swtich case to select the phone type
    switch (choice)
    {
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

    if (choice >= 1 && choice <= 3)
    {
        printf("\nContact: %s\n"
               "Number : ",
               phone->description);
        // using inputCString to get the phone number
        inputCString(phone->number, 10, 10);
    }
    putchar('\n');
}

//////////////////////////////////////
// FILE FUNCTIONS
//////////////////////////////////////

// Import patient data from file into a Patient array (returns # of records read)
/// ToDo:
int importPatients(const char *datafile, struct Patient patients[], int max)
{
    FILE *fp;
    int i = 0;
    fp = fopen(datafile, "r");
    if (fp != NULL)
    {
        while (fscanf(fp, "%d|%[^|]|%[^|]|%[^\n]", &patients[i].patientNumber, patients[i].name, patients[i].phone.description, patients[i].phone.number) != EOF && i < max)
        {
            i++;
        }
        fclose(fp);
    }
    else
    {
        printf("ERROR: File could not be read\n");
    }
    return i;
}

// Import appointment data from file into an Appointment array (returns # of records read)
// ToDo:
int importAppointments(const char *datafile, struct Appointment appoints[], int max)
{
    FILE *fp;
    int i = 0;
    fp = fopen(datafile, "r");
    if (fp != NULL)
    {
        while (fscanf(fp, "%d,%d,%d,%d,%d,%d", &appoints[i].patientNumber, &appoints[i].date.year, &appoints[i].date.month, &appoints[i].date.day, &appoints[i].time.hour, &appoints[i].time.min) != EOF && i <= max)
        {
            i++;
        }
        fclose(fp);
    }
    else
    {
        printf("ERROR: File could not be read\n");
    }
    return i;
}