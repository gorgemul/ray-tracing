#include "interval.h"

bool interval_contains(Interval *interval, double n)
{
    return interval->min <= n && n <= interval->max;
}

bool interval_surrounds(Interval *interval, double n)
{
    return interval->min < n && n < interval->max;
}
