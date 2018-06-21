// ------ 浙大 - To Fill or Not to Fill ------- //
// 贪心策略： //
// 1. 可达距离内有更便宜的油站 - 保证油量足够到达该油站即可 //
// 2. 可达距离没有更便宜的油站 - 加满油，去到最便宜的油站 //

#include <algorithm>
#include <iomanip>
#include <iostream>

using namespace std;

struct GasStation {
  double P;
  int D;
  bool operator < (const GasStation& g) const {
    return D < g.D;
  }
};

int main(int argc, char const *argv[]) {
  int Cmax; // max capacity of tank
  int D;    // distance
  int Davg; // average distance per unit gas can run
  int N;    // number of gas stations
  GasStation G[501];

  // status
  double Ccur; // units of current gas
  double Dleft; // max distance can run from current gas station without add gas
  int Dmax; // max distance can run from current gas station
  int next; // next station
  double fee; // total fee
  bool find_min_flag;

  while(cin >> Cmax >> D >> Davg >> N) {
    // input
    for (int i = 0; i < N; i++) cin >> G[i].P >> G[i].D;
    G[N].P = 0; G[N].D = D;

    // sort by destination
    sort (G, G+N); 

    Ccur = 0; Dmax = Cmax * Davg; fee = 0; next = 0;
    for (int i = 0; i < N; i = next) {
      // left can go       // next to go
      Dleft = Ccur * Davg; next = i + 1;

      // left gas is enough
      if (Dleft + G[i].D >= D) {
        next = N;
        break;
      }

      // left gas is not enough
      find_min_flag = false;
      for (int k = i + 1; k <= N && G[k].D - G[i].D <= Dmax; k++) {
        // find the cheaper station
        if (G[k].P < G[i].P) {
          next = k;
          find_min_flag = true;
          break;
        }
        // find the cheapest station
        if(G[next].P > G[k].P) next = k;
      }

      int distance = G[next].D - G[i].D;
      // cannot go to next
      if (distance > Dmax) {
        next = i;
        break;
      }
      // fill the tank
      if (find_min_flag) {
        // find the cheaper but the left is not enough
        if (distance > Dleft) {
          fee += (distance - Dleft) / Davg * G[i].P;
          Ccur = 0;
        }
        else {
          Ccur -= distance * 1.0 / Davg;
        }
      }
      else {
        // cannot find cheaper one then go to the cheapest
        fee += (Cmax - Ccur) * G[i].P;
        Ccur = Cmax - distance * 1.0 / Davg;
      }
    }

    // output 
    if (next == N) cout << fixed << setprecision(2) << setfill('0') << fee << endl;
    else {
      cout << "The maximum travel distance = ";
      cout << setprecision(2) << fixed << setfill('0') << G[next].D * 1.0 + Dmax << endl;
    }
  }

  return 0;
}
