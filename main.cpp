
#include <windows.h>
#include <mmsystem.h>

using namespace std;

int main()
{

	//Interval between alert sounds in milliseconds
	int alertInterval = 1000;
	//Time for the program to stay idle in milliseconds
	int sleepInterval = 500;

	//Setting the battery percentage limit
	int batteryPercentageLimit = 11;

	//Declaring variable batteryStatus
	SYSTEM_POWER_STATUS batteryStatus;

	while(true)
	{
		//Check whether system is on AC or DC
		GetSystemPowerStatus(&batteryStatus);

		//Reading the battery charging status from the system
		int chargingStatus = batteryStatus.ACLineStatus;

		//Reading the current battery percentage from the system
		int batteryPercentage = batteryStatus.BatteryLifePercent;

		//ALARM LOOP
		if (chargingStatus == true && batteryPercentage >= batteryPercentageLimit)
		{
			PlaySound(TEXT("alert.wav"), NULL, SND_SYNC);
			Sleep(alertInterval);
		}

        Sleep(sleepInterval);

	}

	return 0;
}
