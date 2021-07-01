//
// Created by Kylian Lee on 2021/06/24.
//

#include <iostream>
#include <vector>
#include <map>

using namespace std;

int solution(int tar, vector<int> v, map<int, int> m);

int main(){
  int caseNum;
  cin >> caseNum;
  for (int i = 0; i < caseNum; ++i) {

    vector<int> v;
    map<int, int> m;
    int num, tar;
    cin >> num >> tar;
    for (int j = 0; j < num; ++j) {
      int tmp;
      cin >> tmp;
      v.push_back(tmp);
      m[tmp]++;
    }
    cout << solution(tar, v, m) << endl;
  }
}

int solution(int tar, vector<int> v, map<int, int> m){
  int i = 0;
  int count = 0;
  int size = v.size();
  while(true){
    if(i == size)
      i %= size;
    if(v[i] == 0)
      continue;
    if(i == tar && m.begin()->first == v[i]) {
      count++;
      break;
    }
    if(v[i] == m.end()->first){
      m.end()->second--;
      v[i] = 0;
      count++;
      if(m.end()->second == 0)
        m.erase(m.end()->first);
    }
    i++;
  }
  return count;
}