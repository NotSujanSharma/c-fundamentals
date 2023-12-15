/*/////////////////////////////////////////////////////////////////////////
                                                  Workshop - #A1 (MS03)

                                                  DISCLAIMER

This Work is only for educational purpose, any student who comes across this
work is not permitted to copy this work. AGAIN Any student who comes across these
documents is warned NOT TO USE these as their homework as it is plagiarism and
a clear violation of Seneca's Academic Integrity!

/////////////////////////////////////////////////////////////////////////*/

#include <stdio.h>

#include "clinic.h"

#define MAX_PETS 20
#define MAX_APPOINTMENTS 50

int main(void)
{
    struct Patient pets[MAX_PETS] = { {0} };
    struct Appointment appoints[MAX_APPOINTMENTS] = { {0} };
    struct ClinicData data = { pets, MAX_PETS, appoints, MAX_APPOINTMENTS };

    int patientCount = importPatients("patientData.txt", pets, MAX_PETS);
    int appointmentCount = importAppointments("appointmentData.txt", appoints, MAX_APPOINTMENTS);

    printf("Imported %d patient records...\n", patientCount);
    printf("Imported %d appointment records...\n\n", appointmentCount);

    menuMain(&data);
    
    return 0;
}