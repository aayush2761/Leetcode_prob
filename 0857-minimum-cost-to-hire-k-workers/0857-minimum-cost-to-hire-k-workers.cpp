//naive way // brute Force
class Solution {
public:
    double mincostToHireWorkers(vector<int>& quality, vector<int>& wage, int k) {
     int n = wage.size();
     double minCost = DBL_MAX;

     // we dont have to give each wrker chance to become the captian

     vector<pair<double,int>>workers(n);
     for(int i=0;i<n;i++){
        double ratio = (double) wage[i]/quality[i];
        workers[i]= {ratio, quality[i]};
     }
     sort(workers.begin(),workers.end());

     for(int i=k-1;i<n;i++){
        //
        double captainRatio = workers[i].first;
        vector<double>acceptedOffers;
        for(int j=0;j<i+1;j++){
            double offer = workers[j].second* captainRatio;
            acceptedOffers.push_back(offer);
        }
      
         
        // find the sum of the k smallest elements 
        priority_queue<double , vector<double>> maxheap;
        double sumHeap=0;
        for(int i=0;i<k;i++){
            maxheap.push(acceptedOffers[i]);
            sumHeap+=acceptedOffers[i];
        }
        for(int i=k;i<acceptedOffers.size();i++){
            if(!maxheap.empty() && acceptedOffers[i]<maxheap.top()){
                sumHeap-= maxheap.top();
                maxheap.pop();
                 maxheap.push(acceptedOffers[i]);
                 sumHeap+=acceptedOffers[i];
            }
        }
        double cost = sumHeap;
        minCost= min(minCost , cost);
     }
      return minCost;

    }
};


// //naive way // brute Force
// class Solution {
// public:
//     double mincostToHireWorkers(vector<int>& quality, vector<int>& wage, int k) {
//      int n = wage.size();
//      double minCost = DBL_MAX;
//      for(int i=0;i<n;i++){
//         double captainRatio = (double) wage[i]/quality[i];
//         vector<double>acceptedOffers;
//         for(int j=0;j<n;j++){
//             double offer = quality[j]* captainRatio;
//             if(offer>= wage[j]) acceptedOffers.push_back(offer);
//         }
//         if(acceptedOffers.size()<k) continue;
         
//         // find the sum of the k smallest elements 
//         priority_queue<double , vector<double>> maxheap;
//         double sumHeap=0;
//         for(int i=0;i<k;i++){
//             maxheap.push(acceptedOffers[i]);
//             sumHeap+=acceptedOffers[i];
//         }
//         for(int i=k;i<acceptedOffers.size();i++){
//             if(!maxheap.empty() && acceptedOffers[i]<maxheap.top()){
//                 sumHeap-= maxheap.top();
//                 maxheap.pop();
//                  maxheap.push(acceptedOffers[i]);
//                  sumHeap+=acceptedOffers[i];
//             }
//         }
//         double cost = sumHeap;
//         minCost= min(minCost , cost);
//      }
//       return minCost;

//     }
// };