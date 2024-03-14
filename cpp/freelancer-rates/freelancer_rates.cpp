#include <cmath>

// daily_rate calculates the daily rate given an hourly rate
double daily_rate(double hourly_rate) {
    //day has 8 hours
    return 8 * hourly_rate;
}

// apply_discount calculates the price after a discount
//discount percent is 25% == 25.0
double apply_discount(double before_discount, double discount) {
    return before_discount * (100-discount) / 100;
}

// monthly_rate calculates the monthly rate, given an hourly rate and a discount
// The returned monthly rate is rounded up to the nearest integer.
int monthly_rate(double hourly_rate, double discount) {
    //A month has 22 billable days
    return std::ceil(apply_discount(daily_rate(hourly_rate) * 22, discount));
}

// days_in_budget calculates the number of workdays given a budget, hourly rate,
// and discount The returned number of days is rounded down (take the floor) to
// the next integer.
int days_in_budget(int budget, double hourly_rate, double discount) {
    //conversion to int automatically takes floor
    return budget / ((int)apply_discount(daily_rate(hourly_rate), discount));
}