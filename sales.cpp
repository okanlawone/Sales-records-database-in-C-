#include <iostream>
using namespace std;

const int numQtrs = 4;
const int numBranches = 5;

void fill2DArray(int sales[][numBranches], int numQtrs, int numBranches) {
    for (int i = 0; i < numQtrs; i++) {
        cout << "Enter the sales for Quarter " << i + 1 << " for Branches 1 to 5: ";
        for (int j = 0; j < numBranches; j++) {
            cin >> sales[i][j];
        }
    }
}

void computeQtrlySums(int sales[][numBranches], int qtrlySums[], int numQtrs, int numBranches) {
    for (int i = 0; i < numQtrs; i++) {
        int Qsum = 0;
        for (int j = 0; j < numBranches; j++) {
            Qsum += sales[i][j];
        }
        qtrlySums[i] = Qsum;
    }
}

void computeBranchSums(int sales[][numBranches], int branchSums[], int numQtrs, int numBranches) {
    for (int i = 0; i < numBranches; i++) {
        int Bsum = 0;
        for (int j = 0; j < numQtrs; j++) {
            Bsum += sales[j][i];
        }
        branchSums[i] = Bsum;
    }
}

void displayAnnualSalesReport(int sales[][numBranches], int qtrlySums[], int branchSums[], int numQtrs, int numBranches) {
    cout << "\t\tBranch-1\tBranch-2\tBranch-3\tBranch-4\tBranch-5\tTotal\n";
    for (int i = 0; i < numQtrs; i++) {
        cout << "Quarter-" << i + 1 << "\t";
        for (int j = 0; j < numBranches; j++) {
            cout << sales[i][j] << "\t\t";
        }
        cout << qtrlySums[i] << "\n";
    }
    cout << "Total:\t\t";
    for (int i = 0; i < numBranches; i++) {
        cout << branchSums[i] << "\t\t";
    }
    int total = 0;
    for (int i = 0; i < numQtrs; i++) {
        total += qtrlySums[i];
    }
    cout << total << "\n";
}

int main() {
    int sales[numQtrs][numBranches];
    int qtrlySums[numQtrs];
    int branchSums[numBranches];

    fill2DArray(sales, numQtrs, numBranches);
    computeQtrlySums(sales, qtrlySums, numQtrs, numBranches);
    computeBranchSums(sales, branchSums, numQtrs, numBranches);
    displayAnnualSalesReport(sales, qtrlySums, branchSums, numQtrs, numBranches);

    return 0;
}
