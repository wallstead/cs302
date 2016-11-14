#include <iostream>
#include <string>
#include <fstream>
#include "Merge.h"
#include "ArrayQueue.h"
#include "PriorityQueue.h"

using namespace std;

void populateFile(int count, std::string const& file);

struct Event {
    char type;
    int startTime;
    int duration;
    int endTime;

    bool operator > (const Event &rhs ) const {
        if (startTime < rhs.startTime) {
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

    /* Initialize two queues */
    ArrayQueue<Event> bankLine;
    PriorityQueue<Event> eventPriorityQueue;

    /* Read file into eventPriorityQueue array */
    Event events[99999];
    ifstream hundredThousandFile("events_100,000");
    if (hundredThousandFile.is_open()) {
        int startTime;
        int duration;
        int counter = 0;
        while(hundredThousandFile >> startTime >> duration) {
            Event event;
            event.type = 'A';
            event.startTime = startTime;
            event.duration = duration;
            events[counter] = event; // add it to array

            cout << event.type << " | " << event.startTime << " | " << event.duration << endl; // DEBUG ONLY

            eventPriorityQueue.enqueue(event);

            counter++;
        }
        hundredThousandFile.close();
    } else {
        cout << "Cannot open hundred thousand integer file";
    }

    cout << eventPriorityQueue.peek().startTime << endl;
    eventPriorityQueue.dequeue();
    cout << eventPriorityQueue.peek().startTime << endl;
    eventPriorityQueue.dequeue();
    cout << eventPriorityQueue.peek().startTime << endl;
    eventPriorityQueue.dequeue();
    cout << eventPriorityQueue.peek().startTime << endl;

    // Event event_0;
    // event_0.startTime = 26;
    //
    // Event event_1;
    // event_1.startTime = 50;
    //
    // Event event_2;
    // event_2.startTime = 25;
    //
    // PriorityQueue<Event> eventPriorityQueueTest;
    // eventPriorityQueueTest.enqueue(event_0);
    // eventPriorityQueueTest.enqueue(event_1);
    // eventPriorityQueueTest.enqueue(event_2);
    //
    // cout << eventPriorityQueueTest.peek().startTime << endl;

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
