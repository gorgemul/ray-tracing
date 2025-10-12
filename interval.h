#ifndef INTERVAL_H_
#define INTERVAL_H_

#include <stdbool.h>

typedef struct {
    double min;
    double max;
} Interval;

bool interval_contains(Interval *interval, double n);
bool interval_surrounds(Interval *interval, double n);

#endif // INTERVAL_H_
