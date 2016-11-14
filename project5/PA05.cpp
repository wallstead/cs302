#include <iostream>
#include <string>
#include <fstream>
#include "Merge.h"
#include "ArrayQueue.h"
#include "SortedList.h"
#include "PriorityQueue.h"

using namespace std;

void populateFile(int count, std::string const& file);

struct Event {
    char type;
    int startTime;
    int duration;
    int endTime;

    bool operator > (const Event &rhs ) const {
        if (startTime > rhs.startTime) {
            return true;
        } else {
            return false;
        }
    }

    bool operator != (const Event &rhs ) const {
        if (startTime != rhs.startTime) {
            return true;
        } else {
            return false;
        }
    }
};

int main() {

    /* Prep rand-num generator */
    srand( time( NULL ) );

    /* Populate the file with start times */
    std::string hundredThousand("events_100,000");
    populateFile(99999, hundredThousand);

    ArrayQueue<Event> bankLine;

    SortedList<int> foo;
    int bar1 = 1;
    foo.insertSorted(bar1);
    int bar2 = 3;
    foo.insertSorted(bar2);
    int bar3 = 2;
    foo.insertSorted(bar3);
    // cout << foo.getPosition(bar2) << endl;

    Event event_1;
    event_1.startTime = 0;
    Event event_2;
    event_2.startTime = 2;
    Event event_3;
    event_3.startTime = 1;



    PriorityQueue<Event> bar;
    bar.enqueue(event_1);
    bar.enqueue(event_2);
    bar.enqueue(event_3);
    cout << bar.peek().startTime << endl;
    // bar.enqueue(1);
    // bar.enqueue(2);
    // bar.enqueue(0);
    //

    bar.dequeue();
    cout << bar.peek().startTime << endl;
    bar.dequeue();
    cout << bar.isEmpty() << endl;


    // ArrayQueue<Event> eventPriorityQueue;

    /* Read file into eventPriorityQueue array */
    Event events[99999];
    ifstream hundredThousandFile("events_100,000");
    if (hundredThousandFile.is_open()) {
        int startTime;
        int duration;
        int counter = 0;
        while(hundredThousandFile >> startTime >> duration) {
            Event event;
            event.startTime = startTime;
            event.duration = duration;
            events[counter] = event; // add it to array

            // cout << event.startTime << " | " << event.duration << endl; // DEBUG ONLY
            // eventPriorityQueue.enqueue(event);

            counter++;
        }
        hundredThousandFile.close();
    } else {
        cout << "Cannot open hundred thousand integer file";
    }

    bool tellerAvailable = true;




    return 0;
}

void populateFile(int count, std::string const& file) {
    std::ofstream myfile(file);
    if (!myfile) {
       return;
    }

    /* Populate the array with random start times */
    int randArr[99999];
    for(int index = 0; index < count; index++) {
        int random_start = (rand()%100000); // from 0 to 100000
        randArr[index] = random_start;
    }

    /* Sort array by start time */
    Merge merge = Merge(randArr, 99999); // sort random array using merge sort
    merge.sort(0, 99999-1);

    /* Put values in file along with random durations for each */
    for(int index = 0; index < count; index++) {
        int random_duration = (rand()%100)+1; // from 1 to 100
        myfile << merge.data[index] << " " << random_duration << "\n";
    }
}
