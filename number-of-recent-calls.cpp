#include<cassert>
#include<queue>

class RecentCounter {
  private:
    std::queue<int> q;
  public:
    RecentCounter() { 
    }

    int ping(int t) { 
      int total_pings = 0;
      if(!q.empty()){ 
        if((t - q.front()) <= 3000){
          q.push(t);
        } else {
          while((t - q.front()) > 3000 && !q.empty()){
            q.pop();
          }
          q.push(t);
        }
      } else {
        q.push(t);
      }
      total_pings = q.size();

      return total_pings;
    }
};

int main(){ 
  RecentCounter r;
  /*
    auto n = r.ping(642);
  assert(n == 1) ;
  n = r.ping(1849);
  assert(n == 2) ;
  n = r.ping(4921);
  assert(n == 1) ;
  n = r.ping(5936);
  assert(n == 2) ;
  n = r.ping(5957);
  assert(n == 3);
  */
  auto n = r.ping(1);
  assert(n == 1);
  n = r.ping(100);
  assert(n == 2);
  n = r.ping(3001);
  assert(n == 3);
  n = r.ping(3002);
  assert(n == 3);
}
