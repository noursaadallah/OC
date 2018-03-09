#include <vector>
#include <limits>
#include <algorithm>
#include "cut.h"

using namespace std;

double OptimalCut(int L, const vector<PricedCut>& cuts, vector<int>* cut_indices){

	if(L<= 0 ) return 0.0;

	double _max = -std::numeric_limits<double>::max();

	for(int i = 0; i<cuts.size() ; i++ )
		_max = max(_max, cuts[i].price + OptimalCut(L-cuts[i].length , cuts, cut_indices ) );
	return _max;
}


/*
//Iterative version

double OptimalCut(int L, const vector<PricedCut>& cuts, vector<int>* cut_indices) {
  cut_indices->clear();
  // Formula:
  // OptimalCut(L) =          Max             (x.price + OptimalCut(L - x.length)
  //                 | for x PricedCut |
  //                 | such that x.length <= L |
  // or = 0 if it doesn't exist a PricedCut x st x.length <= L
  //
  // Start by calculating the shortest lengths
  vector<double> best_price(L + 1, 0.0);
  vector<int> best_cut(L + 1, -1);
  for (int l = 1; l <= L; ++l) {
    double best = 0.0;
    for (int i = 0; i < cuts.size(); ++i) {
      if (cuts[i].length <= l) {
        double price = cuts[i].price + best_price[l - cuts[i].length];
        if (price > best) {
          best = price;
          best_cut[l] = i;
        }
      }
    }
    best_price[l] = best;
  }
  // Fill the vector "cut_indices" in the optimal way
  int l = L;
  while (true) {
    const int cut = best_cut[l];
    if (cut < 0) break;
    cut_indices->push_back(cut);
    l -= cuts[cut].length;
  }
  // return best price at L
  return best_price[L];
}
*/