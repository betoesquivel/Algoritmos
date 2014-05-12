#include <iostream>
#include <queue>
#include <vector>

using namespace std;

void requestObjects (int prices[], int weights[], int numObjects){
    for (int i = 0; i < numObjects; i++){
        cin >> prices[i] >> weights[i];
    }
}

int requestWeights (int people[], int nPeople){
    int max = -1;
    for (int i = 0; i < nPeople; i++){
        cin >> people[i];
        max = (people[i] > max) ? people[i]:max;
    }
    return max;
}

void printObjects (int prices[], int weights[], int numObjects){
    cout << "Objects" << endl;
    cout << "Price " << " Weight" << endl;
    for (int i = 0; i < numObjects; i++){
        cout << prices[i] << "  " << weights[i] << endl;
    }
}

void printWeights (int people[], int nPeople){
    cout << "People" << endl;
    cout << "i maxWeight" << endl;
    for (int i = 0; i < nPeople; i++){
        cout << people[i] << endl;
    }
}

int getMax(int a, int b){
    return (a > b) ? a:b;
}

int dynamicBackpack(int prices[], int weights[], int nObjects, int people[], int nPeople, int maxPersonCapacity){
    int max = 0;
    priority_queue<int, vector<int>, greater<int> > orderedPeople; //ordered the people according to their weights

    //initialized dynamic programming array used to solve the subproblems
    //and subsequently the largest final problem
    int D[1200][1200] = {0};

    for (int i = 0; i < nPeople; i++){
        orderedPeople.push(people[i]);
    }

    cout << "Ordered: " << endl;
    while (!orderedPeople.empty()){
        cout << orderedPeople.top() << endl;
        orderedPeople.pop();
    }

    //dynamic programming solution
    //r starts in 1 since the first row is going to stay
    //filled with 0s
    for (int r = 1; r < nObjects; r++){


        for (int c = 0; c < maxPersonCapacity; c++){

        }


    }

    return max;
}


int main(int argc, char const* argv[])
{
    int *prices, *weights, *people;
    int cases = 0;
    cin >> cases;

    int cont = 0;
    while (cont < cases) {
        int nObjects, nPeople, maxValue;
        cin >> nObjects;

        //initialize two new arrays of nObjects size
        prices = new int[nObjects];
        weights = new int[nObjects];

        //get objects from standard input
        requestObjects(prices, weights, nObjects);
        printObjects(prices, weights, nObjects);

        cin >> nPeople;

        //initialize people array of nPeople size
        people = new int[nPeople];

        //get maximum weight that each person can carry from stdin
        int maxCapacity = requestWeights(people, nPeople);
        printWeights(people, nPeople);

        //get the maximum value of goods I can get with this group
        maxValue = dynamicBackpack(prices, weights, nObjects, people, nPeople, maxCapacity);

        cout << "This is the max value your group can carry: " << maxValue << endl;

        //increase case counter
        cont++;

        //release memory taken up by arrays.
        delete []prices;
        delete []weights;
        delete []people;
    }
    return 0;
}
