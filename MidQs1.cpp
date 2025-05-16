#include <iostream>
#include <list>
#include <stack>
#include <algorithm>

using namespace std;

// Class for Reservation Request
class ReservationRequest {
public:
    int passengerID;
    int numSeats;
    string departureTime;
    string startingTerminal;

    // Constructor with zero arguments
    ReservationRequest() {}

    // Constructor with complete arguments
    ReservationRequest(int id, int seats, const string& time, const string& terminal){
        passengerID=id;
        numSeats=seats;
        departureTime=time;
        startingTerminal=terminal;
    }
};

// Class for Terminal Queue Request
class TerminalQueueRequest {
public:
    int requestID;
    int numSeats;

    // Constructor with zero arguments
    TerminalQueueRequest() {}

    // Constructor with complete arguments
    TerminalQueueRequest(int id, int seats){
        requestID=id;
        numSeats=seats;
    }
};

// Class for Terminal
class Terminal {
public:
    list<TerminalQueueRequest> waitingQueue;

    // Constructor with zero arguments
    Terminal() {}

    // Constructor with complete arguments (not needed in this case)
    Terminal(const list<TerminalQueueRequest>& queue) : waitingQueue(queue) {}
};

// Class for Quotas
class Quota {
public:
    int availableSeats;
    int reservedSeats;

    // Constructor with zero arguments
    Quota() {}

    // Constructor with complete arguments
    Quota(int available, int reserved){ 
        availableSeats=available;
        reservedSeats=reserved;
    }
};

stack<ReservationRequest> reservationStack;
Terminal terminals[6];
Quota quotas[7];

void addReservationRequest() {
    ReservationRequest request;
    cout << "Enter Passenger ID: ";
    cin >> request.passengerID;
    cout << "Enter Number of Seats Requested: ";
    cin >> request.numSeats;
    cout << "Enter Departure Time: ";
    cin >> request.departureTime;
    cout << "Enter Starting Terminal: ";
    cin >> request.startingTerminal;
    reservationStack.push(request);
    cout << "Reservation request added.\n";
}

void addTerminalRequest() {
    TerminalQueueRequest terminalRequest;
    int terminalIndex;
    cout << "Enter Request ID: ";
    cin >> terminalRequest.requestID;
    cout << "Enter Number of Seats Requested: ";
    cin >> terminalRequest.numSeats;
    cout << "Enter Terminal Index (0 to 5): ";
    cin >> terminalIndex;
    terminals[terminalIndex].waitingQueue.push_back(terminalRequest);
    cout << "Terminal queue request added.\n";
}

void confirmReservations() {
    while (!reservationStack.empty()) {
        ReservationRequest request = reservationStack.top();
        int terminalIndex = request.startingTerminal.back() - 'A';

        if (request.numSeats <= quotas[terminalIndex].availableSeats) {
            quotas[terminalIndex].availableSeats -= request.numSeats;
            quotas[terminalIndex].reservedSeats += request.numSeats;
            cout << "Reservation confirmed for Passenger ID " << request.passengerID << ".\n";
        } else {
            if (terminalIndex < 5) {
                TerminalQueueRequest nextTerminalRequest(request.passengerID, request.numSeats);
                terminals[terminalIndex + 1].waitingQueue.push_back(nextTerminalRequest);
                cout << "Reservation moved to the waiting queue of the next terminal.\n";
            } else {
                cout << "Insufficient seats available for Passenger ID " << request.passengerID << ".\n";
            }
        }

        reservationStack.pop();
    }
}

void handleCancellationModification() {
    int passengerID;
    cout << "Enter Passenger ID for Cancellation or Modification: ";
    cin >> passengerID;

    stack<ReservationRequest> tempStack;
    while (!reservationStack.empty()) {
        if (reservationStack.top().passengerID == passengerID) {
            reservationStack.pop();
            cout << "Reservation for Passenger ID " << passengerID << " canceled.\n";
            break;
        }
        tempStack.push(reservationStack.top());
        reservationStack.pop();
    }

    while (!tempStack.empty()) {
        reservationStack.push(tempStack.top());
        tempStack.pop();
    }

    for (int i = 0; i < 6; ++i) {
        auto it = find_if(terminals[i].waitingQueue.begin(), terminals[i].waitingQueue.end(),
                          [passengerID](const TerminalQueueRequest &request) { return request.requestID == passengerID; });

        if (it != terminals[i].waitingQueue.end()) {
            terminals[i].waitingQueue.erase(it);
            cout << "Request for Passenger ID " << passengerID << " removed from waiting queue.\n";
            break;
        }
    }

    cout << "No reservation or request found for Passenger ID " << passengerID << ".\n";
}

void displayMenu() {
    cout << "\nMenu:\n";
    cout << "1. Add Reservation Request\n";
    cout << "2. Add Terminal Queue Request\n";
    cout << "3. Confirm Reservations\n";
    cout << "4. Handle Cancellation or Modification\n";
    cout << "5. Display Status\n";
    cout << "6. Exit\n";
}

void displayStatus() {
    cout << "\nCurrent Status:\n";

    // Display reservations
    cout << "Reservations:\n";
    stack<ReservationRequest> tempStack = reservationStack;
    while (!tempStack.empty()) {
        ReservationRequest request = tempStack.top();
        cout << "Passenger ID: " << request.passengerID << ", Seats: " << request.numSeats
             << ", Departure Time: " << request.departureTime << ", Starting Terminal: " << request.startingTerminal << "\n";
        tempStack.pop();
    }

    // Display waiting queues
    cout << "\nWaiting Queues:\n";
    for (int i = 0; i < 6; ++i) {
        cout << "Terminal " << char('A' + i) << ":\n";
        for (const auto& request : terminals[i].waitingQueue) {
            cout << "Request ID: " << request.requestID << ", Seats: " << request.numSeats << "\n";
        }
    }

    // Display quotas
    cout << "\nQuotas:\n";
    for (int i = 0; i < 7; ++i) {
        cout << "Terminal " << char('A' + i) << ": Available Seats: " << quotas[i].availableSeats
             << ", Reserved Seats: " << quotas[i].reservedSeats << "\n";
    }
}

int main() {
    int choice;

    do {
        displayMenu();
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
        case 1:
            addReservationRequest();
            break;
        case 2:
            addTerminalRequest();
            break;
        case 3:
            confirmReservations();
            break;
        case 4:
            handleCancellationModification();
            break;
        case 5:
            displayStatus();
            break;
        case 6:
            cout << "Exiting program.\n";
            break;
        default:
            cout << "Invalid choice. Please try again.\n";
        }
    } while (choice != 6);

    return 0;
}
