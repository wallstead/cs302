#include <iostream>
#include <string>
#include <fstream>
#include "Merge.h"
#include "ArrayQueue.h"

using namespace std;

void populateFile(int count, std::string const& file);

struct Event {
    int startTime;
    int duration;
    int endTime;
};

int main() {

    /* Prep rand-num generator */
    srand( time( NULL ) );

    /* Populate the file with start times */
    std::string hundredThousand("events_100,000");
    populateFile(99999, hundredThousand);


    ArrayQueue<Event> line;

    /* Read file into an events array */
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

            cout << event.startTime << " | " << event.duration << endl; // DEBUG ONLY
            line.enqueue(event);
            //
            cout << line.peekFront().duration << endl;

            counter++;
        }
        hundredThousandFile.close();
    } else {
        cout << "Cannot open hundred thousand integer file";
    }


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
