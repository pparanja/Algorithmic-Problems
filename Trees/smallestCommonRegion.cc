class Solution {
public:
    string findSmallestRegion(vector<vector<string>>& regions, string region1, string region2) {
        
        bool foundreg1 = false, foundreg2 = false;
        string newRegion1, newRegion2;
        for (auto regionList : regions) {
            for (int i=0; i < regionList.size(); i++) {
                if (regionList[i] == region1) {
                    newRegion1=  regionList[0];
                    foundreg1 = true;
                }
                if (regionList[i] == region2) {
                    newRegion2 =  regionList[0];
                    foundreg2 = true;
                }
                
                if (region1 == region2) {
                    return region1;
                }
                
                if (foundreg1 && foundreg2) {
                    goto recurse;
                }
            }
        }
        return "";
        recurse:
        return findSmallestRegion(regions, newRegion1, newRegion2);
 
    }
};
