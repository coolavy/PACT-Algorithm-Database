# Author: coolavy
# Language: Python
# Date: 11/16/2025

def GS(m_pref, w_pref):
    # Label all m and w as free
    free_m = list(m_pref.keys())
    engaged = {}
    proposals = {m: [] for m in m_pref}

    while free_m:
        m1 = free_m.pop(0)
        m1_pref = m_pref[m1]

        # Propose to next woman in preference list
        for w1 in m1_pref:
            if w1 not in proposals[m1]:
                proposals[m1].append(w1)
            
            # If the woman is not engaged, engage her with the man
            if w1 not in engaged:
                engaged[w1] = m1
                break
        
            # If this woman prefers this man over their existing partner
            curr = engaged[w1]
            if w_pref[w1].index(m1) < w_pref[w1].index(curr):
                engaged[w1] = m1
                free_m.append(curr)
                break

    return engaged

# Sample input:
men_preferences = {
"A": ["X", "Y", "Z"],
"B": ["Y", "X", "Z"],
"C": ["X", "Z", "Y"]
}

women_preferences = {
"X": ["B", "A", "C"],
"Y": ["A", "B", "C"],
"Z": ["A", "C", "B"]
}

result = GS(men_preferences, women_preferences)
print("Stable Matching:", result)