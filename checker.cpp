// ConsoleApplication3.cpp : This file contains the 'main' function. Program execution begins and ends there.
//


#include <iostream>

#include <assert.h>

using namespace std;

float MinBPM[] = { 70 };
float MaxBPM[] = { 150 };
float MinSpo2[] = { 90 };
float MinRespRate[] = { 30 };
float MaxRespRate[] = { 95 };

class Alert
{
public:
	virtual void SendAlert(const char* vitalName, const char* Message) = 0;
};
class SmsAlert : public Alert
{
public:
	void SendAlert(const char* vitalName, const char* Message)
	{
		std::cout << vitalName << ": " << Message << endl;
	}
};
class SoundAlert : public Alert
{
public:
	void SendAlert(const char* vitalName, const char* Message)
	{
		std::cout << vitalName << ": " << Message << endl;
	}
};


void checkRespRate(Alert *alert, float value)
{
	if (value < MinRespRate[0])
		alert->SendAlert("Respiration Rate", "is lower");
	else if (value > MaxRespRate[0])
		alert->SendAlert("Respiration Rate", "is higher ");
	else
		alert->SendAlert("Respiration Rate", "is normal");
}

void checkSpo2(Alert *alert, float value)
{
	if (value < MinSpo2[0])
		alert->SendAlert("Spo2", "is less than minimum.");
	else
		alert->SendAlert("Spo2", "is normal");
}

void checkBPM(Alert *alert, float value)
{
	if (value < MinBPM[0])
		alert->SendAlert("BPM", "Below minimum ");
	else if (value > MaxBPM[0])
		alert->SendAlert("BPM", "Higher ");
	else
		alert->SendAlert("BPM", "is normal");
}
void checkAllVitals(float bpm, float spo2, float respRate)
{
	Alert *alert = new SmsAlert();

	checkBPM(alert, bpm);
	checkRespRate(alert, respRate);
	checkSpo2(alert, spo2);
}


int main()
{
	float BPMValues[] = { 10.0, 20.0 };
	float Spo2Values[] = { 90.0, 10.0 };
	float RespRateValues[] = { 33.0, 72.0 };
	checkAllVitals(BPMValues[0], Spo2Values[0], RespRateValues[0]);
	return 0;
}


// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file

