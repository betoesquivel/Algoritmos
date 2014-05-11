#include <iostream>

using namespace std;

void requestObjects (int prices[], int weights[], int numObjects){
    for (int i = 0; i < numObjects; i++){
        cin >> prices[i] >> weights[i];
    }
}

void requestWeights (int people[], int nPeople){
    for (int i = 0; i < nPeople; i++){
        cin >> people[i];
    }
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

int dynamicBackpack(int prices[], int weights[], int nObjects, int people[], int nPeople){
    int max = 0;

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
        requestWeights(people, nPeople);
        printWeights(people, nPeople);

        //get the maximum value of goods I can get with this group
        maxValue = dynamicBackpack(prices, weights, nObjects, people, nPeople);

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
