#pragma once

#define N 65536
#define K 16
#include "ap_fixed.h"

typedef ap_ufixed<32, 20> DataType;

void topK(DataType *distances, DataType * dist, int * index);
