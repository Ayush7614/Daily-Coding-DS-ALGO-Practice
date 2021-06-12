// Rabin-Karp algorithm in C++

#include<bits/stdc++.h>
using namespace std;

#define d 10

void rabinKarpAlgo(char patternInText[], char text[], int q) {
  int m = strlen(patternInText);
  int n = strlen(text);
  int i, j;
  int p = 0;
  int t = 0;
  int h = 1;

  for (i = 0; i < m - 1; i++)
    h = (h * d) % q;

  // Calculating  hash value
  for (i = 0; i < m; i++) {
    p = (d * p + patternInText[i]) % q;
    t = (d * t + text[i]) % q;
  }

  for (i = 0; i <= n - m; i++) {
    if (p == t) {
      for (j = 0; j < m; j++) {
        if (text[i + j] != patternInText[j])
          break;
      }

      if (j == m)
        cout << "Position of pattern :  " << i + 1 << endl;
    }

    if (i < n - m) {
      t = (d * (t - text[i] * h) + text[i + m]) % q;

      if (t < 0)
        t = (t + q);
    }
  }
}

int main() {
  char text[] = "SUNDAY";
  char patternInText[] = "DAY";
  int q = 13;
  rabinKarpAlgo(patternInText, text, q);
}

//Output : Position of pattern  : 4


/*
The time complexity of the searching phase of the Karp-Rabin algorithm is O(mn) (when searching for am in an for instance).
Its expected number of text character comparisons is O(n+m)
  
  /*
