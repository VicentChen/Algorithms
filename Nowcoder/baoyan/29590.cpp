// ------ 浙大 - Graduate Admission ------- //
#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

struct Applicant {
  int no;
  int Ge;
  int Gi;
  int Gf;
  int choice[5];

  bool operator < (const Applicant& a) const {
    if (Gf == a.Gf) return Ge < a.Ge;
    return Gf < a.Gf;
  }
};

struct School {
  int quota;
  Applicant low;
  vector<int> s;
};

int main(int argc, char const *argv[]) {
  int N; // number of all applicant
  int M; // number of graduate school
  int K; // choice of an applicant

  School s[100]; // school
  Applicant a[40000]; // applicant

  while (cin >> N >> M >> K) {
    // read
    for (int i = 0; i < M; i++)
      cin >> s[i].quota;
    for (int i = 0; i < N; i++) {
      a[i].no = i;
      cin >> a[i].Ge >> a[i].Gi;
      a[i].Gf = (a[i].Ge + a[i].Gi);
      for (int j = 0; j < K; j++)
        cin >> a[i].choice[j];
    }

    // sort
    sort(a, a+N);

    // distribute
    for (int i = N - 1; i >= 0; i--) {
      for (int j = 0; j < K; j++) {
        int choice = a[i].choice[j];
        //  not full               rank not lower than last accepted
        if (s[choice].quota > 0 || !(a[i] < s[choice].low)) {
          s[choice].quota--; // accept
          s[choice].low = a[i];
          s[choice].s.push_back(a[i].no);
          break;
        }
      }
    }

    // show 
    for (int i = 0; i < M; i++) {
      int count = s[i].s.size();
      if (count == 0) {
        // no accepted
        cout << endl;
      }
      else {
        sort(s[i].s.begin(), s[i].s.end());
        cout << s[i].s[0];
        for (int j = 1; j < count; j++)
          cout << ' ' << s[i].s[j];
        cout << endl;
      }
    }
  }

  return 0;
}
