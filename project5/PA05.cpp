#include <iostream>
#include <string>
#include <fstream>
#include "Merge.h"
#include "ArrayQueue.h"
#include "PriorityQueue.h"

using namespace std;

struct Event {
    char type; // A: Arrival, D: Departure
    int startTime;
    int duration;

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

void populateFile(int, string const&);
void processArrival(Event, PriorityQueue<Event> &, ArrayQueue<Event> &, bool &, int);

int main() {

    /* Prep rand-num generator */
    srand( time( NULL ) );

    /* Populate the file with start times */
    std::string hundredThousand("events_100,000");
    populateFile(99999, hundredThousand);

    /* Initialize two queues */
    ArrayQueue<Event> bankLine;
    PriorityQueue<Event> eventPriorityQueue;

    /* Read file into eventPriorityQueue */
    Event events[99999];
    ifstream hundredThousandFile("events_100,000");
    if (hundredThousandFile.is_open()) {
        int startTime;
        int duration;
        int counter = 0;
        while(hundredThousandFile >> startTime >> duration) {
            Event newEvent;
            newEvent.type = 'A';
            newEvent.startTime = startTime;
            newEvent.duration = duration;
            // events[counter] = newEvent; // add it to array

            cout << newEvent.type << " | " << newEvent.startTime << " | " << newEvent.duration << endl; // DEBUG ONLY

            eventPriorityQueue.enqueue(newEvent);

            counter++;
        }
        hundredThousandFile.close();
    } else {
        cout << "Cannot open hundred thousand integer file";
    }
    bool tellerAvailable = true;







    Event event_0;
    event_0.type = 'A';
    event_0.startTime = -1;
    event_0.duration = 1;










    cout << eventPriorityQueue.peek().startTime << endl;
    eventPriorityQueue.dequeue();
    cout << eventPriorityQueue.peek().startTime << endl;
    eventPriorityQueue.enqueue(event_0);
    cout << eventPriorityQueue.peek().startTime << endl;

    // while (!eventPriorityQueue.isEmpty()) { // until event queue is empty
    //     Event newEvent = eventPriorityQueue.peek();
    //     int currentTime = newEvent.startTime;
    //
    //     if (newEvent.type == 'A') { // Arrival
    //         // processArrival(newEvent, eventPriorityQueue, bankLine, tellerAvailable, currentTime);
    //
    //         eventPriorityQueue.dequeue(); // remove the event from the event queue
    //         if (bankLine.isEmpty() && tellerAvailable) {
    //             cout << "empty and available" << endl;
    //             int endTime = currentTime + newEvent.duration;
    //
    //             cout << endTime << endl;
    //             Event newDepartureEvent;
    //             newDepartureEvent.type = 'A';
    //             newDepartureEvent.startTime = endTime;
    //             eventPriorityQueue.enqueue(newDepartureEvent);
    //             tellerAvailable = false;
    //         } else {
    //             bankLine.enqueue(newEvent); // add event of the customer to the line
    //         }
    //     } else { // Departure
    //         cout << "NOT implementated" << endl;
    //     }
    // }





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

void processArrival(Event event, PriorityQueue<Event> &eventQueue
                               , ArrayQueue<Event> &bankLine
                               , bool &tellerAvailable
                               , int currentTime) {
    eventQueue.dequeue(); // remove the event from the event queue
    if (bankLine.isEmpty() && tellerAvailable) {
        cout << "empty and available" << endl;
        int endTime = currentTime + event.duration;


        Event newDepartureEvent;
        newDepartureEvent.type = 'D';
        newDepartureEvent.startTime = endTime;
        eventQueue.enqueue(newDepartureEvent);
        tellerAvailable = false;
    } else {
        bankLine.enqueue(event); // add event of the customer to the line
    }

    cout << "got ehre " << endl;

}
