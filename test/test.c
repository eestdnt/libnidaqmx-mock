#include "nidaqmx.h"
#include <assert.h>
#include <stdio.h>
#include <stdlib.h>
#include <unity/unity.h>

char *str = NULL;
TaskHandle task = NULL;
float64 float64_var;
int32 int32_var = 0;
bool32 bool32_var = 0;
uInt32 uint32_var = 0;
void *dat = NULL;

void setUp(void) {}

void tearDown(void) {}

void test_DAQmxGetErrorString()
{
  int r = DAQmxGetErrorString(0, str, 0);
  TEST_ASSERT_EQUAL_INT(0, r);
}

void test_DAQmxCreateTask()
{
  int r = DAQmxCreateTask(str, task);
  TEST_ASSERT_EQUAL_INT(0, r);
}

void test_DAQmxClearTask()
{
  int r = DAQmxClearTask(task);
  TEST_ASSERT_EQUAL_INT(0, r);
}

void test_DAQmxCreateAIVoltageChan()
{
  int r = DAQmxCreateAIVoltageChan(task, str, str, 0, 0.0, 0.0, 0, str);
  TEST_ASSERT_EQUAL_INT(0, r);
}

void test_DAQmxGetDevAIVoltageRngs()
{
  int r = DAQmxGetDevAIVoltageRngs(str, &float64_var, 0);
  TEST_ASSERT_EQUAL_INT(0, r);
}

void test_DAQmxCreateAOVoltageChan()
{
  int r = DAQmxCreateAOVoltageChan(task, str, str, 0.0, 0.0, 0, str);
  TEST_ASSERT_EQUAL_INT(0, r);
}

void test_DAQmxCfgSampClkTiming()
{
  int r = DAQmxCfgSampClkTiming(task, str, 0.0, 0, 0, 0);
  TEST_ASSERT_EQUAL_INT(0, r);
}

void test_DAQmxCfgDigEdgeStartTrig()
{
  int r = DAQmxCfgDigEdgeStartTrig(task, str, 0);
  TEST_ASSERT_EQUAL_INT(0, r);
}

void test_DAQmxWriteAnalogF64()
{
  int r = DAQmxWriteAnalogF64(task, 0, 0, 0.0, 0, (float64 *)dat, &int32_var,
                              &bool32_var);
  TEST_ASSERT_EQUAL_INT(0, r);
}

void test_DAQmxReadAnalogF64()
{
  int32 dat_size = 10;
  dat = malloc(dat_size * sizeof(float64));
  int r = DAQmxReadAnalogF64(task, 0, 0.0, 0, (float64 *)dat, dat_size,
                             &int32_var, &bool32_var);
  TEST_ASSERT_EQUAL_INT(0, r);
  free(dat);
}

void test_DAQmxStartTask()
{
  int r = DAQmxStartTask(task);
  TEST_ASSERT_EQUAL_INT(0, r);
}

void test_DAQmxStopTask()
{
  int r = DAQmxStopTask(task);
  TEST_ASSERT_EQUAL_INT(0, r);
}

void test_DAQmxResetDevice()
{
  int r = DAQmxResetDevice("");
  TEST_ASSERT_EQUAL_INT(0, r);
}

void test_DAQmxGetTaskNumChans()
{
  int r = DAQmxGetTaskNumChans(task, &uint32_var);
  TEST_ASSERT_EQUAL_INT(0, r);
  TEST_ASSERT_EQUAL_INT(2, uint32_var);
}

int main()
{
  UNITY_BEGIN();

  RUN_TEST(test_DAQmxGetErrorString);
  RUN_TEST(test_DAQmxCreateTask);
  RUN_TEST(test_DAQmxClearTask);
  RUN_TEST(test_DAQmxCreateAIVoltageChan);
  RUN_TEST(test_DAQmxGetDevAIVoltageRngs);
  RUN_TEST(test_DAQmxCreateAOVoltageChan);
  RUN_TEST(test_DAQmxCfgSampClkTiming);
  RUN_TEST(test_DAQmxCfgDigEdgeStartTrig);
  RUN_TEST(test_DAQmxWriteAnalogF64);
  RUN_TEST(test_DAQmxReadAnalogF64);
  RUN_TEST(test_DAQmxStartTask);
  RUN_TEST(test_DAQmxStopTask);
  RUN_TEST(test_DAQmxResetDevice);
  RUN_TEST(test_DAQmxGetTaskNumChans);

  return UNITY_END();
}
