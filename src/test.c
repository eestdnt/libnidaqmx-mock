#include <stdio.h>
#include <assert.h>
#include "nidaqmx.h"

int main()
{
    char* str = NULL;
    TaskHandle task = NULL;
    int r = 0;
    float64 float64_var;
    int32 int32_var = 0;
    uInt32* uint32_data = NULL;
    bool32 bool32_var = 0;

    assert((r = DAQmxGetErrorString(0, str, 0)) == 0);
    assert((r = DAQmxCreateTask(str, task)) == 0);
    assert((r = DAQmxClearTask(task)) == 0);
    assert((r = DAQmxCreateAIVoltageChan(task, str, str, 0, 0.0, 0.0, 0, str)) == 0);
    assert((r = DAQmxGetDevAIVoltageRngs(str, &float64_var, 0)) == 0);
    assert((r = DAQmxCreateAOVoltageChan(task, str, str, 0.0, 0.0, 0, str)) == 0);
    assert((r = DAQmxCfgSampClkTiming(task, str, 0.0, 0, 0, 0)) == 0);
    assert((r = DAQmxCfgDigEdgeStartTrig(task, str, 0)) == 0);
    assert((r = DAQmxWriteAnalogF64(task, 0, 0, 0.0, 0, &float64_var, &int32_var, &bool32_var)) == 0);
    assert((r = DAQmxStartTask(task)) == 0);
    assert((r = DAQmxStopTask(task)) == 0);
    assert((r = DAQmxGetTaskNumChans(task, uint32_data)) == 0);
    assert((r = DAQmxReadAnalogF64(task, 0, 0.0, 0, &float64_var, 0, &int32_var, &bool32_var)) == 0);

    printf("All tests passed!\n");

    return 0;
}
