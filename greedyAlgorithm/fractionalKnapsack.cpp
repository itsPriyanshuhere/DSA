#include <iostream>
#include <vector>
#include <algorithm>

struct Item {
  int weight;
  int value;
  double ratio;
};

bool compare(Item i1, Item i2) {
  return i1.ratio > i2.ratio;
}

double fractionalKnapsack(int W, std::vector<Item>& items) {
  double totalValue = 0.0;

  std::sort(items.begin(), items.end(), compare);

  for (auto& item : items) {
    if (W == 0) {
      break;
    }

    if (item.weight <= W) {
      totalValue += item.value;
      W -= item.weight;
    } else {
      totalValue += (double)item.value * W / item.weight;
      W = 0;
    }
  }

  return totalValue;
}

int main() {
  int W, n;
  std::cout << "Enter the capacity of the knapsack: ";
  std::cin >> W;
  std::cout << "Enter the number of items: ";
  std::cin >> n;

  std::vector<Item> items(n);
  for (int i = 0; i < n; i++) {
    std::cout << "Enter the weight and value of item " << i+1 << ": ";
    std::cin >> items[i].weight >> items[i].value;
    items[i].ratio = (double)items[i].value / items[i].weight;
  }

  double maxTotalValue = fractionalKnapsack(W, items);

  std::cout << "Maximum total value in knapsack = " << maxTotalValue << std::endl;

  return 0;
}