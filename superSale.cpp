#include <iostream>
#include <queue>
#include <vector>

using namespace std;

bool debug = false;

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

    if (debug){
        cout << "Ordered: " << endl;
        while (!orderedPeople.empty()){
            cout << orderedPeople.top() << endl;
            orderedPeople.pop();
        }
    }

    int currentObj, spaceLeft;
    //dynamic programming solution
    //r starts in 1 since the first row is going to stay
    //filled with 0s
    for (int r = 1; r <= nObjects; r++){
        currentObj = r - 1; // object in my parallel arrays...
        if (debug){
            cout << "Filling for obj: " << currentObj << endl;
        }

        for (int c = 1; c <= maxPersonCapacity; c++){
            if (debug){
                cout << "Solving subproblem... Kanpsack weight: " << c << endl;
            }
            //calculate space left in knapsack if I include
            //the current obj
            spaceLeft = c - weights[currentObj];

            //if current object fits
            if ( spaceLeft >= 0 ){
                if (debug){
                    cout << "Obj fits, space left: " << spaceLeft << endl;
                }

                //current object does fit
                D[r][c] = getMax(D[r-1][c], prices[currentObj] + D[r-1][spaceLeft]);
                if (debug){
                    cout << "Max possible value: " << D[r][c] << endl;
                }

            }else{

                //current object does not fit
                //inherit value above
                D[r][c] = D[r-1][c];
                if (debug){
                    cout << "Doesnt fit, so: " << D[r][c] << endl;
                }

            }
        }


    }

    if (debug){
        cout << "Matrix after all operations: " << endl;
        for (int r = 0; r <= nObjects; r++){
            for (int c = 0; c <= maxPersonCapacity; c++ ){
                cout << D[r][c] << ' ';
            }
            cout << endl;
        }
    }

    for (int i = 0; i < nPeople; i++){
        max += D[nObjects][people[i]];
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
        if (debug){
            printObjects(prices, weights, nObjects);
        }

        cin >> nPeople;

        //initialize people array of nPeople size
        people = new int[nPeople];

        //get maximum weight that each person can carry from stdin
        int maxCapacity = requestWeights(people, nPeople);
        if (debug){
            printWeights(people, nPeople);
        }

        //get the maximum value of goods I can get with this group
        maxValue = dynamicBackpack(prices, weights, nObjects, people, nPeople, maxCapacity);

        if (debug){
            cout << "This is the max value your group can carry: ";
        }

        cout << maxValue << endl;

        //increase case counter
        cont++;

        //release memory taken up by arrays.
        delete []prices;
        delete []weights;
        delete []people;
    }
    return 0;
}
