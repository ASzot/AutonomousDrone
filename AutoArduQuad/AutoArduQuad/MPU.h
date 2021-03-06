#pragma once 

#include <stdint.h>

class MPU 
{
public:
	MPU();

	bool Init();

	bool UpdateCal(unsigned long dTime);
	void Update();

	double GetNS();
	double GetEW();
	double GetYaw();

	bool CheckBeyondLimits();

	void Zero();
	void ZeroYaw();

	void PrintDebugStr();

	double* YPR;
private:
	double* CalculateYPR();

private:
	double* _calibrationYPR;
	double _lastYaw;	
	uint16_t _expectedPacketSize;    // expected DMP packet size (default is 42 bytes)
	bool _dmpReady;
	int _mpuStatus;
	uint16_t _fifoCount;     // count of all bytes currently in FIFO
	unsigned long _totalSampleTime;
	double* _lastYPR;
};
