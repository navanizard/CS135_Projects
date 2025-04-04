/*
Author: Nava Karine Nizard
Course: CSCI-135
Instructor: Professor Tong Yi
Date: April 2, 2025
Assignment: Lab10 (Tasks A-E)

This program declares classes Time, Movie, and TimeSlot and 
functions on those objects.
*/

#include <iostream>
using namespace std;

class Time 
{
    public: 
        int h, m;
};

enum Genre {ACTION, COMEDY, DRAMA, ROMANCE, THRILLER};

class Movie 
{
    public: 
        string title;
        Genre genre; //only one genre per movie
        int duration;
};

class TimeSlot 
{
    public:
        Movie movie; //what movie
        Time startTime; //when it starts
};

void printTime(Time time);
int minutesSinceMidnight(Time time);
int minutesUntil(Time earlier, Time later);
Time addMinutes(Time time0, int min);
void printMovie(Movie mv);
void printTimeSlot(TimeSlot ts);
TimeSlot scheduleAfter(TimeSlot ts, Movie nextMovie);
bool timeOverlap(TimeSlot ts1, TimeSlot ts2); 


int main()
{
    Movie movie1 = {"Back to the Future", COMEDY, 116};
    Movie movie2 = {"Black Panther", ACTION, 134};
    Movie movie3 = {"Barbie", COMEDY, 115};
    Movie movie4 = {"The Little Mermaid", DRAMA, 127};

    TimeSlot morning = {movie1, {9, 15}}; 
    TimeSlot midMorning = {movie3, {10, 30}};
    TimeSlot daytime = {movie2, {12, 15}}; 
    TimeSlot midAfternoon = {movie4, {14, 45}};
    TimeSlot evening = {movie2, {16, 45}}; 
    printTimeSlot(morning);
    printTimeSlot(midMorning);
    printTimeSlot(daytime);
    printTimeSlot(midAfternoon);
    printTimeSlot(evening);

    printTimeSlot(scheduleAfter(evening, movie2));
    cout << boolalpha << timeOverlap(morning, midMorning);
    return 0;
}

void printTime(Time time)
{
    cout << time.h << ":" << time.m;
}

//returns the number of minutes from 0:00AM until time.
int minutesSinceMidnight(Time time)
{ 
    int hours_in_minutes = time.h * 60;
    int minutes = time.m;
    return hours_in_minutes + minutes;
}

//return the minutes between two given times
int minutesUntil(Time earlier, Time later)
{ 
    int hours_in_minutes = (later.h - earlier.h) * 60;
    int minutes = later.m - earlier.m;
    return hours_in_minutes + minutes;
}

//adds min to the time
Time addMinutes(Time time0, int min)
{
    int totalMinutes = time0.h * 60 + time0.m + min;
    time0.h = totalMinutes / 60;
    time0.m = totalMinutes % 60;
    return time0;
}

//print out the movie in format: title genre (duration)
void printMovie(Movie mv)
{
    string g;
    switch (mv.genre) {
        case ACTION   : g = "ACTION"; break;
        case COMEDY   : g = "COMEDY"; break;
        case DRAMA    : g = "DRAMA";  break;
        case ROMANCE  : g = "ROMANCE"; break;
        case THRILLER : g = "THRILLER"; break;
    }
    cout << mv.title << " " << g << " (" << mv.duration << " min)";
}

//print out the timeslot in format: movie(^) [starts at __, ends by __]
void printTimeSlot(TimeSlot ts) 
{
    printMovie(ts.movie);
    Time endTime = addMinutes(ts.startTime, ts.movie.duration);
    cout << " [starts at " << ts.startTime.h << ":" << ts.startTime.m << ", ends by " <<
        endTime.h << ":" << endTime.m << "]";
    cout << endl;
}

//return a new TimeSlot for the nextMovie, scheduled immdeately after ts.
TimeSlot scheduleAfter(TimeSlot ts, Movie nextMovie)
{
    TimeSlot newMovieTimeSlot;
    newMovieTimeSlot.movie = nextMovie;
    Time oldStartTime = ts.startTime;
    int duration = ts.movie.duration;
    int oldStartTimeInMinutes = oldStartTime.h * 60 + oldStartTime.m;
    int newStartTimeInMinutes = oldStartTimeInMinutes + duration;
    newMovieTimeSlot.startTime.h = newStartTimeInMinutes / 60;
    newMovieTimeSlot.startTime.m = newStartTimeInMinutes % 60;
    return newMovieTimeSlot;
}

//checks if 2 timeslots overlap
bool timeOverlap(TimeSlot ts1, TimeSlot ts2)
{
    int start1 = minutesSinceMidnight(ts1.startTime);
    int end1 = start1 + ts1.movie.duration;
    int start2 = minutesSinceMidnight(ts2.startTime);
    int end2 = start2 + ts2.movie.duration;
    return (start1 < end2) && (start2 < end1);
}

