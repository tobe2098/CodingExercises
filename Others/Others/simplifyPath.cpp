#include "simplifyPath.hpp"

std::string simplifyPath(std::string path) {
    std::string token("/");
    std::vector<std::string> tokens;
    bool slash{ true };

    for (size_t i = 1; i < path.length(); i++) {
        if (path[i] == '/') {
            if (!slash) {
                if (token == "..") {
                    if (tokens.size() > 1) {
                        tokens.pop_back();
                        tokens.pop_back();
                    }
                    token.clear();
                    while (i<path.length() && path[i] == '/') i++;
                    i--;
                    continue;
                }
                else if (token == ".") {
                    tokens.pop_back();
                }
                else if (token!="") {
                    tokens.push_back(token);
                }
                token.clear();
                token.push_back('/');
                slash = true;
            }
        }
        else {
            if (slash) {
                tokens.push_back(token);
                token.clear();
                token.push_back(path[i]);
                slash = false;
            }
            else {
                token.push_back(path[i]);
            }
        }
    }
    if (token == "..") {
        if (tokens.size() > 1) {
            tokens.pop_back();
            tokens.pop_back();
            tokens.pop_back();
        }
    }
    else if (token == ".") {
        tokens.pop_back();
    }
    else if (token!="/" && token!="") {
        tokens.push_back(token);
    }
    while (!tokens.empty() && tokens.back() == "/" ) tokens.pop_back();
    std::string sol;
    for (const std::string& s : tokens) {
        sol.append(s.begin(), s.end());
    }
    if (sol.empty())return "/";
    else return sol;
}

std::string simplifyPath2(std::string path) {
    std::stack<std::string> st;
    std::string ans = "";
    for (int i = 0; i < path.size(); i++) {
        if (path[i] == '/') {
            continue;
        }
        std::string temp;
        while (i < path.size() && path[i] != '/') {
            temp += path[i];
            i++;
        }
        if (temp == ".") {
            continue;
        }
        else if (temp == "..") {
            if (!st.empty()) {
                st.pop();
            }
        }
        else {
            st.push(temp);
        }
    }
    while (!st.empty()) {
        ans = '/' + st.top() + ans;
        st.pop();
    }
    if (ans.size() == 0) {
        return "/";
    }
    return ans;
}