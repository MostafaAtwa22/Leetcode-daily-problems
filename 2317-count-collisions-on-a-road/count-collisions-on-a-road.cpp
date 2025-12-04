class Solution { 
public: 
    int countCollisions(string s) { 
        int cnt = 0; 
        int n = s.size(); 
        stack<char> st; 

        for (int i = 0; i < n; i++) { 
            if (st.empty()) { 
                st.push(s[i]); 
                continue; 
            } 

            if (s[i] == 'L') { 
                bool collided = false;

                if (st.top() == 'R') {
                    cnt += 2;
                    st.pop();
                    collided = true;

                    while (!st.empty() && st.top() == 'R') {
                        cnt++;
                        st.pop();
                    }
                }
                else if (st.top() == 'S') {
                    cnt++;
                    st.pop();
                    collided = true;
                }

                if (collided) st.push('S');
                else st.push('L');
            } 

            else if (s[i] == 'R') { 
                st.push(s[i]); 
            } 

            else { 
                while (!st.empty() && st.top() == 'R') {
                    cnt++;
                    st.pop();
                }
                st.push('S'); 
            } 
        } 
        return cnt; 
    } 
};
