// class Solution {
// public:

//     void buildAns(stack<string>&s,string &ans){
//       if(s.empty()){
//         return;
//       }
//       string minPath=s.top();s.pop();
//     }

//     string simplifyPath(string path) {
//         stack<string>s;
//         int i=0;
//         while(i<path.size()){
//           int i=0;
//           int start=i;
//           int end=i+1;
//           while(end<path.size()&&path[end]!='/'){
//             end++;
//           }
//           string  minpath=path.substr(start,end-start);
//           i=end;
//           if(minpath=="/"||minpath=="/."){
//             continue;
//           }
//           if(minpath!="/.."){
//             s.push(minpath);
//           }
//           else if(!s.empty()){
//             s.pop();
//           }
//         }
//         string ans=s.empty()?"/":"";
//         buildAns(s,ans);
//         return ans;
//     }
// };