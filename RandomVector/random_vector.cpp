#include "random_vector.h"
#include <cstdlib>

RandomVector::RandomVector(int size, double max_val) {
  for (int i = 0; i < size; ++i) {
    double value = static_cast<double>(std::rand()) / RAND_MAX * max_val;
    vect.push_back(value);
  }
}

void RandomVector::print() {
  for (std::size_t i = 0; i < vect.size(); ++i) {
    std::cout << vect[i] << " ";
  }
  std::cout << std::endl;
}

double RandomVector::mean() {
  if (vect.empty()) {
    return 0.0;
  }

  double sum = 0.0;
  for (std::size_t i = 0; i < vect.size(); ++i) {
    sum += vect[i];
  }
  return sum / vect.size();
}

double RandomVector::max() {
  if (vect.empty()) {
    return 0.0;
  }

  double maximum = vect[0];
  for (std::size_t i = 1; i < vect.size(); ++i) {
    if (vect[i] > maximum) {
      maximum = vect[i];
    }
  }
  return maximum;
}

double RandomVector::min() {
  if (vect.empty()) {
    return 0.0;
  }

  double minimum = vect[0];
  for (std::size_t i = 1; i < vect.size(); ++i) {
    if (vect[i] < minimum) {
      minimum = vect[i];
    }
  }
  return minimum;
}

void RandomVector::printHistogram(int bins) {
  if (vect.empty() || bins <= 0) {
    return;
  }

  std::vector<int> counts(bins, 0);
  double minimum = min();
  double maximum = max();
  double range = maximum - minimum;

  if (range == 0.0) {
    counts[0] = static_cast<int>(vect.size());
  } else {
    for (std::size_t i = 0; i < vect.size(); ++i) {
      int bin = static_cast<int>((vect[i] - minimum) / range * bins);
      if (bin == bins) {
        bin = bins - 1;
      }
      counts[bin]++;
    }
  }

  int highest_count = counts[0];
  for (int i = 1; i < bins; ++i) {
    if (counts[i] > highest_count) {
      highest_count = counts[i];
    }
  }

  for (int row = highest_count; row > 0; --row) {
    for (int bin = 0; bin < bins; ++bin) {
      if (counts[bin] >= row) {
        std::cout << "*** ";
      } else {
        std::cout << "    ";
      }
    }
    std::cout << std::endl;
  }
}
