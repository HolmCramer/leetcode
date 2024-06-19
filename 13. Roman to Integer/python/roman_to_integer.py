class Solution:
    def romanToInt(self, s: str) -> int:
        romandict = {"I" : 1, "V" : 5, "X" : 10, "L" : 50, "C" : 100, "D" : 500, "M" : 1000}
        sdict = list(str(s))
        solution = 0

        for i in range(len(sdict)):
            if sdict[i] in romandict:
                if i+1 in range(len(sdict)) and romandict[sdict[i+1]] > romandict[sdict[i]]:
                    solution = solution + romandict[sdict[i+1]] - romandict[sdict[i]]           #wenn das nächste element größer als das aktuelle ist
                elif i-1 in range(len(sdict)) and romandict[sdict[i]] > romandict[sdict[i-1]]:  # wenn das vorherige kleiner als das aktuelle ist
                    pass
                else:
                    solution = solution + romandict[sdict[i]]
        return solution