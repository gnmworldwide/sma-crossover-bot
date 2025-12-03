#include <iostream>
#include <vector>
#include <iomanip>

using namespace std;

// Simple Moving Average (SMA) function
double computeSMA(const vector<double>& prices, int end, int window) {
    if (end + 1 < window) return -1; // not enough data
    double sum = 0.0;
    for (int i = end - window + 1; i <= end; ++i) {
        sum += prices[i];
    }
    return sum / window;
}

int main() {
    // Simulated prices
    vector<double> prices = {
        100.0, 101.5, 102.0, 101.0, 99.5,
        98.0, 97.5, 98.2, 99.0, 100.5,
        101.8, 102.5, 101.0, 100.0, 99.2
    };

    int shortWindow = 3;
    int longWindow = 5;
    bool holding = false;
    double entryPrice = 0.0;
    double profit = 0.0;

    cout << fixed << setprecision(2);
    cout << "📈 Running SMA Crossover Strategy...\n\n";

    for (size_t i = 0; i < prices.size(); ++i) {
        double shortSMA = computeSMA(prices, i, shortWindow);
        double longSMA = computeSMA(prices, i, longWindow);

        cout << "Day " << i + 1 << ": Price = " << prices[i];

        if (shortSMA == -1 || longSMA == -1) {
            cout << " | Waiting for enough data...\n";
            continue;
        }

        cout << " | SMA(" << shortWindow << ") = " << shortSMA
             << ", SMA(" << longWindow << ") = " << longSMA;

        if (!holding && shortSMA > longSMA) {
            holding = true;
            entryPrice = prices[i];
            cout << " → BUY @ " << entryPrice << "\n";
        } else if (holding && shortSMA < longSMA) {
            holding = false;
            double pnl = prices[i] - entryPrice;
            profit += pnl;
            cout << " → SELL @ " << prices[i] << " | PnL: " << pnl << "\n";
        } else {
            cout << "\n";
        }
    }

    cout << "\n💰 Total Strategy PnL: " << profit << endl;

    return 0;
}
