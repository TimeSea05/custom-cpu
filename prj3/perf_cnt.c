#include "perf_cnt.h"

unsigned long _uptime() {
  // TODO [COD]
  // You can use this function to access performance counter related with time or cycle.
  volatile unsigned int* perf_cnt_0_addr = (void*)0x60010000;
  return *perf_cnt_0_addr;
}

void bench_prepare(Result *res) {
  // TODO [COD]
  //   Add preprocess code, record performance counters' initial states.
  //   You can communicate between bench_prepare() and bench_done() through
  //   static variables or add additional fields in `struct Result`
  res->msec = _uptime();
}

void bench_done(Result *res) {
  // TODO [COD]
  //  Add postprocess code, record performance counters' current states.
  res->msec = _uptime() - res->msec;
}

