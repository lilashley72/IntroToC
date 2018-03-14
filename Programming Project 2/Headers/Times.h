/*
 * COP 2334
 * Created by Kevin Patlis, [name], [name]
 * Date Due: 4/23/18
 */
#ifndef PROGRAMMING_PROJECT_2_TIMES_H
#define PROGRAMMING_PROJECT_2_TIMES_H

class Times {
    // Declare 3 functions that deal with the time of departure and total days spent on trip.
public:
    int     daysSpent();
    void    times(double&, double&);
private:
    bool    isValidTime(double);
};


#endif //PROGRAMMING_PROJECT_2_TIMES_H
