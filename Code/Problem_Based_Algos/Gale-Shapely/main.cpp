
// Author: coolavy
// Language: C++
// Date: 11/16/2025

#include <bits/stdc++.h>
using namespace std;

map<string, string> GS(unordered_map<string, vector<string>> m_pref, unordered_map<string, vector<string>> w_pref) {
    // Label all m and w as free
    vector<string> free_m;
    for (auto &p : m_pref) free_m.push_back(p.first);

    map<string, string> engaged; // woman -> man
    unordered_map<string, vector<string>> proposals;
    for (auto &p : m_pref) proposals[p.first] = {};

    while (!free_m.empty()) {
        string m1 = free_m.front();
        free_m.erase(free_m.begin());

        vector<string> &m1_pref = m_pref[m1];

        // Propose to next woman in preference list
        for (const string &w1 : m1_pref) {
            if (find(proposals[m1].begin(), proposals[m1].end(), w1) == proposals[m1].end()) {
                proposals[m1].push_back(w1);
            }

            // If the woman is not engaged, engage her with the man
            if (engaged.find(w1) == engaged.end()) {
                engaged[w1] = m1;
                break;
            }

            // If this woman prefers this man over their existing partner
            string curr = engaged[w1];

            auto &wlist = w_pref[w1];
            int pos_m1 = find(wlist.begin(), wlist.end(), m1) - wlist.begin();
            int pos_curr = find(wlist.begin(), wlist.end(), curr) - wlist.begin();

            if (pos_m1 < pos_curr) {
                engaged[w1] = m1;
                free_m.push_back(curr);
                break;
            }
        }
    }

    return engaged;
}