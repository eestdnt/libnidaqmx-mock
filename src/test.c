#include "nidaqmx.h"
#include <assert.h>
#include <stdio.h>
#include <stdlib.h>

int main()
{
  char *str = NULL;
  TaskHandle task = NULL;
  int r = 0;
  float64 float64_var;
  int32 int32_var = 0;
  bool32 bool32_var = 0;
  uInt32 uint32_var = 0;
  void *dat = NULL;

  assert((r = DAQmxGetErrorString(0, str, 0)) == 0);
  assert((r = DAQmxCreateTask(str, task)) == 0);
  assert((r = DAQmxClearTask(task)) == 0);
  assert((r = DAQmxCreateAIVoltageChan(task, str, str, 0, 0.0, 0.0, 0, str)) ==
         0);
  assert((r = DAQmxGetDevAIVoltageRngs(str, &float64_var, 0)) == 0);
  assert((r = DAQmxCreateAOVoltageChan(task, str, str, 0.0, 0.0, 0, str)) == 0);
  assert((r = DAQmxCfgSampClkTiming(task, str, 0.0, 0, 0, 0)) == 0);
  assert((r = DAQmxCfgDigEdgeStartTrig(task, str, 0)) == 0);
  assert((r = DAQmxWriteAnalogF64(task, 0, 0, 0.0, 0, (float64 *)dat,
                                  &int32_var, &bool32_var)) == 0);
  assert((r = DAQmxStartTask(task)) == 0);
  assert((r = DAQmxStopTask(task)) == 0);
  assert((r = DAQmxResetDevice("")) == 0);

  assert((r = DAQmxGetTaskNumChans(task, &uint32_var)) == 0);
  assert(uint32_var == 2);

  int32 dat_size = 10;
  dat = malloc(dat_size * sizeof(float64));
  assert((r = DAQmxReadAnalogF64(task, 0, 0.0, 0, (float64 *)dat, dat_size,
                                 &int32_var, &bool32_var)) == 0);

  for (int i = 0; i < dat_size; ++i) {
    printf("%.2f\n", ((float*)dat)[i]);
  }
  free(dat);

  printf("All tests passed!\n");

  return 0;
}
