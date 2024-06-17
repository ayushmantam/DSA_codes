/*
class Solution {
public:
    bool isValid(string s) {
        stack<char>st;
        for(int i=0;i<s.length();i++){
          
          if(s[i]=='('||s[i]=='{'||s[i]=='['){
            st.push(s[i]);
          }
         
          else {
            if(!st.empty()){
              char Topch=st.top();
              if(Topch=='('&&s[i]==')'){
                st.pop();
              }
             else if(Topch=='{'&&s[i]=='}'){
                st.pop();
              }
              else if(Topch=='['&&s[i]==']'){
                st.pop();
              }
              else{//brackets not matching
                return false;
              }
            }
            else{
              return false;
            }

          }
        
        }

        if(st.empty()){
          return true;
        }
        else{
          return false;
        }
    }
};
*/