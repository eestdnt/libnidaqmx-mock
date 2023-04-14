#include <string.h>
#include "nidaqmx.h"

int32 DAQmxGetErrorString (int32 errorCode, char errorString[], uInt32 bufferSize)
{
    return 0;
}

int32 DAQmxCreateTask (const char taskName[], TaskHandle *taskHandle)
{
    return 0;
}

int32 DAQmxClearTask (TaskHandle taskHandle)
{
    return 0;
}

int32 DAQmxCreateAIVoltageChan (TaskHandle taskHandle, const char physicalChannel[], const char nameToAssignToChannel[], int32 terminalConfig, float64 minVal, float64 maxVal, int32 units, const char customScaleName[])
{
    return 0;
}

int32 DAQmxGetDevAIVoltageRngs(const char device[], float64 *data, uInt32 arraySizeInSamples)
{
    return 0;
}

int32 DAQmxCreateAOVoltageChan (TaskHandle taskHandle, const char physicalChannel[], const char nameToAssignToChannel[], float64 minVal, float64 maxVal, int32 units, const char customScaleName[])
{
    return 0;
}

int32 DAQmxCfgSampClkTiming (TaskHandle taskHandle, const char source[], float64 rate, int32 activeEdge, int32 sampleMode, uInt64 sampsPerChanToAcquire)
{
    return 0;
}

int32 DAQmxCfgDigEdgeStartTrig (TaskHandle taskHandle, const char triggerSource[], int32 triggerEdge)
{
    return 0;
}

int32 DAQmxWriteAnalogF64 (TaskHandle taskHandle, int32 numSampsPerChan, bool32 autoStart, float64 timeout, bool32 dataLayout, const float64 writeArray[], int32 *sampsPerChanWritten, bool32 *reserved)
{
    return 0;
}

int32 DAQmxStartTask (TaskHandle taskHandle)
{
    return 0;
}

int32 DAQmxStopTask (TaskHandle taskHandle)
{
    return 0;
}

int32 DAQmxGetTaskNumChans(TaskHandle taskHandle, uInt32 *data)
{
    *data = 2;
    return 0;
}

int32 DAQmxReadAnalogF64 (TaskHandle taskHandle, int32 numSampsPerChan, float64 timeout, bool32 fillMode, float64 readArray[], uInt32 arraySizeInSamps, int32 *sampsPerChanRead, bool32 *reserved)
{
    *sampsPerChanRead = numSampsPerChan;
    memset(readArray, 0, arraySizeInSamps * sizeof(float64));
    return 0;
}
